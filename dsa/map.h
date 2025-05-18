//
// Created by Auron Vila on 18.05.2025.
//

#ifndef MAP_H
#define MAP_H
#include<iostream>

template<typename K, typename V>
class Map {
    struct Node {
        K key;
        V value;
        Node *next;

        Node(K key, V val) : key(key), value(val), next(nullptr) {
        }
    };

private:
    Node *head = nullptr;

public:
    void PrintItems();

    void Insert(K key, V value);

    void Put(K key, V newValue);

    void Remove(K key);
};

template<typename K, typename V>
void Map<K, V>::PrintItems() {
    Node *itr = head;
    while (itr != nullptr) {
        std::cout << itr->key << " - " << itr->value << std::endl;
        itr = itr->next;
    }
}

template<typename K, typename V>
void Map<K, V>::Insert(K key, V value) {
    Node *newNode = new Node(key, value);
    Node *itr = head;
    if (head == nullptr) {
        head = newNode;
        return;
    }

    while (itr->next != nullptr) {
        itr = itr->next;
    }
    itr->next = newNode;
}

template<typename K, typename V>
void Map<K, V>::Put(K key, V newValue) {
    Node *itr = head;

    if (itr == nullptr) {
        throw std::runtime_error("Cannot put");
    }

    while (itr->key != key) {
        itr = itr->next;
    }

    if (itr == nullptr) {
        throw std::runtime_error("Cannot put");
    }
    itr->value = newValue;
}

template<typename K, typename V>
void Map<K, V>::Remove(K key) {
    if (head == nullptr) {
        throw std::runtime_error("Map is empty");
    }

    if (head->key == key) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != nullptr) {
        if (curr->key == key) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    throw std::runtime_error("Key was not found");
}
#endif //MAP_H
