#include "Stack.h"

template<typename T>
bool Stack<T>::push(T x) {
    if(top>= (MAX -1)){ // If Stack full
        std::cout << "Stack Overflow";
        return false;
    }else{
        a[++top] = x;
        return true;
    }
}

template<typename T>
T Stack<T>::pop() {
    if(top<0){ // If Stack empty
        return 0;
    }else{
        T x = a[top--];
        return x;
    }
}

template<typename T>
T Stack<T>::peek() {
    if(top<0){
        return 0;
    }else{
        T x = a[top];
        return x;
    }
}
