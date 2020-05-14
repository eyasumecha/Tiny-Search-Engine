/* 
 * implementation of index.h
 * 
 * see index.h for more information
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "memory.h"
#include "hashtable.h"
#include "index.h"
#include "counters.h"
#include "word.h"
#include "webpage.h"

/* implementing index_build*/
void index_build(char* directory, hashtable_t *index){
    char *file = (char*) calloc(100, sizeof(char));   //allocate memory for the file name
    int id = 1;
    sprintf(file, "%s/%d", directory, id);          //concatentae id to file name to open
    char *word = (char*) calloc(100, sizeof(char));

    FILE *fp_i;
    while((fp_i = fopen(file, "r")) != NULL){    //while there is such a file by that name excute the while loop
        fscanf(fp_i, "%s", word);
        webpage_t *page = webpage_new(word, 0, NULL);       //read the first word and create webpage using that url word
        webpage_fetch(page);            //fetch the html
        int pos = 0;
        char *result;
        while((result = webpage_getNextWord(page, &pos)) != NULL){   //fetch the words from the html
            if(NormalizeWord(result) && (strlen(result) >= 3)){   //check factors and insert into hashtable
                counters_t *new = counters_new();
                if(!hashtable_insert(index, result, new)){
                    free(new);
                }
                new = hashtable_find(index, result);
                if(new != NULL){
                    counters_add(new, id);
                }  
            } 
            free(result);
        }
        webpage_delete(page);       //delete hashtable 
        id++;                       //increment id and allocate word to open new file
        fclose(fp_i);
        sprintf(file, "%s/%d", directory, id);
        word = (char*) calloc(100, sizeof(char));
    }
    free(word);   //free word and file pointers 
    free(file);
}

typedef struct node{  //local structure for node in counter
    int counter;           
    int key;          
    struct node *next;

}node_t;
typedef struct counters{
    struct node *head;  //head of the counter data structure 

}counters_t;

static void item_write(void *arg, const char *key, void *item){  //local function to write out the file from index
    FILE *fp_o = arg;
    counters_t *new = item;
    fprintf(fp_o, "%s", key);
    for(node_t *node = new->head; node != NULL; node = node->next){
        fprintf(fp_o, " %d %d", node->counter, node->key);
    }
    fprintf(fp_o, "\n");
}

/* implementing index_save*/
void index_save(FILE* fp, hashtable_t *index){
    hashtable_iterate(index, fp, item_write);
}

/*implementing index_load*/
void index_load(FILE *fp_o, hashtable_t *index){   //create the index hashtable from a file
    char *word = (char*) calloc(100, sizeof(char));
    int x, y;
    while(fscanf(fp_o, "%s", word) != EOF){     //read the word and create the counter for that word and 
        hashtable_insert(index, word, counters_new());      //insert in hashtable
        counters_t *new = hashtable_find(index, word);
        while(fscanf(fp_o, "%d %d", &x, &y) == 2){  //write out the ID and count
            counters_set(new, x, y);
        }
    }
    free(word);  //free word and file
    fclose(fp_o);
}




