//
//  AddTwoNum.swift
//  leetcode
//
//  Created by 孟冰川 on 2019/7/13.
//  Copyright © 2019 孟冰川. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class AddTwoNum {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        }
        if l2 == nil {
            return l1
        }
        var temp = 0
        let result = ListNode(0)
        var current = result
        var l1p = l1
        var l2p = l2
        while l1p != nil || l2p != nil {
            let value = (l1p?.val ?? 0) + (l2p?.val ?? 0) + temp
            temp = value/10
            current.next = ListNode(value%10)
            current = current.next!
            l1p = l1p?.next
            l2p = l2p?.next
        }
        if temp > 0 {
            current.next = ListNode(temp)
        }
        return result.next!
    }

}
