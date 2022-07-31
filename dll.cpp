#include "iostream"
using namespace std;

template<typename T>
class dllNode {
public:
    T data;
    dllNode* next;
    dllNode* prev;
    dllNode (T arg_data) : data (arg_data), next (nullptr), prev (nullptr)
    {}
};

template<typename T>
class dll {
private:
    dllNode<T> * head;
public:

    dll (){
        head = nullptr;
    }

    dllNode<T> * getHead (){ // Return head node of list
        return head;
    }

    void createHead (T data) { // Create a head node of the doubly linked list
        head = new dllNode<T>(data);
    }

    void insert (T data, int after) { // Insert new node into the dll list after the first found node
        dllNode<T>* current = head;

        // Traverse until the node is found after which the data is to be inserted
        while (current != nullptr && current->data != after) {
            current = current->next;
        }

        if (current != nullptr) {
            dllNode<T> * temp = new dllNode<T>(data);
            dllNode<T> * next_node = current->next; // Save the location of node after current
            current->next = temp; // Point current's link to the new node to be inserted

            // Point new node next link (to the next node location previously stored). left link to the current node
            temp->prev  = current;
            temp->next = next_node;

            if (next_node != nullptr) // Point next node's prev to the newly added node (temp)
                next_node->prev = temp;
        }
    }

    void deleteNode (T data_to_be_deleted) { // Delete the first node matching the data given
        //If head node is to be deleted and list only contains head node, delete head node
        if (head->data == data_to_be_deleted && head->next == nullptr){
            head = nullptr;
        }
            // If the head node is to be deleted, then the node to the next of head becomes head node
        else if (head->data == data_to_be_deleted ) {
            dllNode<T> * temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
        } else {
            dllNode<T> * current = head;
            while (current->data != data_to_be_deleted ) {
                current = current->next;
            }
            if (current != nullptr) { // current is to be deleted.
                current->prev->next = current->next; // Update the next link of the node previous of current
                if (current->next != nullptr) {
                    current->next->prev = current->prev; // Update the previous link of the node to the next of current
                }
                delete current;
            }
        }
    }

    void append (T data) { // Append a node to the dll

        dllNode<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        dllNode<T>* temp = new dllNode<T>(data);
        current->next = temp;
        temp->prev = current;
    }

    void printList () { // Display all the nodes
        dllNode<T>* current = head;
        while (current != nullptr) {
            cout << current->data << ", ";
            current = current->next;
        }
        cout << endl<<endl;
    }

    int search(T x){
        dllNode<T>* temp = head;
        int pos = 0;
        while (temp->data != x && temp->next != nullptr){
            pos++;
            temp = temp->next;
        }

        if (temp->data != x){
            return -1;
        }

        return (pos + 1);
    }


    void freeList () {
        while (head != nullptr) {
            dllNode<T> * temp = head->next;
            delete head;
            head = temp;
        }
    }

    int countItem(T itemName){
        int count = 0;
        dllNode<T>* current = head;
        while(current!=NULL){
            if(current->data == itemName){
                count++;
            }
            current = current->next;
        }
        return count;
    }
};
