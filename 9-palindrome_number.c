#include <stdio.h>

bool isPalindrome(int x) {
    char str[12];
    snprintf(str, sizeof(str), "%d", x);

    int left = 0;
    int right = strlen(str) - 1;
    while(left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

//Input: x = 121
//Output: true
//Time to solve: 6min