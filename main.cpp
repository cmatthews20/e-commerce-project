#include <iostream>
#include "linkedList.cpp"
#include "dll.cpp"
#include "Stack.cpp"
#include "queue.cpp"
#include "jsoncpp/include/json/json.h"
#include "jsoncpp/include/json/value.h"
#include <fstream>
#include <string>

using namespace std;

// Insert given node at its correct sorted position into list sorted in increasing order
template<typename T, typename T1>
void sortedInsertPrice(Node<T, T1> **head, Node<T, T1> *newNode) {
    Node<T, T1> dummy;
    Node<T, T1> *current = &dummy;
    dummy.next = *head;

    while (current->next != nullptr && current->next->price < newNode->price) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}

// Sort list by price and actually move nodes
template<typename T, typename T1>
void insertSortPrice(Node<T, T1> **head) {
    Node<T, T1> *result = nullptr;     // build the answer here
    Node<T, T1> *current = *head;   // iterate over the original list
    Node<T, T1> *next;

    while (current != nullptr) {
        next = current->next;// store the next pointer before changing it
        sortedInsertPrice(&result, current);
        current = next;
    }

    *head = result;
}

template<typename T, typename T1>
void sortedInsertExp(Node<T, T1> **head, Node<T, T1> *newNode) {
    Node<T, T1> dummy;
    Node<T, T1> *current = &dummy;
    dummy.next = *head;

    while (current->next != nullptr && current->next->expDate < newNode->expDate) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}

// Sort list by espiry date and actually move nodes
template<typename T, typename T1>
void insertSortExp(Node<T, T1> **head) {
    Node<T, T1> *result = nullptr;     // build the answer here
    Node<T, T1> *current = *head;   // iterate over the original list
    Node<T, T1> *next;

    while (current != nullptr) {
        // tricky: note the next pointer before we change it
        next = current->next;

        sortedInsertExp(&result, current);
        current = next;
    }

    *head = result;
}


//newCust is string for name, string index is an iterator, itemkey doesnt change
template<typename T>
void updateCust(const T &newCust, const T &custIndex, const T &itemKey = "Customers") {
    ofstream writeFile;
    Json::StyledStreamWriter writer; // for writing in json files
    Json::Value newNewValue;
    Json::Reader nreader;             // for reading the data
    ifstream nfile(
            R"(C:\Users\Keegan\Documents\Github\ECE4400-Project\ECE4400-E-Commerce-Project\cmake-build-debug\.bin\customers.json)");

    // check if there is any error is getting data from the json file
    if (!nreader.parse(nfile, newNewValue)) {
        cout << "STOOOOOP" << endl;
        cout << nreader.getFormattedErrorMessages();
        exit(1);
    }

    for (auto item: newNewValue) {
        for (const auto &dat: item) {
            if (item[custIndex].asString() == dat.asString()) {
                //cout << dat << endl;
                item[custIndex] = newCust;
                newNewValue[itemKey] = item;
            } else {
                continue;
            }
        }
    }

    writeFile.open(
            R"(C:\Users\Keegan\Documents\Github\ECE4400-Project\ECE4400-E-Commerce-Project\cmake-build-debug\.bin\customers.json)");
    writer.write(writeFile, newNewValue);
    writeFile.close();
}

template<typename T, typename T1>
linkedList<T, T1> jsonReadFill(linkedList<T, T1> inventory) {
    Json::Reader reader;             // for reading the data
    Json::Value newValue;            // for modifying and storing new values
    Json::Value message;
    T Name, Category, ExpDate;
    T1 Count, Price;

    ifstream file(
            R"(C:\Users\Keegan\Documents\Github\ECE4400-Project\ECE4400-E-Commerce-Project\cmake-build-debug\.bin\inventory.json)");

    // check if there is any error is getting data from the json file
    if (!reader.parse(file, newValue)) {
        cout << "error in jsonRead" << endl;
        cout << reader.getFormattedErrorMessages();
        exit(1);
    }
    for (auto msg: newValue) {
//        cout << "msg: " << msg << endl;
        for (const auto &dat: msg) {
//            cout << "dat: " << dat << endl;
            if (msg["1Name"] == dat) {
                Name = dat.asCString();
            } else if (msg["5Category"] == dat) {
                Category = dat.asCString();
            } else if (msg["2Price"] == dat) {
                Price = stoi(dat.asCString());
            } else if (msg["3Expiry Date"] == dat) {
                ExpDate = dat.asCString();
            } else if (msg["4Count"] == dat) {
                Count = stoi(dat.asCString());
            }
        }
//        cout << Name << ", " << Category << ", " << Price << ", " << ExpDate << ", " << Count << endl;
        inventory.append(Name, Price, ExpDate, Count, Category);
    }
//    inventory.printList();
    return inventory;
}

