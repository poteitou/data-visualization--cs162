#include "Arrow.hpp"

Arrow::Arrow(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, float triangleSize = 20.f, sf::Color Color = sf::Color::Black)
    : mWindow(window), mPos(pos), mAngle(0.f), mScale(1.f, 1.f), mSize(size), mTriangleSize(triangleSize)
{
    mRect.setOrigin(sf::Vector2f(0.f, mSize.y / 2.f));
    mRect.setSize(sf::Vector2f(mSize.x - mTriangleSize, mSize.y));
    mRect.setPosition(sf::Vector2f(0.f, mTriangleSize / 2.f));
    mRect.setFillColor(Color);

    mTriangle.setOrigin(sf::Vector2f(0.f, mTriangleSize / 2.f));
    mTriangle.setPointCount(3);
    mTriangle.setPoint(0, sf::Vector2f(mSize.x - mTriangleSize, 0.f + mTriangleSize / 2.f));
    mTriangle.setPoint(1, sf::Vector2f(mSize.x, mTriangleSize / 2.f + mTriangleSize / 2.f));
    mTriangle.setPoint(2, sf::Vector2f(mSize.x - mTriangleSize, mTriangleSize + mTriangleSize / 2.f));
    mTriangle.setFillColor(Color);
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

void Arrow::setColor(sf::Color Color)
{
    mTriangle.setFillColor(Color);
    mRect.setFillColor(Color);
}

void Arrow::draw()
{
    sf::Transform transform;
    transform.translate(mPos);
    transform.rotate(mAngle);
    transform.scale(mScale);
    mWindow.draw(mRect, transform);
    mWindow.draw(mTriangle, transform);
}

void Arrow::update(float dt)
{
    // TODO: Implement arrow updates here
    mPos.x += 100.f * dt; // Move the arrow to the right at a speed of 100 pixels per second
}

void Arrow::makeLonger(float length, float dt)
{
    if (mSize.x < length)
    {
        mSize.x += 25.f * dt; // 100.f Move the arrow to the right at a speed of 100 pixels per second
        mRect.setSize(sf::Vector2f(mSize.x - mTriangleSize, mSize.y));
        mTriangle.setPoint(0, sf::Vector2f(mSize.x - mTriangleSize, 0.f + mTriangleSize / 2.f));
        mTriangle.setPoint(1, sf::Vector2f(mSize.x, mTriangleSize / 2.f + mTriangleSize / 2.f));
        mTriangle.setPoint(2, sf::Vector2f(mSize.x - mTriangleSize, mTriangleSize + mTriangleSize / 2.f));
        mSize.x = std::min(mSize.x, length);
    }
}