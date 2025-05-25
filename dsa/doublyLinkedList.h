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

        friend std::ostream &operator<<(std::ostream &os, const Node &node) {
            os << node.value;
            return os;
        }
    };

    Node *head = nullptr, *tail = nullptr;
    int length = 0;
    using ArrOfValues = std::vector<T>;

public:
    T &getHeadVal() const {
        if (head == nullptr) {
            throw std::runtime_error("there is no head in the list");
        }

        return head->value;
    }

    T &getTailVal() const {
        if (tail == nullptr) {
            throw std::runtime_error("there is no tail in the list");
        }
        return tail->value;
    }

    [[nodiscard]] int getLength() const { return length; }

    void append(T value);

    void prepend(T value);

    void insert(int index, T value);

    void remove(int index);

    void pop();

    void shift();

    Node &get(int index) const;

    void set(int index, T value);

    void printForward() const;

    void printBackWards() const;

    ArrOfValues toArray();

    DoublyLinkedList();

    ~DoublyLinkedList();
};

template<typename T>
void DoublyLinkedList<T>::append(T value) {
    Node *newNode = new Node(value);

    ++length;
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
}

template<typename T>
void DoublyLinkedList<T>::prepend(T value) {
    Node *newNode = new Node(value);
    ++length;
    if (head == nullptr || tail == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

template<typename T>
void DoublyLinkedList<T>::insert(int index, T value) {
    if ((index > length - 1) || (index < 0)) {
        throw std::runtime_error("index cannot be greater than the length of the doubly linked list");
    }

    Node *itr = head;
    Node *newNode = new Node(value);

    while (index != 0) {
        itr = itr->next;
        index--;
    }

    ++length;
    if (itr == tail) {
        itr->next = newNode;
        newNode->prev = itr;
        tail = newNode;
        return;
    }

    if (itr == head) {
        newNode->next = itr;
        itr->prev = newNode;
        head = newNode;
        return;
    }

    newNode->next = itr->next;
    itr->next = newNode;
    newNode->prev = itr;
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
    if (head == nullptr || tail == nullptr) {
        throw std::runtime_error("cannot remove items because there are no items in the list");
    }

    if (index < 0 || index >= length) {
        throw std::runtime_error("index out of bounds");
    }

    if (index == 0) {
        shift();
        return;
    }

    if (index == length - 1) {
        pop();
        return;
    }

    Node *itr = head;
    for (int i = 0; i < index; i++) {
        itr = itr->next;
    }

    itr->prev->next = itr->next;
    itr->next->prev = itr->prev;

    delete itr;
    length--;
}

template<typename T>
void DoublyLinkedList<T>::pop() {
    if (head == nullptr) {
        throw std::runtime_error("there are not enough elements in the list");
    }

    --length;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        return;
    }

    const Node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

template<typename T>
void DoublyLinkedList<T>::shift() {
    if (head == nullptr) {
        throw std::runtime_error("there are not enough elements in the list");
    }
    --length;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

template<typename T>
typename DoublyLinkedList<T>::Node &DoublyLinkedList<T>::get(int index) const {
    if ((head == nullptr) || (tail == nullptr)) {
        throw std::runtime_error("there are not enough elements in the list");
    }

    if (index > length - 1) {
        throw std::runtime_error("index cannot be greater than the length");
    }

    Node *itr = head;
    while (index != 0) {
        itr = itr->next;
        index--;
    }

    return *itr;
}

template<typename T>
void DoublyLinkedList<T>::set(int index, T value) {
    if (index == 0 && length == 0) {
        throw std::runtime_error("set function cannot be used to insert elements");
    }

    if (index > length - 1) {
        throw std::runtime_error("index cannot be greater than length");
    }

    Node *itr = head;

    while (index != 0) {
        itr = itr->next;
        index--;
    }

    itr->value = value;
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
    std::vector<T> doublyLinkedListArr;
    if (length < 1) {
        throw std::runtime_error("there are not items in the list to be added to the array");
    }

    Node *itr = head;
    while (itr != nullptr) {
        doublyLinkedListArr.push_back(itr->value);
        itr = itr->next;
    }

    return doublyLinkedListArr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() = default;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}
#endif //DOUBLYLINKEDLIST_H
