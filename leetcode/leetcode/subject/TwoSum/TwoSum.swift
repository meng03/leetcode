//
//  TwoSum.swift
//  leetcode
//
//  Created by 孟冰川 on 2019/7/13.
//  Copyright © 2019 孟冰川. All rights reserved.
//

import Foundation

class TwoSum {
    
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var map = [Int:Int]()
        for i in 0...(nums.count - 1) {
            let value = nums[i]
            if let item = map.first(where: {$0.value == value}) {
                return [item.key,i]
            }else {
                map[i] = target - value
            }
        }
        return []
    }
}
