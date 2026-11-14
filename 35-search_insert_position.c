#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    if (target > nums[numsSize - 1]) {
        return numsSize;
    }
    for (int i = 0; i < numsSize - 1; i++) {
        if ((nums[i] < target && target < nums[i+1])) {
            idx = i + 1;
        }
    }
    return idx;
}

// Time to solve: 5min 49sec