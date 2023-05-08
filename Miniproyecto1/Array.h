#include "ADTlistArr.h"
#include <iostream>

class Array: public ADTlistArr {
private:
    int* arr;
    int num_elements;
    int capacity;
public:
    Array(int capacity);
    void insert_left(int v);
    void insert_right(int v);
    bool find(int v);
    int size();
    int delete_left();
    int delete_right();
    void insert(int v, int i);
    void print();

}; 

//todo weno