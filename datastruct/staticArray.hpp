#ifndef STATICARRAY_HPP
#define STATICARRAY_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

class staticArray 
{
public:
    staticArray();
    staticArray(int size);
    staticArray(int size, int* data);
    staticArray(const staticArray& other);
    ~staticArray();

    void add(int element);
    void insert(int index, int element);
    void remove(int index);
    void update(int index, int element);
    int search(int element) const;

    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int element);

private:
    int* array;
    int size;

    void expandArray();
};

#endif // STATICARRAY_HPP
