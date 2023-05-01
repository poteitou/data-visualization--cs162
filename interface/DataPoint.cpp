#include "DataPoint.hpp"

DataPoint::DataPoint() {}

DataPoint::DataPoint(sf::Vector2f pos, sf::Vector2f size, std::string textIn, std::string textOut, sf::Font &font, int inSize = 24, int outSize = 24, sf::Color inColor = sf::Color::Black, sf::Color outColor = sf::Color::Black, sf::Color Color = sf::Color::White) : mPos(pos), mSize(size), mScale(1.f, 1.f), mAppear(false), mDisappear(false), mAppearTime(0), mDisappear(0)
{
    // create rectangle
    mRect.setOrigin(sf::Vector2f(0.f, 0.f));
    mRect.setSize(mSize);
    mRect.setPosition(mPos);
    mRect.setFillColor(Color);
    mRect.setOutlineThickness(2.f);
    mRect.setOutlineColor(sf::Color::Black);

    // create text
    mTextIn.setString(textIn);
    mTextIn.setFont(font);

    // mTextIn.setOrigin(mTextIn.getLocalBounds().left + mTextIn.getLocalBounds().width / 2.0f, mTextIn.getLocalBounds().top + mTextIn.getLocalBounds().height / 2.0f);
    // mTextIn.setPosition(mTextIn.getLocalBounds().getPosition() + mTextIn.getLocalBounds().getSize() / 2.0f);

    mTextIn.setCharacterSize(inSize);
    mTextIn.setPosition(mPos.x + (mSize.x - mTextIn.getLocalBounds().width) / 2, mPos.y + (mSize.y - inSize) / 2);
    mTextIn.setFillColor(inColor);

    mTextOut.setString(textOut);
    mTextOut.setFont(font);

    // mTextOut.setOrigin(mTextOut.getLocalBounds().left + mTextOut.getLocalBounds().width / 2.0f, mTextOut.getLocalBounds().top + mTextOut.getLocalBounds().height / 2.0f);

    mTextOut.setCharacterSize(outSize);
    mTextOut.setPosition(mPos.x + (mSize.x - mTextOut.getLocalBounds().width) / 2, mPos.y + (mSize.y - outSize) / 2 + mSize.y);
    mTextOut.setFillColor(inColor);
}

void DataPoint::setText(std::string textIn, std::string textOut)
{
    mTextIn.setString(textIn);
    mTextOut.setString(textOut);
}

void DataPoint::setTextColor(sf::Color inColor, sf::Color outColor)
{
    mTextIn.setFillColor(inColor);
    mTextOut.setFillColor(outColor);
}

void DataPoint::setBackgroundColor(sf::Color Color)
{
    mRect.setFillColor(Color);
}

void DataPoint::setPosition(sf::Vector2f pos)
{
    mPos = pos;
}

void DataPoint::setScale(sf::Vector2f scale)
{
    mScale = scale;
}

bool DataPoint::appear(float limit, float dt)
{
    mAppearTime += limit * dt;
    if (mAppearTime >= limit)
    {
        mAppearTime = limit;
        mAppear = true;
    }
    return mAppear;
}

void DataPoint::disappear(float limit, float dt)
{
    mRect.setFillColor(sf::Color::Transparent);
    mRect.setOutlineColor(sf::Color::Transparent);
    mTextIn.setFillColor(sf::Color::Transparent);
    mTextOut.setFillColor(sf::Color::Transparent);
    mDisappearTime += limit * dt;
    if (mDisappearTime >= limit)
    {
        mDisappearTime = limit;
        mDisappear = true;
    }
    return mDisappear;
}

void DataPoint::move(float dx, float dy, float dt)
{
    mRect.move(dx, dy);
    mTextIn.move(dx, dy);
    mTextOut.move(dx, dy);
}

void DataPoint::draw(sf::RenderWindow &mWindow)
{
    mWindow.draw(mRect);
    mWindow.draw(mTextIn);
    mWindow.draw(mTextOut);
}
