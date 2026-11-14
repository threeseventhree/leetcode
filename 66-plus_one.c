#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* arr = malloc((digitsSize + 1) * sizeof(int)); // allocating additional digit in case all digits are 9.
    for (int i = 0; i < digitsSize; i++) {
        arr[i] = digits[i];
    } // populating array

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (arr[i] < 9) {
            arr[i]++;
            *returnSize = digitsSize;
            return arr;
        } // if nr is smaller than 9 we just increment it and break the loop, returning instantly.
        arr[i] = 0;
    }
    // case where all elements were 9
    arr[0] = 1;
    arr[digitsSize] = 0;

    *returnSize = digitsSize + 1;
    return arr;
}

// Time to solve: 9min 55sec
// Very complicated and confusing...