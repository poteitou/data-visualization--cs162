#include "searchBar.hpp"

SearchBar::SearchBar(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, sf::Font &font, std::string defaultText)
    : mWindow(window)
{
    // Set up the rectangle shape
    mRectangle.setPosition(position);
    mRectangle.setSize(size);
    mDefaultColor = sf::Color(200, 200, 200);
    mSelectedColor = sf::Color(255, 200, 200);
    mRectangle.setFillColor(mDefaultColor);

    // Set up the text object
    // sf::Font font;
    // font.loadFromFile("resources/fonts/arial.ttf");

    mText.setFont(font);
    mText.setCharacterSize(20);
    mText.setPosition(position.x + 10, position.y + 10);
    mText.setFillColor(sf::Color::Black);
    mText.setString(defaultText);
    mValue = "";

    mHovered = false;
    mSelected = false;
}

void SearchBar::handleEvent(sf::Event event)
{
    sf::Vector2i mousePosition;
    char c;
    
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            mousePosition = sf::Mouse::getPosition(mWindow);
            if (contains(sf::Vector2f(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))))
            {
                mSelected = true;
            }
            else
            {
                mSelected = false;
                if (mHovered)
                {
                    mHovered = false;
                    mRectangle.setFillColor(mDefaultColor);
                }
            }
        }
        break;
    case sf::Event::MouseMoved:
        mousePosition = sf::Mouse::getPosition(mWindow);
        if (contains(sf::Vector2f(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))))
        {
            if (!mHovered)
            {
                mHovered = true;
                mRectangle.setFillColor(mSelectedColor);
            }
        }
        else
        {
            if (!mSelected && mHovered)
            {
                mHovered = false;
                mRectangle.setFillColor(mDefaultColor);
            }
        }
        break;
    case sf::Event::TextEntered:
        if (!mSelected)
        {
            break; // return;
        }
        c = static_cast<char>(event.text.unicode);
        if ((c >= '0' && c <= '9') || c == ' ')
        {
            if (c == ' ' && (mValue.empty() || mValue.back() == ' '))
            {
                // Do not allow the first character to be a space or 2 spaces
                break; // return;
            }
            mValue += c;
            mText.setString(mValue);
        }
        break;
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Backspace)
        {
            if (!mValue.empty())
            {
                mValue.pop_back();
                mText.setString(mValue);
            }
        }
        break;
    default:
        break;
    }
}

void SearchBar::draw()
{
    mWindow.draw(mRectangle);
    mWindow.draw(mText);
}

std::string SearchBar::getValue() const
{
    return mValue;
}

bool SearchBar::contains(sf::Vector2f point) const
{
    return mRectangle.getGlobalBounds().contains(point);
}
