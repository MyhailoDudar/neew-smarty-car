class Button : public Box {
public:
	Button(sf::RenderWindow* window, string text, sf::Font* font, int width, int height, int x, int y, sf::Color color = sf::Color::White, sf::Color textcolor = sf::Color::Black) : Box(window, width, height, x, y, color) {
		this->text.setString(text);
		this->text.setFont(*font);
		this->text.setCharacterSize(15);
		this ->textcolor = textcolor;
	}
	void init(int textSize) {
		this->text.setCharacterSize(textSize);
		sf::FloatRect sahpeRect = this->shape.getGlobalBounds();
		sf::FloatRect textRect = this->text.getGlobalBounds();
		float xOffset = (sahpeRect.width - textRect.width) / 2;
		float yOffset = (sahpeRect.height - textRect.height) / 2;
		this->text.setPosition(sahpeRect.left + xOffset, sahpeRect.top + yOffset);
		this->text.setFillColor(textcolor);
	}
	void display() {
		process();
		this->window->draw(shape);
		this->window->draw(text);
	}
	void eventListener(sf::Event* event) {
		if (event->type != sf::Event::MouseButtonPressed) {
			return;
		}
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
		if (!shape.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
			return;
		}
		(*callback)();
	}
	void setAction(void(*callback)(void)) {
		this->callback = callback;
	}
protected:
	void(*callback)(void);
	sf::Text text;
	sf::Color textcolor;
};