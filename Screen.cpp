#include "Screen.hpp"

Screen::Screen(sf::RenderWindow &window, sf::Font &font)
    : mWindow(window), mFont(font), mData(0), mMenu(mWindow, mFont), mStaticArray(mWindow, mFont)
{
    
}

void Screen::update(bool mousePress, sf::Vector2i mousePosition, char keyPress, float dt)
{
    switch(mData)
    {
    case 0: // Menu
        mMenu.update(mousePress, mousePosition, mData);
        break;
    case 1:
        mStaticArray.update(mousePress, mousePosition, keyPress, mData, dt);
        break;
    default:
        break;
    }
}

void Screen::draw(float dt)
{
    switch(mData)
    {
    case 0: // Menu
        mMenu.draw(mWindow);
        break;
    case 1:
        mStaticArray.draw(dt);
        break;
    default:
        break;
    }
}

