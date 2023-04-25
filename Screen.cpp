#include "Screen.hpp"

Screen::Screen(sf::RenderWindow &window, sf::Font &font)
    : mWindow(window), mFont(font), mData(0), mStaticArray(mWindow, mFont), mMenu(mWindow, mFont)
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
        mMenu.draw();
        break;
    case 1:
        mStaticArray.draw(dt);
        break;
    default:
        break;
    }
}

