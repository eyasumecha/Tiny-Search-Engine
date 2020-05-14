/* 
 * word.h - utility for normalizing words - converting all letters in a word to 
 * lower case
 * 
 * Eyasu Lemma, CS 50, May 2020
 *
 */

#ifndef __WORD_H
#define __WORD_H


#include <ctype.h>
#include <stdbool.h>

/*
    iterates throug each character in the string and 
    changes it to lowercase letter
*/
bool NormalizeWord(char* word);

#endif
