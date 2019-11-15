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
		if (currNode->brand == brand) {
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

