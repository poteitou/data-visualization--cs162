#ifndef SEARCHBAR_HPP
#define SEARCHBAR_HPP

#include <SFML/Graphics.hpp>

class SearchBar
{
public:
    SearchBar(sf::RenderWindow &window, sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string defaultText);

    void handleEvent(sf::Event event);
    void draw();

    std::string getValue() const;

private:
    sf::RenderWindow &mWindow;
    sf::RectangleShape mRectangle;
    sf::Text mText;
    std::string mValue;
    sf::Color mDefaultColor;
    sf::Color mSelectedColor;
    bool mHovered;
    bool mSelected;

    bool contains(sf::Vector2f point) const;
};

#endif
