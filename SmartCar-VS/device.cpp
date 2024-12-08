#include "Device.h"
#include <iostream>

using namespace std;


Device::Device(const string& name) : name(name), state(false) {}

void Device::turnOn() {
	state = true;
	cout << name << " was turned on.\n";
}

void Device::turnOff() {
	state = false;
	cout << name << " was turned off.\n";
}

bool Device::status()const  {
	cout << name << (state ? " is turned on.\n" : " is turned off.\n"); 
	return state;
}