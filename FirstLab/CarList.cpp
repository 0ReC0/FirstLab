
#include "CarList.h"

void menu() {
	cout << "1) Build one-way list with n number nodes" << endl;
	cout << "2) Show list" << endl;
	cout << "3) Form list car line-up" << endl;
	cout << "4) Delete brand from one-way list" << endl;
	cout << "5) Search node in list" << endl;
	cout << "6) Add node to list" << endl;
	cout << "To exit enter number of not equal to proposed" << endl;
};

void showList(carNode* headNode) {
	carNode* currNode = headNode;
	cout << setw(15) << "Brand" << setw(15) << "Country" << setw(15) << "Manufacture year" << endl;
	while (currNode != nullptr && currNode->data.brand != "") {
		cout << setw(15) << currNode->data.brand << setw(15) << currNode->data.manufacturerCountry << setw(15) << currNode->data.manufactureYear << endl;
		currNode = currNode->next;
	}
}
void showNodeInfo(carNode* currNode) {
	if (currNode == nullptr) {
		cerr << "Error while showing info about node \n";
		return;
	}

	cout << setw(15) << "Brand" << setw(15) << "Country" << setw(15) << "Manufacture year" << endl;
	cout << setw(15) << currNode->data.brand << setw(15) << currNode->data.manufacturerCountry << setw(15) << currNode->data.manufactureYear << endl;
}

void createList(carNode*& headNode, carNode* car, int count) {
	fillNodeData(car);
	headNode = car;
	for (int i = 1; i < count; i++) {
		cout << "\n Next car:" << endl;
		addNewNode(headNode, car);
	}
}

void fillNodeData(carNode* car) {
	bool error;

	cout << "Car's brand" << endl;
	do {
		cin >> car->data.brand;
		if (car->data.brand == "") {
			error = 1;
			cout << "Re-enter Car's brand";
		}
		else
			error = 0;
	} while (error);


	cout << "Manufacturer country" << endl;
	cin >> car->data.manufacturerCountry;

	do {
		cout << "Manufacture year" << endl;
		cin >> car->data.manufactureYear;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32000, '\n');
			cerr << "Manufacture year must be numeric \n Re-entry \n";
			error = true;
			continue;
		}
		if (car->data.manufactureYear < 1672) {
			error = true;
			cout << "Manufacture year must be greater than 1672 ";
		}
		else
			error = false;
	} while (error);
	car->next = nullptr;
}


/*Adding new Node*/
void addNewNode(carNode*& headNode, carNode* newCarNode) {
	carNode* currNode = headNode;
	carNode* prevNode = nullptr;

	newCarNode = new carNode;
	fillNodeData(newCarNode);

	//Find first node of model line up
	while (currNode->data.brand != newCarNode->data.brand) {
		if (currNode->next != nullptr) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		else {
			currNode->next = newCarNode;
			return;
		}
	}

	do {
		// if currentNode is not last in list
		if (currNode->next != nullptr) {

			// If manufactureYear of new Node higher then manufactureYear of current Node =----> to place newNode before current Node
			if (currNode->data.manufactureYear < newCarNode->data.manufactureYear) {

				newCarNode->next = currNode;

				if (prevNode != nullptr)
					prevNode->next = newCarNode;
				else
					headNode = newCarNode;
				return;
			}
			// else =----> to place newNode after current Node
			// If next node not belongs to current brand line-up 
			else if (currNode->next->data.brand != currNode->data.brand) {
				newCarNode->next = currNode->next;
				currNode->next = newCarNode;
				return;
			}

			// Iterate
			prevNode = currNode;
			currNode = currNode->next;
		}
		// if currentNode is last in list
		else {
			// If manufactureYear of new Node higher then manufactureYear of current Node =----> to place newNode before current Node
			if (currNode->data.manufactureYear < newCarNode->data.manufactureYear) {

				newCarNode->next = currNode;

				if (prevNode != nullptr)
					prevNode->next = newCarNode;
				else
					headNode = newCarNode;

				return;
			}
			// else =----> to place newNode after current Node
			else {
				currNode->next = newCarNode;
				return;
			}
		}
	} while (true);
}

void formCarLineUp(carNode*& headNode, carLineUpNode*& carLineUp) {
	carNode* currNode = headNode;
	carLineUp = nullptr;

	do {
		if (!IsBrandExistInCarLineUp(carLineUp, currNode->data.brand)) {
			AddBrandToCarLineUp(carLineUp, currNode);
		}

		currNode = currNode->next;
	} while (currNode != nullptr);
}

