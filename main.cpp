#include <iostream>
#include "linkedList.cpp"
#include "dll.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "jsoncpp/include/json/json.h"
#include "jsoncpp/include/json/value.h"
#include <fstream>
#include <string>
using namespace std;

// Inserts a given node at its correct sorted position into a given
// list sorted in increasing order
template<typename T,typename T1>
void sortedInsertPrice(Node<T,T1>** head, Node<T, T1>* newNode)
{
    Node<T,T1> dummy;
    Node<T,T1>* current = &dummy;
    dummy.next = *head;

    while (current->next != NULL && current->next->price < newNode->price) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}

// Given a list, change it to be in sorted order (using `sortedInsert()`).
template<typename T,typename T1>
void insertSortPrice(Node<T, T1>** head)
{
    Node<T,T1>* result = NULL;     // build the answer here
    Node<T,T1>* current = *head;   // iterate over the original list
    Node<T,T1>* next;

    while (current != NULL)
    {
        // tricky: note the next pointer before we change it
        next = current->next;

        sortedInsertPrice(&result, current);
        current = next;
    }

    *head = result;
}

// Function to insert a given node at its correct sorted position into a given
// list sorted in increasing order
template<typename T,typename T1>
void sortedInsertExp(Node<T,T1>** head, Node<T,T1>* newNode)
{
    Node<T,T1> dummy;
    Node<T,T1>* current = &dummy;
    dummy.next = *head;

    while (current->next != NULL && current->next->expDate < newNode->expDate) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}

// Given a list, change it to be in sorted order (using `sortedInsert()`).
template<typename T,typename T1>
void insertSortExp(Node<T,T1>** head)
{
    Node<T,T1>* result = NULL;     // build the answer here
    Node<T,T1>* current = *head;   // iterate over the original list
    Node<T,T1>* next;

    while (current != NULL)
    {
        // tricky: note the next pointer before we change it
        next = current->next;

        sortedInsertExp(&result, current);
        current = next;
    }

    *head = result;
}

void updateCount(const string& newCount, string itemKey) {
    ofstream writeFile;
    Json::StyledStreamWriter writer; // for writing in json files
    Json::Value newNewValue;
    Json::Reader nreader;             // for reading the data
    ifstream nfile("inventory.json");

    // check if there is any error is getting data from the json file
    if (!nreader.parse(nfile, newNewValue)) {
        cout << "STOOOOOP" << endl;
        cout << nreader.getFormattedErrorMessages();
        exit(1);
    }

    for (auto item: newNewValue) {
        for (auto dat: item) {
            if (item["Count"].asString() == dat.asString()) {
                cout << dat << endl;
                item["Count"] = newCount;
                newNewValue[itemKey] = item;
            } else {
                continue;
            }
        }
    }

    writeFile.open("items.json");
    writer.write(writeFile, newNewValue);
    writeFile.close();
}

//newCust is string for name, string index is an iterator, itemkey doesnt change
void updateCust(const string& newCust, const string& custIndex, const string& itemKey = "Customers") {
    ofstream writeFile;
    Json::StyledStreamWriter writer; // for writing in json files
    Json::Value newNewValue;
    Json::Reader nreader;             // for reading the data
    ifstream nfile("C:\\Users\\Keegan\\Documents\\Github\\ECE4400-Project\\ECE4400-E-Commerce-Project\\cmake-build-debug\\.bin\\customers.json");

    // check if there is any error is getting data from the json file
    if (!nreader.parse(nfile, newNewValue)) {
        cout << "STOOOOOP" << endl;
        cout << nreader.getFormattedErrorMessages();
        exit(1);
    }

    for (auto item: newNewValue) {
        for (auto dat: item) {
            if (item[custIndex].asString() == dat.asString()) {
                //cout << dat << endl;
                item[custIndex] = newCust;
                newNewValue[itemKey] = item;
            } else {
                continue;
            }
        }
    }

    writeFile.open("C:\\Users\\Keegan\\Documents\\Github\\ECE4400-Project\\ECE4400-E-Commerce-Project\\cmake-build-debug\\.bin\\customers.json");
    writer.write(writeFile, newNewValue);
    writeFile.close();
}

