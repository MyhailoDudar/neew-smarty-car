#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "proces.hpp"
#include "object.hpp"
#include "Button.hpp"
#include "textField.hpp"
#include "Screen.hpp"
#include "InputField.hpp"

#include "Info.h"
#include "Conditioner.h"
#include "Signal.h"
#include "Engine.h"
#include "Media.h"

#include "Functions.hpp"

using namespace std;

Conditioner Vent("Conditioner", 20);
Engine CarEngine("Car Engine");
Media AudioSystem("Media System", 100);
Signal CarSignal("Car Signal");
Info CarInfo("Tesla Model X", "Double electric", "White", 250, "Stephan", 25);

int stringToInt(const string& line) {
    string reverseStr;
    for (size_t i = 0; i < line.size(); i++) {
        if ((line[i] < '0' || line[i] > '9') && line[i] != '-') {
            break;
        }
        reverseStr.insert(0, 1, line[i]);
    }
    bool minus = false;
    if (!reverseStr.empty() && reverseStr[reverseStr.size() - 1] == '-') {
        minus = true;
        reverseStr.resize(reverseStr.size() - 1);
    }
    int result = 0;
    for (size_t i = 0; i < reverseStr.size(); i++) {
        result += (reverseStr[i] - '0') * static_cast<int>(pow(10, static_cast<int>(i)));
    }
    if (minus) {
        result *= -1;
    }
    return result;
}

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

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

sf::Color backColor = sf::Color::Black;
sf::Font font;
sf::RenderWindow window(sf::VideoMode(1900, 1000), "smart-car");

Screen MainDisplay(&window);
Screen Ventilate(&window);
Screen Engin(&window);
Screen Audio(&window);
Screen Sig(&window);
Screen Information(&window);

Button Back(&window, "<-", &font, 50, 50, 0, 0, sf::Color::Cyan);
Button Venta(&window, "Ventilation", &font, 100, 50, 10, 10, sf::Color::Yellow);
Button Engane(&window, "Engine", &font, 100, 50, 10, 65, sf::Color::Yellow);
Button Sound(&window, "Media", &font, 100, 50, 10, 120, sf::Color::Yellow);
Button Signaling(&window, "Signaling", &font, 100, 50, 10, 175, sf::Color::Yellow);
Button Inf(&window, "Info", &font, 100, 50, 10, 230, sf::Color::Yellow);

Button SetTemp(&window, "Set", &font, 100, 50, 200, 200, sf::Color::Cyan);
Button TurnVOn(&window, "On", &font, 50, 50, 320, 200, sf::Color::Cyan);
Button TurnVOff(&window, "Off", &font, 50, 50, 320, 280, sf::Color::Cyan);
InputField Temp(&window, 250, 100, 500, 300);
TextField CurTemp(&font, 25, "Current Temp:", &window, 80, 50, 400, 20, sf::Color::Transparent);
TextField CurVOn(&font, 25, "Vent Status:", &window, 50, 50, 480, 20, sf::Color::Transparent);

Button TurnEOn(&window, "On", &font, 50, 50, 320, 200, sf::Color::Cyan);
Button TurnEOff(&window, "Off", &font, 50, 50, 320, 280, sf::Color::Cyan);
TextField CurEng(&font, 25, "Engine Status:", &window, 50, 50, 400, 20, sf::Color::Transparent);

Button SetVol(&window, "Set", &font, 100, 50, 200, 200, sf::Color::Cyan);
Button TurnMOn(&window, "On", &font, 50, 50, 320, 200, sf::Color::Cyan);
Button TurnMOff(&window, "Off", &font, 50, 50, 320, 280, sf::Color::Cyan);
InputField Vol(&window, 250, 100, 500, 300);
TextField CurMOn(&font, 25, "Media Status:", &window, 50, 50, 400, 20, sf::Color::Transparent);
TextField CurVol(&font, 25, "Volume:", &window, 80, 50, 400, 50, sf::Color::Transparent);

Button TurnSOn(&window, "On", &font, 50, 50, 320, 200, sf::Color::Cyan);
Button TurnSOff(&window, "Off", &font, 50, 50, 320, 280, sf::Color::Cyan);
TextField CurSignal(&font, 25, "Signal Status:", &window, 50, 50, 400, 20, sf::Color::Transparent);

TextField driver(&font, 25, "Driver: ", &window, 200, 50, 400, 20, sf::Color::Transparent);
TextField car(&font, 25, "Car Info: ", &window, 200, 50, 400, 80, sf::Color::Transparent);

void InTemp() {
    Vent.set_temp(stringToInt(Temp.getText()));
}
void InVol() {
    AudioSystem.SetVol(stringToInt(Vol.getText()));
}

void GoBack() {
    MainDisplay.enable();
    Ventilate.disable();
    Audio.disable();
    Engin.disable();
    Sig.disable();
    Information.disable();
}

