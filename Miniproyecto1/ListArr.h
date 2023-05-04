#ifndef _LISTARR
#define _LISTARR
#include <iostream>

class ListArr{

public:
    struct Node{
        int *arr;
        int capacity;
        int num_elements;
        Node *next;

        Node(int capacity)
        {
            this->capacity = capacity;
            next = nullptr;
            num_elements = 0;
            arr = new int[capacity];
        }

        ~Node()
        {
            delete[] arr;
        }
    };

    int capacity;
    int num_elements;
    Node *head;

    struct NodeSummary{
        int total_capacity;
        int total_size;
        Node *left_child;
        Node *right_child;
    };

    //Constructor de ListArr
    ListArr(int capacity);

    // METODO PARA CREACION DE NODOS RESUMEN
    void createSummaryNodes(Node *root);
    void createSummaryNodes(NodeSummary *root);

    // METODOS PARA NODOS (ACCESO A SUS ARREGLOS)
    int size();
    int delete_left();
    int delete_right();
    int countNodes();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
};

#endif