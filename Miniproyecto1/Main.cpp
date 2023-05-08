#include "ListArr.h"
#include "Array.h"
#include "List.h"
#include <chrono>

using namespace std;

int main(){
    ListArr test_listArr1(512); // Se crea una instancia de clase ListArr
    Array test_array1(64);
    List test_list1;
    cout<<"---------ListArr:----------"<<endl;
    chrono::high_resolution_clock::time_point inicio, final;
    double tiempo_final_1 = 0;
    for(int i=0; i<20; i++){
        inicio = chrono::high_resolution_clock::now();
            
            for(int i=0; i<10000;i++){
                test_listArr1.insert_left(0);
            }
        
        final = chrono::high_resolution_clock::now();
        auto vector_list_time = chrono::duration_cast<chrono::microseconds>(final-inicio).count();
        tiempo_final_1+=vector_list_time;
    }
    double tiempo_promedio_1 = tiempo_final_1/20;
    cout<<"Tiempo promedio Insert_left(): "<<tiempo_promedio_1<<" us"<<endl;
    
    return 0;
}