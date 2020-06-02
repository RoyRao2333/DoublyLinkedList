//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Roy Rao on 2020/6/1.
//  Copyright © 2020 RoyRao. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

#endif /* LinkedList_hpp */

struct LNode {
    int data;
    LNode *next;
    LNode *prev;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &list);
    ~DoublyLinkedList();
    void append2End(int data);
    void append2Front(int data);
    void insertAtIndex(int index, int data);
    void insertBefore(LNode *ptrMark, int data);
    void insertAfter(LNode *ptrMark, int data);
    void deleteAtIndex(int index);
    void deleteWith(LNode *ptrDelete);
    int getLength();
    void print();
private:
    LNode *head;
    LNode *tail;
    int length;
};
