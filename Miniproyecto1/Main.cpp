#include "ListArr.h"

using namespace std;

int main(){
    ListArr listArr(5); // Se crea una instancia de clase ListArr
    ListArr::Node *root = new ListArr::Node(5); //Se crea un nodo de tamaño 10

    //Aqui debemos llamar la funcion para insertar elementos al nodo y si estos se pasan del tama;o la misma funcion debe crear nodos nuevos
    for(int i=0;i<20;i++){
        listArr.insert_left(4);
        
    }
    listArr.print();

    listArr.createSummaryNodes(root);
    cout<<"Nodo raiz:"+ listArr.TreeRoot->total_capacity;
    
    
}