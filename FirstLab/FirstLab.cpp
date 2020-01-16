// FirstLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "CarList.h"

#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	carNode* headNode = nullptr;
	carLineUpNode* carLineUp = nullptr;
	carNode* car = new carNode;

	int menu_vibor, count_node = -1;
	bool flag = 0, error = 0;
	menu();
	while (true) {
		cout << "\n\nNext select: ";
		cin >> menu_vibor;
		switch (menu_vibor) {
		case 1: // "1) Build one-way list with n number nodes"
			do {
				cout << "Enter number nodes: ";
				cin >> count_node;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32000, '\n');
					cerr << "Enter number \n Retry entering \n";
					error = true;
					continue;
				}
				if (count_node <= 0) {
					error = true;
					cout << "Enter number nodes greater than 0: ";
				}
				else {
					error = false;
					createList(headNode, car, count_node);
				}
			} while (error);
			break;
		case 2: // 2) Show list
			if (headNode != nullptr) {
				showList(headNode);
			}
			break;
		case 3: // 3) Form list car line-up
			if (headNode != nullptr) {
				formCarLineUp(headNode, carLineUp);
			}
			break;
		case 4: // 4) Delete brand from one-way list
			if (headNode != nullptr) {

				deleteBrandCars(headNode, carLineUp);
			}
			break;
		case 5:  // 5) Search node in list
			if (headNode != nullptr) {
				showNodeInfo(searchNodeInList(headNode));
			}
			break;
		case 6:  // 6) Add node to list
			//fillNodeData(car);

			if (headNode) {
				addNewNode(headNode, car);
			}
			else {
				cout << "Error while adding new node \n";
			}
			break;
		default: // To exit enter number of not equal to proposed
			std::system("pause");
			return 0;
		}
	}
}
