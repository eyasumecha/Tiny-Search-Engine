# Testing script for crawler.c
# Author: Eyasu Lemma
# Date: May 5, 2020
#
# usage: bash -v testing.sh

#defining variables 
seedURL1=http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
externalURL=www.google.com

##these tests should fail

# 1 argument
./crawler

#2 arguments
./crawler $seedURL1

#3 arguments 
./crawler $seedURL1 data1

#4 arguments + external URL
./crawler $externalURL data1 2

####these tests should pass

# at depth 0
./crawler $seedURL1 data1 0
diff -rq data1/ data2/letters-depth-0/

#at depth 3
rm -fv data1/*
./crawler $seedURL1 data1 3
diff -rq data1/ data2/letters-depth-3/
