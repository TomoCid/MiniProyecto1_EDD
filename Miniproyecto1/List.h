#include "ADTlistArr.h"
#include <iostream>

class List {
private:
    struct Node{
        int data;
        Node* next;
        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
    int num_elements;
    Node* head;
public:
    List();
    void insert_left(int v);
    void insert_right(int v);
    bool find(int v);
    int size();
    int delete_left();
    int delete_right();
    void insert(int v, int i);
    void print();
};