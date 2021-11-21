
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
    ~Stack();

    void push(T value);
    T pop();
    bool empty() { return (counter == 0); }
    int size() {return counter; }
    void clear();
    void print();
};

template<typename T>
Stack<T>::~Stack()
{
    cout << "\nstack is destroyed " << endl;
    clear();
}

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
T Stack<T>::pop()
{
    if(counter == 0)
        throw runtime_error("No elements to remove!");
    
    T result = head->data;
    node* killer = head;

    head = head->next;
    if(head == nullptr)
        tail = nullptr;

    delete killer;


    --counter;
    return result;
}

template<typename T>
void Stack<T>::print()
{
    if(counter == 0)
        cout << "\nEmpty " << endl;
    node* walker = head;

    while(walker != nullptr)
    {
        cout << walker->data << " -> ";
        walker = walker->next;
    }
    cout << " | " << endl;
}

template<typename T>
void Stack<T>::clear()
{
    while (counter > 0)
    {
        node* killer = head;
        head = head->next;
        delete killer;
    }
    tail = nullptr;
    counter = 0;
    
}