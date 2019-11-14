#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Car.h"

using namespace std;

class CarNode
{
public:
	CarNode();

	CarNode(Car* car, CarNode* next);

	Car* carData;

	CarNode* next;

	void showNodeInfo();
};

