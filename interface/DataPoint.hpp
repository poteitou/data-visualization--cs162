#ifndef DATAPOINT_HPP
#define DATAPOINT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class DataPoint
{
public:
    DataPoint(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, std::string textIn, std::string textOut, sf::Font &font, int inSize, int outSize, sf::Color inColor, sf::Color outColor, sf::Color Color);
    void setText(std::string textIn, std::string textOut);
    void setTextColor(sf::Color inColor, sf::Color outColor);
    void setBackgroundColor(sf::Color Color);
    void setPosition(sf::Vector2f pos);
    void setScale(sf::Vector2f scale);
    void appear(float dt);
    void disappear(float dt);
    void move(float dx, float dy);
    void draw();

private:
    sf::RenderWindow &mWindow;
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
