#include "StaticArray.hpp"

StaticArray::StaticArray(sf::RenderWindow &window, sf::Font &font) : mWindow(window), mFont(font), mType(0), mSmallType(0)
{
    mDefaultText.resize(7);
    for (int i = 0; i < 7; i++)
    {
        mDefaultText[i].setFont(font);
        mDefaultText[i].setFillColor(sf::Color::Black);
    }

    // Top right
    mDefaultText[0].setString("STATIC ARRAY");
    mDefaultText[1].setString("Max size: 7");
    mDefaultText[2].setString("Value range: 0..99");
    mDefaultText[3].setString("Implementation:");

    // Create Enter
    mDefaultText[4].setString("Max size");
    mDefaultText[5].setString("Size");
    mDefaultText[6].setString("Value");

    mDefaultText[0].setCharacterSize(45);
    mDefaultText[1].setCharacterSize(25);
    mDefaultText[2].setCharacterSize(25);
    mDefaultText[3].setCharacterSize(30);
    for (int i = 4; i < 7; i++)
    {
        mDefaultText[i].setCharacterSize(22);
        mDefaultText[i].setPosition(250, 650 + 19 + (i - 4) * 55);
    }

    mDefaultText[0].setPosition(1100, 70);
    mDefaultText[1].setPosition(950, 150);
    mDefaultText[2].setPosition(950, 200);
    mDefaultText[3].setPosition(1150, 275);

    std::string nameButton[] = {"Create", "Insert", "Remove", "Update", "Search", "Run step-by-step", "Run at-once", "Choose data structure"};
    for (int i = 0; i < 5; i++)
        mButton.push_back(Button(mWindow, sf::Vector2f(100, 50), sf::Vector2f(100, 600 + i * 55), sf::Color::Cyan, sf::Color::Blue, nameButton[i], font, 22));

    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 450), sf::Color::Cyan, sf::Color::Blue, nameButton[5], font, 22));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 505), sf::Color::Cyan, sf::Color::Blue, nameButton[6], font, 22));
    mButton.push_back(Button(mWindow, sf::Vector2f(250, 50), sf::Vector2f(1300, 150), sf::Color::Cyan, sf::Color::Blue, nameButton[7], font, 22));

    std::string nameBCreate[] = {"Enter", "Random", "Data File"};
    for (int i = 0; i < 3; i++)
        mBCreate.push_back(Button(mWindow, sf::Vector2f(100, 50), sf::Vector2f(300 + i * 200, 600), sf::Color::Cyan, sf::Color::Blue, nameBCreate[i], font, 22));

    std::string nameBInsert[] = {"At The First", "At The Last", "At The Middle"};
    for (int i = 0; i < 3; i++)
    {
        mBInsert.push_back(Button(mWindow, sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 600), sf::Color::Cyan, sf::Color::Blue, nameBInsert[i], font, 22));
        mBRemove.push_back(Button(mWindow, sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 600), sf::Color::Cyan, sf::Color::Blue, nameBInsert[i], font, 22));
    }

    mSearchBar.push_back(SearchBar(mWindow, sf::Vector2f(100, 50), sf::Vector2f(350, 650 + 5), font, ""));
    mSearchBar.push_back(SearchBar(mWindow, sf::Vector2f(100, 50), sf::Vector2f(350, 650 + 50 + 10), font, ""));
    mSearchBar.push_back(SearchBar(mWindow, sf::Vector2f(300, 50), sf::Vector2f(350, 650 + 100 + 15), font, ""));

    array = new int[0];
    size = 0;
}

void StaticArray::handle(sf::Event event, int &mData)
{
    for (int i = 0; i < 8; i++)
        mButton[i].checkMouseOver();
    for (int i = 0; i < 5; i++)
        if (mButton[i].checkPress())
        {
            mType = i + 1;
            mSmallType = 0;
        }
    if (mButton[7].checkPress())
        mData = 0;
    
    switch (mType)
    {
    case 1: // Create
        for (int i = 0; i < 3; i++)
            mBCreate[i].checkMouseOver();
        for (int i = 0; i < 3; i++)
        {
            if (mBCreate[i].checkPress())
                mSmallType = i + 1;
        }
        switch (mSmallType)
        {
        case 0:
            break;
        case 1:
            mSearchBar[0].handleEvent(event, 1);
            mSearchBar[1].handleEvent(event, 1);
            mSearchBar[2].handleEvent(event, 20);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
        break;
    case 2: // Insert
        for (int i = 0; i < 3; i++)
            mBInsert[i].checkMouseOver();
        break;
    case 3: // Remove
        for (int i = 0; i < 3; i++)
            mBRemove[i].checkMouseOver();
        break;
    case 4: // Update
        break;
    case 5: // Search
        break;
    default:
        break;
    }
}

void StaticArray::draw(float dt)
{
    for (int i = 0; i < 4; i++)
        mWindow.draw(mDefaultText[i]);
    for (int i = 0; i < 8; i++)
        mButton[i].draw();
    
    switch (mType)
    {
    case 1: // Create
        for (int i = 0; i < 3; i++)
            mBCreate[i].draw();
        switch (mSmallType)
        {
        case 0:
            break;
        case 1:
            for (int i = 4; i < 7; i++)
                mWindow.draw(mDefaultText[i]);
            for (int i = 0; i < 3; i++)
                mSearchBar[i].draw();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
        break;
    case 2: // Insert
        for (int i = 0; i < 3; i++)
            mBInsert[i].draw();
        break;
    case 3: // Remove
        for (int i = 0; i < 3; i++)
            mBRemove[i].draw();
        break;
    case 4: // Update
        break;
    case 5: // Search
        break;
    default:
        break;
    }
}

/* void StaticArray::enter(int size)
{
    array = new int[size];
    this->size = size;
}

void StaticArray::random(int size)
{
    array = new int[size];
    this->size = size;
}

void StaticArray::dataFile(int size)
{
    array = new int[size];
    this->size = size;
} */

/* StaticArray::StaticArray(int size, int *data)
{
    array = new int[size];
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        array[i] = data[i];
    }
}

StaticArray::StaticArray(const StaticArray &other)
{
    array = new int[other.size];
    size = other.size;
    for (int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
}

StaticArray::~StaticArray()
{
    delete[] array;
}

void StaticArray::randomize(int min = 0, int max = 100)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void StaticArray::add(int element)
{
    expandArray();
    array[size - 1] = element;
}

void StaticArray::insert(int index, int element)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    expandArray();
    for (int i = size - 1; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = element;
}

void StaticArray::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
    int *temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

void StaticArray::update(int index, int element)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    array[index] = element;
}

int StaticArray::search(int element) const
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int StaticArray::getSize() const
{
    return size;
}

int StaticArray::getElement(int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

void StaticArray::setElement(int index, int element)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    array[index] = element;
}

void StaticArray::expandArray()
{
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size++;
}
 */
