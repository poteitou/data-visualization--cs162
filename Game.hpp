#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "datastruct/StaticArray.hpp"
#include "interface/Button.hpp"

class Game
{
public:
                Game();
    void        run();

private:
    void        processEvents(Screen &mScreen, float dt);
    void        update(Screen &screen, float dt);
    void        render(Screen &screen);

private:
    sf::RenderWindow mWindow;
    sf::Font mFont;
};

#endif // GAME_HPP
