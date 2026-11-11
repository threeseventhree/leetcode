#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Impl 1
// int compareChars(const void* a, const void* b) {
//     return (*(char*) a - *(char*)b);
// }

// char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
//     bool visited[strsSize];
//     for (int i = 0; i < strsSize; i++) {
//         visited[i] = false;
//     }

//     int groupCount = 0;
//     char*** result = malloc(strsSize * sizeof(char**));
//     *returnColumnSizes = malloc(strsSize * sizeof(int));
    
//     for (int i = 0; i < strsSize; i++) {
//         if (visited[i]) { continue; }
        
//         result[groupCount] = malloc(strsSize * sizeof(char*));
//         int columnCount = 0;

//         char* a = strdup(strs[i]);
//         qsort(a, strlen(a), sizeof(char), compareChars);
//         for (int j = 0; j < strsSize; j++) {
//             if (visited[j] || strlen(strs[i]) != strlen(strs[j])) {
//                 continue;
//             }

//             char* b = strdup(strs[j]);
//             qsort(b, strlen(b), sizeof(char), compareChars);
//             if (strcmp(a, b) == 0) {
//                 result[groupCount][columnCount] = strs[j];
//                 columnCount++;
//                 visited[j] = true;

//             }
//             free(b);
//         }
//         free(a);
//         (*returnColumnSizes)[groupCount] = columnCount;
//         groupCount++;
//     }
//     *returnSize = groupCount;
//     return result;
// }


//Impl 2
// void check_frequency(char* str, int freq[26]) {
//     for(int i = 0; i < 26; i++) {
//         freq[i] = 0;
//     }

//     for(int i = 0; str[i] != '\0'; i++) {
//         int index = str[i] - 'a';
//         freq[index]++;
//     }
    
// }

// char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // int groupCount = 0;                                 
    // char*** result = malloc(strsSize * sizeof(char**)); 
    // *returnColumnSizes = malloc(strsSize * sizeof(int));

    // bool visited[strsSize];
    // for(int i = 0; i < strsSize; i++) { visited[i] = false; }
    
//     for(int i = 0; i < strsSize; i++) {
//         if (visited[i]) { continue; }

//         int freqA[26];
//         check_frequency(strs[i], freqA);

//         result[groupCount] = malloc(strsSize * sizeof(char*));
//         int columnCount = 0;

//         for(int j = 0; j < strsSize; j++) {
//             if (visited[j]) { continue; }

//             int freqB[26];
//             check_frequency(strs[j], freqB);

//             if (memcmp(freqA, freqB, sizeof(freqA)) == 0) {
//                 result[groupCount][columnCount] = strs[j];
//                 columnCount++;                            
//                 visited[j] = true;
//             }
//         }
//         (*returnColumnSizes)[groupCount] = columnCount;
//         groupCount++;
//     }
//     *returnSize = groupCount;
//     return result;
// }

//Iter 3
#define TABLE_SIZE 1009 // prime number
typedef struct Node {
    int key[26];
    int groupIndex;
    struct Node* next;
} Node; //defining the bucket for the hashmap

void check_frequency(char* str, int freq[26]) {
    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }
} // getting frequency sequence

bool compare_frequency(int a[26], int b[26]) {
    return memcmp(a, b, sizeof(int) * 26) == 0;
} // comparing the 2 frequencies 

unsigned long hash_frequency(int freq[26]) {
    unsigned long hash = 5381;

    for (int i = 0; i < 26; i++) {
        hash = hash * 33 + freq[i];
    }

    return hash;
} // getting hash for the frequency sequence

Node* find_group(Node* table[], int freq[26]) {
    unsigned long hash = hash_frequency(freq);
    int index = hash % TABLE_SIZE;

    Node* current = table[index];

    while (current != NULL) {
        if (compare_frequency(current->key, freq)) {
            return current;
        } // comparing the node frequency with the inputted frequency, if matched we return it

        current = current->next; // if frequencies didnt match, we add onto our bucket
    } // found a node at index

    return NULL; //no node found at said index
}

void insert_group(Node* table[], int freq[26], int groupIndex) {
    unsigned long hash = hash_frequency(freq);
    int index = hash % TABLE_SIZE;

    Node* newNode = malloc(sizeof(Node));

    memcpy(newNode->key, freq, sizeof(newNode->key));

    newNode->groupIndex = groupIndex;

    newNode->next = table[index];
    table[index] = newNode;
} // if there are no entries at said index, we add one

void free_table(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;

            current = current->next;

            free(temp);
        }
    }
} //freeing memory

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Node* table[TABLE_SIZE] = {NULL};

    char*** result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = calloc(strsSize, sizeof(int));
    int* capacities = malloc(strsSize * sizeof(int));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        int freq[26];
        check_frequency(strs[i], freq); // getting frequency for current string and appending that frequency to the freq 

        Node* found = find_group(table, freq);

        int groupIndex;
        if (found != NULL) {
            groupIndex = found->groupIndex;
        } // found a node, setting group index as that node's group index
        else {
            groupIndex = groupCount;

            result[groupIndex] = malloc(sizeof(char*));
            capacities[groupIndex] = 1;

            insert_group(table, freq, groupIndex);

            groupCount++;
        } // creating new group, if no node found

        if ((*returnColumnSizes)[groupIndex] == capacities[groupIndex]) {
            capacities[groupIndex] *= 2;

            result[groupIndex] = realloc(
                result[groupIndex],
                capacities[groupIndex] * sizeof(char*)
            );
        } // growing the ground

        int column = (*returnColumnSizes)[groupIndex];
        result[groupIndex][column] = strs[i];
        (*returnColumnSizes)[groupIndex]++;
    }
    *returnSize = groupCount;
    free(capacities);
    free_table(table);
    return result;
}


//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//Thought process: we have an array of arrays, each of these arrays contains grouped anagrams. 
//We need an algo for checking whether the word is an anagram. (can use the algo with quicksort and comparing)
//We can have an array and an i, anagrams[i], we then check a word for potential anagrams, if none found we just insert it into the array as is, if some found we create an inner array and include all those words.
//Things learned: qsort returns void and modifies the original string, compareChars must return int, can use strcmp instead of ==, freeing memory after using, 
// learning to use memcmp to compare 2 arrays of integers. Learned hashmaps.

//First implementation: testing successful, time limit exceeded... Scrap implemenetation 1.
//Second implementation: still time limit exceeded...
//Third implementation with hashmap worked!
//Time to solve: 58min