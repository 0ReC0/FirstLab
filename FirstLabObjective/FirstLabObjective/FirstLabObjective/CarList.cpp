#include "CarList.h"

CarList::CarList() {
	this->head = nullptr;
	this->headCarLineUp = nullptr;
}

void CarList::showList() {
	if (this) {
		CarNode* currNode = this->head;
		cout << setw(30) << "Brand" << setw(30) << "Country" << setw(30) << "Manufacture year" << endl;
		while (currNode != nullptr) {
			cout << setw(30) << currNode->carData->brand << setw(30) << currNode->carData->manufacturerCountry << setw(30) << currNode->carData->manufactureYear << endl;
			currNode = currNode->next;
		}
	}
	else {
		cerr << "Error while showing list" << endl;
	}
}

void CarList::createList(int count) {
	this->head = nullptr;
	this->headCarLineUp = nullptr;

	CarNode* headNode = new CarNode();
	headNode->next = nullptr;
	headNode->carData->fillNodeData();
	this->head = headNode;

	for (int i = 1; i < count; i++) {
		cout << "\n Next car:" << endl;
		this->addNewNode();
	}
}

/*Adding new Node*/
void CarList::addNewNode() {
	CarNode* currNode = this->head;
	CarNode* prevNode = nullptr;

	CarNode* newCarNode = new CarNode();
	newCarNode->carData->fillNodeData();

	//Find first node of model line up
	while (currNode->carData->brand != newCarNode->carData->brand) {
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
			if (currNode->carData->manufactureYear < newCarNode->carData->manufactureYear) {


				newCarNode->next = currNode;

				if (prevNode != nullptr) {
					prevNode->next = newCarNode;
				}
				else {
					this->head = newCarNode;
				}
				return;
			}
			// else =----> to place newNode after current Node
			// If next node not belongs to current brand line-up 
			else if (currNode->next->carData->brand != currNode->carData->brand) {
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
			if (currNode->carData->manufactureYear < newCarNode->carData->manufactureYear) {


				newCarNode->next = currNode;

				if (prevNode != nullptr) {
					prevNode->next = newCarNode;
				}
				else {
					this->head = newCarNode;
				}

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
CarNode* CarList::searchNodeInList() {
	CarNode* searchNode = new CarNode();

	searchNode->carData->fillNodeData();

	CarNode* currNode = this->head;
	while (currNode) {
		if (currNode->carData->brand == searchNode->carData->brand
			&& currNode->carData->manufacturerCountry == searchNode->carData->manufacturerCountry
			&& currNode->carData->manufactureYear == searchNode->carData->manufactureYear)
			return currNode;
		currNode = currNode->next;
	}
	delete currNode;
	delete searchNode;
	return nullptr;
}
void CarList::deleteBrandCars() {
	cout << "Enter car's brand, which you want to delete from list \n";
	string brand;
	cin >> brand;

	CarNode* nodeBeforeDeleted = nullptr;
	CarNode* nodeAfterDeleted = nullptr;
	CarNode* firstNodeToDelete = nullptr;
	CarNode* currentNode = this->head;
	CarNode* prevNode = nullptr;

	firstNodeToDelete = this->headCarLineUp->getFirstNodeToDelete(brand);


	while (currentNode != nullptr)
	{
		if (nodeBeforeDeleted && currentNode != nullptr && currentNode->carData->brand != brand) {
			nodeAfterDeleted = currentNode;
		}

		// if exist any node before deleting node then remember it
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
				this->head = nullptr;
				return;
			}
		}

		// if doesnt exist any node before and it is not last in line-up then delete currentNode and iterate 
		//		or if next node from another brand line-up then set it to headNode
		else if (!nodeBeforeDeleted
			&& currentNode->next != nullptr
			&& currentNode != nullptr
			&& currentNode->carData->brand == brand) {

			prevNode = currentNode;
			currentNode = currentNode->next;

			delete prevNode;

			if (currentNode->carData->brand != brand) {
				this->head = currentNode;
				break;
			}

			continue;
		}

		// if doesnt exist any node before and it is last in line-up then set headNode to nullptr
		else if (!nodeBeforeDeleted
			&& currentNode->next == nullptr
			&& currentNode != nullptr
			&& currentNode->carData->brand == brand) {

			delete currentNode;
			this->head = nullptr;
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

			delete prevNode->next;
		}

		// connect node before deleted nodes and node after them
		if (nodeAfterDeleted) {
			nodeBeforeDeleted->next = nodeAfterDeleted;
		}
	}


}
void CarList::AddBrandToCarLineUp( CarNode* newCarBrandNode) {
	if (this->headCarLineUp != nullptr) {
		CarLineUpNode* currNode = this->headCarLineUp;
		CarLineUpNode* prevNode = nullptr;

		// find last node
		while (currNode != nullptr) {
			prevNode = currNode;
			currNode = currNode->next;
		}

		currNode = new CarLineUpNode(newCarBrandNode->carData->brand, newCarBrandNode);

		prevNode->next = currNode;
	}
	else {
		this->headCarLineUp = new CarLineUpNode(newCarBrandNode->carData->brand, newCarBrandNode);
	}
}
void CarList::formCarLineUp() {
	CarNode* currNode = this->head;
	if (currNode == nullptr) {
		cerr << "Error while forming car line up \nCar list doesnt exist \n";
		return;
	}

	this->headCarLineUp = nullptr;

	do {
		if (!(this->headCarLineUp->IsBrandExistInCarLineUp(currNode->carData->brand))) {
			this->AddBrandToCarLineUp(currNode);
		}

		currNode = currNode->next;
	} while (currNode != nullptr);
}