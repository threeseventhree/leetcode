#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = malloc(200 * sizeof(char));
    int k = 0;
    for (int i = 0; strs[0][i] != '\0'; i++) { //used for character
        for (int j = 1; j < strsSize; j++) { //used for string
            if (strs[j][i] == '\0' || strs[j][i] != strs[0][i]) { //if end of string or the characters dont match we close the prefix string and return
                prefix[k] = '\0';
                return prefix;
            }
        }
        prefix[k] = strs[0][i]; //if we didnt return, we append the letter to the prefix
        k++;
    }
    prefix[k] = '\0'; //we end the string and return it
    return prefix;
}
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Time to solve 17min

//Difficulties encountered: figuring out the logic of appending characters to the prefix, figuring out how to properly allocate the prefix, figuring out how to iterate through the prefix.