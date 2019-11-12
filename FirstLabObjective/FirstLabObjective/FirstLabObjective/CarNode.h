#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Car.h"
#include "CarLineUpNode.h"

using namespace std;

class CarNode
{
public:
	CarNode();

	Car* carData;
	CarNode* next;


	void showList();

	void createList(int count);

	void addNewNode();

	CarNode* searchNodeInList();

	void showNodeInfo();
};

