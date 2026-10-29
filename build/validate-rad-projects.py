#!/usr/bin/env python3
"""Validate the RAD Studio project configuration metadata used by GUI groups."""
from pathlib import Path
import re
import sys
import xml.etree.ElementTree as ET

root = Path(__file__).resolve().parent.parent
repos = root.parent
ns = "{http://schemas.microsoft.com/developer/msbuild/2003}"
packages = (
    repos / "TUTPackage" / "TUTPackageNative.dproj",
    repos / "d7zip" / "MapManagerArchiveNative.dproj",
    repos / "Virtual-TreeView" / "Packages" / "CBuilder 13" / "VirtualTreesCR.dproj",
)
groups = (root / "MapManager-Components.groupproj", root / "MapManager-All.groupproj")

def check_package(p):
    doc = ET.parse(p).getroot()
    groups = [x for x in doc if x.tag == ns + "PropertyGroup"]
    for cfg, key in (("Debug", "Cfg_1"), ("Release", "Cfg_2")):
        matches = [
            x for x in groups
            if re.search(
                r"'\$\(Config\)'\s*==\s*'" + cfg + r"'",
                x.get("Condition", ""),
            )
        ]
        assert len(matches) == 1, (
            f"{p}: configuration {cfg} has {len(matches)} property groups; "
            "RAD Studio rejects duplicate declarations"
        )
        assert matches[0].findtext(ns + key) == "true", f"{p}: {key} missing"
        # RAD Studio's native project writer normally stores this as a Base
        # option rather than repeating it under Release/Debug.
        base_opts = [
            x for x in groups
            if x.attrib.get("Condition") == "'$(Base)'!=''"
        ]
        option_in_config = matches[0].findtext(ns + "DCC_CBuilderOutput")
        option_in_base = (base_opts[0].findtext(ns + "DCC_CBuilderOutput")
                          if len(base_opts) == 1 else None)
        assert option_in_config == "All" or option_in_base == "All", (
            f"{p}: package static .lib output is not enabled"
        )
    configs = doc.findall(".//" + ns + "BuildConfiguration")
    names = [x.get("Include") for x in configs]
    assert sorted(names) == sorted(("Base", "Debug", "Release")), (
        f"{p}: invalid or duplicated BuildConfiguration entries: {names}"
    )
    personality = doc.find(
        ns + "ProjectExtensions/" + ns + "BorlandProject/" +
        ns + "Delphi.Personality"
    )
    assert personality is not None, f"{p}: missing Delphi project personality"
    print("PASS", p.name, "Base/Debug/Release unique and IDE metadata present")

for p in packages:
    check_package(p)

for p in groups:
    doc = ET.parse(p).getroot()
    projects = doc.findall(".//" + ns + "Projects")
    assert projects, f"{p}: project group is empty"
    expected = (repos / "Virtual-TreeView" / "Packages" /
                "CBuilder 13" / "VirtualTreesCR.dproj").resolve()
    found_native = 0
    for project in projects:
        src = (p.parent / project.get("Include")).resolve()
        assert src.is_file(), f"{p}: missing project {src}"
        if src == expected:
            found_native += 1
        assert src.name != "VirtualTreesCR.cbproj", (
            f"{p}: obsolete C++Builder Virtual TreeView runtime package selected"
        )
    assert found_native == 1, f"{p}: expected one native Delphi VTV package"
    print("PASS", p.name, "native Delphi package and project references exist")

print("RAD Studio project configuration validation passed.")


vtv = repos / "Virtual-TreeView" / "Packages" / "CBuilder 13"
dpk = (vtv / "VirtualTreesCR.dpk").read_text(encoding="utf-8")
unit_list = re.findall(
    r"(?m)^\s*VirtualTrees(?:\.[A-Za-z0-9_]+)?\s+in\s+'([^']+)'",
    dpk,
)
assert len(unit_list) == 22, f"Native VTV package needs all 22 units: {len(unit_list)}"
assert len(set(unit_list)) == len(unit_list), "Duplicate VTV source reference"
for ref in unit_list:
    assert (vtv / ref.replace("\\", "/")).is_file(), f"Missing VTV unit {ref}"
print("PASS VirtualTreesCR.dpk: all 22 original Pascal units referenced")
