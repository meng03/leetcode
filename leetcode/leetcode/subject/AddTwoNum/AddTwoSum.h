//
//  AddTwoSum.h
//  leetcode
//
//  Created by 孟冰川 on 2019/7/14.
//  Copyright © 2019 孟冰川. All rights reserved.
//

#ifndef AddTwoSum_h
#define AddTwoSum_h

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void testAddTwoNumbers();

#endif /* AddTwoSum_h */
