#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Time to solve: 3min