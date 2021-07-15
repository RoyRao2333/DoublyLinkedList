//
//  DLList.swift
//  DLList-Swift
//
//  Created by Roy on 2021/7/14.
//

import Foundation


// MARK: Doubly Linked List
public class DLList<Value> {
    public private(set) var head: DLNode<Value>?
    public private(set) var tail: DLNode<Value>?
    public private(set) var count: UInt = 0
    
    public var isEmpty: Bool {
        return count == 0
    }
    
    
    /**
     *  Returns a `DLList` instance.
     *
     *  This operation will initialize the head of a `DLList` if the parameter `value` isn't `nil`.
     *  Otherwise, an empty `DLList` instance will be created.
     *
     *  - Parameters:
     *      - value: The value for the head.
     */
    public init(_ value: Value? = nil) {
        if let value = value {
            head = DLNode(value)
            tail = head
            count = 1
        }
    }
}


// MARK: Public Methods -
extension DLList {
    
    /**
     *  Returns a `DLNode` of the `DLList` if available.
     *
     *  Find and return the `DLNode` at the given index.
     *
     *  - Parameters:
     *      - index: A node's position in list.
     */
    public func node(at index: UInt) -> DLNode<Value>? {
        guard index < count else { return nil }
        
        var currentIndex = 0
        var currentNode = head
        
        while currentIndex < index, currentNode != nil {
            currentIndex += 1
            currentNode = currentNode?.next
        }
        
        return currentNode
    }
    
    /**
     *  Add element to the front of a `DLList`.
     *
     *  - Parameters:
     *      - value: The value you want to add.
     */
    public func push_front(_ value: Value) {
        let newNode = DLNode(value, next: head, prev: nil)
        head?.prev = newNode
        head = newNode
        
        // Only One Node Left in List
        if tail == nil {
            tail = head
        }
        
        count += 1
    }
    
    /**
     *  Add element to the tail of a `DLList`.
     *
     *  - Parameters:
     *      - value: The value you want to add.
     */
    public func push_back(_ value: Value) {
        if isEmpty {
            push_front(value)
            
            return
        }
        
        let newNode = DLNode(value, next: nil, prev: tail)
        tail?.next = newNode
        tail = newNode
        count += 1
    }
    
    /**
     *  Returns the new `DLNode` just added.
     *
     *  Add element to a `DLList` after a existing node.
     *
     *  - Parameters:
     *      - value: The value you want to add.
     *      - node: The existing node before the node you want to add.
     */
    @discardableResult
    public func insert(_ value: Value, after node: DLNode<Value>) -> DLNode<Value> {
        if node === tail {
            push_back(value)
            
            return tail!
        }
        
        node.next = DLNode(value, next: node.next, prev: node)
        
        return node.next!
    }
    
    /**
     *  Returns the new `DLNode` just added.
     *
     *  Add element to a `DLList` before a existing node.
     *
     *  - Parameters:
     *      - value: The value you want to add.
     *      - node: The existing node after the node you want to add.
     */
    @discardableResult
    public func insert(_ value: Value, before node: DLNode<Value>) -> DLNode<Value> {
        if node === head {
            push_front(value)
            
            return head!
        }
        
        node.prev = DLNode(value, next: node, prev: node.prev)
        
        return node.prev!
    }
    
    /**
     *  Returns the new `DLNode` if added successfully.
     *
     *  Add element to a position in a `DLList` by  a given index.
     *
     *  - Parameters:
     *      - value: The value you want to add.
     *      - index: The position you want the value to be added.
     */
    @discardableResult
    public func insert(_ value: Value, at index: UInt) -> DLNode<Value>? {
        guard !isEmpty else {
            push_front(value)
            
            return head!
        }
        
        guard index != 0 else {
            insert(value, after: head!)
            
            return head!.next!
        }
        
        if let node = node(at: index - 1) {
            return insert(value, after: node)
        }
        
        return nil
    }
    
    /**
     *  Returns the value stored by the removed node if available.
     *
     *  Remove the first element from a `DLList`.
     */
    @discardableResult
    public func pop_front() -> Value? {
        guard !isEmpty else { return nil }
        
        let oldHead = head
        head = oldHead?.next
        count -= 1
        
        // Only One Node Left in List
        if tail === oldHead {
            tail = nil
        }
        
        return oldHead?.value
    }
    
    /**
     *  Returns the value stored by the removed node if available.
     *
     *  Remove the last element from a `DLList`.
     */
    @discardableResult
    public func pop_back() -> Value? {
        guard count > 1 else { return pop_front() }
        
        let removedNode = tail
        let newTail = tail?.prev
        newTail?.next = nil
        tail = newTail
        count -= 1
        
        return removedNode?.value
    }
    
    /**
     *  Returns the value of the new node after the parameter `node` if available.
     *
     *  Remove the element after a given existing node from a `DLList`.
     *
     *  - Parameters:
     *      - node: The existing node before the node you want to remove.
     */
    @discardableResult
    public func pop(after node: DLNode<Value>) -> Value? {
        guard node.next != nil else { return nil }
        
        guard node.next?.next != nil else {
            return pop_back()
        }
        
        node.next = node.next?.next
        
        return node.next?.value
    }
    
    /**
     *  Returns the value of the new node before the parameter `node` if available.
     *
     *  Remove the element before a given existing node from a `DLList`.
     *
     *  - Parameters:
     *      - node: The existing node after the node you want to remove.
     */
    @discardableResult
    public func pop(before node: DLNode<Value>) -> Value? {
        guard node.prev != nil else { return nil }
        
        guard node.prev?.prev != nil else {
            return pop_front()
        }
        
        node.prev = node.prev?.prev
        
        return node.prev?.value
    }
    
    /**
     *  Returns the value stored by the removed node if available.
     *
     *  Remove the element by a given index from a `DLList`.
     *
     *  - Parameters:
     *      - index: The position of the node you want to remove.
     */
    @discardableResult
    public func pop(at index: UInt) -> Value? {
        guard index < count else { return nil }
        
        if index == 0 {
            return pop_front()
        } else if index == count - 1 {
            return pop_back()
        }
        
        if let node = node(at: index - 1) {
            return pop(after: node)
        }
        
        return nil
    }
    
    /**
     *  Returns all values stored by nodes in a `DLList`.
     */
    public func readAll() -> [Value] {
        guard !isEmpty else { return [] }
        
        var current = head
        var result: [Value] = []
        
        while let value = current?.value {
            result.append(value)
            
            current = current?.next
        }
        
        return result
    }
}
