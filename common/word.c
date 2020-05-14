/* 
 * implementation of  word.h
 * 
 * see word.h for more information
 */

# include <ctype.h>
# include <stdbool.h>
# include "word.h" 

bool NormalizeWord(char* word){
    for (int i = 0; word[i]; i++){  //read each string and make them lowercase
        word[i] = tolower(word[i]);
    }
    return true; 
} 