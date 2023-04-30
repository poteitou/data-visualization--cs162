#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "../interface/Button.hpp"

#include <fstream>

struct Menu
{
    Menu(sf::RenderWindow &window, sf::Font &font);
    void handle(sf::Event event, int &mData);
    void draw(sf::RenderWindow &mWindow);

    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    std::vector<Button> mButton;
};

#endif // MENU_HPP
