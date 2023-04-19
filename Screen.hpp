#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "datastruct/StaticArray.hpp"
#include "datastruct/Menu.hpp"

class Screen
{
public:
    Screen(sf::RenderWindow& window, sf::Font& font);
    void draw();
    void update(sf::Event event);

private:
    sf::RenderWindow& mWindow;
    sf::Font& mFont;
    Menu mMenu;
    StaticArray mStaticArray;
    int mData; 
};

#endif // SCREEN_HPP