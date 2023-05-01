#include "Button.hpp"

Button::Button() {}

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, std::string textString, sf::Font &font, int sizeText)
    : mColor(color), mHoverColor(hoverColor), mHovered(false)
{
    mRect.setSize(size);
    mRect.setPosition(position);
    mRect.setFillColor(mColor);
    mRect.setOutlineThickness(2.f);
    mRect.setOutlineColor(sf::Color::Black);

    mText.setString(textString);
    mText.setFont(font);
    mText.setCharacterSize(sizeText);
    mText.setPosition(position.x + (size.x - mText.getLocalBounds().width) / 2, position.y + (size.y - sizeText) / 2);
    mText.setFillColor(sf::Color::Black);
}

void Button::draw(sf::RenderWindow &mWindow)
{
    if (mHovered)
    {
        mRect.setFillColor(mHoverColor);
        mText.setFillColor(sf::Color::White);
    }
    else
    {
        mRect.setFillColor(mColor);
        mText.setFillColor(sf::Color::Black);
    }

    mWindow.draw(mRect);
    mWindow.draw(mText);
}

bool Button::setMouseOver(sf::Vector2i mousePosition)
{
    sf::FloatRect bounds = mRect.getGlobalBounds();

    if (bounds.contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        mHovered = true;
        return true;
    }
    else
    {
        mHovered = false;
        return false;
    }
}

void Button::reset()
{
    mHovered = false;
}

