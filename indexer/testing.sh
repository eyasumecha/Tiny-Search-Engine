# Testing script for indexer.c and indextest.c
# Author: Eyasu Lemma
# Date: May 13, 2020
#
# usage: bash -v testing.sh

##these tests should fail

# 1 argument
./indexer

# 2 argument
./indexer ../common/data

# 3 argument
./indexer ../common/data1

# 4 argument
./indextest file

# 5 argument
./indextest file file1


####these tests should pass

# 1 argument
./indexer ../crawler/data1 savefile 

# 2 argument
./indextest savefile testfile 

# 3 argument
gawk -f indexsort.awk savefile > savefile.sorted
gawk -f indexsort.awk testfile > testfile.sorted
diff savefile.sorted testfile.sorted



