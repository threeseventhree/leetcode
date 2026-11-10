#include <stdio.h>

int romanToInt(char* s) {
    int number = 0;
    int current = 0;
    int next = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case 'I': current = 1; break;
            case 'V': current = 5; break;
            case 'X': current = 10; break;
            case 'L': current = 50; break;
            case 'C': current = 100; break;
            case 'D': current = 500; break;
            case 'M': current = 1000; break;
        }
        switch(s[i + 1]) {
            case 'I': next = 1; break;
            case 'V': next = 5; break;
            case 'X': next = 10; break;
            case 'L': next = 50; break;
            case 'C': next = 100; break;
            case 'D': next = 500; break;
            case 'M': next = 1000; break;
        }
        if (current < next) {
            number -= current;
        } else {
            number += current;
        }
    }    
    return number;
}

// Input: s = "III"
// Output: 3
// Input: s = "LVIII"
// Output: 58
// Input: s = "MCMXCIV"
// Output: 1994
// Time to solve: 13min 15sec