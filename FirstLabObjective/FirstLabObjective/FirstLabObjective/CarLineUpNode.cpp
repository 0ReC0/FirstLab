#include "CarLineUpNode.h"

CarLineUpNode::CarLineUpNode() {
	this->brand = "";
	this->firstCarNodeInLineUp = new CarNode();
	this->next = nullptr;
}
CarLineUpNode::CarLineUpNode(string brand, CarNode* firstCarNodeInLineUp) {
	this->brand = brand;
	this->firstCarNodeInLineUp = firstCarNodeInLineUp;
	this->next = nullptr;
};
void CarLineUpNode::showList() {
	if (this) {
		CarLineUpNode* currLineUpNode = this;
		while (currLineUpNode != nullptr) {
			cout << setw(15) << "Brand " << currLineUpNode->brand << endl;
			CarNode* currNode = currLineUpNode->firstCarNodeInLineUp;
			cout << setw(30) << "Brand" << setw(30) << "Country" << setw(30) << "Manufacture year" << endl;
			while (currNode != nullptr && currNode->carData->brand == currLineUpNode->brand) {
				cout << setw(30) << currNode->carData->brand << setw(30) << currNode->carData->manufacturerCountry << setw(30) << currNode->carData->manufactureYear << endl;
				currNode = currNode->next;
			}

			currLineUpNode = currLineUpNode->next;
		}
	}
	else {
		cerr << "Error while showing list" << endl;
	}
}
void CarLineUpNode::formCarLineUp(CarLineUpNode*& headCarLineUpNode, CarNode* headNode) {
	CarNode* currNode = headNode;
	if (headNode == nullptr) {
		cerr << "Error while forming car line up \nCar list doesnt exist \n";
		return;
	}

	CarLineUpNode* carLineUp = headCarLineUpNode;
	carLineUp = nullptr;

	do {
		if (!(carLineUp->IsBrandExistInCarLineUp(currNode->carData->brand))) {
			carLineUp->AddBrandToCarLineUp(headCarLineUpNode, currNode);
		}

		currNode = currNode->next;
	} while (currNode != nullptr);
}

void CarLineUpNode::AddBrandToCarLineUp(CarLineUpNode*& headCarLineUpNode, CarNode* newCarBrandNode) {
	if (this != nullptr) {
		CarLineUpNode* currNode = this;
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
		headCarLineUpNode = new CarLineUpNode(newCarBrandNode->carData->brand, newCarBrandNode);
	}
}

bool CarLineUpNode::IsBrandExistInCarLineUp(string brand) {
	if (this == nullptr)
		return false;

	CarLineUpNode* currNode = this;
	while (currNode != nullptr) {
		if (currNode->brand == brand)
			return true;
		currNode = currNode->next;
	}
	return false;
}

CarNode* CarLineUpNode::getFirstNodeToDelete(string brand) {
	CarLineUpNode* currNode = this;
	while (currNode != nullptr)
	{
		if (this->brand == brand) {
			return currNode->firstCarNodeInLineUp;
			break;
		}
		if (currNode == nullptr) {
			cout << "This brand doesnt exist \n";
			return nullptr;
		}
		currNode = currNode->next;

	}
	return nullptr;
}

