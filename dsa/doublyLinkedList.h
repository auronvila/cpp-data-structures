//
// Created by Auron Vila on 24.05.2025.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <vector>


template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node *next;
        Node *prev;

        Node(T v) : value(v), next(nullptr), prev(nullptr) {
        }
    };

    using ArrOfValues = std::vector<T[]>;

    Node *head = nullptr, *tail = nullptr;
    int length = 1;

public:
    T &getHeadVal() const { return head->value; }
    T &getTailVal() const { return tail->value; }
    [[nodiscard]] int getLength() const { return length; }

    void append(T value);

    void prepend(T value);

    void insert(int index, T value);

    void remove(int index);

    void pop();

    void shift();

    Node &get(int index);

    void set(int index, T value);

    void printForward() const;

    void printBackWards() const;

    ArrOfValues toArray();
};

template<typename T>
void DoublyLinkedList<T>::append(T value) {
    Node *newNode = new Node(value);

    // if inserted first
    if (head == nullptr || tail == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    // if inserted last
    Node *itr = head;
    while (itr->next != nullptr) {
        itr = itr->next;
    }

    itr->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    ++length;
}

template<typename T>
void DoublyLinkedList<T>::prepend(T value) {
    Node *newNode = new Node(value);
    if (head == nullptr || tail == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    ++length;
}

template<typename T>
void DoublyLinkedList<T>::insert(int index, T value) {
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
}

template<typename T>
void DoublyLinkedList<T>::pop() {
}

template<typename T>
void DoublyLinkedList<T>::shift() {
}

template<typename T>
typename DoublyLinkedList<T>::Node &DoublyLinkedList<T>::get(int index) {
}

template<typename T>
void DoublyLinkedList<T>::set(int index, T value) {
}

template<typename T>
void DoublyLinkedList<T>::printForward() const {
    Node *itr = head;
    while (itr != nullptr) {
        std::cout << itr->value << std::endl;
        itr = itr->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::printBackWards() const {
    Node *itr = tail;
    while (itr != nullptr) {
        std::cout << itr->value << std::endl;
        itr = itr->prev;
    }
}

template<typename T>
typename DoublyLinkedList<T>::ArrOfValues DoublyLinkedList<T>::toArray() {
}
#endif //DOUBLYLINKEDLIST_H
