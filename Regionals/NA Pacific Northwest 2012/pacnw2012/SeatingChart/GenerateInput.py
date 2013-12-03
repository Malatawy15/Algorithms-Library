#!/usr/bin/env python

import random
import string

random.seed(0)
trans = string.maketrans("0123456789", "abcdefghij")

for i in range(20):
    n = min(100000, 1 << i)
    print n
    names = [string.translate("%s" % j, trans) for j in range(n)]
    random.shuffle(names)
    print " ".join(names)
    random.shuffle(names)
    print " ".join(names)

n = 100000
print n
names = sorted([string.translate("%s" % j, trans) for j in range(n)])
print " ".join(names)
print " ".join(names)
print n
print " ".join(names)
print " ".join(reversed(names))
print 0
