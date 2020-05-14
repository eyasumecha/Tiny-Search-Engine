/* 
 * implementation of pagedir.h
 * 
 * see pagedir.h for more information
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pagedir.h"
#include "memory.h"
#include "webpage.h"
#include "hashtable.h"
#include "bag.h"

/* implementing pagefetcher*/
/* see pagedir.h for more information*/
bool pagefetcher(webpage_t *page){
    return webpage_fetch(page);
}

/*implementing pagescanner*/
/*see pagedir.h for more information*/
int pagescanner(webpage_t *page, bag_t *bag, hashtable_t *hash){
    int pos = 0;
    char *url;
    while((url = webpage_getNextURL(page, &pos)) != NULL){
        if(NormalizeURL(url) && IsInternalURL(url)){
            if(hashtable_insert(hash, url, "")){
                webpage_t *new = webpage_new(url, webpage_getDepth(page) + 1, NULL);
                if(new == NULL){
                    fprintf(stderr, "error in creating new page\n");

                    return 1;
                }
                bag_insert(bag, new);
            }   
        }
    }
    return 0;
}

/*implementing pagesaver*/
/*see pagedir.h for more information*/
int pagesaver(webpage_t *page, char *directory, int *arg){
    char *file = (char*) calloc(100, sizeof(char));
    if(directory[strlen(directory) - 1] == '/'){
        sprintf(file, "%s%d", directory, *arg);
    
        
    }
    else{
        sprintf(file, "%s/%d", directory, *arg);
        
    }
    printf("%s\n", file);
    FILE *fp_o = fopen(file, "w");
    if(fp_o == NULL){
        fprintf(stderr, "error opening file\n");
        return 1;
    }
    fprintf(fp_o, webpage_getURL(page));
    fprintf(fp_o, "\n");
    fprintf(fp_o, "%d", webpage_getDepth(page));
    fprintf(fp_o, "\n");
    fprintf(fp_o, webpage_getHTML(page));
    fclose(fp_o);
    free(file);
    return 0;
}
