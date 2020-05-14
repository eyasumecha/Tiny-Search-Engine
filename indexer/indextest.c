 /* 
 * designing the index test module
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
#include "file.h"
#include "counters.h"

void namedelete(void *item){   //local function for deleting counters 
    if(item != NULL){
        counters_delete(item);
    }
}

int indextest(char *oldIndexFilename, char *newIndexFilename){
    FILE *fp_i;
    FILE *fp_o;
    hashtable_t *index;

    if((fp_i = fopen(oldIndexFilename, "r")) != NULL){
        int i = lines_in_file(fp_i);   //create the hashtable 
        index = hashtable_new(i);
        index_load(fp_i, index);   //call index load to create the hashtable from the file

    }
    else{
        fprintf(stderr, "error opening file\n");
        return 1;
    }
   

    if((fp_o = fopen(newIndexFilename, "w")) != NULL){
        index_save(fp_o, index);    //create the file from the hash
        fclose(fp_o);
    }
    else{
        fprintf(stderr, "error opening file\n");
        return 1;
    }

    hashtable_delete(index, namedelete);   //delete the hash in the end 
    return 0;
}
int main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "invalid number of parameteres\n");  //validate the parameters 
        return 1;
    }
    else{
        indextest(argv[1], argv[2]);
    }
    return 0;
}