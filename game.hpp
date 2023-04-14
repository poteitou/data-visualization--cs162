#include <SFML/Graphics.hpp>

class Game
{
public:
                Game();
    void        run();

private:
    void        handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void        processEvents();
    void        update(sf::Time deltaTime);
    void        render();

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    sf::Font mFont;

    sf::Time TimePerFrame;
    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
    double PlayerSpeed;
};