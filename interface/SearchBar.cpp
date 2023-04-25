#include "SearchBar.hpp"

SearchBar::SearchBar(sf::RenderWindow &window, sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string defaultText)
    : mWindow(window)
{
    // Set up the rectangle shape
    mRectangle.setPosition(position);
    mRectangle.setSize(size);
    mDefaultColor = sf::Color(200, 200, 200);
    mHoveredColor = sf::Color(255, 200, 200);
    mSelectedColor = sf::Color(255, 130, 130);
    mRectangle.setFillColor(mDefaultColor);

    // Set up the text object
    // sf::Font font;
    // font.loadFromFile("resources/fonts/arial.ttf");

    mText.setFont(font);
    mText.setCharacterSize(25);
    mText.setPosition(position.x + 10, position.y + 10);
    mText.setFillColor(sf::Color::Black);
    mText.setString(defaultText);
    mValue = defaultText;

    mHovered = false;
    mSelected = false;
}

void SearchBar::handleEvent(sf::Event event, int capacity)
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
                mRectangle.setFillColor(mSelectedColor);
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
                mRectangle.setFillColor(mHoveredColor);
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
        if (!mSelected || (int)mValue.size() == capacity)
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
            int mSize = (int)mValue.size();
            if (c != ' ' && mSize >= 2 && mValue[mSize - 1] != ' ' && mValue[mSize - 2] != ' ')
            {
                // Do not allow 3-digit numbers
                break;
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

std::string SearchBar::getValue()// const
{
    return mValue;
}

bool SearchBar::contains(sf::Vector2f point) const
{
    return mRectangle.getGlobalBounds().contains(point);
}

void SearchBar::reset()
{
    mValue = "";
}