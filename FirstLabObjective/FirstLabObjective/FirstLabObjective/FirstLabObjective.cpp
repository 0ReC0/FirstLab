// FirstLabObjective.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// FirstLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "CarNode.h"
#include "CarLineUpNode.h"

#include <iostream>
void menu() {
	cout << "1) Build one-way list with n number nodes" << endl;
	cout << "2) Show list" << endl;
	cout << "3) Form list car line-up" << endl;
	cout << "4) Delete brand from one-way list" << endl;
	cout << "5) Search node in list" << endl;
	cout << "6) Add node to list" << endl;
	cout << "To exit enter number of not equal to proposed" << endl;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CarNode* headNode = nullptr;
	CarLineUpNode* carLineUp = nullptr;

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
					headNode->createList(count_node);
				}
			} while (error);
			break;
		case 2: // 2) Show list
			headNode->showList();
			break;
		case 3: // 3) Form list car line-up
			carLineUp->formCarLineUp(headNode);
			break;
		case 4: // 4) Delete brand from one-way list
			carLineUp->formCarLineUp(headNode);
			carLineUp->deleteBrandCars(headNode);
			break;
		case 5:  // 5) Search node in list
			( headNode->searchNodeInList() )->showNodeInfo();
			break;
		case 6:  // 6) Add node to list
			carLineUp->carData->fillNodeData();

			if (headNode) {
				headNode->addNewNode();
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
