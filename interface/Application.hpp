#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"

struct Application
{
                Application();
    void        run();
    void        processEvents();
    void        render(Screen &mScreen);

    sf::RenderWindow mWindow;
    sf::Font mFont;

    bool mousePress;
    sf::Vector2i mousePosition;
    char keyPress;
};

#endif // APPLICATION_HPP
