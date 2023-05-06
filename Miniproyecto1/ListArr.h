#ifndef _LISTARR
#define _LISTARR
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ListArr{

public:
    struct Node{
        vector<int> *arr;
        int capacity;
        int num_elements;
        Node *next;

        Node(int capacity, Node* next = nullptr)
        {
            this->capacity = capacity;
            this->next = next;
            num_elements = 0;
            arr = new vector<int>;
        }

        ~Node()
        {
            delete[] arr;
        }
    };

    int capacity;
    int total_num_elements;
    int nodeCount;
    Node *head;

    struct NodeSummary{
        int total_capacity;
        int total_size;
        //ESTOS SON LOS HIJOS DE TIPO NODO (LOS QUE CONTIENEN ARREGLOS)
        Node *left_child;
        Node *right_child;
        //ESTOS SON LOS HIJOS DE TIPO NODESUMARY (EN OTRAS PALABRAS, HIJOS RESUMEN)
        NodeSummary *Summaryleft_child = nullptr;
        NodeSummary *Summaryright_child = nullptr;

       
    };

    NodeSummary *TreeRoot = nullptr;
    
    //Constructor de ListArr
    ListArr(int capacity);

    // METODO PARA CREACION DE NODOS RESUMEN
    void createSummaryNodes(Node *root);
    void createSummaryNodes(vector<NodeSummary *> PrevSummaryNodes);

    // METODOS PARA NODOS (ACCESO A SUS ARREGLOS)
    int size();
    int delete_left();
    int delete_right();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);

    //Métodos extra de utilidad
    int getHeight();
    void searchIndex(int i, NodeSummary* TreeRoot, Node* target);
    void deleteTree(NodeSummary *TreeRoot);
    void updateTree();
    void deleteLastElement(int* &arr, int &size);
};

#endif