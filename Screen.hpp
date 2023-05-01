#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "datastruct/StaticArray.hpp"
#include "datastruct/Menu.hpp"

struct Screen
{
    Screen(sf::RenderWindow &window, sf::Font &font);
    void update(bool mousePress, sf::Vector2i mousePosition, char keyPress, float dt);
    void draw(float dt);

    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    Menu mMenu;
    StaticArray mStaticArray;
    int mData;
};

#endif // SCREEN_HPP