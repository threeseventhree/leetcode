#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
*/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = malloc(numsSize * sizeof(int));
    int prefix = 1;
    int suffix = 1;
    for(int i = 0; i < numsSize; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }
    for(int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    *returnSize = numsSize;
    return answer;
}

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// You must write an algorithm that runs in O(n) time and without using the division operation.
// First for: answer[0] = 1 prefix = 1; answer[1] = 1 prefix = 2, answer[2] = 2 prefix = 6, answer[3] = 6 prefix = 24;
// Second for: answer[3] = 24 suffix = 4; answer[2] = 8 suffix = 12; answer[1] = 12 suffix = 24; answer[0] = 24, suffix = 24;

// Thought: n[0] => 2*3*4, n[1] => 1*3*4, n[2] => 1*2*4, n[3] => 1*2*3
// Can't just make product and divide by n[0]
// Need to utilize prefix and suffix, quicksort works on prefix and suffix, check quicksort algorithm
// Prefix is 0 to i-1, suffix is i+1 to numsSize
// Can only think of using forloops for prefix (j = 0; j < i; j++) and suffix (j = i+1; j < numsSize; j++), that would give me higher complexity... Need O(n)
// Time to solve: 12min 40sec