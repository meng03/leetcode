//
//  RemoveNilValue.swift
//  leetcode
//
//  Created by 孟冰川 on 2019/7/13.
//  Copyright © 2019 孟冰川. All rights reserved.
//

import Foundation

let dic: [String: Any?] = [
    "sub1":["a","b",nil,"d"],
    "sub2":nil,
    "sub3":[
        "sub1":["a","b",nil,"d"],
        "sub2":nil,
        "sub3":2
    ],
    "sub4": [["hh": 34],["gg":4],["kk":nil]]
]

func removeNilFromDic(dic: [String: Any?]) -> [String: Any]? {
    var result = [String: Any]()
    for item in dic {
        if let value = removeNil(value: item.value) {
            result[item.key] = value
        }
    }
    if result.count == 0 {
        return nil
    }
    return result
}

func removeNilFromArray(arr: [Any?]) -> [Any]? {
    var array = [Any]()
    for item in arr {
        if let value = removeNil(value: item) {
            array.append(value)
        }
    }
    if array.count == 0 {
        return nil
    }
    return array
}

func removeNil(value: Any?) -> Any? {
    if let array = value as? [Any?] {
        return removeNilFromArray(arr: array)
    }else if let dict = value as? [String: Any?] {
        return removeNilFromDic(dic: dict)
    }
    return value
}
