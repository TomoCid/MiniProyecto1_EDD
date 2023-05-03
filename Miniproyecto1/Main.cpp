#include "ListArr.h"

using namespace std;

int main(){
    ListArr listArr(10); // Se crea una instancia de clase ListArr
    ListArr::Node *root = new ListArr::Node(10); //Se crea un nodo de tamaño 10

    //Aqui debemos llamar la funcion para insertar elementos al nodo y si estos se pasan del tama;o la misma funcion debe crear nodos nuevos
    
    listArr.createSummaryNodes(root); //Se llama a la funcion para crear los nodos resumen en base a la cantida de nodos
}