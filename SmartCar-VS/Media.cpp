#include "Media.h"
#include <iostream>

Media::Media(const std::string& name, int vol) : Device(name), vol(vol) {}

void Media::SetVol(int vol) {
    std::cout << "Current volume is: " << vol << ", Insert new volume: ";
    std::cin >> vol;
}

int Media::Status() {
   // std::cout << "Device: " << name << ", Volume: " << vol << std::endl;
    return vol;
}

