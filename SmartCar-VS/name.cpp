#include "Info.h"
#include "Conditioner.h"
#include "Signal.h"
#include "Engine.h"
#include "Media.h"
#include <iostream>
#include <string>

using namespace std;

Conditioner Vent("Conditioner", 20);
Engine CarEngine("Car Engine");
Media AudioSystem("Media System", 100);
Signal CarSignal("Car Signal");
Info CarInfo("Tesla Model X", "Double electric", "White", 250, "Stephan", 25);

int main()
{
    int temp;
    int vol;
    string op;
    bool ownerNear;
    cout << "Smart Car VS v0.1f4 \nTo view list of commands type: \"Help\"" << endl;

    while (true)
    {
        if (op == "")
        {
            cout << "-> ";
        }
        getline(cin, op);

        if (op == "Quit" || op == "quit")
        {
            break;
        }

        switch (hash<string>{}(op))
        {
        case hash<string>{}("help"): 
        case hash<string>{}("Help"):
            cout << "List of commands:\n"
                 << "Set temperature\nGet temperature\nTurn conditioner on\nTurn conditioner off\n"
                 << "Turn engine on\nTurn engine off\nEngine status\n"
                 << "Set volume\nMedia status\nTurn media on\nTurn media off\n"
                 << "Turn signal on\nTurn signal off\nSignal status\n"
                 << "Car info\nDriver info\n"
                 << "Help\n";
            break;
        case hash<string>{}("Set temperature"):
            cout << "Enter desired temperature: ";
            cin >> temp;
            Vent.setTemperature(temp);
            cin.ignore();
            break;
        case hash<string>{}("Get temperature"):
            cout << "Current temperature: " << Vent.getTemperature() << "\n";
            break;
        case hash<string>{}("Turn conditioner on"):
            Vent.turnOn();
            break;
        case hash<string>{}("Turn conditioner off"):
            Vent.turnOff();
            break;
        case hash<string>{}("Turn engine on"):
            CarEngine.turnOn();
            break;
        case hash<string>{}("Turn engine off"):
            CarEngine.turnOff();
            break;
        case hash<string>{}("Engine status"):
            CarEngine.getStatus();
            break;
        case hash<string>{}("Set volume"):
            cout << "Enter desired volume: ";
            cin >> vol;
            AudioSystem.setVolume(vol);
            cin.ignore();
            break;
        case hash<string>{}("Media status"):
            AudioSystem.getStatus();
            break;
        case hash<string>{}("Turn media on"):
            AudioSystem.turnOn();
            break;
        case hash<string>{}("Turn media off"):
            AudioSystem.turnOff();
            break;
        case hash<string>{}("Turn signal on"):
            CarSignal.turnOn();
            break;
        case hash<string>{}("Turn signal off"):
            CarSignal.turnOff();
            break;
        case hash<string>{}("Signal status"):
            CarSignal.getStatus();
            break;
        case hash<string>{}("Car info"):
            CarInfo.displayCarInfo();
            break;
        case hash<string>{}("Driver info"):
            CarInfo.displayDriverInfo();
            break;
        default:
            cout << "Unknown command. Type 'Help' to see the list of commands.\n";
        }

        op = "";
    }

    return 0;
}
