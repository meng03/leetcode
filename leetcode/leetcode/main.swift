//
//  main.swift
//  leetcode
//
//  Created by 孟冰川 on 2019/7/13.
//  Copyright © 2019 孟冰川. All rights reserved.
//

import Foundation

let l1 = ListNode(2)
l1.next = ListNode(4)
l1.next?.next = ListNode(3)

let l2 = ListNode(5)
l2.next = ListNode(6)
l2.next?.next = ListNode(4)
var node = AddTwoNum().addTwoNumbers(l1, l2)
while node != nil {
    print(node?.val)
    node = node?.next
}
