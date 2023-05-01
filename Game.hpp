#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "datastruct/Menu.hpp"
#include "datastruct/StaticArray.hpp"
#include "interface/Button.hpp"
#include <iostream>

struct Game
{
                Game();
    void        run();

    void        processEvents();
    void        render(Screen &mScreen);

    sf::RenderWindow mWindow;
    sf::Font mFont;

    bool mousePress;
    sf::Vector2i mousePosition;
    char keyPress;
};

#endif // GAME_HPP
