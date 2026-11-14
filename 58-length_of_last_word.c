#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;
    while (i >= 0 && isspace(s[i])) {
        i--;
    } // deletes the whitespaces at the end.
    int end = i; // setting the end 

    while (i >= 0 && !isspace(s[i])) {
        i--;
    } // getting the idx of the start of the last word
    return end - i; // calculating length
}
// Test string: "   fly me   to   the moon  "
// Time to solve: 13min 11sec