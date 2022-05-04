#!/usr/bin/env python3
"""Create a new problem solution file from a language template."""
from argparse import ArgumentParser, Namespace
from pathlib import Path
from shutil import Error, copyfile
from sys import stderr

PROJECT_ROOT = Path(__file__).parent.parent


def parse_args() -> Namespace:
    parser = ArgumentParser()
    parser.add_argument("name", type=str)
    parser.add_argument("-t", "--topic", type=str, choices=("algorithm", "concurrency", "shell"), default="algorithm")
    parser.add_argument("-l", "--language", type=str, choices=("c++", "python", "shell"), default="c++")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if args.topic == "shell":
        print("error: no bash template", file=stderr)
        return 1

    template = PROJECT_ROOT / "src" / "templates" / "default.cpp"
    dest = PROJECT_ROOT / "src" / args.topic / f"{args.name}.cpp"
    try:
        copyfile(template, dest)
    except (Error, OSError) as error:
        print("error:", error, file=stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
