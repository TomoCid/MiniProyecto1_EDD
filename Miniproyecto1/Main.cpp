#include "ListArr.h"

using namespace std;

int main(){
    ListArr listArr(5); // Se crea una instancia de clase ListArr

    //Aqui debemos llamar la funcion para insertar elementos al nodo y si estos se pasan del tama;o la misma funcion debe crear nodos nuevos
    for(int i=0;i<14;i++){
        listArr.insert_left(4);
    }
    listArr.print();

    cout<<"NODO RAIZ!: ";
    cout<<"Capacidad total: "<<listArr.TreeRoot->total_capacity;
    cout<<"Espacio usado: "<<listArr.TreeRoot->total_size;
}