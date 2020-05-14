/* 
 * utility for loading and saving index files
 * 
 * Eyasu Lemma, CS 50, May 2020
 *
 */

#ifndef __INDEX_H
#define __INDEX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "memory.h"
#include "hashtable.h"
#include "counters.h"
#include "word.h"
#include "webpage.h"

/*
    given a directory of html files, it creates a data structure that
    maps the words in the html to file ID and count of occurance in that
    file
*/

void index_build(char* directory, hashtable_t *index);

/*
    given an index structure, it writes out the the index structure 
    into a file with one word per line with file ID and count
*/

void index_save(FILE* fp, hashtable_t *index);

/*
    given an index filename it creates the index hashtable data structure 
*/
void index_load(FILE *fp_o, hashtable_t *index);


#endif