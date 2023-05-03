#ifndef DATAPOINT_HPP
#define DATAPOINT_HPP

#include <SFML/Graphics.hpp>

struct DataPoint
{
    DataPoint();
    DataPoint(sf::Vector2f pos, sf::Vector2f size, std::string textIn, std::string textOut, sf::Font &font, int inSize, int outSize, sf::Color inColor, sf::Color outColor, sf::Color Color, float appearTime, float disappearTime);
    void setText(std::string textIn, std::string textOut);
    void setTextColor(sf::Color inColor, sf::Color outColor);
    void setBackgroundColor(sf::Color Color);
    void setPosition(sf::Vector2f pos);
    void setScale(sf::Vector2f scale);
    void reset();
    bool appear(float limit, float dt);
    bool disappear(float limit, float dt);
    void move(float dx, float dy, float dt);
    void draw(sf::RenderWindow &mWindow);

    sf::RectangleShape mRect;
    sf::Text mTextIn;
    sf::Text mTextOut;
    sf::Vector2f mPos;
    sf::Vector2f mSize;
    sf::Vector2f mScale;

    float mAppearTime;
    float mDisappearTime;
    bool mAppear;
    bool mDisappear;

    float mDefaultAppear;
    float mDefaultDisappear;
    sf::Color mInColor;
    sf::Color mColor;
};

#endif


