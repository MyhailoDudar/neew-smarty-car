#include "Conditioner.h"
#include <iostream>

using namespace std;

Conditioner::Conditioner(const string& name, int temp) :Device(name), temp(temp) {}

void Conditioner::set_temp(int temp) {
	cout << "temperature was set to: " << temp << "\'C" << endl;
	this->temp = temp;
}
int Conditioner::Status() {
	//cout << "temperature is set to: " << temp << "\'C" << endl;
	return temp;
}