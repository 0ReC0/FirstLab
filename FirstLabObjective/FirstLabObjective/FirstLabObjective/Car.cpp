#include "Car.h"

Car::Car() {
	this->brand = "";
	this->manufacturerCountry = "";
	this->manufactureYear = 0;
}

void Car::fillNodeData() {
	bool error;

	cout << "this's brand" << endl;
	do {
		cin >> this->brand;
		if (this->brand == "") {
			error = 1;
			cout << "Re-enter this's brand";
		}
		else
			error = 0;
	} while (error);


	cout << "Manufacturer country" << endl;
	cin >> this->manufacturerCountry;

	do {
		cout << "Manufacture year" << endl;
		cin >> this->manufactureYear;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32000, '\n');
			cerr << "Manufacture year must be numeric \n Re-entry \n";
			error = true;
			continue;
		}
		if (this->manufactureYear < 1672) {
			error = true;
			cout << "Manufacture year must be greater than 1672 ";
		}
		else
			error = false;
	} while (error);
}