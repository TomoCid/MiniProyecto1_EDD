#include "DataNode.h"
#include <iostream>

using namespace std;

DataNode::DataNode(int capacity){
    int* arr = new int[capacity];
    this -> capacity = capacity;
    this -> countUsed = 0;
    this -> next = nullptr;
}

bool DataNode::findNumber(int data){
    for(int i = 0; i < capacity; i++){
        if(arr[i] == data){
            return true;
        }
    }
    if(next == nullptr){
        return false;
    } else {
        next -> findNumber(data);
    }
}

void DataNode :: add(int data,int pos){
    if(pos <= capacity){
        if(countUsed < capacity){
            for(int i = capacity; i >= pos; --i){
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = data;
            capacity ++;
        }
    } else {
        if(next == nullptr || next->getCapacity() == capacity){
            DataNode* aux = next;
            DataNode* newAux = new DataNode(capacity);
            newAux -> next;
            next = newAux;
        }
        next -> addLeft(arr[capacity - 1]);
        for(int i = capacity; i >= pos; --i){
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = data;
        capacity++;
    }
}

void DataNode :: addLeft(int data){
    if(countUsed == 0){
        arr[0] = data;
        countUsed++;
    } else {
        if(countUsed <= capacity - 1){
            for(int i = 0; i < countUsed; i++){
                arr[countUsed - 1]=arr[countUsed - i - 1];
            }
            countUsed++;
        } else {
            //Agregar caso en que el array 
        }
        arr[0] = data;
    }
}

void DataNode::printElements(){
    for(int i=0; i < countUsed; i++){
        cout << arr[i] << endl;
    }
    if(next != nullptr){
        cout << endl;
        next -> printElements();
    }
}
// Sección Setters y getters
void DataNode::setNext(DataNode* auxNext) {
	next = auxNext;
}

DataNode* DataNode::getNext(){
    return next;
}

int* DataNode::getArreglo(){
    return arr;
}

int DataNode::getCapacity() {
	return capacity;
}

int DataNode::getcountUsed() {
	return countUsed;
}
