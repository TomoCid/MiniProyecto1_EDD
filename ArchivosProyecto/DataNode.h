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
	void addLeft(int);
	void add(int, int);
	void setNext(DataNode*);
	DataNode* getNext();
	int getCapacity();
	int getcountUsed();
	void printElements();
};
#endif