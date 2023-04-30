#ifndef _LISTARR
#define _LISTARR
#include <iostream>

using namespace std;

class ListArr{
    private:
    struct Node {
        int *arr;
        int capacidad;
        int num_elements;
        Node *next;
        
        Node(int capacidad, Node* next=nullptr) {
            this->capacidad = capacidad;
            this->next = next;
            num_elements = 0;
            arr = new int[capacidad];
        }
        
        ~Node() {
            delete[] arr;
        }
    };
    
    int b;
    int num_elements;
    Node *head;

public:
    ListArr(int);
    virtual int size() = 0;
    virtual int delete_left() = 0;
    virtual int delete_right() = 0;
    virtual void insert_left(int v) = 0;
    virtual void insert_right(int v) = 0;
    virtual void insert(int v, int i) = 0;
    virtual void print() = 0;
    virtual bool find(int v) = 0;

};

#endif