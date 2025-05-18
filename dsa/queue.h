//
// Created by Auron Vila on 18.05.2025.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include <iostream>

template<typename T>
class Queue {
    struct Node {
        explicit Node(T value) : value(value), previous(nullptr) {
        }

        T value;
        Node *previous;
    };

private:
    int size = 0;
    Node *front = nullptr, *back = nullptr;

public:
    // push pop isEmpty front back print
    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] int Size() const { return size; }

    void Push(T value);

    void Pop();

    T Front();

    T Back();

    void PrintElements();
};

template<typename T>
bool Queue<T>::IsEmpty() const {
    if (size < 1) {
        return true;
    }
    return false;
}

template<typename T>
void Queue<T>::Push(T value) {
    Node *newNode = new Node(value);
    size++;
    if (front == nullptr) {
        front = newNode;
        back = newNode;
        return;
    }

    Node *itr = front;
    while (itr->previous != nullptr) {
        itr = itr->previous;
    }

    itr->previous = newNode;
    back = newNode;
}

template<typename T>
void Queue<T>::Pop() {
    if (size < 1) {
        throw std::runtime_error("Queue is empty");
    }
    Node *temp = front;
    front = front->previous;

    if (front == nullptr) {
        back = nullptr;
    }

    delete temp;
    size--;
}

template<typename T>
T Queue<T>::Front() {
    if (size < 1) {
        throw std::runtime_error("Queue is empty");
    }
    return front->value;
}

template<typename T>
T Queue<T>::Back() {
    if (size < 1) {
        throw std::runtime_error("Queue is empty");
    }
    return back->value;
}

template<typename T>
void Queue<T>::PrintElements() {
    Node *itr = front;
    while (itr != nullptr) {
        std::cout << itr->value << std::endl;
        itr = itr->previous;
    }
}
#endif //QUEUE_H
