#include "Menu.hpp"

Menu::Menu(sf::RenderWindow &window, sf::Font &font)
    : mWindow(window), mFont(font)
{
    mButton.resize(7);
    mButton[0] = Button(sf::Vector2f(300, 100), sf::Vector2f(200, 350), sf::Color(160, 220, 255), sf::Color(50, 140, 200), "Static Array", mFont, 30);
    mButton[1] = Button(sf::Vector2f(300, 100), sf::Vector2f(200, 500), sf::Color(160, 220, 255), sf::Color(50, 140, 200), "Dynamic Array", mFont, 30);
    mButton[2] = Button(sf::Vector2f(400, 100), sf::Vector2f(600, 300), sf::Color(160, 220, 255), sf::Color(50, 140, 200), "Singly Linked List", mFont, 30);
    mButton[3] = Button(sf::Vector2f(400, 100), sf::Vector2f(600, 450), sf::Color(160, 220, 255), sf::Color(50, 140, 200), "Doubly Linked List", mFont, 30);
    mButton[4] = Button(sf::Vector2f(400, 100), sf::Vector2f(600, 600), sf::Color(160, 220, 255), sf::Color(50, 140, 200), "Circular Linked List", mFont, 30);
    mButton[5] = Button(sf::Vector2f(300, 100), sf::Vector2f(1100, 350), sf::Color(160, 220, 255), sf::Color(50, 140, 200), "Stack", mFont, 30);
    mButton[6] = Button(sf::Vector2f(300, 100), sf::Vector2f(1100, 500), sf::Color(160, 220, 255), sf::Color(50, 140, 200), "Queue", mFont, 30);
}

void Menu::update(bool mousePress, sf::Vector2i mousePosition, int &mData)
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

void Menu::draw()
{
    sf::Font mFont1;
    mFont1.loadFromFile("resources/fonts/milestone.ttf");
    
    sf::Text text1;
    text1.setString("Data   structure     Visualization");
    text1.setCharacterSize(120);
    text1.setPosition(150, 40);
    text1.setFont(mFont1);
    text1.setFillColor(sf::Color(230, 100, 100));

    sf::Text text2;
    text2.setString("Choose a data structure:");
    text2.setCharacterSize(45);
    text2.setPosition(550, 180);
    text2.setFont(mFont);
    text2.setFillColor(sf::Color(230, 100, 100));
    mWindow.draw(text1);
    mWindow.draw(text2);
    for (int i = 0; i < 7; i++)
        mButton[i].draw(mWindow);
}

