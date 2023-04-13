#include "button.h"

Button::Button(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, std::string textString, sf::Font& font)
: mWindow(window), mColor(color), mHoverColor(hoverColor), mHovered(false)
{
    mShape.setSize(size);
    mShape.setPosition(position);
    mShape.setFillColor(mColor);
    mShape.setOutlineThickness(2.f);
    mShape.setOutlineColor(sf::Color::Black);

    mText.setString(textString);
    mText.setFont(font);
    mText.setCharacterSize(20);
    mText.setFillColor(sf::Color::White);
    mText.setPosition(position.x + (size.x - mText.getLocalBounds().width) / 2, position.y + (size.y - mText.getLocalBounds().height) / 2);
}

void Button::draw()
{
    if (mHovered) 
    {
        mShape.setFillColor(mHoverColor);
    }
    else 
    {
        mShape.setFillColor(mColor);
    }

    mWindow.draw(mShape);
    mWindow.draw(mText);
}

bool Button::isMouseOver()
{
    sf::FloatRect bounds = mShape.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);

    return bounds.contains(static_cast<sf::Vector2f>(mousePosition));
}

void Button::setHovered(bool value)
{
    mHovered = value;
}
