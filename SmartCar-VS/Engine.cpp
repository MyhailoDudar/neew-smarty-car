#include "Engine.h"
#include <iostream>

Engine::Engine(const std::string& name) : Device(name), state(false) {}

void Engine::TurnOn(bool ownerNear) {
    if (ownerNear) {
        std::cout << "Engine was turned on.\n";
        state = true;
    }
}

