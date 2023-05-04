#include "ListArr.h"
#include "NodeSummary.h"
using namespace std;

//Modificar para adaptarlo a la estructura de nodos
ListArr::ListArr(int capacity){
    this->capacity = capacity;
}

//En proceso
void ListArr::insert(int v, int i){
        
}

//En proceso
void ListArr::createSummaryNodes(NodeSummary *root){ //Funcion recurvisa 
    
    if (root == nullptr)
    {
        return;
    }

    NodeSummary *current = root;
    NodeSummary *prev = nullptr;
    //------------------------//
}

//En proceso
void ListArr::createSummaryNodes(Node *root){
    if (root == nullptr)
    {
        return;
    }

    Node *current = root;
    Node *prev = nullptr;

    if (current->next == nullptr)
    {
        NodeSummary *summary = new NodeSummary();
        summary->total_capacity = current->capacity;
        summary->total_size = current->num_elements;
        summary->left_child = current;
        summary->right_child = nullptr;
        return;
    }

    while (current != nullptr)
    {
        if (current->next == nullptr)
        {
            NodeSummary *summary = new NodeSummary();
            summary->total_capacity = prev->capacity + current->capacity;
            summary->total_size = prev->num_elements + current->num_elements;
            summary->left_child = prev;
            summary->right_child = current;
        }

        prev = current;
        current = current->next;
    }
}

//En proceso
int ListArr::delete_left(){
    if(head == nullptr){
        throw "No hay elementos que eliminar";
        return;
    }else{
        Node *current = head;
        if(current->num_elements == 0){
            current = current->next;
        }
        if(current -> arr[0]){
            int element = current->arr[0];
            for(int i=0; i < num_elements; i++){
                current->arr[i]=current->arr[i+1];
            }
            return element;
        }
    }
}

//Pendiente
int ListArr::delete_right(){
}

//"Listo a medias" (Requiere que los metodos insert queden finalizados, por si hay que hacer algun cambio)
int ListArr::size(){
    return num_elements;
}

//"Listo a medias" (La idea es que en base al metodo insert aplicarlo en insert_left)
void ListArr::insert_left(int v){
    if (head == nullptr){ // En caso de que intentemos ingresar un elemento y no exista un nodo,creamos uno.
        head = new Node(capacity); 
        head->arr[0] = v; //Se ingresa el elemento
        head->num_elements++; //Aumenta el cntador de elementos del nodo
        num_elements++;  //Aumenta el contador de elementos global
    }
    else{ 
        Node *current = head; //Recorremos todos los nodos para buscar el que tenga espacio
        while (current->next != nullptr && current->next->num_elements == current->capacity) { //Si el nodo que viene es vacio, entonces este es el ultimo nodo e ingresamos aqui, 
        //si en los nodos que siguen se encuentra uno que no este lleno, nos detenemos ahi
        current = current->next;
    }

    if(current->num_elements == current->capacity){ //En caso de que ningun nodo tenga espacio para guardar el elemento, creamos un nodo nuevo
        Node *new_node = new Node(capacity); 
        new_node->arr[0] = v; 
        new_node->num_elements++;
        num_elements++;
        current->next = new_node;
    } else { //Si hay espacio en el nodo actual, ingresaremos el elemento ahi
        for (int i = current->num_elements; i > 0; i--) { //Se mueven todos los elementos a la derecha para poder ingresar nuestro elemento a la izquierda
            current->arr[i] = current->arr[i-1];
        }
        current->arr[0] = v;
        current->num_elements++;
        num_elements++;
        }
    }
}

//"Listo a medias" (La idea es que en base al metodo insert aplicarlo en insert_right)
void ListArr::insert_right(int v){
    if (head == nullptr){ // En caso de que intentemos ingresar un elemento y no exista un nodo,creamos uno.
        head = new Node(capacity); 
        head->arr[capacity-1] = v; //Se ingresa el elemento en la posición más a la derecha
        head->num_elements++; //Aumenta el contador de elementos del nodo
        num_elements++;  //Aumenta el contador de elementos global
    }
    else{ 
        Node *current = head; //Recorremos todos los nodos para buscar el que tenga espacio
        while (current->next != nullptr && current->next->num_elements == current->capacity) { //Si el nodo que viene es vacio, entonces este es el ultimo nodo e ingresamos aqui, 
        //si en los nodos que siguen se encuentra uno que no este lleno, nos detenemos ahi
        current = current->next;
    }

    if(current->num_elements == current->capacity){ //En caso de que ningun nodo tenga espacio para guardar el elemento, creamos un nodo nuevo
        Node *new_node = new Node(capacity); 
        new_node->arr[capacity-1] = v; //Se ingresa el elemento en la posición más a la derecha
        new_node->num_elements++;
        num_elements++;
        current->next = new_node;
    } else { //Si hay espacio en el nodo actual, ingresaremos el elemento ahi
        for (int i = current->num_elements; i > 0; i--) { //Se mueven todos los elementos a la derecha para poder ingresar nuestro elemento a la izquierda
            current->arr[i] = current->arr[i-1];
        }
        current->arr[0] = v; //Se ingresa el elemento en la posición más a la derecha
        current->num_elements++;
        num_elements++;
        }
    }
}

//Listo
void ListArr::print(){
    Node *current = head;
    while (current->next != nullptr){
        for(int i = 0; i< num_elements; i++){
            cout << current->arr[i] + " " ;
        } 
        current = current->next;
    }
}

//"Listo a medias" (En una de esas hay una forma más eficiente de implementarlo con NodeSummary, por lo que es una solucion temporal)
//Falta comprobar si funciona o hay algun error.
bool ListArr::find(int v){
    Node* current = head; //Guardamos la ubicacion de head.
    for(int i=0; i<num_elements; i++){
        if(head->arr[i] == v){ //Si encuentra el dato en el arreglo retorna true.
            head = current;
            return true;
        }
    }
    if(head->next != nullptr){ //Si no, revisa si hay más nodos, y en el caso de que si, lo recorre.
        head->next;
        find(v);
    } else {  // Si no quedan nodos, retorna false.
        return false;
    }
}

//Listo (*IDEA*: Se puede mejorar agregando un contador de nodos dentro de la estructura)
int ListArr::countNodes(){ //Recorre los nodos, y cuenta hasta llegar a nulo.
    Node* current = head;
    int count = 0;
    for(count = 0; current->next != nullptr; count++){
        current = current -> next;
    }
    return count;
}