// newCust is the index of customers, custName is the customers name
//void updateCust(const string& newCust, const string& custName) {
//    ofstream writeFile;
//    Json::StyledStreamWriter writer; // for writing in json files
//    Json::Value newNewValue;
//    Json::Reader nreader;             // for reading the data
//    ifstream nfile("customers.json");
//
//    // check if there is any error is getting data from the json file
//    if (!nreader.parse(nfile, newNewValue)) {
//        cout << "STOOOOOP" << endl;
//        cout << nreader.getFormattedErrorMessages();
//        exit(1);
//    }
//
//    for (auto item: newNewValue) {
//        for (auto dat: item) {
//            if (newCust == dat.asString()) {
//                cout << dat << endl;
//                item[newCust] = custName;
//                newNewValue[custName] = item;
//            } else {
//                continue;
//            }
//        }
//    }
//
//    writeFile.open("customers.json");
//    writer.write(writeFile, newNewValue);
//    writeFile.close();
//}
int main() {
//    jsonRead();

    // Inventory init (linked list)
    linkedList<std::string, int> inventory;
    inventory.append("Bob-Burger", 21, "2023/07/12", 4, "Deli");
    inventory.append("Kirkland-Kabob", 1738, "2022/03/23", 5, "Deli");
    inventory.append("Amr-Ale", 2025, "2024/02/02", 5, "Beverage");
    inventory.append("Shair-Sauce", 19, "2024/03/16", 5, "Beverage");
    inventory.append("Keegan-Kiwi", 18, "2024/02/14", 5, "Produce");
    inventory.append("Agwad-Apple", 4400, "2022/07/31", 5, "Produce");
    inventory.append("Cole'slaw", 100, "2023/05/17", 7, "Produce");
    inventory.append("Robert-Fudge", 40, "2023/05/23", 5, "Snack");
    inventory.append("Fares-Feta", 44, "2023/01/12", 5, "Snack");
    inventory.append("Noah-Nachos", 3, "2019/03/15", 5, "Snack");

    // Customer history init (Circular Queue)
    queue<std::string> customerHistory(3);

    // Vars for later
    Node<std::string, int>* head = inventory.getHead();
    std::string menu;
    std::string search;
    std::string change;
    std::string customer;
    float total;
    bool again = true;

    while(again){ // MAIN PROGRAM LOOP

        // Cart init (doubly linked list)
        dll<std::string> cart;

        std::cout << "Welcome to the store. Please input your name: "; std::cin >> customer; std::cout << std::endl;
        customerHistory.enQueue(customer); // Add customer to Circular queue

        inventory.printList(); // Print inventory to start session
        while(true){
            std::cout << "OPTIONS: Show Inventory = S  |  Sort by Price = P  |  Sort by Expiry = E  |  Add item = A  |  Remove item = R \n |  Filter = F  |  |  Count Item = C  |  Display Cart = D  |  Checkout = X\n\n"<<"Enter: ";
            std::cin >> menu; std::cout << std::endl;
            if(menu=="S"){
                inventory.printList(); // Print inventory
            }
            if(menu=="P"){
                insertSortPrice(&head);
                std::cout << "Inventory Sorted by Price!\n\n";
                inventory.printList(); // Print inventory
            }
            if(menu=="E"){
                insertSortExp(&head);
                std::cout << "Inventory Sorted by Expiry!\n";
                inventory.printList(); // Print inventory
            }
            if(menu=="A"){
                std::cout << "What would you like to add?: ";
                std::cin >> change; std::cout << std::endl;
                if(cart.getHead() == NULL){cart.createHead(change);}
                else{
                    cart.append(change);
                }
                std::cout << change << " Added!"<<std::endl<<"Current Cart: ";
                cart.printList();
            }
            if(menu=="R"){
                std::cout << "What would you like to remove?: ";
                std::cin >> change; std::cout << std::endl;
                cart.deleteNode(change);
                std::cout << change << " Removed!"<<std::endl<<"Current Cart: ";
                cart.printList();
            }
            if(menu=="F"){
                std::cout << "Filter by Type:"; std::cin >> search; std::cout << std::endl;
                std::cout << "Filter Applied!\n";
                inventory.displayCategory(search);
            }
            if(menu=="C"){

            }
            if(menu=="D"){
                std::cout<<"Current Cart: ";
                cart.printList();
            }
            if(menu=="X"){
                std::cout << "Thank you for Shopping with us :)\n\n Your Cart: ";
                cart.printList();
                break;
            }
        }

        while(true){ // Next customer decision loop
            std::cout<< "Next customer? (y/n): "; std::cin>>customer; std::cout<<std::endl;
            if(customer == "y"){
                break;
            }
            if(customer == "n"){
                again = false;
                break;
            }
        }
        cart.freeList();
    }


    customer = "init";
    std::cout<<"Today's Shoppers: ";
    int custIndex = 1;
    while(true){
        customer = customerHistory.deQueue();
        if(customer != "empty") {
            updateCust(customer,to_string(custIndex));
            custIndex++;
            std::cout << customer << ", ";

        } else
            break;
    }

    std::cout<<std::endl;




    // Queue tests
//    queue<std::string> q(3);
//
//    // Inserting elements in Circular Queue
//    q.enQueue("Cole");
//    q.enQueue("Cole");
//    q.enQueue("Bob");
//    q.enQueue("Keegs");
//    q.enQueue("Kirk");

    // Display elements present in Circular Queue
//    q.displayQueue();

    // Deleting elements from Circular Queue
//    q.deQueue();
//    q.displayQueue();


    //DLL tests
//    dllNode<std::string> *head;
//    dll<std::string> sampleList;
//    sampleList.append(&head, "Mike McCarthy's Hard Lemonade");
//    sampleList.append(&head, "Thumeera Thin Crust Pizza");
//    sampleList.append(&head, "WorcesterSHAIR Sauce");
//    sampleList.append(&head, "Amr's Almond Milk");
//    sampleList.append(&head, "Malcolm's Milkshake");
//    sampleList.append(&head, "Misha's Mystery Meat");
//    std::cout<<sampleList.search(&head, "Thumeera Thin Crust Pizza");
//    sampleList.printList(head); // Print list

//    sampleList.deleteNode(&head, head->next); // Delete the second node
//    std::cout<< "\nDelete Node!\n";
//    sampleList.printList(head); // Print list again to show result



    // Stack tests
//    stack<int> sampleStack;
//    sampleStack.push(1);
//    sampleStack.push(2);
//    sampleStack.push(3);
//    std::cout << sampleStack.pop()<<std::endl;
//    std::cout << sampleStack.pop()<<std::endl;
//    std::cout << sampleStack.pop()<<std::endl;




    return 0;
}
