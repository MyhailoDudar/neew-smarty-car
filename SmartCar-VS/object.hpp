using namespace std;
class Box {
public:
  Box(sf::RenderWindow* window, int width, int height, int x, int y, sf::Color color = sf::Color::White) {
    shape = sf::RectangleShape(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(color);
    this->window = window;
    type = "object";
  }
  virtual void display() {
    process();
    this->window->draw(shape);
  }
  bool isIntersects(Box box) {
    if (shape.getGlobalBounds().intersects(box.getRect())) {
      return true;
    }
    return false;
  }
  sf::FloatRect getRect() {
    return shape.getGlobalBounds();
  }
  virtual void eventListener(sf::Event* event) {

  }
  bool isTypeOf(string typ) {
      if (type == typ)
      {
          return true;
      }
      return false;
  }
  int getXCords() {
      return shape.getPosition().x;
  }
protected:
  virtual void process() {

  }
  sf::RectangleShape shape;
  sf::RenderWindow* window;
  string type;
     
};


