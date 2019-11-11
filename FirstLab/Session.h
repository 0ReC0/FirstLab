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
	string manufacturer—ountry;
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

void showList(carNode* L);

void formCarLineUp(carNode*& headNode, carLineUpNode*& carLineUp);

void deleteBrandCars(carNode*& headNode, carLineUpNode* carLineUp);

void AddBrandToCarLineUp(carLineUpNode*& carLineUp, carNode* newCarBrandNode);

bool IsBrandExistInCarLineUp(carLineUpNode*& carLineUp, string brand);

void deleteBrandCars(carNode*& headNode, carLineUpNode* carLineUp);

void fillNodeData(carNode* person);

void createList(carNode*& L, carNode* person, int count);

void addNewNode(carNode*& L, carNode* person);

carNode* search_node(carNode* headNode);
