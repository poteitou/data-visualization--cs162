#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "datastruct/StaticArray.hpp"
#include "datastruct/Menu.hpp"

class Screen
{
public:
    Screen(sf::RenderWindow& window, sf::Font& font);
    void handle(sf::Event event);
    void draw(float dt);

private:
    sf::RenderWindow& mWindow;
    sf::Font& mFont;
    Menu mMenu;
    StaticArray mStaticArray;
    int mData; 
};

#endif // SCREEN_HPP