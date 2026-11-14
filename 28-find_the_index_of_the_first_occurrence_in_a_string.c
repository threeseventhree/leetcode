#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int length = strlen(needle);
    for (int i = 0; haystack[i] != '\0'; i++) {
        int k = 0;
        while (k < length && haystack[i + k] == needle[k]) {
            k++;
        } //i0k0 s==s k1, i0k1 a==a k2, i0k2 d==d k3, i0k3 b!=? breakloop compare, return.
        if (k == length) {
            return i;
        }
    }
    return -1;
}

//Time to solve: 10min 56sec