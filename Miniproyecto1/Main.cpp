#include "ListArr.h"
#include "Array.h"
#include "List.h"
#include <chrono>

using namespace std;

int main(){

    int b = 8192; //Modificar b para la capacidad de cada experimento
    ListArr test_listArr1(b);
    Array test_array1(10); //Capacidad tal que no se llene con las pruebas
    List test_list1;

    cout<<"---------Find():----------"<<endl;
    chrono::high_resolution_clock::time_point inicio1, final1;
    double tiempo_final_1 = 0;
    for(int i=0; i<10;i++){
            test_listArr1.insert_right(i);
    }
    inicio1 = chrono::high_resolution_clock::now();
            
    for(int i=0; i<10;i++){
        test_listArr1.find(i);
    }

    final1 = chrono::high_resolution_clock::now();
    auto vector_list_time = chrono::duration_cast<chrono::microseconds>(final1-inicio1).count();
    tiempo_final_1+=vector_list_time;

    double tiempo_promedio_1 = tiempo_final_1;
    cout<<"Tiempo promedio Find(): "<<tiempo_promedio_1<<" us"<<endl;

    cout<<"---------Insert_left():----------"<<endl;
    chrono::high_resolution_clock::time_point inicio2, final2;
    double tiempo_final_2 = 0;
    inicio2 = chrono::high_resolution_clock::now();

    for(int i=0; i<10;i++){
        test_listArr1.insert_left(i);
    }

    final2 = chrono::high_resolution_clock::now();
    auto vector_list_time_2 = chrono::duration_cast<chrono::microseconds>(final2-inicio2).count();
    tiempo_final_2+=vector_list_time_2;

    double tiempo_promedio_2 = tiempo_final_2;
    cout<<"Tiempo promedio Insert_left(): "<<tiempo_promedio_2<<" us"<<endl;

    cout<<"---------Insert_right():----------"<<endl;
    chrono::high_resolution_clock::time_point inicio3, final3;
    double tiempo_final_3 = 0;
    inicio3 = chrono::high_resolution_clock::now();

    for(int i=0; i<100000;i++){
        test_listArr1.insert_right(i);
    }

    final3 = chrono::high_resolution_clock::now();
    auto vector_list_time_3 = chrono::duration_cast<chrono::microseconds>(final3-inicio3).count();
    tiempo_final_3+=vector_list_time_3;

    double tiempo_promedio_3 = tiempo_final_3;
    cout<<"Tiempo promedio Insert_right(): "<<tiempo_promedio_3<<" us"<<endl;

    
    return 0;
}