#ifndef DATANODE_HPP
#define DATANODE_HPP

#include <SFML/Graphics.hpp>
#include "Arrow.hpp"

struct DataNode
{
    DataNode();
    DataNode(sf::Vector2f pos, sf::Vector2f posPrev, sf::Vector2f posNext, std::string textIn, std::string textOut, sf::Font &font, int inSize, int outSize, sf::Color inColor, sf::Color outColor, sf::Color Color, float appearTime, float disappearTime, bool prev, bool next);
    void setText(std::string textIn, std::string textOut);
    void setColor(sf::Color inColor, sf::Color outColor, sf::Color Color);
    void setPosition(sf::Vector2f pos);
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
    float mDisappearTime;
    bool mAppear;
    bool mDisappear;
    bool mPrev;
    bool mNext;

    float mDefaultAppear;
    float mDefaultDisappear;
    sf::Color mInColor;
    sf::Color mColor;
};

#endif

