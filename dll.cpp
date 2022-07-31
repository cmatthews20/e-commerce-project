
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

    dll () {
        head = nullptr;
    }

    // Return the head node.
    dllNode<T> * getHead () {
        return head;
    }

    // Create a head node of the doubly linked list.
    void createHead (T data) {
        head = new dllNode<T>(data);
    }

    // Insert a new node into the doubly-linked list after the first found node.
    void insert (T data, int after) {

        dllNode<T>* current = head;

        // Traverse the linked list till the node is found after
        // which the data is to be insert
        while (current != nullptr && current->data != after) {
            current = current->next;
        }

        if (current != nullptr) {
            dllNode<T> * temp = new dllNode<T>(data);
            // Save the location of node after current in next_node.
            dllNode<T> * next_node = current->next;
            // Point current's link to the new node to be inserted.
            current->next = temp;

            // Point new node's next link (to the next node location previously stored).
            // left link to the current node.
            temp->prev  = current;
            temp->next = next_node;

            // Point next node's prev to the newly added node i.e temp.
            if (next_node != nullptr)
                next_node->prev = temp;
        }
    }

    // Delete the first node matching the data from the doubly linked list.
    void deleteNode (T data_to_be_deleted) {

        // If the head node is to be deleted, then the node to the next of head becomes the head node.
        if (head->data == data_to_be_deleted ) {
            dllNode<T> * temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
        } else {
            dllNode<T> * current = head;
            while (current->data != data_to_be_deleted ) {
                current = current->next;
            }
            // current is to be deleted.
            if (current != nullptr) {
                current->prev->next = current->next; // Update the next link of the node previous of current
                if (current->next != nullptr) {
                    current->next->prev = current->prev; // Update the previous link of the node to the next of current
                }
                delete current;
            }
        }
    }

    // Append a node to the doubly linked list.
    void append (T data) {

        dllNode<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        dllNode<T>* temp = new dllNode<T>(data);
        current->next = temp;
        temp->prev = current;
    }

    // Display all the nodes in the doubly linked list.
    void printList () {

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

    // Free the linked list.
    void freeList () {

        while (head != nullptr) {
            dllNode<T> * temp = head->next;
            delete head;
            head = temp;
        }
    }
};