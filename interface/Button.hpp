#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

struct Button
{
    Button();
    Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, std::string textString, sf::Font &font, int sizeText);

    void draw(sf::RenderWindow &mWindow);
    bool setMouseOver(sf::Vector2i mousePosition);
    void reset();

    sf::RectangleShape mRect;
    sf::Text mText;
    sf::Color mColor;
    sf::Color mHoverColor;
    bool mHovered;
};

#endif // BUTTON_HPP

