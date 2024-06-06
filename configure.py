#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "G8ME01",  # 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--no-asm",
    action="store_true",
    help="don't incorporate .s files from asm directory",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = args.version
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.debug = args.debug
config.generate_map = args.map
config.sjiswrap_path = args.sjiswrap
if not is_windows():
    config.wrapper = args.wrapper
if args.no_asm:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20231018"
config.dtk_tag = "v0.7.6"
config.sjiswrap_tag = "v1.1.1"
config.wibo_tag = "0.6.13"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym version={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
    "-W off",
]

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    # define the platform
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    # for multibyte
    "-multibyte",
    "-char unsigned",
    # platform specific
    "-fp hardware",
    "-Cpp_exceptions off",
    '-pragma "cats off"',
    # default compiler flags
    "-W all",
    "-O4,p",
    "-inline auto",
    '-pragma "warn_notinlined off"',
    # helpful linking stuff
    "-maxerrors 1",
    "-nosyspath",
    # dtk-specific includes
    "-i include",
    f"-i build/{config.version}/include",
    f"-DVERSION={version_num}",
]

# Debug flags
if config.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# Game-specific flags
cflags_static = [
    *cflags_base,
    "-fp_contract on",
    "-use_lmw_stmw on",
    "-rostr",
    "-inline auto,deferred",
    "-sdata 48",
    "-sdata2 6",
    "-w nonotused",
    "-once",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

config.linker_version = "GC/2.6"


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_base,
        "host": False,
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/2.6",
        "cflags": cflags_rel,
        "host": True,
        "objects": objects,
    }


Matching = True
NonMatching = False

