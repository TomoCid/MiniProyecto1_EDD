//#include "ADTlistArr.h"
#include <iostream>

class Array  {
private:
    int* arr;
    int num_elements;
    int capacity;
public:
    Array(int capacity);
    void insert_left(int v);
    void insert_right(int v);
    bool find(int v);

};