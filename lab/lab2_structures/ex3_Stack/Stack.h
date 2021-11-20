
#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack
{
    private:
    struct node{
        T data;
        node* next;
        node(T D, node* N=nullptr)
        {
            data = D; 
            next = N;
        }
    };
    node* head = nullptr;
    node* tail = nullptr;
    int counter = 0;

    public:

    Stack() = default;
    void push(T value);
    void pop();

    void print();
};

template<typename T>
void Stack<T>::push(T value)
{
    node* n = new node(value, head);

    if(head == nullptr)
        tail = n;
    
    head = n;
    ++counter;

}

template<typename T>
void Stack<T>::print()
{
    node* walker = head;

    while(walker != nullptr)
    {
        cout << walker->data << " -> ";
        walker = walker->next;
    }
    cout << " | " << endl;
}