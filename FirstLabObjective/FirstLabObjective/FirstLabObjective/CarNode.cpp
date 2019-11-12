#include "CarNode.h"

CarNode::CarNode() {
	this->next = nullptr;
	this->carData = new Car();
}


void CarNode::showList() {
	CarNode* currNode = this;
	cout << setw(15) << "Brand" << setw(15) << "Country" << setw(15) << "Manufacture year" << endl;
	while (currNode != nullptr) {
		cout << setw(15) << currNode->carData->brand << setw(15) << currNode->carData->manufacturerCountry << setw(15) << currNode->carData->manufactureYear << endl;
		currNode = currNode->next;
	}
}
void CarNode::showNodeInfo() {
	if (this == nullptr) {
		cerr << "Error while showing info about node \n";
		return;
	}

	cout << setw(15) << "Brand" << setw(15) << "Country" << setw(15) << "Manufacture year" << endl;
	cout << setw(15) << this->carData->brand << setw(15) << this->carData->manufacturerCountry << setw(15) << this->carData->manufactureYear << endl;
}

void CarNode::createList(int count) {
	this->carData->fillNodeData();

	for (int i = 1; i < count; i++) {
		cout << "\n Next car:" << endl;
		this->addNewNode();
	}
}

/*Adding new Node*/
void CarNode::addNewNode() {
	CarNode* currNode = this;
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

				if (prevNode != nullptr)
					prevNode->next = newCarNode;
				else
					*this = *newCarNode;
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

				if (prevNode != nullptr)
					prevNode->next = newCarNode;
				else
					*this = *newCarNode;

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


CarNode* CarNode::searchNodeInList() {
	CarNode* searchNode = new CarNode();

	searchNode->carData->fillNodeData();

	CarNode* currNode = this;
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