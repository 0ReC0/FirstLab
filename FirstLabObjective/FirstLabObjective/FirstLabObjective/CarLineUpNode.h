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

	

	CarNode* getFirstNodeToDelete(string brand);
	bool IsBrandExistInCarLineUp(string brand);


};

