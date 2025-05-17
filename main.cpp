#include <iostream>
#include"dsa/linkedList.h"
#include "dsa/stack.h"
#include<string>

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

    Stack<int> myStack;
    std::cout << myStack.Size() << std::endl;
    std::cout << myStack.IsEmpty() << std::endl;

    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Pop();
    myStack.PrintElements();
    return 0;
}
