#pragma once
#include "CarNode.h"
#include "CarLineUpNode.h"

class CarList
{
public:
	CarList();

	CarNode* head;

	CarLineUpNode* headCarLineUp;

	void deleteBrandCars();

	void showList();

	void createList(int count);

	void AddBrandToCarLineUp(CarNode* newCarBrandNode);

	void formCarLineUp();

	void addNewNode();

	CarNode* searchNodeInList();


};

