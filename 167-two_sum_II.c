#include <stdio.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    int left = 0;
    int right = numbersSize - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if(sum == target) {
            *returnSize = 2;
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        }
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;
    return result;
}
// Time to solve: 3min 40sec