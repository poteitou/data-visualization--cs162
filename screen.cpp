#include "screen.hpp"

Screen::Screen(sf::RenderWindow& window, sf::Font& font)
: mWindow(window)
{
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Static Array", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 500), sf::Color::Cyan, sf::Color::Magenta, "Dynamic Array", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(600, 300), sf::Color::Cyan, sf::Color::Magenta, "Singly Linked List", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(600, 500), sf::Color::Cyan, sf::Color::Magenta, "Doubly Linked List", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(600, 700), sf::Color::Cyan, sf::Color::Magenta, "Circular Linked List", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(1200, 300), sf::Color::Cyan, sf::Color::Magenta, "Stack", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(1200, 500), sf::Color::Cyan, sf::Color::Magenta, "Queue", font, 25));
}

void Screen::draw()
{
    for (int i = 0; i < 7; i++)
        mButton[i].draw();
}

void Screen::setHovered()
{
    for (int i = 0; i < 7; i++)
        mButton[i].setHovered(mButton[i].isMouseOver());
}