#pragma once
#include <iostream>
#include <string>
#include "CarNode.h"
using namespace std;

class CarLineUpNode : public CarNode
{
public:
	CarLineUpNode();

	CarLineUpNode(string brand, CarNode* firstCarNodeInLineUp);

	string brand;

	CarNode* firstCarNodeInLineUp;

	CarLineUpNode* next;


	void formCarLineUp(CarNode*& headNode);

	void deleteBrandCars(CarNode*& headNode);



private:
	CarNode* getFirstNodeToDelete(string brand);

	bool IsBrandExistInCarLineUp(string brand);

	void AddBrandToCarLineUp(CarNode* newCarBrandNode);
};

