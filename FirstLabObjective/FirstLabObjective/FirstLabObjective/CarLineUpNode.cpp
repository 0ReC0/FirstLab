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
void CarLineUpNode::formCarLineUp(CarNode*& headNode) {
	CarNode* currNode = headNode;
	CarLineUpNode* carLineUp = nullptr;

	do {
		if (!(carLineUp->IsBrandExistInCarLineUp(currNode->carData->brand))) {
			carLineUp->AddBrandToCarLineUp(currNode);
		}

		currNode = currNode->next;
	} while (currNode != nullptr);
}

void CarLineUpNode::AddBrandToCarLineUp(CarNode* newCarBrandNode) {
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
		*this = *(new CarLineUpNode(newCarBrandNode->carData->brand, newCarBrandNode));
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
		currNode = currNode->next;

		if (currNode == nullptr) {
			cout << "This brand doesnt exist \n";
			return nullptr;
		}
	}
	return nullptr;
}

void CarLineUpNode::deleteBrandCars(CarNode*& headNode) {
	cout << "Enter car's brand, which you want to delete from list \n";
	string brand;
	cin >> brand;

	CarNode* nodeBeforeDeleted = nullptr;
	CarNode* nodeAfterDeleted = nullptr;
	CarNode* firstNodeToDelete = nullptr;
	CarNode* currentNode = headNode;
	CarNode* prevNode = nullptr;

	firstNodeToDelete = this->getFirstNodeToDelete(brand);


	while (currentNode != nullptr)
	{
		if (nodeBeforeDeleted && currentNode != nullptr && currentNode->carData->brand != brand) {
			nodeAfterDeleted = currentNode;
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
			&& currentNode->carData->brand == brand) {

			prevNode = currentNode;
			currentNode = currentNode->next;

			delete prevNode;

			if (currentNode->carData->brand != brand) {
				headNode = currentNode;
				break;
			}

			continue;
		}

		// if doesnt exit any node before and it is last in line-up then set headNode to nullptr
		else if (!nodeBeforeDeleted
			&& currentNode->next == nullptr
			&& currentNode != nullptr
			&& currentNode->carData->brand == brand) {

			delete currentNode;
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

			delete prevNode->next;
		}

		// connect node before deleted nodes and node after them
		if (nodeAfterDeleted) {
			nodeBeforeDeleted->next = nodeAfterDeleted;
		}
	}


}