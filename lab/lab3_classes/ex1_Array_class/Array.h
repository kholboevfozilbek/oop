
#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Array
{
    private:
    T* arr;
    unsigned int length=0;

    public:

    Array(unsigned int s=5);
    ~Array();

    unsigned int size() {return length; }
    void read();
    void print();
    float avg();
    T min();
    T max();
    void reverse();
    
};

template<typename T>
Array<T>::Array(unsigned int s)
{
    if(s <= 0)
        throw runtime_error("Array size can not be 0!");
    length = s;
    arr = new T[length]{};
    cout << "\n\nArray has been created " << endl;
}

template<typename T>
Array<T>::~Array()
{
    if(length > 0)
    {
        delete[] arr;
    }
    cout << "\n\nArray has been destroyed " << endl;
}

template<typename T>
void Array<T>::read()
{
    cout << "\n\nPlease enter the elemenets of the array:  \n"; 
    for (size_t i = 0; i < length; i++)
    {
        cout << ": ";
        cin >> arr[i];
    }
    
}

template<typename T>
void Array<T>::print()
{
    for (size_t i = 0; i < length; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

template<typename T>
float Array<T>::avg()
{
    float sum = 0.0f;
    for (size_t i = 0; i < length; i++)
        sum += arr[i];
    return sum / length;
}

template<typename T>
T Array<T>::min()
{
    T minn = arr[0];
    for (size_t i = 0; i < length; i++)
        if(arr[i] < minn)
            minn  = arr[i];
    
    return minn;
}

template<typename T>
T Array<T>::max()
{
    T maxx = arr[0];
    for (size_t i = 0; i < length; i++)
        if(arr[i] > maxx)
            maxx  = arr[i];
    
    return maxx;
}

template<typename T>
void Array<T>::reverse()
{
    if(length % 2 != 0)
        for (size_t i = 0, j=length-1; i < length/2 && j > length/2; ++i, j--)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    else
        for (size_t i = 0, j=length-1; i < length/2 && j >= length/2; ++i, j--)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } 
    
}

#endif