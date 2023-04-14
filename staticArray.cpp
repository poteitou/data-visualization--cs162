#include "staticArray.hpp"

staticArray::staticArray() {
    array = new int[0];
    size = 0;
}

staticArray::staticArray(int size) 
{
    array = new int[size];
    this->size = size;
}

staticArray::staticArray(int size, int* data) 
{
    array = new int[size];
    this->size = size;
    for (int i = 0; i < size; i++) {
        array[i] = data[i];
    }
}

staticArray::staticArray(const staticArray& other) 
{
    array = new int[other.size];
    size = other.size;
    for (int i = 0; i < size; i++) 
    {
        array[i] = other.array[i];
    }
}

staticArray::~staticArray() 
{
    delete[] array;
}

void staticArray::add(int element) 
{
    expandArray();
    array[size-1] = element;
}

void staticArray::insert(int index, int element) 
{
    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    expandArray();
    for (int i = size-1; i > index; i--) {
        array[i] = array[i-1];
    }
    array[index] = element;
}

void staticArray::remove(int index) 
{
    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size-1; i++) 
    {
        array[i] = array[i+1];
    }
    size--;
    int* temp = new int[size];
    for (int i = 0; i < size; i++) 
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

void staticArray::update(int index, int element) 
{
    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    array[index] = element;
}

int staticArray::search(int element) const 
{
    for (int i = 0; i < size; i++) 
    {
        if (array[i] == element) 
        {
            return i;
        }
    }
    return -1;
}

int staticArray::getSize() const 
{
    return size;
}

int staticArray::getElement(int index) const 
{
    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

void staticArray::setElement(int index, int element) 
{
    if (index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    array[index] = element;
}

void staticArray::expandArray() 
{
    int* temp = new int[size+1];
    for (int i = 0; i < size; i++) 
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size++;
}

