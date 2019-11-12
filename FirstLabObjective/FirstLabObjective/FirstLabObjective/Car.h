#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car();

	string brand;

	string manufacturerCountry;

	int manufactureYear;

	void fillNodeData();
};

