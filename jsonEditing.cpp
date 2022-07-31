//#include <iostream>
//#include "jsoncpp/include/json/json.h"
//#include "jsoncpp/include/json/value.h"
//#include <fstream>
//
//using namespace std;
//
//void updateCount(string newCount, string itemKey) {
//    ofstream writeFile;
//    Json::StyledStreamWriter writer; // for writing in json files
//    Json::Value newNewValue;
//    Json::Reader nreader;             // for reading the data
//    ifstream nfile("inventory.json");
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
//            if (item["Count"].asString() == dat.asString()) {
//                cout << dat << endl;
//                item["Count"] = newCount;
//                newNewValue[itemKey] = item;
//            } else {
//                continue;
//            }
//        }
//    }
//
//    writeFile.open("items.json");
//    writer.write(writeFile, newNewValue);
//    writeFile.close();
//
//}
////
////int jsonRead() {
////    Json::Reader reader;             // for reading the data
////    Json::Value newValue;            // for modifying and storing new values
////    Json::Value message;
////    int x;
////
////    ifstream file("items.json");
////
////    // check if there is any error is getting data from the json file
////    if (!reader.parse(file, newValue)) {
////        cout<< "error in jsonRead" << endl;
////        cout << reader.getFormattedErrorMessages();
////        exit(1);
////    }
////    for (auto msg: newValue) {
////        cout << newValue << endl;
////        for (auto dat: msg) {
////            if (msg[" Name"] == dat) {
////                cout << "Name: " << dat.asString() << endl;
////            } else if (msg["Category"] == dat) {
////                cout << "Category: " << dat.asString() << endl;
////            } else if (msg["Price"] == dat) {
////                cout << "Price: " << stoi(dat.asString()) << endl;
////            } else if (msg["Expiry Date"] == dat) {
////                cout << "Expiry Date: " << dat.asString() << endl;
////            } else if (msg["Count"] == dat) {
////                x = stoi(dat.asString());
////                cout << "Count: " << x << endl;
////            }
////        }
////        cout << "\n";
////    }
////    // make the changes in a new file/original file
//////    ifstream newFile;
//////
//////    if (!reader.parse(newFile, newValue)) {
//////        cout << reader.getFormattedErrorMessages();
//////        exit(1);
//////    }
////    updateCount("4","0");
////    return 0;
////}
