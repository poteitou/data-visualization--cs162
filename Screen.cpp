#include "Screen.hpp"

Screen::Screen(sf::RenderWindow &window, sf::Font &font)
    : mWindow(window), mFont(font), mData(0), mMenu(mWindow, mFont), mStaticArray(mWindow, mFont)
{

}

void Screen::handle(sf::Event event, float dt)
{
    switch(mData)
    {
    case 0: // Menu
        mMenu.handle(event, mData);
        break;
    case 1:
        mStaticArray.handle(event, mData, dt);
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

