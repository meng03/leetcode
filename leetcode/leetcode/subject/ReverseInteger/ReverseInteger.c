//
//  ReverseInteger.c
//  leetcode
//
//  Created by 孟冰川 on 2019/9/5.
//  Copyright © 2019 孟冰川. All rights reserved.
//

#include "ReverseInteger.h"
#include <math.h>

int reverse(int x){
    int reversed = 0;
    int min = -pow(2, 31);
    int max = -(min + 1);
    int bit = 1;
    while (x != 0 ) {
        int tail = x%10;
        x = x/10;
        if (bit == 10) {
            //分成两部分求大小，前9位，和后一位
            if ((reversed > max/10) || ((reversed == max/10) && tail > 7)) { return 0; }
            if ((reversed < min/10) || ((reversed == max/10) && tail < -8)) { return 0; }
        }
        reversed = reversed*10 + tail;
        bit++;
    }
    return reversed;
}

void testReverse() {
    printf("%d\n", reverse(-2147483647 ));
//    printf("%d\n", reverse(-123));
//    printf("%d\n", reverse(120));
}
