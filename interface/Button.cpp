#include "Button.hpp"

Button::Button(sf::RenderWindow &window, sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, std::string textString, sf::Font &font, int sizeText)
    : mWindow(window), mColor(color), mHoverColor(hoverColor), mHovered(false)
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

bool Button::checkMouseOver()
{
    sf::FloatRect bounds = mRect.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);

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

bool Button::checkPress()
{
    /* if (button.isMouseOver())
            {
                button.setHovered(true);

                // Check if mouse is clicked on button
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) */
    if (checkMouseOver() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    else
    {
        return false;
    }
}
