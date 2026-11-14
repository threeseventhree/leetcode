#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
*/
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int freq[20001] = {0};
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    int **buckets = calloc(numsSize + 1, sizeof(int*)); // suppose the array contains all distinct numbers, then we need to allocate bucket for each number, calloc initializes.
    int *bucketSizes = calloc(numsSize + 1, sizeof(int)); // if we had, for instance 1 1 1, 2 2 2, the bucket size would grow
    for(int i = 0; i < 20001; i++) {
        int f = freq[i];
        int num = i - 10000;
        if (f == 0) { continue; }
        
        buckets[f] = realloc(
            buckets[f],
            (bucketSizes[f] + 1) * sizeof(int)
        ); //reallocating memory as needed

        buckets[f][bucketSizes[f]] = num;
        bucketSizes[f]++;
    }

    int *result = malloc(k * sizeof(int));
    int count = 0;
    for (int i = numsSize; i >= 1 && count < k; i--) {
        for (int j = 0; j < bucketSizes[i] && count < k; j++) {
            result[count++] = buckets[i][j];
        }
    } // iterating buckets, the higher the indice, the higher the frequency.
    for (int i = 0; i <= numsSize; i++) {
        free(buckets[i]);
    } //freeing bucket memory after usage, result already stored.
    free(buckets);
    free(bucketSizes);

    *returnSize = count;
    return result;
}
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//Time to solve: 35min 45sec