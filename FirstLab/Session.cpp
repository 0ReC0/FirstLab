
#include "Session.h"

void menu() {
	cout << "1) C������� ������ �� n �����" << endl;
	cout << "2) ����� ������" << endl;
	cout << "3) ����� ���� � �������� ���������" << endl;
	cout << "4) �������� ����� ����" << endl;
	cout << "5) ������� ���� � ��������� ������� ������" << endl;
	cout << "6) ������������ ����� ������ �� ���������, ������� � ���� ���� � ������� ����, �������� �� ��� ���� �� ��������� ������" << endl;
	cout << "��� ������ ������� ������ �� ������ ������� ����" << endl;
};

void showList(carNode* headNode) {
	carNode* currNode = headNode;
	cout << setw(15) << "�����" << setw(15) << "������" << setw(15) << "��� �������" << endl;
	while (currNode != nullptr) {
		cout << setw(15) << currNode->data.brand << setw(15) << currNode->data.manufacturer�ountry << setw(15) << currNode->data.manufactureYear << endl;
		currNode = currNode->next;
	}
}

void createList(carNode*& L, carNode* person, int count) {
	fillNodeData(person);
	L = person;
	for (int i = 1; i < count; i++) {
		cout << "\n ��������� ����������:" << endl;
		addNewNode(L, person);
	}
}

void fillNodeData(carNode* car) {
	bool error;

	cout << "����� ����������" << endl;
	do {
		cin >> car->data.brand;
		if (car->data.brand == "") {
			error = 1;
			cout << "������� ������ ����� ����������";
		}
		else
			error = 0;
	} while (error);


	cout << "������ ������������" << endl;
	cin >> car->data.manufacturer�ountry;

	do {
		cout << "��� �������" << endl;
		cin >> car->data.manufactureYear;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32000, '\n');
			cerr << "��� ������� ������ ���� ��������� ������� \n ��������� ���� \n";
			error = true;
			continue;
		}
		if (car->data.manufactureYear < 1672) {
			error = true;
			cout << "��� ������� ������ ���� ������ 1672 ";
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
			cout << "������ ����� ��� � ������ \n";
			return nullptr;
		}
	}
}

void deleteBrandCars(carNode*& headNode, carLineUpNode* carLineUp) {
	cout << "������� �������� ����� ����������, ������� ������ ������� �� ������ \n";
	string brand;
	cin >> brand;

	carNode* nodeBeforeDeleted = nullptr;
	carNode* nodeAfterDeleted = nullptr;
	carNode* firstNodeToDelete = nullptr;
	carNode* currentNode = headNode;
	carNode* prevNode = nullptr;

	firstNodeToDelete = getFirstNodeToDelete(carLineUp, brand);


	while (currentNode != nullptr)
	{
		if (nodeBeforeDeleted && currentNode != nullptr && currentNode->data.brand != brand) {
			nodeAfterDeleted = currentNode;
		}
		if (currentNode->next == firstNodeToDelete) {
			nodeBeforeDeleted = currentNode;
		}
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
		else if (!nodeBeforeDeleted
			&& currentNode->next != nullptr
			&& currentNode != nullptr
			&& currentNode->data.brand == brand) {

			prevNode = currentNode;
			currentNode = currentNode->next;

			delete prevNode;

			if (currentNode->data.brand != brand) {
				headNode = currentNode;
				break;
			}

			continue;
		}
		else if (!nodeBeforeDeleted
			&& currentNode->next == nullptr
			&& currentNode != nullptr
			&& currentNode->data.brand == brand) {

			delete currentNode;
			headNode = nullptr;
			break;
		}
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	if (nodeBeforeDeleted != nullptr) {

		currentNode = nodeBeforeDeleted;
		while (currentNode != nullptr
			&& currentNode != nodeAfterDeleted
			&& currentNode->next != nullptr
			&& currentNode->next->next != nullptr) {

			prevNode = currentNode;
			currentNode = currentNode->next->next;

			delete prevNode->next;
		}
		if (nodeAfterDeleted) {
			nodeBeforeDeleted->next = nodeAfterDeleted;
		}
	}


}
carNode* search_node(carNode* headNode) {
	carNode* searchNode = new carNode;

	fillNodeData(searchNode);

	carNode* currNode = headNode;
	while (currNode) {
		if (currNode->data.brand == searchNode->data.brand
			&& currNode->data.manufacturer�ountry == searchNode->data.manufacturer�ountry
			&& currNode->data.manufactureYear == searchNode->data.manufactureYear)
			return currNode;
		currNode = currNode->next;
	}
	delete currNode;
	delete searchNode;
	return nullptr;
}