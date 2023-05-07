#include "Arrow.hpp"

Arrow::Arrow() {}

Arrow::Arrow(sf::Vector2f posBegin, sf::Vector2f posEnd, sf::Color Color = sf::Color::Black)
    : mPosBegin(sf::Vector2f(posBegin.x, posBegin.y - 2.f)), mPosEnd(sf::Vector2f(posEnd.x, posEnd.y - 2.f)), mAngle(0.f), mTriangleSize(12.f)
{
    mLength = std::sqrt((mPosEnd.x - mPosBegin.x) * (mPosEnd.x - mPosBegin.x) + (mPosEnd.y - mPosBegin.y) * (mPosEnd.y - mPosBegin.y));
    mAngle = std::atan2(mPosEnd.y - mPosBegin.y, mPosEnd.x - mPosBegin.x) * 180.f / std::acos(-1);
    mRect.setSize(sf::Vector2f(mLength - mTriangleSize, 4.f));
    mRect.setFillColor(Color);

    mTriangle.setPointCount(3);
    mTriangle.setPoint(0, sf::Vector2f(mLength - mTriangleSize, -mTriangleSize / 2 + 2));
    mTriangle.setPoint(1, sf::Vector2f(mLength, 2));
    mTriangle.setPoint(2, sf::Vector2f(mLength - mTriangleSize, mTriangleSize / 2 + 2));
    mTriangle.setFillColor(Color);
}

void Arrow::setPosition(sf::Vector2f posBegin, sf::Vector2f posEnd)
{
    mPosBegin = sf::Vector2f(posBegin.x, posBegin.y - 2.f);
    mPosEnd = sf::Vector2f(posEnd.x, posEnd.y - 2.f);
    mLength = std::sqrt((mPosEnd.x - mPosBegin.x) * (mPosEnd.x - mPosBegin.x) + (mPosEnd.y - mPosBegin.y) * (mPosEnd.y - mPosBegin.y));
    mAngle = std::atan2(mPosEnd.y - mPosBegin.y, mPosEnd.x - mPosBegin.x) * 180.f / std::acos(-1);
    mRect.setSize(sf::Vector2f(mLength - mTriangleSize, 4.f));
    mTriangle.setPoint(0, sf::Vector2f(mLength - mTriangleSize, -mTriangleSize / 2 + 2));
    mTriangle.setPoint(1, sf::Vector2f(mLength, 2));
    mTriangle.setPoint(2, sf::Vector2f(mLength - mTriangleSize, mTriangleSize / 2 + 2));
}

void Arrow::setColor(sf::Color Color)
{
    mRect.setFillColor(Color);
    mTriangle.setFillColor(Color);
}

void Arrow::draw(sf::RenderWindow &mWindow)
{
    sf::Transform transform;
    transform.translate(mPosBegin);
    transform.rotate(mAngle);
    mWindow.draw(mRect, transform);
    mWindow.draw(mTriangle, transform);
}
