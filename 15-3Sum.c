#include <stdio.h>
#include <stdlib.h>
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

int compare_ints(const void* a, const void* b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare_ints);
    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    int capacity = 0;
    for(int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        } // if i is equal to previous, its a duplicate, skip
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (*returnSize == capacity) {
                    capacity = (capacity == 0) ? 4 : capacity * 2;
                    result = realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                } // while value is equal to previous, skip
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                } // while value is equal to next, skip 
            } else if (sum < 0) { // sum too small, incrementing left since were in a sorted array, and incrementing left means getting bigger numbers
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}
// Time to solve: 26min 55sec