#include "SearchBar.hpp"

SearchBar::SearchBar() {}

SearchBar::SearchBar(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string defaultText, bool alphabet)
    : mValue(defaultText), mHovered(false), mSelected(false), mAlphabet(alphabet)
{
    // Set up the rectangle shape
    mRect.setPosition(position);
    mRect.setSize(size);
    mDefaultColor = sf::Color(200, 200, 200);
    mHoveredColor = sf::Color(200, 200, 255);
    mSelectedColor = sf::Color(130, 130, 255);
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
            mText.setFillColor(sf::Color::White);
        }
        else
        {
            mSelected = false;
            mHovered = false;
            mRect.setFillColor(mDefaultColor);
            mText.setFillColor(sf::Color::Black);
        }
        return;
    }
    if (!mSelected && bounds.contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        mHovered = true;
        mRect.setFillColor(mHoveredColor);
        mText.setFillColor(sf::Color::Black);
    }
    else if (!mSelected)
    {
        mHovered = false;
        mRect.setFillColor(mDefaultColor);
        mText.setFillColor(sf::Color::Black);
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
        if (keyPress == ' ' && (mAlphabet || capacity <= 2 || mValue.empty() || mValue.back() == ' '))
        {
            // Do not allow the first character to be a space or 2 spaces, space in alphabet mode, space in 2-digit mode
            keyPress = '$';
            return;
        }
        int mSize = (int)mValue.size();
        if (!mAlphabet && keyPress != ' ' && mSize >= 2 && mValue[mSize - 1] != ' ' && mValue[mSize - 2] != ' ')
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

void SearchBar::reset(std::string defaultText)
{
    mValue = defaultText;
    mText.setString(mValue);
}