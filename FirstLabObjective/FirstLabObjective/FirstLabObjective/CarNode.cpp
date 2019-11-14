#include "CarNode.h"

CarNode::CarNode() {
	this->next = nullptr;
	this->carData = new Car();
}
CarNode::CarNode(Car* car, CarNode* next) {
	this->next = next;
	this->carData = car;
}



void CarNode::showNodeInfo() {
	if (this == nullptr) {
		cerr << "Error while showing info about node \n";
		return;
	}

	cout << setw(15) << "Brand" << setw(30) << "Country" << setw(30) << "Manufacture year" << endl;
	cout << setw(15) << this->carData->brand << setw(30) << this->carData->manufacturerCountry << setw(30) << this->carData->manufactureYear << endl;
}

