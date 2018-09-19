#! /usr/bin/env python
# -*- coding: utf-8 -*-

##########modules#############

import os
import sys

##############################
#####print message by format##
##############################
def fun_invert_dnaseq(seq):
    """invert DNA sequence to complementary sequence"""
    d = {"A":"T","T":"A","C":"G","G":"C","a":"t","t":"a","c":"g","g":"c"}
    cseq = ""
    #for i in range(len(seq)-1,-1,-1):
    for i in range(len(seq)):
        try:
            cseq += d[seq[i]]
        except KeyError:
            cseq += seq[i]
    return cseq[::-1]


def fun_print_help(*args):
    """print a simple help information. eg: fun_print_help("a.bed", "b.bed")"""
    fun_print("usage:", "green", "none", 1)
    str_args = " ".join(args)
    fun_print("{0} {1}".format(sys.argv[0], str_args), "green", "black", 1)
    sys.exit(0)

def fun_print_error(error):
    """print a error use specific style"""
    sys.stderr.write("\033[1;31m{0}\033[0m\n".format(error))
    sys.exit(0)

def fun_print(content, col="white", bg="none", font=0):
    """
    print a string to stdout use specific style.
    usage:
    fun_print(content, col="white|black...", bg="black|white...", font=0|1|2|3|4)
    eg. fun_print("hello", "red", "white", 1)
    """
    dict_col = {"white":37, "black":30, "red":31, "green":32,
            "brown":33, "blue":34, "purple":35, "cyan":36}
    dict_bg = {"black":40, "red":41, "green":42, "brown":43,
            "blue":44, "purple":45, "cyan":46, "white":47, "none": ""}
    dict_font = {0:"", 1:1, 2:2, 3:4, 4:5}
    try:
        col_style = dict_col[col]
        bg_style = dict_bg[bg]
    except KeyError:
        fun_print_error("can not find color: {0}".format(col))
    try:
        font_style = dict_font[font]
    except KeyError:
        fun_print_error("can not find font: {0}.\nfont\t0: no; 1: thick; 2: halflight; 3: underline; 4: blink".format(font))
    print("\033[{0};{1};{2}m{3}\033[0m".format(font_style,col_style,bg_style,content))

####################################
#####basic file read or write#######
####################################

def fun_open_file(path, action="r"):
    """
    open a file
    usage: fun_open_file(path, action="r|w")
    """
    try:
        file_in = open(path, action)
        return file_in
    except IOError:
        fun_print_error("No file in {0}".format(path))

def fun_read(path, format="tab", type="list", key_number=1, sep="\t"):
    """
    read file into list or dict.
    usage:
    fun_read(path, format="tab|bed|chrom_size", type="list/l|dict/d", key_number=1|[0-9]+,
        sep="\\t|...")
    eg. fun_read("mouse_gene.bed", "bed", "list")
    eg. fun_read("mouse_gene.bed", "bed", "dict", 4)
    eg. fun_read("mouse.chrom_size", "chrom_size", "dict")
    eg. fun_read("gene_exp.tab")
    eg. fun_read("gene_exp.tab", "tab", "dict", 2, ":")
    """
    file_in = fun_open_file(path)
    if type == "list" or type == "l":
        out = []
        for l in file_in:
            line = l.strip("\n").split(sep)
            if format ==  "tab":
                pass
            elif format ==  "bed":
                line[1:3] = map(int, line[1:3])
            elif format ==  "chrom_size":
                line[1] = int(line[1])
            else:
                fun_print_error("wrong format: {0}. only support tab, \
                        bed and chrom_size".format(format))
            out.append(line)
    elif type == "dict" or type == "d":
        out = {}
        for l in file_in:
            line = l.strip("\n").split(sep)
            if format ==  "tab":
                pass
            elif format ==  "bed":
                line[1:3] = map(int, line[1:3])
            elif format ==  "chrom_size":
                line[1] = int(line[1])
            else:
                fun_print_error("wrong format: {0}. only support tab, \
                        bed and chrom_size".format(format))
            try:
                key = line[key_number-1]
            except IndexError:
                fun_print_error("the column number is less than {0}, \
                        key_number error".format(key_number))
            value = line[0:key_number-1] + line[key_number:]
            try:
                out[key].append(value)
            except KeyError:
                out[key] = [value]
    else:
        fun_print_error("wrong type: {0}. only support list/l and dict/d".format(type))
    return out

def fun_write_list(list_out, path=""):
    """
    write list into stdout or a file, only works for 1 or 2 dimensional list
    usage:
    fun_write_list(list_out, path="|...")
    eg. fun_write_list(list_out, "mouse_gene.list")
    eg. fun_write_list(list_out)
    """
    if not path:
        for i in list_out:
            if isinstance(i, list):
                for j in range(len(i)-1):
                    sys.stdout.write("{0}\t".format(i[j]))
                sys.stdout.write("{0}\n".format(i[-1]))
            else:
                sys.stdout.write("{0}\n".format(i))
    else:
        file_out = fun_open_file(path, "w")
        for i in list_out:
            if isinstance(i, list):
                for j in range(len(i)-1):
                    file_out.write("{0}\t".format(i[j]))
                file_out.write("{0}\n".format(i[-1]))
            else:
                file_out.write("{0}\n".format(i))
        file_out.close()

def fun_quick_write(content, path):
    """quick write a string into a file"""
    file_out = fun_open_file(path, "w")
    if not isinstance(content, str):
        fun_print_error("input must be string")
    file_out.write(content)
    file_out.close()

