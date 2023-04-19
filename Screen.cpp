#include "Screen.hpp"

Screen::Screen(sf::RenderWindow &window, sf::Font &font)
    : mWindow(window), mFont(font), mData(0), mStaticArray(mWindow, mFont), mMenu(mWindow, mFont)
{

}

void Screen::draw()
{
    switch(mData)
    {
    case 0: // Menu
        mMenu.draw(mData);
        break;
    case 1:
        mStaticArray.draw();
        break;
    default:
        break;
    }
}

void Screen::update(sf::Event event)
{
    
}