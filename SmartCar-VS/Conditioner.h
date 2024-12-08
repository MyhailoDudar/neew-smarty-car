#ifndef CONDiTiONER_H
#define CONDiTiONER_H

#include "Device.h"

using namespace std;

class Conditioner :public Device {
public:
	Conditioner(const string& name, int temp = 20);
	void set_temp(int temp);
	int Status();
protected:
	int temp;

};

#endif // !CONDiTiONER_H