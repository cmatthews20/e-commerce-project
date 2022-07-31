#ifndef PROJECTS_STACK_H
#define PROJECTS_STACK_H
#include <iostream>
#define MAX 100

template<typename T>
class Stack {
private:
    int top;
public:
    T a[MAX]; // Max size of Stack
    Stack(){ top = -1;} // Default constructor
    bool push(T x);
    T pop();
    T peek();
};

#endif //PROJECTS_STACK_H

// END OF FILE