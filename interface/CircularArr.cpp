#include "CircularArr.hpp"

CircularArr::CircularArr() {}

CircularArr::CircularArr(sf::Vector2f posBegin, sf::Vector2f posEnd, sf::Color Color, bool beDraw): mDraw(beDraw)
{
    float mLength = length(sf::Vector2f(300, posBegin.y + 25), sf::Vector2f(posBegin.x, posBegin.y + 25));
    mPosRect = sf::Vector2f(300, posBegin.y + 25);
    mRect.setSize(sf::Vector2f(mLength - 12.f, 4.f));
    mTriangle.setPointCount(3);
    mTriangle.setPoint(0, sf::Vector2f(mLength - 12.f, -12.f / 2 + 2));
    mTriangle.setPoint(1, sf::Vector2f(mLength, 2));
    mTriangle.setPoint(2, sf::Vector2f(mLength - 12.f, 12.f / 2 + 2));

    mPosRectOnly[0] = sf::Vector2f(300, posBegin.y + 25);
    mLength = length(sf::Vector2f(300, posBegin.y + 25), sf::Vector2f(300, 325));
    mRectOnly[0].setSize(sf::Vector2f(4.f, mLength));

    mPosRectOnly[1] = sf::Vector2f(300, 325);
    mLength = length(sf::Vector2f(300, 325), sf::Vector2f(posEnd.x + 90, 325));
    mRectOnly[1].setSize(sf::Vector2f(mLength, 4.f));

    mPosRectOnly[2] = sf::Vector2f(posEnd.x + 90, posEnd.y + 25);
    mLength = length(sf::Vector2f(posEnd.x + 90, posEnd.y + 25), sf::Vector2f(posEnd.x + 90, 325)) + 4.f;
    mRectOnly[2].setSize(sf::Vector2f(4.f, mLength));

    mPosRectOnly[3] = sf::Vector2f(posEnd.x + 50, posEnd.y + 25);
    mLength = length(sf::Vector2f(posEnd.x + 50, posEnd.y + 25), sf::Vector2f(posEnd.x + 90, posEnd.y + 25));
    mRectOnly[3].setSize(sf::Vector2f(mLength, 4.f));

    mRect.setFillColor(Color);
    mTriangle.setFillColor(Color);
    for (int i = 0; i < 4; i++)
        mRectOnly[i].setFillColor(Color);
    /* mRect (300, posBegin.y + 25), (posBegin.x, posBegin.y + 25)
mLeft (300, posBegin.y + 25), (300, 325)
mBot  (300, 325), (posEnd.x + 90, 325)
mRight (posEnd.x + 90, posEnd.y + 25), (posEnd.x + 90, 325)
mTop  (posEnd.x + 50, posEnd.y + 25), (posEnd.x + 90, posEnd.y + 25) */
}

float CircularArr::length(sf::Vector2f posBegin, sf::Vector2f posEnd)
{
    return std::sqrt((posEnd.x - posBegin.x) * (posEnd.x - posBegin.x) + (posEnd.y - posBegin.y) * (posEnd.y - posBegin.y));
}

void CircularArr::setColor(sf::Color Color)
{
    mRect.setFillColor(Color);
    mTriangle.setFillColor(Color);
    for (int i = 0; i < 4; i++)
        mRectOnly[i].setFillColor(Color);
}

void CircularArr::draw(sf::RenderWindow &mWindow)
{
    if (!mDraw) return;
    sf::Transform transform;
    transform.translate(mPosRect);
    mWindow.draw(mRect, transform);
    mWindow.draw(mTriangle, transform);

    for (int i = 0; i < 4; i++)
    {
        sf::Transform trans;
        trans.translate(mPosRectOnly[i]);
        mWindow.draw(mRectOnly[i], trans);
    }
}

