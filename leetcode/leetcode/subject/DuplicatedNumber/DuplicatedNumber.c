//
//  DuplicatedNumber.c
//  leetcode
//
//  Created by 孟冰川 on 2019/9/2.
//  Copyright © 2019 孟冰川. All rights reserved.
//

#include "DuplicatedNumber.h"

void change(int* nums,int i,int j) {
    int num = nums[i];
    nums[i] = nums[j];
    nums[j] = num;
}

//
bool duplicate(int* numbers, int length, int* duplication) {
    for(int i = 0;i<length;i++) {
        while (numbers[i] != i) {
            int numAtI = numbers[i];
            if (numbers[numAtI] == numAtI) {
                duplication[0] = numbers[i];
                return true;
            }else {
                change(numbers, i, numbers[i]);
            }
        }
    }
    return false;
}

void testDuplicate() {
    int nums[] = {2,1,3,0,4};
    int dups[1];
    if (duplicate(nums, 5, dups)) {
        printf("%d\n", dups[0]);
    }else {
        printf("no duplicate");
    }
    
}
