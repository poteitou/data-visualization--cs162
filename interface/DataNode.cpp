#include "DataNode.hpp"

DataNode::DataNode() {}

DataNode::DataNode(sf::Vector2f pos, sf::Vector2f posPrev, sf::Vector2f posNext, std::string textIn, std::string textOut, sf::Font &font, int inSize = 24, int outSize = 24, sf::Color inColor = sf::Color::Black, sf::Color outColor = sf::Color::Black, sf::Color Color = sf::Color::White, float appearTime = 0, float disappearTime = 0, bool prev = false, bool next = true) : mPos(pos), mPosPrev(posPrev), mPosNext(posNext), mAppear(false), mDisappear(false), mAppearTime(appearTime), mDefaultAppear(appearTime), mDisappearTime(disappearTime), mDefaultDisappear(disappearTime), mInColor(inColor), mColor(Color), mPrev(prev), mNext(next)
{
    // create rectangle
    mRect.setOrigin(sf::Vector2f(0.f, 0.f));
    mRect.setSize(sf::Vector2f(50.f, 50.f));
    mRect.setPosition(mPos);
    mRect.setFillColor(Color);
    mRect.setOutlineThickness(2.f);
    mRect.setOutlineColor(sf::Color::Black);

    // create text
    mTextIn.setString(textIn);
    mTextIn.setFont(font);

    mTextIn.setCharacterSize(inSize);
    mTextIn.setPosition(mPos.x + (50.f - mTextIn.getLocalBounds().width) / 2, mPos.y + (50.f - inSize) / 2);
    mTextIn.setFillColor(inColor);

    mTextOut.setString(textOut);
    mTextOut.setFont(font);

    mTextOut.setCharacterSize(outSize);
    mTextOut.setPosition(mPos.x + (50.f - mTextOut.getLocalBounds().width) / 2, mPos.y + (50.f - outSize) / 2 + 50.f);
    mTextOut.setFillColor(outColor);

    // create arrow
    mPrevArrow = Arrow(sf::Vector2f(mPos.x, mPos.y + 23), sf::Vector2f(mPosPrev.x + 50, mPosPrev.y + 23), mPrev ? (mInColor == sf::Color::Black ? sf::Color::Black : mColor) : sf::Color::Transparent);
    mNextArrow = Arrow(sf::Vector2f(mPos.x + 50, mPos.y + 27), sf::Vector2f(mPosNext.x, mPosNext.y + 27), mNext ? (mInColor == sf::Color::Black ? sf::Color::Black : mColor) : sf::Color::Transparent);
}

void DataNode::setText(std::string textIn, std::string textOut)
{
    mTextIn.setString(textIn);
    mTextOut.setString(textOut);
}

void DataNode::setColor(sf::Color inColor, sf::Color outColor, sf::Color Color)
{
    mInColor = inColor;
    mTextIn.setFillColor(inColor);
    mTextOut.setFillColor(outColor);
    mColor = Color;
    mRect.setFillColor(Color);
    mPrevArrow.setColor(mPrev ? (mInColor == sf::Color::Black ? sf::Color::Black : mColor) : sf::Color::Transparent);
    mNextArrow.setColor(mNext ? (mInColor == sf::Color::Black ? sf::Color::Black : mColor) : sf::Color::Transparent);
}

void DataNode::setPosition(sf::Vector2f pos)
{
    mPos = pos;
    mPrevArrow.setPosition(sf::Vector2f(mPos.x, mPos.y + 23), sf::Vector2f(mPosPrev.x + 50, mPosPrev.y + 23));
    mNextArrow.setPosition(sf::Vector2f(mPos.x + 50, mPos.y + 27), sf::Vector2f(mPosNext.x, mPosNext.y + 27));
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

void DataNode::draw(sf::RenderWindow &mWindow)
{
    mWindow.draw(mRect);
    mWindow.draw(mTextIn);
    mWindow.draw(mTextOut);
    if (mPrev) mPrevArrow.draw(mWindow);
    if (mNext) mNextArrow.draw(mWindow);
}
