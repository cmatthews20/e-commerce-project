// Template not verified
// Class not verified
// Correct operation last verified around 7:30 PM saturday

#ifndef PROJECTS_STACK_H
#define PROJECTS_STACK_H
#include <iostream>
#define MAX 100

template<typename T>
class stack {
private:
    int top;
public:
    T a[MAX]; // Max size of stack
    stack(){top = -1;} // Default constructor
    bool push(T x);
    T pop();
    T peek();
};

#endif //PROJECTS_STACK_H

// END OF FILE