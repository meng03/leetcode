//
//  LongestSubString.c
//  leetcode
//
//  Created by 孟冰川 on 2019/7/23.
//  Copyright © 2019 孟冰川. All rights reserved.
//

#include "LongestSubString.h"

//返回重复的位置
char * repeated(char * start,char * end,char value) {
    while (start <= end) {
        if (value == *start) {
            return start;
        }
        start++;
    }
    return NULL;
}

int lengthOfLongestSubstring(char * s){
    if(*s == '\0') {
        return 0;
    }
    char *start = s;
    char *end = s + 1;
    int maxSubStrCount = 0;
    while (*end != '\0') {
        char * position = repeated(start, end - 1 , *end);
        if (position != NULL) {
            int temp = (int)(end - start);
            maxSubStrCount = maxSubStrCount > temp ? maxSubStrCount : temp;
            start = position + 1;
        }
        end++;
    }
    int temp = (int)(end - start);
    return maxSubStrCount > temp ? maxSubStrCount : temp;
}

void testRepeated() {
    char * s = "abcde";
    char value = 'd';
    printf("重复:%p,%c,位置%p\n",s,value,repeated(s, s+4, value));
    char * st = "abc";
    value = 'd';
    printf("重复:%p,%c,位置%p\n",s,value,repeated(st, st+2, value));
    
}

void testLongest() {
    printf("最长无重复字符串长度：%d",lengthOfLongestSubstring("abcadefgh"));
}
