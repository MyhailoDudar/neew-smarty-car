#include "Info.h"
#include <iostream>

string intToString(int number) {
    if (number == 0) {
        return "0";
    }
    bool minus = number < 0;
    if (minus) {
        number *= -1;
    }
    string line;
    while (number > 0) {
        int n = number % 10;
        number /= 10;
        line.insert(line.begin(), static_cast<char>(n + '0'));
    }
    if (minus) {
        line.insert(line.begin(), '-');
    }
    return line;
}

using namespace std;

Info::Info(string Model, string Etype, string color, int MaxVel, string Owner, int Age)
    : Model(Model), Etype(Etype), color(color), MaxVel(MaxVel), Owner(Owner), Age(Age) {}

string Info::CarInfo() {
    cout << "Model: " << Model << "\nEngine type: " << Etype << "\nColor: " << color
        << "\nMax speed: " << MaxVel << " km/h\n" << endl;
    return Model + " " + Etype + " " + color + " " + intToString(MaxVel);
}

string Info::DriverInfo() {
    cout << "Owner is: " << Owner << ", Age: " << Age << " years old" << endl;
    return Owner + " " + intToString(Age);
}
