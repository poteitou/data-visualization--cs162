#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "interface/Button.hpp"

class Screen
{
public:
    Screen(sf::RenderWindow& window, sf::Font& font);
    
    void draw();
    void setHovered();

private:
    sf::RenderWindow& mWindow;

    std::vector<Button> mButton;
};

#endif // SCREEN_HPP