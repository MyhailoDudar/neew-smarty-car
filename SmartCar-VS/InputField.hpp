#include <iostream>
using namespace std;

class InputField : public Box{
    public:
    InputField(sf::RenderWindow* window, int width, int height, int x, int y, sf::Color color = sf::Color::White) : Box(window, width, height, x, y, color){
        shape.setOutlineColor(sf::Color::Green);
    }
    void eventListener(sf::Event* event){
        if(event->type == sf::Event::MouseButtonPressed){
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
            if(shape.getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
                active = true;
            }
            else{
                active = false;
            }
        }
        if(!active){
            return;
        }
        if(event->type != sf::Event::KeyPressed){
            return;
        }
        int keyCode = event->key.code;
        if(keyCode >=48 && keyCode <= 57){
            
             textLine.push_back(keyCode);
             cout << keyCode << endl;
            
        }
        if(keyCode == sf::Keyboard::BackSpace && textLine.size() != 0){
            textLine.resize(textLine.size() - 1);
        }
        text.setString(textLine);
    }
    void display() {
        process();
        this->window->draw(shape);
        this->window->draw(text);
    }
    void setupText(sf::Font* font, int textSize){
        text.setFont(*font);
        text.setCharacterSize(textSize);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect shapeRect =  shape.getGlobalBounds();
        sf::FloatRect textRect = text.getGlobalBounds();
        float xOffset = (shapeRect.width - textRect.width) / 2;
        float yOffset = (shapeRect.height - textRect.height) / 2;
        text.setPosition(shapeRect.left + 20, shapeRect.top + yOffset);
    }
    string getText() {
       // cout << textLine;
        return textLine;

    }
    protected:
        void process(){
            activeProcess();
        }
        void activeProcess(){
            if(active){
                shape.setOutlineThickness(3);
            }
            else{
                shape.setOutlineThickness(0);
            }
        }
        bool active = false;
        string textLine = "";
        sf::Text text;
};
