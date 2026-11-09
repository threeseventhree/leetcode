#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int start = 0;
    int maxLength = 0;
    for (int end = 0; s[end] != '\0'; end++) {
        for (int i = start; i < end; i ++) {
            if(s[end] == s[i]) {
                start = i + 1;
                break;
            }
        }

        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    return maxLength;
}
// Input: s = "abcabcbb"
// Output: 3
//Time to solve: 7min 30sec