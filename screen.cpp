#include "screen.hpp"

Screen::Screen(sf::RenderWindow& window, std::vector<Button> button)
: mWindow(window)
{
    vector<Button> button.resize(7);
    std::string buttonName[] = {""}
    button[0] = Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(300, 250), sf::Color::Cyan, sf::Color::Magenta, "Click me!", font, 25);
}