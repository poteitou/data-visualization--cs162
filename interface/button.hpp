#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button 
{
public:
    Button(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, std::string textString, sf::Font& font, int sizeText);

    void draw();
    bool isMouseOver();
    bool checkPress();
    void setHovered(bool value);

private:
    sf::RenderWindow& mWindow;
    sf::RectangleShape mShape;
    sf::Text mText;
    sf::Color mColor;
    sf::Color mHoverColor;
    bool mHovered;
};

#endif // BUTTON_HPP

