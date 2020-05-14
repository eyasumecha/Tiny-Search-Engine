# design of indexer
my indexer is a hashtable structure. the key in the hashtable structure is 
the word in the html pages, and the item is a crawler. so each word has a crawler
and in the crawler the key value pair is file ID and count, which means we store 
a file ID that word is found in and then we store the number of times it occurs in
that file. 

so we read the first line from the files created by our crawler and then we create 
a webpage using that, and then we fetch the html page. Then we use the getNextword module
in webpage to find the word and store in it in hash together with the file ID its found in
and also count

and then we do that for every file in the directory created using our directory 