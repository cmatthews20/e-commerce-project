// Template not verified
// Class not verified
// Correct operation last verified around 7:30 PM saturday

#include "stack.h"

template<typename T>
bool stack<T>::push(T x) {
    if(top>= (MAX -1)){ // If stack full
        std::cout << "Stack Overflow";
        return false;
    }else{
        a[++top] = x;
        //std::cout << x << " pushed into stack\n";
        return true;
    }
}

template<typename T>
T stack<T>::pop() {
    if(top<0){ // If stack empty
        std::cout<<"Stack Underflow";
    }else{
        T x = a[top--];
        return x;
    }
}

template<typename T>
T stack<T>::peek() {
    if(top<0){
        std::cout<<"Stack is Empty";
        return 0;
    }else{
        T x = a[top];
        return x;
    }
}

// END OF FILE