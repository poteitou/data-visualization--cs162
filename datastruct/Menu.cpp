#include "Menu.hpp"

Menu::Menu(sf::RenderWindow &window, sf::Font &font)
    : mWindow(window), mFont(font)
{
    mButton.resize(7);
    mButton[0] = Button(sf::Vector2f(300, 100), sf::Vector2f(200, 300), sf::Color::Cyan, sf::Color::Blue, "Static Array", mFont, 30);
    mButton[1] = Button(sf::Vector2f(300, 100), sf::Vector2f(200, 500), sf::Color::Cyan, sf::Color::Blue, "Dynamic Array", mFont, 30);
    mButton[2] = Button(sf::Vector2f(400, 100), sf::Vector2f(600, 300), sf::Color::Cyan, sf::Color::Blue, "Singly Linked List", mFont, 30);
    mButton[3] = Button(sf::Vector2f(400, 100), sf::Vector2f(600, 500), sf::Color::Cyan, sf::Color::Blue, "Doubly Linked List", mFont, 30);
    mButton[4] = Button(sf::Vector2f(400, 100), sf::Vector2f(600, 700), sf::Color::Cyan, sf::Color::Blue, "Circular Linked List", mFont, 30);
    mButton[5] = Button(sf::Vector2f(300, 100), sf::Vector2f(1100, 300), sf::Color::Cyan, sf::Color::Blue, "Stack", mFont, 30);
    mButton[6] = Button(sf::Vector2f(300, 100), sf::Vector2f(1100, 500), sf::Color::Cyan, sf::Color::Blue, "Queue", mFont, 30);

    mousePress = false;
}

void Menu::handle(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
    {
        mousePress = true;
    }
    else
    {
        mousePress = false;
    }
    mousePosition = sf::Mouse::getPosition(mWindow);
}

void Menu::update(int &mData)
{
    for (int i = 0; i < 7; i++)
    {
        if (mButton[i].setMouseOver(mousePosition) && mousePress)
        {
            mData = i + 1;
            mButton[i].reset();
        }
    }
}

void Menu::draw(sf::RenderWindow &mWindow)
{
    for (int i = 0; i < 7; i++)
        mButton[i].draw(mWindow);
}

