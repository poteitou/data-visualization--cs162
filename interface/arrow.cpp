#include "Arrow.hpp"

Arrow::Arrow(float length, float thickness, float triangleSize)
    : mPos(0.f, 0.f), mAngle(0.f), mScale(1.f, 1.f), mColor(sf::Color::White),
      mLength(length), mThickness(thickness), mTriangleSize(triangleSize)
{
    mRect.setSize(sf::Vector2f(mLength - mTriangleSize, mThickness));
    mRect.setOrigin(sf::Vector2f(0.f, mThickness / 2.f));
    mRect.setFillColor(mColor);
    mRect.setPosition(sf::Vector2f(0.f, mTriangleSize / 2.f));

    mTriangle.setPointCount(3);
    mTriangle.setPoint(0, sf::Vector2f(mLength - mTriangleSize, 0.f + mTriangleSize / 2.f));
    mTriangle.setPoint(1, sf::Vector2f(mLength, mTriangleSize / 2.f + mTriangleSize / 2.f));
    mTriangle.setPoint(2, sf::Vector2f(mLength - mTriangleSize, mTriangleSize + mTriangleSize / 2.f));
    mTriangle.setOrigin(sf::Vector2f(0.f, mTriangleSize / 2.f));
    mTriangle.setFillColor(mColor);
}

void Arrow::setPosition(sf::Vector2f pos)
{
    mPos = pos;
}

void Arrow::setRotation(float angle)
{
    mAngle = angle;
}

void Arrow::setScale(sf::Vector2f scale)
{
    mScale = scale;
}

void Arrow::setColor(sf::Color color)
{
    mColor = color;
    mTriangle.setFillColor(mColor);
    mRect.setFillColor(mColor);
}

void Arrow::draw(sf::RenderWindow &window)
{
    sf::Transform transform;
    transform.translate(mPos);
    transform.rotate(mAngle);
    transform.scale(mScale);
    window.draw(mRect, transform);
    window.draw(mTriangle, transform);
}

void Arrow::update(float dt)
{
    // TODO: Implement arrow updates here
    mPos.x += 100.f * dt; // Move the arrow to the right at a speed of 100 pixels per second
}

void Arrow::makeLonger(float length, float dt)
{
    if (mLength < length)
    {
        mLength += 25.f * dt; // 100.f Move the arrow to the right at a speed of 100 pixels per second
        mRect.setSize(sf::Vector2f(mLength - mTriangleSize, mThickness));
        mTriangle.setPoint(0, sf::Vector2f(mLength - mTriangleSize, 0.f + mTriangleSize / 2.f));
        mTriangle.setPoint(1, sf::Vector2f(mLength, mTriangleSize / 2.f + mTriangleSize / 2.f));
        mTriangle.setPoint(2, sf::Vector2f(mLength - mTriangleSize, mTriangleSize + mTriangleSize / 2.f));
        mLength = std::min(mLength, length);
    }
}