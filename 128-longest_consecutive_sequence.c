#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* values;
    bool* occupied;
    int size;
    int count;
} HashSet;

HashSet* set_new(int size) {
    HashSet* s = malloc(sizeof(HashSet));
    s->size = size;
    s->count = 0;
    s->values = malloc(s->size * sizeof(int));
    s->occupied = calloc(s->size, sizeof(bool)); // initialize
    return s;
}

unsigned int hash(int key) {
    unsigned int h = 5381;
    h = h * 33 + key;
    return h;
}

void insert(HashSet* set, int key) {
    int idx = hash(key) % set->size;
    while (set->occupied[idx]) {
        if (set->values[idx] == key) {
            return;
        }
        idx = (idx + 1) % set->size;
    }
    set->values[idx] = key;
    set->occupied[idx] = true;
    set->count++;
}

bool contains(HashSet* set, int key) {
    int idx = hash(key) % set->size;
    while (set->occupied[idx]) {
        if (set->values[idx] == key) {
            return true;
        }
        idx = (idx + 1) % set->size;
    }
    return false;
}

void free_hash_set(HashSet* set) {
    if (set == NULL) return;

    free(set->values);
    free(set->occupied);
    free(set);
}

int longestConsecutive(int* nums, int numsSize) {
    HashSet* s = set_new(numsSize * 2 + 1);
    for (int i = 0; i < numsSize; i++) {
        insert(s, nums[i]);
    } // populating set
    int longest = 0;
    for (int i = 0; i < s->size; i++) {
        if (!s->occupied[i]) continue;

        int num = s->values[i];
        if (contains(s, num - 1)) continue;

        int current = num;
        int length = 1;

        while (contains(s, current + 1)) {
            current++;
            length++;
        }
        if (length > longest) {
            longest = length;
        }
    }
    free_hash_set(s);
    return longest;
}

// Time to solve: 28min 31sec
// Difficulties: Learning and implementing a hashset.