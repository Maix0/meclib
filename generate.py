#!/usr/bin/env python3

from pathlib import Path, PosixPath
import argparse
import os
import subprocess
import shutil


if not shutil.which("fastmod"):
    print("please run `cargo install fastmod` and rerun the script !")
    exit(2)

if not shutil.which("rg"):
    print("please run `cargo install ripgrep` and rerun the script !")
    exit(2)


DEFAULT_GEN_SOURCES = Path("gsrc").absolute()
DEFAULT_OUT_SOURCES = Path("generic").absolute()
PROG_VERSION = "v0.1"

COL_RED = "\x1B[31m"
COL_WHITE = "\x1B[37m"

V_TRACE = 3
V_DEBUG = 2
V_MORE = 1

V_LEVEL = 0


def prune_invalid_path(p):
    if p.exists():
        return True
    print(f"{COL_RED}Invalid path: {p}{COL_WHITE}")
    return False


def flatten(iterables):
    return (elem for iterable in iterables for elem in iterable)


def walk_dir(p):
    walk = os.walk(p)

    return flatten(
        flatten(
            (
                ((p for p in map(lambda n: Path(dirpath) / n, files)),)
                for (dirpath, dirname, files) in walk
            )
        )
    )


def filter_for_c_files(path):
    return path.suffix == ".c" or path.suffix == ".h"


"""
#pomski regex

[space]*'#'[space]* 
'include' [space]+
'"'
:fullpath(
 'me/'
  :module([word]+) 
  '/generic/'
  :type('g_'[word]+'.h')
)
'"'
"""


parser = argparse.ArgumentParser(
    prog="MeLib Source Generator", description="Generate sources from template files"
)

parser.add_argument(
    "-s",
    "--sources",
    default=DEFAULT_GEN_SOURCES,
    help="The path of the desired sources for the generic files to be created",
)

parser.add_argument(
    "-o",
    "--out",
    default=DEFAULT_OUT_SOURCES,
    help="The path of the desired output directory for the generic files to be created",
)


parser.add_argument(
    "--version", "-V", action="version", version=f"%(prog)s {PROG_VERSION}"
)

parser.add_argument("-v", "--verbose", action="count", help="Verbose mode", default=0)

parser.add_argument(
    "paths",
    action="append",
    help="Source files to get generated that need to be created",
    nargs="+",
)

args = parser.parse_args()

args.sources = Path(args.sources).absolute()
args.out = Path(args.out).absolute()
args.paths = [Path(p).absolute().resolve() for p in flatten(args.paths)]
args.paths = list(filter(prune_invalid_path, args.paths))

if len(args.paths) == 0:
    exit(1)
V_LEVEL = args.verbose

if V_LEVEL >= V_DEBUG:
    print(args)

all_files = list(
    map(
        lambda p: f"{p}", filter(filter_for_c_files, flatten(map(walk_dir, args.paths)))
    )
)

if len(all_files) == 0:
    exit(0)

output = subprocess.run(
    [
        "rg",
        "-o",
        "-I",
        '\s*#\s*include\s+"(?P<fullpath>me/(?P<module>\w+)/generic/g_(?P<type>[\w_]+)\.h)"',
        "--replace",
        "$module|$type",
        *all_files,
    ],
    text=True,
    capture_output=True,
)


def find_source_for_gen(gen_mod):
    mod, ty = (gen_mod["module"], gen_mod["type"])
    return {
        "in_header": args.sources / "include" / f"me/{mod}/generic/template.h",
        "out_header": args.out / "include" / f"me/{mod}/generic/g_{mod}_{ty}.h",
        "in_source": args.sources / "src" / f"me/{mod}/generic/template/",
        "out_source": args.out / "src" / f"me/{mod}/generic/g_{ty}/",
        "type_header": f'#include "me/types/{ty}.h"',
        "module": mod,
        "ty": ty,
    }


def from_dual(dual):
    mod, ty = dual
    ty = ty.removeprefix(mod + '_')
    return {"module": mod, "type": ty}


if output.returncode == 1 and output.stderr == "":
    print("No files created")
    exit(0)

all_generated = list(
    map(
        from_dual,
        set(
            map(
                lambda s: tuple(s.split("|")),
                filter(lambda s: len(s) != 0, output.stdout.split("\n")),
            )
        ),
    )
)


def copy_and_overwrite(from_path, to_path):
    if os.path.exists(to_path):
        if to_path.is_dir():
            shutil.rmtree(to_path)
        else:
            os.remove(to_path)
    if from_path.is_dir():
        shutil.copytree(from_path, to_path)
    else:
        shutil.copy(from_path, to_path)


if len(all_generated) == 0:
    exit(0)

source_needed = list(map(find_source_for_gen, all_generated))

for s in source_needed:
    if not (s["in_source"].exists() and s["in_header"].exists()):
        print(
            f"{COL_RED}Please check the sources of the module '{s['module']}'{COL_WHITE}"
        )
        exit(3)
    os.makedirs(s["out_header"].parent, exist_ok=True)
    os.makedirs(s["out_source"].parent, exist_ok=True)
    copy_and_overwrite(s["in_source"], s["out_source"])
    copy_and_overwrite(s["in_header"], s["out_header"])
    output = [
        subprocess.run(
            [
                "fastmod",
                "-F",
                "__TYPENAME__",
                s["ty"],
                "--accept-all",
                s["out_source"],
                "-e",
                "c,h",
            ],
            text=True,
            capture_output=True,
        ),
        subprocess.run(
            [
                "fastmod",
                "-F",
                "__TYPENAME__",
                s["ty"],
                "--accept-all",
                s["out_header"],
                "-e",
                "c,h",
            ],
            text=True,
            capture_output=True,
        ),
        subprocess.run(
            [
                "fastmod",
                "-F",
                "__TYPEHEADER__",
                s["type_header"],
                "--accept-all",
                s["out_source"],
                "-e",
                "c,h",
            ],
            text=True,
            capture_output=True,
        ),
        subprocess.run(
            [
                "fastmod",
                "-F",
                "__TYPEHEADER__",
                s["type_header"],
                "--accept-all",
                s["out_header"],
                "-e",
                "c,h",
            ],
            text=True,
            capture_output=True,
        ),
        subprocess.run(
            [
                "fastmod",
                "-F",
                "TEMPLATE_H",
                f"G_{s['module'].upper()}_{s['ty'].upper()}_H",
                "--accept-all",
                s["out_header"],
                "-e",
                "c,h",
            ],
            text=True,
            capture_output=True,
        ),
    ]
    if any(map(lambda r: r.returncode != 0, output)) != 0:
        print(f"An error has occured with module {s['module']}<{s['ty']}>!")
    else:
        print(f"Written module {s['module']} for type {s['ty']}")
