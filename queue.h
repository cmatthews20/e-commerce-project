// Template not verified
// Class not verified
// Correct operation last verified at 8:08 PM saturday

#ifndef PROJECTS_QUEUE_H
#define PROJECTS_QUEUE_H
#include <iostream>

template<typename T>
class queue {
    int rear, front, size;
    T* arr;

public:
    queue(int s){
        front = rear = -1;
        size = s;
        arr = new T[s];
    }
    void enQueue(T value);
    T deQueue();
    void displayQueue();

};




#endif //PROJECTS_QUEUE_H
