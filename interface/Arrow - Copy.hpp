#ifndef ARROW_HPP
#define ARROW_HPP

#include <SFML/Graphics.hpp>
#include <algorithm>

class Arrow
{
public:
    Arrow(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, float triangleSize, sf::Color Color);
    void setPosition(sf::Vector2f pos);
    void setRotation(float angle);
    void setScale(sf::Vector2f scale);
    void setColor(sf::Color Color);
    void draw();
    void update(float dt);
    void makeLonger(float length, float dt);

private:
    sf::RenderWindow &mWindow;
    sf::RectangleShape mRect;
    sf::ConvexShape mTriangle;
    sf::Vector2f mPos;
    sf::Vector2f mSize;
    sf::Vector2f mScale;
    float mAngle;
    float mTriangleSize;
};

#endif // ARROW_HPP

/*
#include <SFML/Graphics.hpp>
#include "interface/Arrow.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arrow Example");
    window.setFramerateLimit(60);

    Arrow arrow(window, sf::Vector2f(0.f, 0.f), sf::Vector2f(50.f, 5.f), 10.f, sf::Color::Black);
    arrow.setRotation(30.f);
    arrow.setScale(sf::Vector2f(2.f, 2.f));
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
        arrow.draw();
        window.display();
    }

    return 0;
}
*/
