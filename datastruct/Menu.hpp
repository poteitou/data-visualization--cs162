#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "../interface/Button.hpp"

struct Menu
{
    Menu(sf::RenderWindow &window, sf::Font &font);
    void update(bool mousePress, sf::Vector2i mousePosition, int &mData);
    void draw();

    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    std::vector<Button> mButton;

    bool mousePress;
    sf::Vector2i mousePosition;
};

#endif // MENU_HPP
