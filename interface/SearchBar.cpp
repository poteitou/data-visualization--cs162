#include "SearchBar.hpp"

SearchBar::SearchBar() {}

SearchBar::SearchBar(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string defaultText)
    : mValue(defaultText), mHovered(false), mSelected(false)
{
    // Set up the rectangle shape
    mRect.setPosition(position);
    mRect.setSize(size);
    mDefaultColor = sf::Color(200, 200, 200);
    mHoveredColor = sf::Color(180, 225, 255);
    mSelectedColor = sf::Color(100, 180, 255);
    mRect.setFillColor(mDefaultColor);

    // Set up the text object
    // sf::Font font;
    // font.loadFromFile("resources/fonts/arial.ttf");

    mText.setFont(font);
    mText.setCharacterSize(25);
    mText.setPosition(position.x + 10, position.y + 10);
    mText.setFillColor(sf::Color::Black);
    mText.setString(defaultText);
}

void SearchBar::update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int capacity)
{
    sf::FloatRect bounds = mRect.getGlobalBounds();
    if (mousePress)
    {
        if (bounds.contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            mSelected = true;
            mRect.setFillColor(mSelectedColor);
        }
        else
        {
            mSelected = false;
            mHovered = false;
            mRect.setFillColor(mDefaultColor);
        }
        return;
    }
    if (!mSelected && bounds.contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        mHovered = true;
        mRect.setFillColor(mHoveredColor);
    }
    else if (!mSelected)
    {
        mHovered = false;
        mRect.setFillColor(mDefaultColor);
    }

    if (keyPress == '$' || !mSelected)
    {
        keyPress = '$';
        return;
    }
    if (keyPress == '@')
    {
        if (!mValue.empty())
        {
            mValue.pop_back();
            mText.setString(mValue);
        }
    }
    else if ((int)mValue.size() < capacity)
    {
        if (keyPress == ' ' && (mValue.empty() || mValue.back() == ' '))
        {
            // Do not allow the first character to be a space or 2 spaces
            keyPress = '$';
            return;
        }
        int mSize = (int)mValue.size();
        if (keyPress != ' ' && mSize >= 2 && mValue[mSize - 1] != ' ' && mValue[mSize - 2] != ' ')
        {
            // Do not allow 3-digit numbers
            keyPress = '$';
            return;
        }
        mValue += keyPress;
        mText.setString(mValue);
    }

    keyPress = '$';
}

void SearchBar::draw(sf::RenderWindow &mWindow)
{
    mWindow.draw(mRect);
    mWindow.draw(mText);
}

std::string SearchBar::getValue()
{
    return mValue;
}

bool SearchBar::contains(sf::Vector2f point) const
{
    return mRect.getGlobalBounds().contains(point);
}

void SearchBar::reset(std::string defaultText)
{
    mValue = defaultText;
}