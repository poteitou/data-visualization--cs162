#ifndef SEARCHBAR_HPP
#define SEARCHBAR_HPP

#include <SFML/Graphics.hpp>
#include <string.h>

struct SearchBar
{
    SearchBar();
    SearchBar(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string defaultText, bool alphabet);

    void update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int capacity);
    void draw(sf::RenderWindow &mWindow);
    void reset(std::string defaultText);

    sf::RectangleShape mRect;
    sf::Text mText;
    std::string mValue;
    sf::Color mDefaultColor;
    sf::Color mHoveredColor;
    sf::Color mSelectedColor;
    bool mAlphabet;
    bool mHovered;
    bool mSelected;
};

#endif
