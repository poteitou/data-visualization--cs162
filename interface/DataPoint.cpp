#include "DataPoint.hpp"

DataPoint::DataPoint(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, std::string textIn, std::string textOut, sf::Font &font, int inSize = 24, int outSize = 24, sf::Color inColor = sf::Color::Black, sf::Color outColor = sf::Color::Black, sf::Color Color = sf::Color::White) : mWindow(window), mPos(pos), mSize(size), mScale(1.f, 1.f), mAppearing(true), mDisappearing(false)
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

void DataPoint::appear(float dt)
{
    // if (mAppearing)
    {
        sf::Color color = mRect.getFillColor();
        color.a += dt * 255.f;
        if (color.a >= 255.f)
        {
            color.a = 255;
            // mAppearing = false;
        }
        mRect.setFillColor(color);
        mTextIn.setFillColor(sf::Color(mTextIn.getFillColor().r, mTextIn.getFillColor().g, mTextIn.getFillColor().b, color.a));
        mTextOut.setFillColor(sf::Color(mTextOut.getFillColor().r, mTextOut.getFillColor().g, mTextOut.getFillColor().b, color.a));
    }
}

void DataPoint::disappear(float dt)
{
    if (mDisappearing)
    {
        sf::Color color = mRect.getFillColor();
        color.a -= dt * 255.f;
        if (color.a <= 0.f)
        {
            color.a = 0;
            mDisappearing = false;
        }
        mRect.setFillColor(color);
        mTextIn.setFillColor(sf::Color(mTextIn.getFillColor().r, mTextIn.getFillColor().g, mTextIn.getFillColor().b, color.a));
        mTextOut.setFillColor(sf::Color(mTextOut.getFillColor().r, mTextOut.getFillColor().g, mTextOut.getFillColor().b, color.a));
    }
}

void DataPoint::move(float dx, float dy)
{
    mRect.move(dx, dy);
    mTextIn.move(dx, dy);
    mTextOut.move(dx, dy);
}

void DataPoint::draw()
{
    mWindow.draw(mRect);
    mWindow.draw(mTextIn);
    mWindow.draw(mTextOut);
}
