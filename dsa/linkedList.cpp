//
// Created by Auron Vila on 28.04.2025.
//

#include "linkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    count = 0;
}

LinkedList::~LinkedList() {
}

void LinkedList::PushBack(int value) {
    Node *itr = head;
    Node *newNode = new Node;
    newNode->Val = value;
    newNode->Next = nullptr;
    if (head == nullptr) {
        head = newNode;
        count++;
        return;
    }

    while (itr->Next != nullptr) {
        itr = itr->Next;
    }

    itr->Next = newNode;
    count++;
}

void LinkedList::PushFront(int val) {
    Node *newNode = new Node;
    newNode->Val = val;
    newNode->Next = nullptr;
    count++;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->Next = head;
    head = newNode;
}

void LinkedList::PushAtIndex(int index, int val) {
    if (index > count) {
        std::cout << "cannot insert in this index (index out of bounds)!!!" << std::endl;
        return;
    }
    Node *newNode = new Node;
    Node *itr = head;
    newNode->Val = val;
    newNode->Next = nullptr;
    int counter = 0;
    while (counter < index) {
        itr = itr->Next;
        counter++;
    }
    newNode->Next = itr->Next;
    itr->Next = newNode;
}

void LinkedList::PrintLinkedList() const {
    Node *itr = head;

    while (itr != nullptr) {
        std::cout << itr->Val << std::endl;
        itr = itr->Next;
    }
}
