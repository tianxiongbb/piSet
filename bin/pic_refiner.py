#!/usr/bin/env python

# Author: Yu Fu
# Refine boundaries of piRNA clusters
# Note that there are two ways to calculate the piRNA RPM for a given window:
# mean and mean0. Here mean seems to be a better way... becuase for repetitive
# regions, mean0 for unique reads are usually very very low
import sys

import pyBigWig

class ChromInfo:
    def __init__(self, l):
        '''It reads in a dict of chromsome:chromesome_length pairs
'''
        self.length = {}
        for i in l:
            self.length[i] = int(l[i])


def mean0(chrom, start, end, bw):
    '''The stat mean in pyBigWig only uses regions with signals to calculate means.
It is sometimes useful to calculate means for all bases in a region, assuming
those non-covered bases having signals of 1.'''
    # Note that bw.stats returns lists, not floats. If there is nothing in the range
    # it will report [None,]
    # print "**in mean0: %s\t%d\t%d" % (chrom, start, end)
    cov = bw.stats(chrom, start, end, type="cov")[0]
    # This is the mean without consider the non-covered bases
    mean = bw.stats(chrom, start, end)[0]
    if mean is None:
        mean = 0
    if cov is None:
        cov = 0
        
    mean0 = mean * cov
    return mean0
            
            
class Interval:
    def __init__(self, chrom, start, end, name, signal, strand):
        self.chrom = chrom
        self.start = int(start)
        self.end = int(end)
        self.name = name
        self.signal = signal
        self.strand = strand
        self.start_refined = self.start
        self.start_is_refined = False
        self.end_refined = self.end
        self.end_is_refined = False
        self.total = 0.0
        self.comments = []

    def __str__(self):
        ret1 = "Original: %s:%d-%d(%s)" % (self.chrom, self.start,
                                           self.end, self.strand)
        ret2 = "Refined:  %s:%d-%d(%s)" % (self.chrom, self.start_refined,
                                           self.end_refined, self.strand)
        return ret1 + "\n" + ret2
        
    def refine(self, bw, dist=5000, cutoff=1):
        '''it uses overlapping 5kb windows around the boundaries to find
the point where the windowed RPM is lower than cutoff (default is 1)'''
        win_size = 5000
        # Potentially a bug with bigWig files or pyBigWig:
        # when the contig has no signal at all, it is not stored in the
        # header of bigWig files at all!
        ci = bw.chroms()
        if self.chrom not in ci:
            print "%s(%s) does not have any signals in the bigWig file.\
Skipping!" % (self.chrom, self.strand)
            self.total = 0
            self.comments.append("__ctg_not_found_in_bigwig")
            return
        chrom_len = ci[self.chrom]
        print "Current chromosome length: %d" % chrom_len

        print "Putative piC before refining: " + str(self)
        # Use a sliding window of 5kb around the start coordinate
        # Do not worry about crossing the chrom boundaries as the windows
        # are guaranteed >= 5k, even though it should be able to handle that

        m0 = mean0(self.chrom, self.start, self.end, bw)
        m = bw.stats(self.chrom, self.start, self.end)[0]
        if m is None:
            m = 0
        print "Mean0 of the entire putative piC: %f" % m0
        print "Mean of the entire putative piC: %f" % m
        
        # Use a sliding window of 5kb around the start coordiate 
        search_start = self.start - dist
        if search_start < int(win_size/2):
            print "**Left chromosome boundary encountered. Limiting the search space"
            search_start = int(win_size/2)
        search_end = self.start + dist
        if search_end > chrom_len - int(win_size/2):
            print "**Right chromosome boundary encountered. Limiting the search space"
            search_end = chrom_len - int(win_size/2)
        print "** Refining the start position. Search space of win midpoint: \n\
%s:%d-%d" % (self.chrom, search_start, search_end)
        for i in reversed(range(search_start, search_end)):
            ## print "Current: ",
            ## print self.chrom, i - int(win_size/2), i + int(win_size/2)
            ## print "Midpoint: " + str(i)            
            # avg = mean0(self.chrom, i - int(win_size/2), i + int(win_size/2), bw)
            avg = bw.stats(self.chrom, i - int(win_size/2), i + int(win_size/2))[0]
            if avg is None:
                avg = 0
            if abs(avg) >= cutoff:
                self.start_refined = i - int(win_size / 2)
                self.start_is_refined = True
                ## print self.start_refined
                ## print "** %s:%d-%d passes the cutoff: avg %f" % \
                ## (self.chrom, i, i+dist, avg)
                ## print "*" * 72
        print "Putative piC after refining the start point:"
        print str(self)
        if not self.start_is_refined:
            self.comments.append("__start_not_refined")
        ########################################################################
        # Use a sliding window of 5kb around the end coordiate
        search_start = self.end - dist
        if search_start < int(win_size/2):
            print "**Left chromosome boundary encountered. Limiting the search space"
            search_start = win_size / 2
        search_end = self.end + dist
        if search_end > chrom_len - int(win_size/2):
            print "**Right chromosome boundary encountered. Limiting the search space"
            search_end = chrom_len - int(win_size/2)
        print "** Refining the end position. Search space of win midpoint:: \
        %s:%d-%d" % (self.chrom, search_start, search_end)
            
        for i in range(search_start, search_end):
            # avg = mean0(self.chrom, i - int(win_size/2), i + int(win_size/2), bw)
            avg = bw.stats(self.chrom, i - int(win_size/2), i + int(win_size/2))[0]
            # print "Current: ",
            # print self.chrom, i - int(win_size/2), i + int(win_size/2)
            # print "Midpoint: " + str(i)
            # print avg
            if avg is None:
                avg = 0
            if abs(avg) >= cutoff:
                self.end_refined = i + int(win_size/2)
                self.end_is_refined = True
                # print self.end_refined
                # print "**%s:%d-%d passes the cutoff: avg %f" % \
                #     (self.chrom, i, i+dist, avg)
        print "Putative piC after refining the end point:"
        print str(self)
        if not self.end_is_refined:
            self.comments.append("__end_not_refined")
        self.total = bw.stats(self.chrom,
                              self.start_refined, self.end_refined)[0]
        
        print "*" * 72
        print 
        ########################################################################


