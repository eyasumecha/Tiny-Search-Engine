 /* 
 * designing the indexer module
 * 
 * Eyasu Lemma, Spring 2020, CS50
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "memory.h"
#include "hashtable.h"
#include "index.h"
#include "counters.h"

void namedelete(void *item){   //local function for freeeing counters
    if(item != NULL){
        counters_delete(item);
    }
}

int indexer(char *directory, char* indexFilename){
    char *file = (char*) calloc(100, sizeof(char));
    sprintf(file, "%s/.crawler", directory);
    FILE *f;
    if((f = fopen(file, "r")) == NULL){
        fprintf(stderr, "invalid directory\n");  //checks if directory exists and is valid
        return 1;
    }
    fclose(f);
    free(file);
    
    FILE *fp_o;
    hashtable_t *index = hashtable_new(500); //create the hashtable 
    
    if((fp_o = fopen(indexFilename, "w")) != NULL){
        index_build(directory, index);  //call index build to build the index hashtable
        index_save(fp_o, index);   //call index save to save the hashtable to file
    }
    else{
        fprintf(stderr, "error opening indexFilename\n");
        return 1;
    }
    fclose(fp_o);
    hashtable_delete(index, namedelete);  //delete the hastbale after finishing 
    return 0;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "invalid number of parameteres\n");  //validate number of parameters 
        return 1;
    }
    else{
        indexer(argv[1], argv[2]);
    }
    return 0;
}