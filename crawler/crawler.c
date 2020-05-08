/* 
 * designing the crawler module
 *
 * Eyasu Lemma, Spring 2020, CS50
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pagedir.h"
#include "memory.h"
#include "webpage.h"
#include "hashtable.h"
#include "bag.h"

typedef struct webpage {
  char *url;                               // url of the page
  char *html;                              // html code of the page
  size_t html_len;                         // length of html code
  int depth;                               // depth of crawl
} webpage_t;

int crawler(char *url, char *directory, int maxDepth){   //module to crawl the webpages 
    bag_t *bag = bag_new();   // assign bag for the webpage
    hashtable_t *hash = hashtable_new(12);   //assign hash of size 12 for the urls
    bag_t *bag2 = bag_new();    //assign another bag to add the extracted bags to and delete later
    int count = 1;   //file ID
    webpage_t *new;
    

    if(NormalizeURL(url) && IsInternalURL(url)  && directory != NULL && maxDepth >= 0){
        new = webpage_new(url, 0, NULL);   //create the inital webpage for the url
        if(new == NULL){
            fprintf(stderr, "error in creating new page\n");
            return 1;
        }
    }
    bag_insert(bag, new);           // add to bag and hashtable the url
    hashtable_insert(hash, url, "");

    webpage_t *extracted = count_malloc(sizeof(webpage_t));
    while((extracted = bag_extract(bag)) != NULL){      //while bag is non empty, extract 
        if(pagefetcher(extracted)){                     
            pagesaver(extracted, directory, &count);       //save the page
            count++;
            if(webpage_getDepth(extracted) < maxDepth){
                pagescanner(extracted, bag, hash);  //extract other webpages 
            }
            bag_insert(bag2, extracted);        //insert extracted to bag to later delete

        }
    }
    bag_delete(bag, NULL);          //free the bag, hash, and bag2 and webpages included 
    hashtable_delete(hash, NULL);
    bag_delete(bag2, webpage_delete);
    return 0;
    
}

int main( int argc, char *argv[]){
    if(argc != 4){
        fprintf(stderr, "invalid number of paramteres\n");   //make arguments valid and call crawler accordingly. 
        return 1;
    }
    else{
        crawler(argv[1], argv[2], atoi(argv[3]));
    }
}
