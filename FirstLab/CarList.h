#pragma once
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

struct car {
	string brand;
	string manufacturerCountry;
	int manufactureYear;
};
typedef struct list {
	car data; 
	struct list* next;
}carNode;

struct carLineUpNode {
	string brand;
	struct list* firstCarNode;
	struct carLineUpNode* next;
};

void menu();

void showList(carNode* headNode);

void formCarLineUp(carNode*& headNode, carLineUpNode*& carLineUp);

void deleteBrandCars(carNode*& headNode, carLineUpNode* carLineUp);
carNode* getFirstNodeToDelete(carLineUpNode* carLineUp, string brand);

void AddBrandToCarLineUp(carLineUpNode*& carLineUp, carNode* newCarBrandNode);

bool IsBrandExistInCarLineUp(carLineUpNode*& carLineUp, string brand);

void fillNodeData(carNode* car);

void createList(carNode*& L, carNode* car, int count);

void addNewNode(carNode*& L, carNode* car);

carNode* searchNodeInList(carNode* headNode);

void showNodeInfo(carNode* currNode);
