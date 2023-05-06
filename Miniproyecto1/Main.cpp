#include "ListArr.h"

using namespace std;

int main(){
    ListArr listArr(5); // Se crea una instancia de clase ListArr

    //Aqui debemos llamar la funcion para insertar elementos al nodo y si estos se pasan del tama;o la misma funcion debe crear nodos nuevos
    for(int i=0;i<14;i++){
        listArr.insert_right(i);
    }

    cout<<"Elementos en listArr: ";
    listArr.print();
    cout<<"NODO RAIZ:"<<endl<<"Capacidad total: "<<listArr.TreeRoot->total_capacity<<endl<<"Espacio usado: "<<listArr.TreeRoot->total_size<<endl;

    //Pruebas funcionamiento de find()
    listArr.find(4);
    listArr.find(3);

    listArr.delete_right();

    listArr.updateTree();
    cout<<"NODO RAIZ:"<<endl<<"Capacidad total: "<<listArr.TreeRoot->total_capacity<<endl<<"Espacio usado: "<<listArr.TreeRoot->total_size<<endl;

    listArr.print();

    return 0;
}
