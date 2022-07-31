// Template not verified
// Class not verified
// Correct operation last verified at 8:08 PM saturday

#include "queue.h"

template<typename T>
void queue<T>::enQueue(T value) {

    if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){ // If queue full
        //std::cout<<"\nQueue is Full";
        deQueue();
        enQueue(value);
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

template<typename T>
T queue<T>::deQueue() {
    if (front == -1){
        //printf("\nQueue is Empty");
        return "empty";
    }

    T data = arr[front];
    arr[front] = -1;
    if (front == rear){
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;
}

template<typename T>
void queue<T>::displayQueue() {
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            std::cout<<arr[i] << ", ";
    }
    else
    {
        for (int i = front; i < size; i++)
            std::cout<<arr[i]<< ", ";

        for (int i = 0; i <= rear; i++)
            std::cout<<arr[i]<< ", ";
    }
}
