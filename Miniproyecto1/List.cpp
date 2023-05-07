#include "List.h"

using namespace std;

List::List(){
    this->num_elements=0;
    head=nullptr;
}

void List::insert_left(int v){
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
    num_elements++;
}

void List::insert_right(int v){
    Node* newNode = new Node(v);
    num_elements++;
    if(head==nullptr){
        head = newNode;
    } else {
        Node* aux = head;
        while(aux->next != nullptr){
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

bool List::find(int v){
    Node* aux = head;
    while(aux != nullptr){
        if(aux->data == v){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