int main() {
    // Reset customers.json to blank
    for (int i = 1; i <= 3; i++)
        updateCust<string>("_", to_string(i));

    // fill SLL with the contents of inventory.json
    linkedList<std::string, int> inventory;
    inventory = jsonReadFill<string, int>(inventory);

    // Customer history init (Circular Queue)
    queue<std::string> customerHistory(3);

    // Receipt/Tab init (Stack)
    Stack<int> tabStack;

    // Vars for later
    Node<std::string, int> *head = inventory.getHead();
    std::string menu;
    std::string countCheck;
    std::string search;
    std::string change;
    std::string customer;

    bool again = true;

    while (again) { // MAIN PROGRAM LOOP

        // Cart init (doubly linked list)
        dll<std::string> cart;
        int total = 0;
        std::cout << "Welcome to the Gimmick Gallery. Please input your name: ";
        std::cin >> customer;
        std::cout << std::endl;
        customerHistory.enQueue(customer); // Add customer to Circular queue

        inventory.printList(); // Print inventory to start session
        while (true) {
            std::cout
                    << "OPTIONS:\n"
                    << "| Show Inventory = S | Sort by Price = P | Sort by Expiry = E | Add item = A | Remove item = R |\n| Filter = F | Count Item = C | Display Cart = D | Checkout = X |\n\n"
                    << "Enter: ";
            std::cin >> menu;
            std::cout << std::endl;
            string emptyString = "";
            for (auto ch: menu)
                emptyString.push_back(toupper(ch));
            menu = emptyString;

            if (menu == "S") {
                inventory.printList(); // Print inventory
            }
            if (menu == "P") {
                insertSortPrice(&head);
                std::cout << "Inventory Sorted by Price!\n\n";
                inventory.printList(); // Print inventory
            }
            if (menu == "E") {
                insertSortExp(&head);
                std::cout << "Inventory Sorted by Expiry!\n";
                inventory.printList(); // Print inventory
            }
            if (menu == "A") {
                std::cout << "What would you like to add?: ";
                std::cin >> change;
                std::cout << std::endl;
                std::cout << "How many " << change << " would you like to add?: ";
                int amount;
                std::cin >> amount;
                std::cout << std::endl;
//                amount = isdigit(amount);

                if (inventory.itemExists(change)) {
                    if(((cart.countItem(change)+1)*amount) <= inventory.getCount(change)){
                        for (int i = 0;i<amount;i++) {
                            if (cart.getHead() == nullptr) { cart.createHead(change); }
                            else {
                                cart.append(change);
                            }
                            tabStack.push(inventory.getPrice(change)); // Add to tab
                        }
                        std::cout << amount << " " << change << " Added!" << std::endl << "Current Cart: ";
                        cart.printList();
                    }else{
                        std::cout << "Sorry, We don't have " << amount << " of that item. You cannot add it to your cart." <<
                        std::endl << "Current Cart: ";
                        cart.printList();
                    }

                } else {
                    std::cout << "Item not in inventory!\n\n";
                }
            }
            if (menu == "R") {
                std::cout << "What would you like to remove?: ";
                std::cin >> change;
                std::cout << std::endl;
                if(cart.countItem(change) > 0){
                    cart.deleteNode(change);
                    // Remove price check
                    tabStack.push(-1*(inventory.getPrice(change))); // remove price from tab
                    std::cout << change << " Removed!" << std::endl << "Current Cart: ";

                }else{
                    std::cout << change << " Not in cart." << std::endl << "Current Cart: ";
                }
                cart.printList();
            }
            if (menu == "F") {
                std::cout << "Filter by Type:";
                std::cin >> search;
                std::cout << std::endl;
                std::cout << "Filter Applied!\n";
                inventory.displayCategory(search);
            }
            if (menu == "C") {
                // Count items
                std::cout << "What cart item would you like to count?: ";
                std::cin >> countCheck;
                std::cout << std::endl;
                std::cout<< "There are "<<cart.countItem(countCheck)<<" "<< countCheck<< " in your cart right now.\n\n";
            }
            if (menu == "D") {
                std::cout << "Current Cart: ";
                cart.printList();
            }
            if (menu == "X") {
                std::cout << "Thank you for Shopping with us :)\n\nYour Cart: ";
                cart.printList();
                while(tabStack.peek()!=0){
                    total = total + tabStack.pop();
                }
                std::cout<<"\nYour total is: $"<<total<<std::endl;

                Node<std::string, int> *current = inventory.getHead(); // to iterate thru inventory

                while(current!=NULL){
                    int numInCart = cart.countItem(current->item);
                    current->count = current->count - numInCart;
                    current=current->next;
                }

                break;
            }
        }

        while (true) { // Next customer decision loop
            std::cout << "Next customer? (y/n): ";
            std::cin >> customer;
            std::cout << std::endl;
            if (customer == "y") {
                break;
            }
            if (customer == "n") {
                again = false;
                break;
            }
        }
        cart.freeList();
    }

    customer = "init";
    std::cout << "Today's Shoppers: ";
    int custIndex = 1;
    while (true) {
        customer = customerHistory.deQueue();
        if (customer != "empty") {
            updateCust(customer, to_string(custIndex));
            custIndex++;
            std::cout << customer << ", ";

        } else
            break;
    }

    std::cout << std::endl;

    return 0;
}

// Manual inventory creation
//    inventory.append("Bob-Burger", 21, "2023/07/12", 4, "Deli");
//    inventory.append("Kirkland-Kabob", 1738, "2022/03/23", 5, "Deli");
//    inventory.append("Amr-Ale", 2025, "2024/02/02", 5, "Beverage");
//    inventory.append("Shair-Sauce", 19, "2024/03/16", 5, "Beverage");
//    inventory.append("Keegan-Kiwi", 18, "2024/02/14", 5, "Produce");
//    inventory.append("Agwad-Apple", 4400, "2022/07/31", 5, "Produce");
//    inventory.append("Cole'slaw", 100, "2023/05/17", 7, "Produce");
//    inventory.append("Robert-Fudge", 40, "2023/05/23", 5, "Snack");
//    inventory.append("Fares-Feta", 44, "2023/01/12", 5, "Snack");
//    inventory.append("Noah-Nachos", 3, "2019/03/15", 5, "Snack");

// END OF FILE