#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char* stack = malloc(len * sizeof(char));
    int top = -1;
    for(int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        switch(c) {
            case '(':
            case '{':
            case '[':
                stack[++top] = c;
                break;
            default: 
                break;
        }
        switch(c) {
            case ')':
                if (top == -1) { return false; }
                if (stack[top] == '(') {
                    top--;
                } else {
                    return false;
                }
                break;
            case '}':
                if (top == -1) { return false; }
                if (stack[top] == '{') {
                    top--;
                } else {
                    return false;
                }
                break;
            case ']':
                if (top == -1) { return false; }
                if (stack[top] == '[') {
                    top--;
                } else {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    free(stack);
    return top == -1;
}
// Time to solve: 11min
// Learned how a stack works, how to push and pop to stack
// Used malloc and free properly.