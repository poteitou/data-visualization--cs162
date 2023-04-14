#include "screen.hpp"

Screen::Screen(sf::RenderWindow& window, sf::Font& font)
: mWindow(window)
{
    mButton.push_back(Button(mWindow, sf::Vector2f(300, 100), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Blue, "Static Array", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(300, 100), sf::Vector2f(100, 500), sf::Color::Cyan, sf::Color::Blue, "Dynamic Array", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(300, 100), sf::Vector2f(600, 300), sf::Color::Cyan, sf::Color::Blue, "Singly Linked List", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(300, 100), sf::Vector2f(600, 500), sf::Color::Cyan, sf::Color::Blue, "Doubly Linked List", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(300, 100), sf::Vector2f(600, 700), sf::Color::Cyan, sf::Color::Blue, "Circular Linked List", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(300, 100), sf::Vector2f(1200, 300), sf::Color::Cyan, sf::Color::Blue, "Stack", font, 25));
    mButton.push_back(Button(mWindow, sf::Vector2f(300, 100), sf::Vector2f(1200, 500), sf::Color::Cyan, sf::Color::Blue, "Queue", font, 25));
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