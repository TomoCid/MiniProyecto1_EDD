#include "Array.h"

using namespace std;

Array::Array(int capacity){
    this->capacity;
    this->num_elements=0;
    this->arr = new int[capacity];
}

void Array::insert_left(int v){
    if(num_elements==capacity){
        int* newArr = new int[capacity*2];
        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = capacity*2;
    }
    for(int i = 0; i<num_elements; i++){
        arr[ i + 1] = arr[i];
    }
    arr[0] = v;
    num_elements++;
}

void Array::insert_right(int v){
    if(num_elements==capacity){
        int* newArr = new int[capacity*2];
        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = capacity*2;
    }
    arr[num_elements] = v;
    num_elements++;
}

bool Array::find(int v){
    for(int i=0; i<num_elements; i++){
        if(arr[i]==v){
            return true;
        }
    }
    return false;
}

int Array::size(){
    return 0;
}

int Array::delete_left(){
    return 0;
}
    
int Array::delete_right(){
    return 0;
}

void Array::insert(int v, int i){
    return;
}
    
void Array::print(){
    return;    
}