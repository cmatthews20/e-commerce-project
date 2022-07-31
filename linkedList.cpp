#include "linkedList.h"

template<typename T, typename T1>
linkedList<T,T1>::linkedList() { // Constructor for LL
    head = NULL;
    listSize = 0;
}

template<typename T, typename T1>
void linkedList<T,T1>::printList() { // Prints the list
    Node<T, T1>* temp = head;
    std::cout<< "================================================== INVENTORY =======================================================\n\n";
    while(temp != NULL){
        std::cout<< temp->item << ":\t\t Price: $";
        std::cout<< temp->price << ",\t\tExp: ";
        std::cout<< temp->expDate << ",\t\t";
        std::cout<< temp->count << " Remaining,\t\t";
        std::cout<< temp->category << " Dept.\n"<<std::endl;

        temp = temp->next;
    }
    std::cout<< "====================================================================================================================\n\n";
}

template<typename T, typename T1>
void linkedList<T,T1>::append(T newItem, T1 newPrice, T newExpDate, T1 newCount, T newCategory) { // Adds new node at end of list
    Node<T,T1> *new_node = new Node<T,T1>; // Allocate new node

    new_node->item = newItem; // Put in the food values
    new_node->price = newPrice;
    new_node->expDate = newExpDate;
    new_node->count = newCount;
    new_node->category = newCategory;

    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return;
    } else {
        new_node->next = head;
        head = new_node;
    }
    listSize++;
}

template<typename T, typename T1>
void linkedList<T,T1>::reverseLinkedList() {
    Node<T,T1>* current = head;
    Node<T,T1> *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next; // Save next
        current->next = prev; // Reverse current node pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    head = prev;
}

template<typename T, typename T1>
void linkedList<T,T1>::displayCategory(T itemSearch){
    Node<T,T1>* current = head;
    while(current != NULL){
        if(current->category == itemSearch){
            std::cout<< current->item << ":\t\t Price:$";
            std::cout<< current->price << "\t\tExp: ";
            std::cout<< current->expDate << ",\t\t";
            std::cout<< current->count << " Remaining,\t\t";
            std::cout<< current->category << " Dept.\n"<<std::endl;
        }
        current = current->next;
    }
}

template<typename T,typename T1>
bool linkedList<T,T1>::itemExists(T search){
    Node<T,T1>* current = head;
    while(current!=NULL){
        if(current->item == search){
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T,typename T1>
T1 linkedList<T,T1>::getPrice(T search){
    Node<T,T1>* current = head;
    while(current!=NULL && current->item!=search){
        current = current->next;
    }
    return current->price;
}

template<typename T,typename T1>
T1 linkedList<T,T1>::getCount(T search){
    Node<T,T1>* current = head;
    while(current!=NULL && current->item!=search){
        current = current->next;
    }
    return current->count;
}

template<typename T,typename T1>
int linkedList<T,T1>::getSize(){
    return listSize;
}




// END OF FILE