#include <stdio.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}
//Had a timeout error with original implementation (with k = 0 and counting)
//Implementation without k still gave a timeout error
//Third implementation and final is sorting, complexity dropped from n^2 to n.

//qsort: void qsort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *))
//Time to solve: 10min 20sec
//Difficulties: getting it to run without a timeout error... i should be mindful about the amount of resources i use
