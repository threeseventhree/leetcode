#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    qsort(s, strlen(s), sizeof(char), compareChars); 
    qsort(t, strlen(t), sizeof(char), compareChars);

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] != t[i]) {
            return false;
        }
    }
    return true;
}  

//Difficulties: What is an anagram??? Also didnt pass testcase where 1 string shorter than the other...
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
//Thought process: since we know both strings have the same letters, we could sort the letters and check if all match, if they dont match then just return false and exit... Can use qsort and compare???
//Things learned: *(char*)a is used to dereference and typecast.
//Time to solve: 7min 38sec