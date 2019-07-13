//
//  SplitRange.swift
//  leetcode
//
//  Created by 孟冰川 on 2019/7/13.
//  Copyright © 2019 孟冰川. All rights reserved.
//

import Foundation

struct ContentRange {
    var location: Int
    var length: Int
    var local: Bool
    
    var endOffset: Int {
        return location + length
    }
    
    func isEqual(other: ContentRange) -> Bool {
        return self.location == other.location && self.length == other.length
    }
}

func splitRange(_ range: ContentRange,exists: [ContentRange]) -> [ContentRange] {
    
    guard let startRelativeRange = exists.first(where: {range.location < $0.endOffset}),
        let endRelativeRange = exists.reversed().first(where: {range.endOffset > $0.location }) else {
            return [range]
    }
    
    if !startRelativeRange.isEqual(other: endRelativeRange) && startRelativeRange.location > endRelativeRange.endOffset {
        return [range]
    }
    
    var startDataIndex = exists.firstIndex(where: {$0.isEqual(other: startRelativeRange)})!
    let endDataIndex = exists.firstIndex(where: {$0.isEqual(other: endRelativeRange)})!
    var results = [ContentRange]()
    var offset = range.location
    let end = range.endOffset
    while offset < end && startDataIndex <= endDataIndex {
        let startDataRange = exists[startDataIndex]
        var tempEnd = offset
        var local = false
        if offset < startDataRange.location {
            local = false
            tempEnd = startDataRange.location
        }else {
            local = true
            tempEnd = startDataRange.endOffset
        }
        tempEnd = min(tempEnd,end)
        let length = Int(tempEnd - offset)
        if local {
            results.append(ContentRange(location: offset, length: length, local: true))
            startDataIndex += 1
        }else {
            results.append(ContentRange(location: offset, length: length, local: false))
        }
        //更新cursor
        offset = tempEnd
        
    }
    return results
}

func testSplitRange() {
    let range = ContentRange(location: 20, length: 700, local: false)
    let exists = [ContentRange(location: 10, length: 35, local: true),
                  ContentRange(location: 50, length: 25, local: true),
                  ContentRange(location: 90, length: 300, local: true),
                  ContentRange(location: 400, length: 100, local: true),
                  ContentRange(location: 550, length: 60, local: true),
                  ContentRange(location: 610, length: 200, local: true),
                  ]
    print(splitRange(range, exists: exists))
    
}
