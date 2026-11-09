#include <stdio.h>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode dummy;
    struct ListNode *current = &dummy;
    dummy.next = NULL;

    while( l1 != NULL || l2 != NULL || carry != 0 ) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    return dummy.next;
}
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [7,0,8]
//iteration 1: val1=2 val2=5 sum=7 carry=0 digit=7, creating a node with val7 current becomes 7 null
//iteration 2: va1=4 val2=6 sum=10 carry=1 digit=0, node: val0, current: 0, 7
//iteration 3: val1=3 val2=4 sum=7+carry=8 digit=8, node: val8, current 8, 0
//Time to solve: 13min