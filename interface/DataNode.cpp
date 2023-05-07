#include "DataNode.hpp"

DataNode::DataNode() {}

DataNode::DataNode(sf::Vector2f pos, sf::Vector2f size, std::string textIn, std::string textOut, sf::Font &font, int inSize = 24, int outSize = 24, sf::Color inColor = sf::Color::Black, sf::Color outColor = sf::Color::Black, sf::Color Color = sf::Color::White, float appearTime = 0, float disappearTime = 0) : mPos(pos), mSize(size), mScale(1.f, 1.f), mAppear(false), mDisappear(false), mAppearTime(appearTime), mDefaultAppear(appearTime), mDisappearTime(disappearTime), mDefaultDisappear(disappearTime), mInColor(inColor), mColor(Color)
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

    mTextIn.setCharacterSize(inSize);
    mTextIn.setPosition(mPos.x + (mSize.x - mTextIn.getLocalBounds().width) / 2, mPos.y + (mSize.y - inSize) / 2);
    mTextIn.setFillColor(inColor);

    mTextOut.setString(textOut);
    mTextOut.setFont(font);

    mTextOut.setCharacterSize(outSize);
    mTextOut.setPosition(mPos.x + (mSize.x - mTextOut.getLocalBounds().width) / 2, mPos.y + (mSize.y - outSize) / 2 + mSize.y);
    mTextOut.setFillColor(outColor);
}

void DataNode::setText(std::string textIn, std::string textOut)
{
    mTextIn.setString(textIn);
    mTextOut.setString(textOut);
}

void DataNode::setTextColor(sf::Color inColor, sf::Color outColor)
{
    mInColor = inColor;
    mTextIn.setFillColor(inColor);
    mTextOut.setFillColor(outColor);
}

void DataNode::setBackgroundColor(sf::Color Color)
{
    mColor = Color;
    mRect.setFillColor(Color);
}

void DataNode::setPosition(sf::Vector2f pos)
{
    mPos = pos;
}

void DataNode::setScale(sf::Vector2f scale)
{
    mScale = scale;
}

void DataNode::reset()
{
    mAppearTime = mDefaultAppear;
    mDisappearTime = mDefaultDisappear;
    mAppear = mDisappear = false;
}

bool DataNode::appear(float limit, float dt)
{
    mAppearTime += limit * dt;
    if (mAppearTime >= limit)
    {
        mAppearTime = limit;
        mAppear = true;
    }
    return mAppear;
}

bool DataNode::disappear(float limit, float dt)
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

void DataNode::move(float dx, float dy, float dt)
{
    mRect.move(dx, dy);
    mTextIn.move(dx, dy);
    mTextOut.move(dx, dy);
}

void DataNode::draw(sf::RenderWindow &mWindow)
{
    mWindow.draw(mRect);
    mWindow.draw(mTextIn);
    mWindow.draw(mTextOut);
}
