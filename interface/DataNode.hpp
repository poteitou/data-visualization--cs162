#ifndef DATANODE_HPP
#define DATANODE_HPP

#include <SFML/Graphics.hpp>
#include "Arrow.hpp"

struct DataNode
{
    DataNode();
    DataNode(sf::Vector2f pos, sf::Vector2f posPrev, sf::Vector2f posNext, std::string textIn, std::string textOut, sf::Font &font, sf::Color inColor, sf::Color outColor, sf::Color Color, sf::Color arrColor, float appearTime, bool prev, bool next);
    void setText(std::string textIn, std::string textOut);
    void setColor(sf::Color inColor, sf::Color outColor, sf::Color Color, sf::Color arrColor);
    void setPosition(sf::Vector2f pos, sf::Vector2f posPrev, sf::Vector2f posNext);
    void reset();
    bool appear(float limit, float dt);
    void draw(sf::RenderWindow &mWindow);

    sf::RectangleShape mRect;
    sf::Text mTextIn;
    sf::Text mTextOut;
    sf::Vector2f mPos;
    sf::Vector2f mPosPrev;
    sf::Vector2f mPosNext;
    Arrow mPrevArrow;
    Arrow mNextArrow;

    float mAppearTime;
    bool mAppear;
    bool mPrev;
    bool mNext;

    float mDefaultAppear;
    sf::Color mInColor;
    sf::Color mColor;
    sf::Color mArrColor;
};

#endif

