#ifndef _LISTARR
#define _LISTARR
#include <iostream>

class ListArr{
    
private:
    struct Node{
        int *arr;
        int b;
        int num_elements;
        Node *next;

        Node(int b)
        {
            this->b = b;
            next = nullptr;
            num_elements = 0;
            arr = new int[b];
        }

        ~Node()
        {
            delete[] arr;
        }
    };

    

    int b;
    int num_elements;
    Node *head;

public:
struct NodeSummary{
        int total_capacity;
        int total_size;
        NodeSummary *left_child;
        NodeSummary *right_child;
    };

    virtual int size() = 0;
    virtual int delete_left() = 0;
    virtual int delete_right() = 0;
    virtual void insert_left(int v) = 0;
    virtual void insert_right(int v) = 0;
    virtual void insert(int v, int i) = 0;
    virtual void print() = 0;
    virtual bool find(int v) = 0;

    NodeSummary createNodeSummary(Node* left, Node* right);
};

#endif