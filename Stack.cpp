#include "Stack.h"

template<typename T>
bool Stack<T>::push(T x) {
    if(top>= (MAX -1)){ // If Stack full
        std::cout << "Stack Overflow";
        return false;
    }else{
        a[++top] = x;
        //std::cout << x << " pushed into Stack\n";
        return true;
    }
}

template<typename T>
T Stack<T>::pop() {
    if(top<0){ // If Stack empty
        //std::cout<<"Stack Underflow";
        return 0;
    }else{
        T x = a[top--];
        return x;
    }
}

template<typename T>
T Stack<T>::peek() {
    if(top<0){
        //std::cout<<"Stack is Empty";
        return 0;
    }else{
        T x = a[top];
        return x;
    }
}

// END OF FILE