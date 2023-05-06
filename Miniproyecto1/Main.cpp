#include "ListArr.h"

using namespace std;

int main(){
    ListArr listArr(5); // Se crea una instancia de clase ListArr
    ListArr listArr2(5);

    cout<<"-------------------- CASO VALIDO : --------------------------------"<<endl;
    for(int i=0;i<30;i++){
        listArr2.insert_left(i);
    }

    cout<<"Elementos en listArr2: ";
    listArr2.print();

    cout<<"NODO RAIZ:"<<endl<<" -Capacidad total: "<<listArr2.TreeRoot->total_capacity<<endl<<" -Espacio usado: "<<listArr2.TreeRoot->total_size<<endl;
    cout<<"Nodo hijo izquierdo, capacidad: "<<listArr2.TreeRoot->Summaryleft_child->total_capacity<<endl;

    cout<<"Nodo hijo derecha, capacidad: "<<listArr2.TreeRoot->Summaryright_child->total_capacity<<endl;
    cout<<"Cantidad de nodos:"<<listArr2.nodeCount<<endl;

    cout<<"-------------------- CASO ERRONEO : --------------------------------"<<endl;

    for(int i=0;i<31;i++){
        listArr.insert_left(i);
    }

    cout<<"Elementos en listArr: ";
    listArr.print();

    cout<<"NODO RAIZ:"<<endl<<" -Capacidad total: "<<listArr.TreeRoot->total_capacity<<endl<<" -Espacio usado: "<<listArr.TreeRoot->total_size<<endl;
    cout<<"Nodo hijo izquierdo, capacidad: "<<listArr.TreeRoot->Summaryleft_child->total_capacity<<endl;

    cout<<"Nodo hijo derecha, capacidad: "<<listArr.TreeRoot->Summaryright_child->total_capacity<<endl;
    cout<<"Cantidad de nodos:"<<listArr.nodeCount<<endl;
    
    return 0;
}
