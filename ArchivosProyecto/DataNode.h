#ifndef _DATANODE
#define _DATANODE
#include <iostream>
using namespace std;

class DataNode{
private:
    DataNode* next;
    int* arr;
    int capacity;
	int countUsed;
public:
	DataNode(int);
	bool findNumber(int);
	void addLeft(int);
	void add(int, int);
	void printElements();
	void setNext(DataNode*);
	DataNode* getNext();
	int* getArreglo();
	int getCapacity();
	int getcountUsed();
};
#endif