DEBUG = False

if __name__ == "__main__":
    fn_cand = sys.argv[1]
    fn_watson = sys.argv[2]
    fn_crick = sys.argv[3]
    fn_output = sys.argv[4]

    cand = []
    with open(fn_cand) as fh:
        for line in fh:
            col = line.strip().split()
            # Only store the chromosome, start, end and strand
            interv = Interval(col[0], col[1], col[2], col[3], col[4], col[5])
            cand.append(interv)


    ## Need to know the chromosome boundaries                                  
    ## bw_watson = pyBigWig.open("Zamore.SRA.Aaeg.ovary.ox.x_rRNA.x_hairpin.aaegL3v0.all.piRNA.sorted.uniq.Watson.bigWig")
    bw_watson = pyBigWig.open(fn_watson)
    bw_crick = pyBigWig.open(fn_crick)

    # print bw.chroms('supercont1.4171')
    # print bw.header()

    # ctg = "supercont1.1"
    # start = 9180
    # end = 9181
    # print bw.stats(ctg, start, end, exact=True)

    for interv in cand:
        if interv.strand == "+":
            interv.refine(bw_watson, dist=10000, cutoff=1)
        else:
            interv.refine(bw_crick, dist=10000, cutoff=1)

    with open(fn_output, "w") as out:
        for interv in cand:
            print interv
            print >>out, "\t".join([interv.chrom,
                                    str(interv.start_refined),
                                    str(interv.end_refined), ".",
                                    str(interv.total), interv.strand,
                                    ",".join(interv.comments)])
