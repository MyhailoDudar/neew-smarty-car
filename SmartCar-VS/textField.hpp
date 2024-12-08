
class TextField:public Box
{
public:
	TextField(sf::Font* font,int fontSize,string text, sf::RenderWindow* window, int width, int height, int x, int y, sf::Color color = sf::Color::White) :Box(window, width, height, x, y, color) {
		this->text.setString(text);
		this->text.setFont(*font);
		this->text.setCharacterSize(fontSize);
	}
	void setUp() {
		sf::FloatRect boxRect = getRect();
		sf::FloatRect textRect = text.getGlobalBounds();
		float xOfSet = (boxRect.width - textRect.width) / 2;
		float yOfSet = (boxRect.height - textRect.height) / 2;
		text.setPosition(boxRect.left, boxRect.top);
 	}
	void display() {
		process();
		this->window->draw(shape);
		window->draw(text);
	}
	void setString(string name) {
		text.setString(name);
	}
	string getString() {
		return text.getString();
	}
protected:
	sf::Text text;
};
