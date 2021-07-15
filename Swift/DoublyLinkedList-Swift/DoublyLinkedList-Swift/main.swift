//
//  main.swift
//  DoublyLinkedList-Swift
//
//  Created by Roy on 2021/7/14.
//

import Foundation


let dList = DLList<Int>(5)
for i in 10 ..< 15 {
    dList.push_back(i)
}

dList.pop_back()

print(dList.tail?.value)
