//
//  AddTwoSum.c
//  leetcode
//
//  Created by 孟冰川 on 2019/7/14.
//  Copyright © 2019 孟冰川. All rights reserved.
//

#include "AddTwoSum.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *next = result;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        struct ListNode *current = malloc(sizeof(struct ListNode));
        int l1value = 0;
        int l2value = 0;
        if (l1 != NULL) {
            l1value = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2value = l2->val;
            l2 = l2->next;
        }
        int value = l1value + l2value + carry;
        carry = value/10;
        current->val = value%10;
        next->next = current;
        next = next->next;
    }
    if (carry > 0) {
        struct ListNode *tail = malloc(sizeof(struct ListNode));
        tail->val = carry;
        next->next = tail;
        tail->next = NULL;
    }else {
        next->next = NULL;
    }
    return result->next;
}

void testAddTwoNumbers() {
    struct ListNode *node1 = malloc(sizeof(struct ListNode));
    node1->val = 4;
    struct ListNode *node2 = malloc(sizeof(struct ListNode));
    node2->val = 5;
    struct ListNode *node0 = malloc(sizeof(struct ListNode));
    node0->val = 2;
    node0->next = node1;
    node1->next = node2;
    node2->next = NULL;
    
    struct ListNode *node3 = malloc(sizeof(struct ListNode));
    node3->val = 5;
    struct ListNode *node4 = malloc(sizeof(struct ListNode));
    node4->val = 6;
    struct ListNode *node5 = malloc(sizeof(struct ListNode));
    node5->val = 5;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    
    struct ListNode *l = addTwoNumbers(node2, node5);
    while (l != NULL) {
        printf("%d",l->val);
        l = l->next;
    }
    
}
