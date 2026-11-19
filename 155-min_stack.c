#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int* minStack;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack *s = malloc(sizeof(MinStack));
    s->capacity = 30000;
    s->top = -1;

    s->data = malloc(s->capacity * sizeof(int));
    s->minStack = malloc(s->capacity * sizeof(int));
    return s;
}

void minStackPush(MinStack* s, int value) {
    s->data[++(s->top)] = value;

    if (s->top == 0 || value <= s->minStack[s->top - 1]) {
        s->minStack[s->top] = value;
    } else {
        s->minStack[s->top] = s->minStack[s->top - 1];
    }
}

void minStackPop(MinStack* s) {
    s->top--;
}

int minStackTop(MinStack* s) {
    return s->data[s->top];
}

int minStackGetMin(MinStack* s) {
    return s->minStack[s->top];
}

void minStackFree(MinStack* s) {
    free(s->data);
    free(s->minStack);
    free(s);
}
// Time to solve: 6min 48sec