#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    while (left < right) {
        int dist = right - left;
        int h = (height[left] > height[right]) ? height[right] : height[left];
        int area = dist * h;
        if(area > max_area) max_area = area;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_area;
}

// Time to solve: 12min 57sec