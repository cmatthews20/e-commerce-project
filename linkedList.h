#ifndef PROJECTS_LINKEDLIST_H
#define PROJECTS_LINKEDLIST_H
#include <iostream>

template<typename T, typename T1>
class Node{ // Struct for a single node of a linked list
public:
    T item;
    T1 price; // could have whole num prices, or decimals
    T expDate;
    int count; // cant have half an item
    T category;
    Node* next;
};

template<typename T, typename T1>
class linkedList {
    Node<T,T1>* head;
    int listSize;
public:
    linkedList();
    void printList();
    void append(T newItem, T1 newPrice, T newExpDate, T1 newCount, T newCategory);
    void displayCategory(T itemSearch);
    bool itemExists(T search);
    T1 getPrice(T search);
    T1 getCount(T search);
    int getSize();
    
    Node<T,T1>* getHead(){return head;}
};

#endif //PROJECTS_LINKEDLIST_H
