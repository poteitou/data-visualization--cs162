#include "screen.hpp"

Screen::Screen(sf::RenderWindow& window, std::vector<Button> button)
: mWindow(window)
{
    vector<Button> button.resize(7);
    button[0] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Static Array", font, 25);
    button[1] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Dynamic Array", font, 25);
    button[2] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Singly Linked List", font, 25);
    button[3] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Doubly Linked List", font, 25);
    button[4] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Circular Linked List", font, 25);
    button[5] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Stack", font, 25);
    button[6] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 300), sf::Color::Cyan, sf::Color::Magenta, "Queue", font, 25);
}

void Screen::draw()
{
    for (int i = 0; i < 7; i++)
        mWindow.draw(button[i]);
}

void Screen::setHovered()
{
    for (int i = 0; i < 7; i++)
        button[i].setHovered(button[i].isMouseOver());
}