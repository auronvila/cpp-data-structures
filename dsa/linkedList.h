//
// Created by Auron Vila on 28.04.2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>

struct Node {
    int Val;
    Node *Next;
};

class LinkedList {
    Node *head;
    int count;

public:
    LinkedList();

    ~LinkedList();

    void PushBack(int value);

    void PrintLinkedList() const;

    void PushFront(int val);

    void PushAtIndex(int index, int val);

    int GetCount() const { return count; }
};

#endif //LINKEDLIST_H
