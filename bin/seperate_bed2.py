#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import bb_basic as bb


def main():
    print_help()
    dict_files = {}
    dir_out = sys.argv[3].rstrip("/") + "/"
    # file open limited to 1024 in lunix, colse files when 800 files is read
    ss = 1
    for l in bb.fun_open_file(sys.argv[2], "r"):
        line = l.strip().split()
        dict_files[line[0]] = bb.fun_open_file(dir_out+line[0]+".bed2", "w")
        if ss%800 == 0:
            for l in bb.fun_open_file(sys.argv[1], "r"):
                line = l.strip().split()
                try:
                    dict_files[line[0]].write(l)
                except:
                    continue
            for key in dict_files:
                dict_files[key].close()
        ss+=1
    for l in bb.fun_open_file(sys.argv[1], "r"):
        line = l.strip().split()
        try:
            dict_files[line[0]].write(l)
        except:
            continue
    for key in dict_files:
        dict_files[key].close()


# --------functions--------
def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--version", action="version", version="%(prog)s 1.0")
    parser.add_argument("args", help="", nargs="*")
    args = parser.parse_args()
    return args


def print_help():
    if len(sys.argv) < 2:
        bb.fun_print_help("in.bed2", "in.feature.sizes", "out.dir")

# --------process--------
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        bb.fun_print_error("user interrupted, abort!")
        sys.exit(0)