void VentScr() {
    MainDisplay.disable();
    Ventilate.enable();
}
void EngScr() {
    MainDisplay.disable();
    Engin.enable();
}
void MedScr() {
    MainDisplay.disable();
    Audio.enable();
}
void SigScr() {
    MainDisplay.disable();
    Sig.enable();
}
void InfScr() {
    MainDisplay.disable();
    Information.enable();
}

void VentOn() {
    Vent.turnOn();
}
void VentOff() {
    Vent.turnOff();
}

void EngOn() {
    CarEngine.turnOn();
}
void EngOff() {
    CarEngine.turnOff();
}

void MedOn() {
    AudioSystem.turnOn();
}
void MedOff() {
    AudioSystem.turnOff();
}

void SigOn() {
    CarSignal.turnOn();
}
void SigOff() {
    CarSignal.turnOff();
}

int main()
{
    if (!font.loadFromFile("./Fonts/arial.ttf")) {
        cout << "Failed to load font!" << endl;
        return -1;
    }

    Back.setAction(GoBack);
    Venta.setAction(VentScr);
    Engane.setAction(EngScr);
    Sound.setAction(MedScr);
    Signaling.setAction(SigScr);
    Inf.setAction(InfScr);

    SetTemp.setAction(InTemp);
    SetVol.setAction(InVol);
    SetTemp.init(10);
    SetVol.init(10);

    TurnVOn.setAction(VentOn);
    TurnVOff.setAction(VentOff);
    TurnVOn.init(10);
    TurnVOff.init(10);

    TurnEOn.setAction(EngOn);
    TurnEOff.setAction(EngOff);
    TurnEOn.init(10);
    TurnEOff.init(10);

    TurnMOn.setAction(MedOn);
    TurnMOff.setAction(MedOff);
    TurnMOn.init(10);
    TurnMOff.init(10);

    TurnSOn.setAction(SigOn);
    TurnSOff.setAction(SigOff);
    TurnSOn.init(10);
    TurnSOff.init(10);

    MainDisplay.setObject(&Venta);
    MainDisplay.setObject(&Engane);
    MainDisplay.setObject(&Sound);
    MainDisplay.setObject(&Signaling);
    MainDisplay.setObject(&Inf);

    Ventilate.setObject(&SetTemp);
    Ventilate.setObject(&CurTemp);
    Ventilate.setObject(&CurVOn);
    Ventilate.setObject(&Temp);
    Ventilate.setObject(&TurnVOn);
    Ventilate.setObject(&TurnVOff);
    Ventilate.setObject(&Back);

    Engin.setObject(&TurnEOn);
    Engin.setObject(&TurnEOff);
    Engin.setObject(&CurEng);
    Engin.setObject(&Back);

    Audio.setObject(&SetVol);
    Audio.setObject(&TurnMOff);
    Audio.setObject(&TurnMOn);
    Audio.setObject(&Vol);
    Audio.setObject(&CurMOn);
    Audio.setObject(&CurVol);
    Audio.setObject(&Back);

    Sig.setObject(&TurnSOff);
    Sig.setObject(&TurnSOn);
    Sig.setObject(&CurSignal);
    Sig.setObject(&Back);

    Information.setObject(&driver);
    Information.setObject(&car);
    Information.setObject(&Back);

    CurTemp.setUp();
    CurVOn.setUp();
    CurEng.setUp();
    CurMOn.setUp();
    CurVol.setUp();
    CurSignal.setUp();
    driver.setUp();
    car.setUp();

    Temp.setupText(&font, 10);
    Vol.setupText(&font, 10);

    cout << "Smart Car VS v0.1f4\nTo view list of commands type: \"Help\"" << endl;
    MainDisplay.enable();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            MainDisplay.eventListener(&event);
            Ventilate.eventListener(&event);
            Engin.eventListener(&event);
            Audio.eventListener(&event);
            Sig.eventListener(&event);
            Information.eventListener(&event);
        }

        CurTemp.setString("Current Temp: " + intToString(Vent.Status()));
        CurVOn.setString("Vent Status: " + string((Vent.Status() ? "On" : "Off")));

        CurEng.setString("Engine Status: " + string(CarEngine.status() ? "On" : "Off"));

        CurMOn.setString("Media Status: " + string(AudioSystem.status() ? "On" : "Off"));
        CurVol.setString("Volume: " + intToString(AudioSystem.Status()));

        CurSignal.setString("Signal Status: " + string(CarSignal.status() ? "On" : "Off"));

        driver.setString("Driver: " + CarInfo.DriverInfo());
        car.setString("Car Info: " + CarInfo.CarInfo());

        window.clear(backColor);

        MainDisplay.showScreen();
        Ventilate.showScreen();
        Engin.showScreen();
        Audio.showScreen();
        Sig.showScreen();
        Information.showScreen();

        window.display();
    }

    return 0;
}
