//
//  main.cpp
//  LinkedList
//
//  Created by Roy Rao on 2020/6/1.
//  Copyright © 2020 RoyRao. All rights reserved.
//

#define INIT_COUNT 10
#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned)time(NULL));
    DoublyLinkedList *listPtr = new DoublyLinkedList;
    for (int i = 1; i <= INIT_COUNT; i++) {
        int randomNum = rand() % (9 - 0 + 1) + 0;
        listPtr->insertAtIndex(i, randomNum);
    }
    listPtr->print();
    listPtr->deleteAtIndex(5);
    listPtr->print();
    
    return 0;
}
