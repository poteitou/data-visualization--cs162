#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "../interface/Button.hpp"

class Menu
{
public:
    Menu(sf::RenderWindow &window, sf::Font &font);
    void draw(int &mData);

private:
    sf::RenderWindow &mWindow;
    std::vector<Button> mButton;
};

#endif // MENU_HPP