void AddBrandToCarLineUp(carLineUpNode*& carLineUp, carNode* newCarBrandNode) {
	if (carLineUp != nullptr) {
		carLineUpNode* currNode = carLineUp;
		carLineUpNode* prevNode = nullptr;

		// find last node
		while (currNode != nullptr) {
			prevNode = currNode;
			currNode = currNode->next;
		}

		currNode = new carLineUpNode;

		currNode->firstCarNode = newCarBrandNode;
		currNode->brand = newCarBrandNode->data.brand;
		currNode->next = nullptr;

		prevNode->next = currNode;
	}
	else {
		carLineUp = new carLineUpNode;
		carLineUp->brand = newCarBrandNode->data.brand;
		carLineUp->firstCarNode = newCarBrandNode;
		carLineUp->next = nullptr;
	}
}

bool IsBrandExistInCarLineUp(carLineUpNode*& carLineUp, string brand) {
	if (carLineUp == nullptr)
		return false;

	carLineUpNode* currNode = carLineUp;
	while (currNode != nullptr) {
		if (currNode->brand == brand)
			return true;
		currNode = currNode->next;
	}
	return false;
}

carNode* getFirstNodeToDelete(carLineUpNode* carLineUp, string brand) {
	while (carLineUp != nullptr)
	{
		if (carLineUp->brand == brand) {
			return carLineUp->firstCarNode;
			break;
		}
		carLineUp = carLineUp->next;

		if (carLineUp == nullptr) {
			cout << "This brand doesnt exist \n";
			return nullptr;
		}
	}
	return nullptr;
}

void deleteBrandCars(carNode*& headNode, carLineUpNode* carLineUp) {
	cout << "Enter car's brand, which you want to delete from list \n";
	string brand;
	cin >> brand;

	carNode* nodeBeforeDeleted = nullptr;
	carNode* nodeAfterDeleted = nullptr;
	carNode* firstNodeToDelete = nullptr;
	carNode* currentNode = headNode;
	carNode* prevNode = nullptr;

	formCarLineUp(headNode, carLineUp);

	firstNodeToDelete = getFirstNodeToDelete(carLineUp, brand);


	while (currentNode != nullptr)
	{
		if (nodeBeforeDeleted && currentNode != nullptr && currentNode->data.brand != brand) {
			nodeAfterDeleted = currentNode;
			break;
		}

		// if exit any node before deleting node then remember it
		if (currentNode->next == firstNodeToDelete) {
			nodeBeforeDeleted = currentNode;
		}

		// if current node first and alone in line-up or its last in line-up then set it to nullptr
		if (currentNode == firstNodeToDelete && currentNode->next == nullptr) {
			if (prevNode) {
				prevNode->next = nullptr;
				return;
			}
			else {
				headNode = nullptr;
				return;
			}
		}

		// if doesnt exit any node before and it is not last in line-up then delete currentNode and iterate 
		//		or if next node from another brand line-up then set it to headNode
		else if (!nodeBeforeDeleted
			&& currentNode->next != nullptr
			&& currentNode != nullptr
			&& currentNode->data.brand == brand) {

			prevNode = currentNode;
			currentNode = currentNode->next;

			prevNode = nullptr;

			if (currentNode->data.brand != brand) {
				headNode = currentNode;
				break;
			}

			continue;
		}

		// if doesnt exit any node before and it is last in line-up then set headNode to nullptr
		else if (!nodeBeforeDeleted
			&& currentNode->next == nullptr
			&& currentNode != nullptr
			&& currentNode->data.brand == brand) {

			currentNode = nullptr;
			headNode = nullptr;
			break;
		}
		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	if (nodeBeforeDeleted != nullptr) {

		currentNode = nodeBeforeDeleted;

		// deleting node useless nodes
		while (currentNode != nullptr
			&& currentNode != nodeAfterDeleted
			&& currentNode->next != nullptr
			&& currentNode->next->next != nullptr) {

			prevNode = currentNode;
			currentNode = currentNode->next->next;

			prevNode->next = nullptr;
		}

		// connect node before deleted nodes and node after them
		if (nodeAfterDeleted) {
			nodeBeforeDeleted->next = nodeAfterDeleted;
		}
	}


}
carNode* searchNodeInList(carNode* headNode) {
	carNode* searchNode = new carNode;

	fillNodeData(searchNode);

	carNode* currNode = headNode;
	while (currNode) {
		if (currNode->data.brand == searchNode->data.brand
			&& currNode->data.manufacturerCountry == searchNode->data.manufacturerCountry
			&& currNode->data.manufactureYear == searchNode->data.manufactureYear)
			return currNode;
		currNode = currNode->next;
	}
	delete currNode;
	delete searchNode;
	return nullptr;
}