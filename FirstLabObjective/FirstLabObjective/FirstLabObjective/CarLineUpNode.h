#pragma once
#include <iostream>
#include <string>
#include "CarNode.h"
using namespace std;

class CarLineUpNode
{
public:
	CarLineUpNode();

	CarLineUpNode(string brand, CarNode* firstCarNodeInLineUp);

	string brand;

	CarNode* firstCarNodeInLineUp;

	CarLineUpNode* next;

	void showList();

	void formCarLineUp(CarLineUpNode*& headCarLineUpNode, CarNode* headNode);

	CarNode* getFirstNodeToDelete(string brand);
private:

	bool IsBrandExistInCarLineUp(string brand);

	void AddBrandToCarLineUp(CarLineUpNode*& headCarLineUpNode, CarNode* newCarBrandNode);
};

