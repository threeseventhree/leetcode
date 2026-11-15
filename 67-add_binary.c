#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    int maxLength = (len_a > len_b) ? len_a : len_b;
    char* result = malloc((maxLength + 2) * sizeof(char)); // 1 for carry 1 for \0;

    int carry = 0;
    int i = len_a - 1;
    int j = len_b - 1;
    int k = maxLength;
    result[maxLength + 1] = '\0'; // setting last char of array to \0 for proper string
    while( i >= 0 || j >= 0 || carry ) {
        int c_a = (i >= 0) ? a[i] - '0' : 0; // converting char to int
        int c_b = (j >= 0) ? b[j] - '0' : 0; // converting char to int
        int sum = c_a + c_b + carry;
        char bit = (sum % 2) + '0';
        carry = sum / 2;
        result[k--] = bit;
        i--;
        j--;
    }
    if (k >= 0) {
        memmove(result, result + k + 1, maxLength - k + 1);
    }
    return result;
}
// Time to solve: 12min 12sec