#include <vector>
#include <iostream>

using namespace std;

class Screen {
public:
	Screen(sf::RenderWindow* window) {
		this->window = window;
	}
	void showScreen() {
		if (!enabled) {
			return;
		}
		for (int i = 0; i < ecshons.size(); i++) {
			ecshons[i]->Run();
		}
		window->clear();
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->display();
		}
		window->display();
	}
	void setObject(Box* obj) {
		objects.push_back(obj);
	}
	std::vector<Box*>* getObject() {
		return &objects;
	}
	void eventListener(sf::Event* event) {
		if (!enabled) {
			return;
		}
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->eventListener(event);
		}
	}
	void enable() {
		enabled = true;
		//cout << 'e' << endl;
	}
	void disable() {
		enabled = false;
		//cout << 'd' << endl;
	}
	void addEcshons(Proces* ect) {
		ecshons.push_back(ect);
	}
protected:
	sf::RenderWindow* window;
	std::vector<Box*> objects;
	std::vector<Proces*> ecshons;
	bool enabled = false;
};