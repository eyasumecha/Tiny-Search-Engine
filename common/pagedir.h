/* 
 * webpage - utility for downloading, saving, and loading web pages
 * 
 * Eyasu Lemma, CS 50, May 2020
 *
 */

#ifndef __PAGEDIR_H
#define __PAGEDIR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "memory.h"
#include "webpage.h"
#include "hashtable.h"
#include "bag.h"


/* 
 * retrieves a webpage from the url given and 
 * and stores it into the page->html
 * and if successful it returns true, false if else
 */
bool pagefetcher(webpage_t *page);

/* 
 * extract a webpage (URL,depth) item from the bag of webpages to be crawled
 * pause fro a second, normalize and check if url is internal
 * then try to add the url to hashtable given, if success make a new webpage
 * from the url and add to bag
 */

int pagescanner(webpage_t *page, bag_t *bag, hashtable_t *hash);

/* 
 * given the html, directory, and id, it writes out the html to the right directory 
 * according to the id given
 */
int pagesaver(webpage_t *page, char *directory, int *arg);

#endif // __PAGEDIR_H
