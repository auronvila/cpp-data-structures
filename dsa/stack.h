//
// Created by Auron Vila on 17.05.2025.
//

#ifndef STACK_H
#define STACK_H
#include <iostream>

// | Step                  | Description                                                  |
// | --------------------- | ------------------------------------------------------------ |
// | 1. **Iterator class** | Holds a pointer/reference to your current node/state         |
// | 2. **`operator*()`**  | Returns current value (`T&`)                                 |
// | 3. **`operator++()`** | Moves iterator forward (or however your structure traverses) |
// | 4. **`operator!=()`** | Ends loop when current node reaches `nullptr` or a sentinel  |
// | 5. **`begin()`**      | Returns iterator starting from first element                 |
// | 6. **`end()`**        | Returns iterator pointing to end (`nullptr`)                 |


template<typename T>
class Stack {
    struct Node {
        T val;
        Node *next;

        Node(const T &value, Node *nextNode = nullptr)
            : val(value), next(nextNode) {
        }
    };

private:
    int size;
    Node *top;

public:
    Stack();

    ~Stack();

    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] int Size() const { return size; }

    T &Top() const;

    void Push(const T &val);

    void Pop();

    void PrintElements();

    class Iterator {
    private:
        Node *current;

    public:
        explicit Iterator(Node *node): current(node) {
        }

        T &operator*() const {
            return current->val;
        }

        Iterator &operator++() {
            if (current) current = current->next;
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(top);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};


template<typename T>
Stack<T>::Stack() {
    top = nullptr;
    size = 0;
}


template<typename T>
bool Stack<T>::IsEmpty() const {
    if (size < 1) {
        return true;
    }
    return false;
}

template<typename T>
void Stack<T>::Push(const T &val) {
    top = new Node(val, top);
    size++;
}

template<typename T>
T &Stack<T>::Top() const {
    return top->val;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] top;
}

template<typename T>
void Stack<T>::Pop() {
    if (IsEmpty()) throw std::runtime_error("Stack is empty");
    if (size == 1) {
        delete top;
        return;
    }
    const Node *temp = top;
    top = top->next;
    delete temp;
    size--;
}

template<typename T>
void Stack<T>::PrintElements() {
    while (top != nullptr) {
        std::cout << top->val << std::endl;
        top = top->next;
    }
}
#endif //STACK_H
