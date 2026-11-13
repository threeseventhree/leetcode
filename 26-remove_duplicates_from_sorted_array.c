#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    for(int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

//Array sorted, first number remains the same. We rewrite the array if the nr isnt duplicate
//Time to solve: 9min 1sec