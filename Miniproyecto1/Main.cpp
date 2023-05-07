#include "ListArr.h"

using namespace std;

int main(){
    ListArr listArr(2); // Se crea una instancia de clase ListArr
    ListArr listArr2(5);

    cout<<"-------------------- CASO VALIDO : --------------------------------"<<endl;
    for(int i=0;i<15;i++){
        listArr2.insert_left(i);
    }

    cout<<"Node 1:"<<listArr2.head->num_elements<<endl;
    cout<<"Node 2:"<<listArr2.head->next->num_elements<<endl;
    cout<<"Node 3:"<<listArr2.head->next->next->num_elements<<endl;
    
    cout<<"Elementos en listArr2: ";
    listArr2.print();


    cout<<"NODO RAIZ:"<<endl<<" -Capacidad total: "<<listArr2.TreeRoot->total_capacity<<endl<<" -Espacio usado: "<<listArr2.TreeRoot->total_size<<endl;
    cout<<"Nodo hijo izquierdo, capacidad: "<<listArr2.TreeRoot->Summaryleft_child->total_capacity<<endl;    

    cout<<"Nodo hijo derecha, capacidad: "<<listArr2.TreeRoot->Summaryright_child->total_capacity<<endl;
    cout<<"Cantidad de nodos:"<<listArr2.nodeCount<<endl;

    cout<<"-------------------- PRUEBA FUNCION INSERT --------------------------------"<<endl;

    cout<<"Total de elementos [VARIABLE]: "<<listArr2.total_num_elements<<endl;
    listArr2.insert(2,11);
    cout<<"Node 1:"<<listArr2.head->num_elements<<endl;
    cout<<"Node 2:"<<listArr2.head->next->num_elements<<endl;
    cout<<"Node 3:"<<listArr2.head->next->next->num_elements<<endl;

    cout<<"Elementos en listArr2: ";
    listArr2.print();


    cout<<"NODO RAIZ:"<<endl<<" -Capacidad total: "<<listArr2.TreeRoot->total_capacity<<endl<<" -Espacio usado: "<<listArr2.TreeRoot->total_size<<endl;
    cout<<"Nodo hijo izquierdo, capacidad: "<<listArr2.TreeRoot->Summaryleft_child->total_capacity<<endl;    

    cout<<"Nodo hijo derecha, capacidad: "<<listArr2.TreeRoot->Summaryright_child->total_capacity<<endl;
    cout<<"Cantidad de nodos:"<<listArr2.nodeCount<<endl;

    
    return 0;
}