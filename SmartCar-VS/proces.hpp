class Proces
{
public:
	Proces(int timeOut) {
		this->timeOut = timeOut;
	}
	
	void Run() {
		if (clock.getElapsedTime().asMilliseconds()<timeOut) {
			return;
		}
		clock.restart();
		(*callback)();
	}
	void (*callback)();
protected:
	sf::Clock clock;
	int timeOut = 0;
};