config.warn_missing_config = False
config.warn_missing_source = False
config.libs = [
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "host": False,
        "objects": [
            Object(NonMatching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
        ],
    },
    {
        "lib": "battle",
        "mw_version": config.linker_version,
        "cflags": cflags_static,
        "host": False,
        "objects": [
            Object(NonMatching, "battle/battle.c"),
            Object(NonMatching, "battle/battle_ac.c"),
            Object(NonMatching, "battle/battle_ac_help.c"),
            Object(NonMatching, "battle/battle_acrobat.c"),
            Object(NonMatching, "battle/battle_actrecord.c"),
            Object(NonMatching, "battle/battle_attack_audience.c"),
            Object(NonMatching, "battle/battle_audience.c"),
            Object(NonMatching, "battle/battle_audience_kind_data.c"),
            Object(NonMatching, "battle/battle_audience_kinopio.c"),
            Object(NonMatching, "battle/battle_break_slot.c"),
            Object(NonMatching, "battle/battle_camera.c"),
            Object(NonMatching, "battle/battle_damage.c"),
            Object(NonMatching, "battle/battle_database_common.c"),
            Object(NonMatching, "battle/battle_detect.c"),
            Object(NonMatching, "battle/battle_disp.c"),
            Object(NonMatching, "battle/battle_enemy_item.c"),
            Object(NonMatching, "battle/battle_event_cmd.c"),
            Object(NonMatching, "battle/battle_event_default.c"),
            Object(NonMatching, "battle/battle_event_subset.c"),
            Object(NonMatching, "battle/battle_evt_cmd.c"),
            Object(NonMatching, "battle/battle_icon.c"),
            Object(NonMatching, "battle/battle_information.c"),
            Object(NonMatching, "battle/battle_item_data.c"),
            Object(NonMatching, "battle/battle_mario.c"),
            Object(NonMatching, "battle/battle_menu_disp.c"),
            Object(NonMatching, "battle/battle_message.c"),
            Object(NonMatching, "battle/battle_monosiri.c"),
            Object(NonMatching, "battle/battle_pad.c"),
            Object(NonMatching, "battle/battle_party.c"),
            Object(NonMatching, "battle/battle_seq.c"),
            Object(NonMatching, "battle/battle_seq_command.c"),
            Object(NonMatching, "battle/battle_seq_end.c"),
            Object(NonMatching, "battle/battle_stage.c"),
            Object(NonMatching, "battle/battle_stage_object.c"),
            Object(NonMatching, "battle/battle_status_effect.c"),
            Object(NonMatching, "battle/battle_status_icon.c"),
            Object(NonMatching, "battle/battle_sub.c"),
            Object(NonMatching, "battle/battle_unit.c"),
            Object(NonMatching, "battle/battle_unit_event.c"),
            Object(NonMatching, "battle/battle_weapon_power.c"),
        ],
    },
    {
        "lib": "data",
        "mw_version": config.linker_version,
        "cflags": cflags_static,
        "host": False,
        "objects": [
            Object(Matching, "data/item_data.c"),
        ],
    },
    {
        "lib": "effect",
        "mw_version": config.linker_version,
        "cflags": cflags_static,
        "host": False,
        "objects": [
            Object(NonMatching, "effect/eff_batfukidashi.c"),
            Object(NonMatching, "effect/eff_batten.c"),
            Object(NonMatching, "effect/eff_bomb.c"),
            Object(NonMatching, "effect/eff_break.c"),
            Object(NonMatching, "effect/eff_breath_fire.c"),
            Object(NonMatching, "effect/eff_butterfly.c"),
            Object(NonMatching, "effect/eff_charge.c"),
            Object(NonMatching, "effect/eff_confetti.c"),
            Object(NonMatching, "effect/eff_damage_star.c"),
            Object(NonMatching, "effect/eff_energy.c"),
            Object(NonMatching, "effect/eff_fall.c"),
            Object(NonMatching, "effect/eff_fire.c"),
            Object(NonMatching, "effect/eff_fukidashi.c"),
            Object(NonMatching, "effect/eff_funemizu.c"),
            Object(NonMatching, "effect/eff_gonbaba_breath.c"),
            Object(NonMatching, "effect/eff_hibashira.c"),
            Object(NonMatching, "effect/eff_hit.c"),
            Object(NonMatching, "effect/eff_ibuki.c"),
            Object(NonMatching, "effect/eff_ice.c"),
            Object(NonMatching, "effect/eff_indirect.c"),
            Object(NonMatching, "effect/eff_irekaeru.c"),
            Object(NonMatching, "effect/eff_itemget.c"),
            Object(NonMatching, "effect/eff_kemuri.c"),
            Object(NonMatching, "effect/eff_kemutest.c"),
            Object(NonMatching, "effect/eff_kiss.c"),
            Object(NonMatching, "effect/eff_las_mon.c"),
            Object(NonMatching, "effect/eff_laser.c"),
            Object(NonMatching, "effect/eff_levelup.c"),
            Object(NonMatching, "effect/eff_machinegun.c"),
            Object(NonMatching, "effect/eff_mahojin.c"),
            Object(NonMatching, "effect/eff_mahorn.c"),
            Object(NonMatching, "effect/eff_mahorn2.c"),
            Object(NonMatching, "effect/eff_majinai.c"),
            Object(NonMatching, "effect/eff_mario_balloon.c"),
            Object(NonMatching, "effect/eff_minigame.c"),
            Object(NonMatching, "effect/eff_miss_star.c"),
            Object(NonMatching, "effect/eff_mist.c"),
            Object(NonMatching, "effect/eff_mist2.c"),
            Object(NonMatching, "effect/eff_mizutama.c"),
            Object(NonMatching, "effect/eff_mobj_broken.c"),
            Object(NonMatching, "effect/eff_mugi.c"),
            Object(NonMatching, "effect/eff_naniga.c"),
            Object(NonMatching, "effect/eff_nice.c"),
            Object(NonMatching, "effect/eff_nokotarou.c"),
            Object(NonMatching, "effect/eff_nozle.c"),
            Object(NonMatching, "effect/eff_number.c"),
            Object(NonMatching, "effect/eff_particle.c"),
            Object(NonMatching, "effect/eff_peach_fukidashi.c"),
            Object(NonMatching, "effect/eff_pointget.c"),
            Object(NonMatching, "effect/eff_puniballoon.c"),
            Object(NonMatching, "effect/eff_queen.c"),
            Object(NonMatching, "effect/eff_queen2.c"),
            Object(NonMatching, "effect/eff_rankup.c"),
            Object(NonMatching, "effect/eff_recovery.c"),
            Object(NonMatching, "effect/eff_ripple.c"),
            Object(NonMatching, "effect/eff_sandars.c"),
            Object(NonMatching, "effect/eff_scanning.c"),
            Object(NonMatching, "effect/eff_sheep.c"),
            Object(NonMatching, "effect/eff_sleep.c"),
            Object(NonMatching, "effect/eff_small_star.c"),
            Object(NonMatching, "effect/eff_spark.c"),
            Object(NonMatching, "effect/eff_spirit.c"),
            Object(NonMatching, "effect/eff_splash.c"),
            Object(NonMatching, "effect/eff_stageclear.c"),
            Object(NonMatching, "effect/eff_stardust.c"),
            Object(NonMatching, "effect/eff_starpoint.c"),
            Object(NonMatching, "effect/eff_syuryou.c"),
            Object(NonMatching, "effect/eff_teresa.c"),
            Object(NonMatching, "effect/eff_toge_flush.c"),
            Object(NonMatching, "effect/eff_toiki.c"),
            Object(NonMatching, "effect/eff_torch.c"),
            Object(NonMatching, "effect/eff_treasure_map.c"),
            Object(NonMatching, "effect/eff_ultra_hammer.c"),
            Object(NonMatching, "effect/eff_updown.c"),
            Object(NonMatching, "effect/eff_uranoko.c"),
        ],
    },
    Rel(
        "aaa",
        objects=[
            Object(NonMatching, "REL/aaa/aaa.c"),
            Object(NonMatching, "REL/aaa/aaa_00.c"),
        ],
    ),
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress and write progress.json
    config.progress_each_module = args.verbose
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
