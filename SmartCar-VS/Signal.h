#ifndef SIGNAL_H
#define SIGNAL_H

#include "Device.h"

using namespace std;

class Signal :public Device {
public:
	Signal(const string& name);
};

#endif // !SIGNAL_H
