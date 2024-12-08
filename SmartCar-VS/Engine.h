#ifndef ENGINE_H
#define ENGINE_H

#include "Device.h"
#include <string>

class Engine : public Device {
public:
    Engine(const std::string& name);
    void TurnOn(bool ownerNear);
protected:
    bool state;
};

#endif // ENGINE_H
