//
//  DoublyLinkedList.cpp
//  DoublyLinkedList
//
//  Created by Roy Rao on 2020/6/1.
//  Copyright © 2020 RoyRao. All rights reserved.
//

#include "DoublyLinkedList.hpp"
using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    this->head = new LNode;
    this->tail = new LNode;
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->head->prev = nullptr;
    this->tail->next = nullptr;
    this->length = 0;
    cout << "List initialization completed." << endl;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &list) {
    this->head = new LNode;
    this->tail = new LNode;
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->head->prev = nullptr;
    this->tail->next = nullptr;
    this->length = 0;
    
    LNode *cpNode = list.head->next;
    while (cpNode != nullptr) {
        this->append2End(cpNode->data);
        cpNode = cpNode->next;
        this->length++;
    }
    
    cout << "List copying completed." << endl;
}

DoublyLinkedList::~DoublyLinkedList() {
    LNode *nodeTemp = this->head->next;
    while (nodeTemp != nullptr) {
        LNode *pNext = nodeTemp->next;
        this->deleteWith(nodeTemp);
        nodeTemp = pNext;
    }
    delete this->head;
    this->length = 0;
    cout << "List destroyed." << endl;
}

void DoublyLinkedList::append2End(int data) {
    LNode *ptrCur = this->head;
    while (ptrCur->next != this->tail) {
        ptrCur = ptrCur->next;
    }
    LNode *newNode = new LNode;
    newNode->data = data;
    newNode->prev = ptrCur;
    newNode->next =this->tail;
    ptrCur->next = newNode;
    this->tail->prev = newNode;
    cout << "Node appended to the end." << endl;
}

void DoublyLinkedList::append2Front(int data) {
    LNode *ptrHead = this->head;
    LNode *newNode = new LNode;
    newNode->data = data;
    newNode->prev = ptrHead;
    newNode->next = ptrHead->next;
    ptrHead->next->prev = newNode;
    ptrHead->next = newNode;
    cout << "Node appended to the front" << endl;
}

void DoublyLinkedList::insertAtIndex(int index, int data) {
    if (index > this->length + 1) {
        cout << "Oops! Index is out of range!" << endl;
        return;
    }
    LNode *newNode = new LNode;
    newNode->data = data;
    LNode *originalNode = this->head;
    for (int i = 1; i <= index; i++) {
        originalNode = originalNode->next;
    }
    newNode->next = originalNode;
    newNode->prev = originalNode->prev;
    originalNode->prev->next = newNode;
    originalNode->prev = newNode;
    this->length++;
    cout << "Node inserted at " << index << "." << endl;
    return;
}

void DoublyLinkedList::insertBefore(LNode *ptrMark, int data) {
    if (this->getLength() == 0) {
        cout << "Oops! List is empty!" << endl;
        return;
    } else if (ptrMark == nullptr) {
        cout << "Oops! Can not insert nullptr!" << endl;
        return;
    }
    LNode *ptrCur = this->head->next;
    while (ptrCur != this->tail) {
        if (ptrCur == ptrMark) {
            LNode *newNode = new LNode;
            newNode->data = data;
            newNode->prev = ptrCur->prev;
            newNode->next = ptrCur;
            ptrCur->prev->next = newNode;
            ptrCur->prev = newNode;
            cout << "Node successfully inserted." << endl;
            return;
        }
        ptrCur = ptrCur->next;
    }
    cout << "Oops! Node not found!" << endl;
}

void DoublyLinkedList::insertAfter(LNode *ptrMark, int data) {
    if (this->getLength() == 0) {
        cout << "Oops! List is empty!" << endl;
        return;
    } else if (ptrMark == nullptr) {
        cout << "Oops! Can not insert nullptr!" << endl;
        return;
    }
    LNode *ptrCur = this->head->next;
    while (ptrCur != this->tail) {
        if (ptrCur == ptrMark) {
            LNode *newNode = new LNode;
            newNode->data = data;
            newNode->prev = ptrCur;
            newNode->next = ptrCur->next;
            ptrCur->next->prev = newNode;
            ptrCur->next = newNode;
            cout << "Node successfully inserted." << endl;
            return;
        }
        ptrCur = ptrCur->next;
    }
    cout << "Oops! Node not found!" << endl;
}

void DoublyLinkedList::deleteAtIndex(int index) {
    if (this->getLength() == 0) {
        cout << "Oops! List is empty!" << endl;
        return;
    } else if (index > this->length) {
        cout << "Oops! Index is out of range!" << endl;
        return;
    }
    LNode *deleteNode = this->head;
    for (int i = 1; i <= index; i++) {
        deleteNode = deleteNode->next;
    }
    deleteNode->prev->next = deleteNode->next;
    deleteNode->next->prev = deleteNode->prev;
    delete deleteNode;
    this->length--;
}

void DoublyLinkedList::deleteWith(LNode *ptrDelete) {
    if (this->getLength() == 0) {
        cout << "Oops! List is empty!" << endl;
        return;
    }
    if (ptrDelete == head || ptrDelete == tail) {
        cout << "Oops! You can not remove list's head/tail!" << endl;
        return;
    }
    LNode *ptrCur = this->head->next;
    while (ptrCur != nullptr) {
        if (ptrCur == ptrDelete) {
            ptrCur->prev->next = ptrCur->next;
            ptrCur->next->prev = ptrCur->prev;
            delete ptrCur;
            this->length--;
            cout << "Node successfully deleted." << endl;
            return;
        }
        ptrCur = ptrCur->next;
    }
    cout << "Oops! Node not found!" << endl;
}

int DoublyLinkedList::getLength() {
    return this->length;
}

void DoublyLinkedList::print() {
    LNode *ptrNode = this->head->next;
    while (ptrNode != nullptr) {
        cout << ptrNode->data << "\t";
        ptrNode = ptrNode->next;
    }
    cout << endl << "Completed." << endl;
}
