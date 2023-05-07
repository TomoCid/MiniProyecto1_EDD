#include "ListArr.h"

using namespace std;

int main(){
    ListArr listArr(2); // Se crea una instancia de clase ListArr
    ListArr listArr2(5);

    cout<<"-------------------- CASO VALIDO : --------------------------------"<<endl;
    for(int i=0;i<30;i++){
        listArr2.insert_left(i);
    }

    cout<<"Node 1:"<<listArr2.head->num_elements<<endl;
    cout<<"Node 2:"<<listArr2.head->next->num_elements<<endl;
    cout<<"Node 3:"<<listArr2.head->next->next->num_elements<<endl;
    cout<<"Node 4:"<<listArr2.head->next->next->next->num_elements<<endl;
    cout<<"Node 5:"<<listArr2.head->next->next->next->next->num_elements<<endl;
    cout<<"Node 6:"<<listArr2.head->next->next->next->next->next->num_elements<<endl;
    

    listArr2.createSummaryNodes(listArr2.head);

    cout<<"Elementos en listArr2: ";
    listArr2.print();

    cout<<"NODO RAIZ:"<<endl<<" -Capacidad total: "<<listArr2.TreeRoot->total_capacity<<endl<<" -Espacio usado: "<<listArr2.TreeRoot->total_size<<endl;
    cout<<"Nodo hijo izquierdo, capacidad: "<<listArr2.TreeRoot->Summaryleft_child->total_capacity<<endl;
    

    cout<<"Nodo hijo derecha, capacidad: "<<listArr2.TreeRoot->Summaryright_child->total_capacity<<endl;
    cout<<"Cantidad de nodos:"<<listArr2.nodeCount<<endl;

    cout<<"-------------------- CASO ERRONEO : --------------------------------"<<endl;

    for(int i=0;i<17;i++){
        listArr.insert_left(i);
    }

    cout<<"Node 1:"<<listArr.head->num_elements<<endl;
    cout<<"Node 2:"<<listArr.head->next->num_elements<<endl;
    cout<<"Node 3:"<<listArr.head->next->next->num_elements<<endl;
    cout<<"Node 4:"<<listArr.head->next->next->next->num_elements<<endl;
    cout<<"Node 5:"<<listArr.head->next->next->next->next->num_elements<<endl;
    cout<<"Node 6:"<<listArr.head->next->next->next->next->next->num_elements<<endl;
    cout<<"Node 7:"<<listArr.head->next->next->next->next->next->next->num_elements<<endl;





    

    listArr.createSummaryNodes(listArr.head);


    cout<<"Elementos en listArr: ";
    listArr.print();

    cout<<"NODO RAIZ:"<<endl<<" -Capacidad total: "<<listArr.TreeRoot->total_capacity<<endl<<" -Espacio usado: "<<listArr.TreeRoot->total_size<<endl;
    cout<<"Nodo hijo izquierdo, capacidad: "<<listArr.TreeRoot->Summaryleft_child->total_capacity<<endl;
    cout<<"Nodo hijo izquierdo, size: "<<listArr.TreeRoot->Summaryleft_child->total_size<<endl;


    cout<<"Nodo hijo derecha, capacidad: "<<listArr.TreeRoot->Summaryright_child->total_capacity<<endl;
    cout<<"Nodo hijo derecha, size: "<<listArr.TreeRoot->Summaryright_child->total_size<<endl;

    cout<<"Cantidad de nodos:"<<listArr.nodeCount<<endl;
    
    return 0;
}