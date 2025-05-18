#include <iostream>
#include"dsa/linkedList.h"
#include "dsa/stack.h"
#include<string>
#include "dsa/queue.h"
#include "dsa/map.h"

int main() {
    // LinkedList myList;
    // myList.PushBack(1);
    // myList.PushBack(2);
    // myList.PushBack(3);
    // myList.PushBack(9);
    // myList.PushFront(6);
    // myList.PushFront(7);
    // myList.PushAtIndex(3, 4);
    //
    // std::cout << "count ----" << std::endl;
    // std::cout << myList.GetCount() << std::endl;
    // std::cout << "----" << std::endl;
    // myList.PrintLinkedList();

    // Stack<int> myStack;
    // std::cout << myStack.Size() << std::endl;
    // std::cout << myStack.IsEmpty() << std::endl;
    //
    // myStack.Push(1);
    // myStack.Push(2);
    // myStack.Push(3);
    // myStack.Pop();
    // myStack.PrintElements();

    // Queue<int> my_queue;
    // my_queue.Push(1);
    // my_queue.Push(2);
    // my_queue.Push(3);
    // my_queue.Pop();
    //
    // my_queue.PrintElements();

    // std::cout << my_queue.Size() << std::endl;
    // std::cout << my_queue.Front();
    // std::cout << my_queue.Back();

    Map<int, int> my_map;
    my_map.Insert(1, 1);
    my_map.Insert(2, 2);
    my_map.Insert(4, 4);
    my_map.Insert(5, 5);
    my_map.Insert(6, 6);
    my_map.Put(2, 5);

    my_map.Remove(2);
    std::cout << my_map[5] << std::endl;
    my_map.PrintItems();
    return 0;
}
