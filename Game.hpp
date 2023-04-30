#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "datastruct/Menu.hpp"
#include "datastruct/StaticArray.hpp"
#include "interface/Button.hpp"

struct Game
{
                Game();
    void        run();

    void        processEvents(Screen &mScreen, float dt);
    void        update(Screen &mScreen, float dt);
    void        render(Screen &mScreen);

    sf::RenderWindow mWindow;
    sf::Font mFont;
};

#endif // GAME_HPP
