// Template not verified
// Class not verified
// Correct operation last verified at 6:32 PM saturday

#ifndef PROJECTS_LINKEDLIST_H
#define PROJECTS_LINKEDLIST_H
#include <iostream>

template<typename T, typename T1>
struct Node{ // Struct for a single node of a linked list
    T item;
    T1 price;
    T expDate;
    T1 count;
    T category;
    Node* next;
};

template<typename T, typename T1>
class linkedList {
    Node<T,T1>* head;
public:
    linkedList();
    void printList();
    void append(T newItem, T1 newPrice, T newExpDate, T1 newCount, T newCategory);
    void reverseLinkedList();
    void displayCategory(T itemSearch);
    
    Node<T,T1>* getHead(){return head;}
};

#endif //PROJECTS_LINKEDLIST_H

// END OF FILE