#include "Button.hpp"

Button::Button(sf::RenderWindow &window, sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, std::string textString, sf::Font &font, int sizeText)
    : mWindow(window), mColor(color), mHoverColor(hoverColor), mHovered(false)
{
    mRect.setSize(size);
    mRect.setPosition(position);
    mRect.setFillColor(mColor);
    mRect.setOutlineThickness(3.f);
    mRect.setOutlineColor(sf::Color::Black);

    mText.setString(textString);
    mText.setFont(font);
    mText.setCharacterSize(sizeText);
    mText.setPosition(position.x + (size.x - mText.getLocalBounds().width) / 2, position.y + (size.y - sizeText) / 2);
    mText.setFillColor(sf::Color::Black);
}

void Button::draw()
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

bool Button::isMouseOver()
{
    sf::FloatRect bounds = mRect.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);

    return bounds.contains(static_cast<sf::Vector2f>(mousePosition));
}

bool Button::checkPress()
{
    if (isMouseOver() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Button::setHovered(bool value)
{
    mHovered = value;
}
