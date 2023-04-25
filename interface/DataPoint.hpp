#ifndef DATAPOINT_HPP
#define DATAPOINT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

struct DataPoint
{
    DataPoint();
    DataPoint(sf::Vector2f pos, sf::Vector2f size, std::string textIn, std::string textOut, sf::Font &font, int inSize, int outSize, sf::Color inColor, sf::Color outColor, sf::Color Color);
    void setText(std::string textIn, std::string textOut);
    void setTextColor(sf::Color inColor, sf::Color outColor);
    void setBackgroundColor(sf::Color Color);
    void setPosition(sf::Vector2f pos);
    void setScale(sf::Vector2f scale);
    void appear(float dt);
    void disappear(float dt);
    void move(float dx, float dy);
    void draw(sf::RenderWindow &mWindow);

    sf::RectangleShape mRect;
    sf::Text mTextIn;
    sf::Text mTextOut;
    sf::Vector2f mPos;
    sf::Vector2f mSize;
    sf::Vector2f mScale;
    bool mAppearing;
    bool mDisappearing;
};

#endif

/* 
#include <SFML/Graphics.hpp>
#include "interface/DataPoint.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DataPoint Example");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("resources/fonts/arial.ttf");

    // create a datapoint
    DataPoint dataPoint;
    dataPoint = DataPoint(sf::Vector2f(100.f, 100.f), sf::Vector2f(200.f, 50.f), "Input", "Output", font, 30, 24, sf::Color::Black, sf::Color::Black, sf::Color(200, 200, 255));

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // update the datapoint
        dataPoint.appear(0.01f);

        // draw the datapoint
        window.clear(sf::Color::White);
        dataPoint.draw(window);
        window.display();
    }

    return 0;
}

 */
