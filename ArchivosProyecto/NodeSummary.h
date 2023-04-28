#include <iostream>
#include "DataNode.h" //Cambiar a ListArray en caso de fusion.
using namespace std;

class SummaryNode{
private:
    int capacity, usedCpacity;
    SummaryNode* rightSuma;
    SummaryNode* leftSuma;
    DataNode* rightData;
    DataNode* leftSuma;
public:
    SummaryNode();
    int getUsedCapacity();
	int getCapacity();
	void updateUsedCapacity();
	void updateFullCapacity();
	int getNumDataNodes();
	void setLeftData(DataNode* dataAux);
	void setRightData(DataNode* dataAux);
	void setLeftSuma(SummaryNode* summaryAux);
	void setRightSuma(SummaryNode* summaryAux);
	DataNode* getLeftData();
	DataNode* getRightData();
	SummaryNode* getLeftSuma();
	SummaryNode* getRightSuma();
	bool isLastLevel();
	void addLeft(int number);
	void addRight(int number);
	void add(int number, int pos);
	bool find(int number);
	void printEntireArray();

};
