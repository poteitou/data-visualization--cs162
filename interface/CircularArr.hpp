#ifndef CIRCULARARR_HPP
#define CIRCULARARR_HPP

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <math.h>

struct CircularArr
{
    CircularArr();
    CircularArr(sf::Vector2f posBegin, sf::Vector2f posEnd, sf::Color Color, bool beDraw);
    void setColor(sf::Color Color);
    void draw(sf::RenderWindow &mWindow);

    sf::RectangleShape mRect;
    sf::ConvexShape mTriangle;
    sf::RectangleShape mRectOnly[4];
    sf::Vector2f mPosRect;
    sf::Vector2f mPosRectOnly[4];

    bool mDraw;
};

#endif // CIRCULARARR_HPP

/*

#include <SFML/Graphics.hpp>
#include "interface/CircularArr.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "CircularArr Example");
    window.setFramerateLimit(60);

    CircularArr arrow;
    arrow = CircularArr(sf::Vector2f(0.f, 0.f), sf::Vector2f(50.f, 5.f), 10.f, sf::Color::Black);
    arrow.mAngle = 30.f;
    arrow.mScale = sf::Vector2f(2.f, 2.f);
    arrow.setColor(sf::Color::Red);

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();

        // arrow.update(dt);
        arrow.makeLonger(100.f, dt);

        window.clear(sf::Color::White);
        arrow.draw(window);
        window.display();
    }

    return 0;
}

*/
