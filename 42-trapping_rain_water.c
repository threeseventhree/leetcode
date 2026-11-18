#include <stdio.h>

int min_int(int a, int b) {
    if (a < b) return a;
    if (a > b) return b;
    return a; 
}

int trap(int* height, int heightSize) {
    int leftMax[heightSize];
    leftMax[0] = height[0]; //setting first index to first index of height
    int rightMax[heightSize];
    rightMax[heightSize - 1] = height[heightSize - 1]; //setting last index to last index of height
    int water = 0;
    for (int i = 1; i < heightSize; i++) { //starting index 1 cause we filled 0
        leftMax[i] = (height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1];
    } // filling leftmax, if the height is greater than the value to the left of it, we append height, else the element to the left

    for (int i = heightSize - 2; i >= 0; i--) { //starting index heightSize - 2 cause we filled heightSize - 1
        rightMax[i] = (height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1];
    } // filling rightmax, if the height is greater than the value to the right of it, we append height, else the element to the right
    for(int i = 0; i < heightSize; i++) {
        water += min_int(leftMax[i], rightMax[i]) - height[i];
    }
    return water;
}

// Time to solve: 9min 9sec