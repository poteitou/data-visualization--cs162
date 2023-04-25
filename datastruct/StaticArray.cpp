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
    mDefaultText[1].setString("Max size: 9");
    mDefaultText[2].setString("Value range: 0..99");
    mDefaultText[3].setString("Color tone:");

    // Create Enter
    mDefaultText[4].setString("Value");

    mDefaultText[0].setCharacterSize(45);
    mDefaultText[1].setCharacterSize(25);
    mDefaultText[2].setCharacterSize(25);
    mDefaultText[3].setCharacterSize(25);
    
    mDefaultText[4].setCharacterSize(22);

    mDefaultText[0].setPosition(650, 70);
    mDefaultText[1].setPosition(1050, 450);
    mDefaultText[2].setPosition(1050, 500);
    mDefaultText[3].setPosition(1050, 550);

    mDefaultText[4].setPosition(250, 620 + 19);

    std::string nameButton[] = {"Create", "Insert", "Remove", "Update", "Search", "Run step-by-step", "Run at-once", "Choose data structure", "OK"};
    for (int i = 0; i < 5; i++)
        mButton.push_back(Button(mWindow, sf::Vector2f(100, 50), sf::Vector2f(100, 570 + i * 55), sf::Color::Cyan, sf::Color::Blue, nameButton[i], font, 22));

    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 420), sf::Color::Cyan, sf::Color::Blue, nameButton[5], font, 22));
    mButton.push_back(Button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(100, 475), sf::Color::Cyan, sf::Color::Blue, nameButton[6], font, 22));
    mButton.push_back(Button(mWindow, sf::Vector2f(250, 50), sf::Vector2f(1300, 150), sf::Color::Cyan, sf::Color::Blue, nameButton[7], font, 22));
    
    mButton.push_back(Button(mWindow, sf::Vector2f(100, 50), sf::Vector2f(700, 770), sf::Color::Cyan, sf::Color::Blue, nameButton[8], font, 22));

    std::string nameBCreate[] = {"Enter", "Random", "Data File"};
    for (int i = 0; i < 3; i++)
        mBCreate.push_back(Button(mWindow, sf::Vector2f(100, 50), sf::Vector2f(300 + i * 200, 570), sf::Color::Cyan, sf::Color::Blue, nameBCreate[i], font, 22));

    std::string nameBInsert[] = {"At The First", "At The Last", "At The Middle"};
    for (int i = 0; i < 3; i++)
    {
        mBInsert.push_back(Button(mWindow, sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color::Cyan, sf::Color::Blue, nameBInsert[i], font, 22));
    }

    mSearchBar.push_back(SearchBar(mWindow, sf::Vector2f(100, 50), sf::Vector2f(350, 620 + 5), font, ""));
    mSearchBar.push_back(SearchBar(mWindow, sf::Vector2f(100, 50), sf::Vector2f(350, 620 + 50 + 10), font, ""));
    mSearchBar.push_back(SearchBar(mWindow, sf::Vector2f(300, 50), sf::Vector2f(350, 620 + 5), font, "8 4 22 9"));

    array = new std::string[9];
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
    {
        mData = 0;
        mButton[7].reset();
        mDataPoint.clear();

        std::ofstream outFile("data/create.data");
        outFile << "";
        outFile.close();
        return;
    }
    
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
        case 1: // Enter
            mSearchBar[2].handleEvent(event, 20);

            mButton[8].checkMouseOver();

            if (mButton[8].checkPress())
            {
                std::ofstream outFile("data/create.data");
                outFile << mSearchBar[2].getValue();
                outFile.close();

                enter();
            }
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
            mBInsert[i].checkMouseOver();
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
    for (int i = 0; i < 5; i++)
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
        case 1: // Enter
            mWindow.draw(mDefaultText[4]);
            mSearchBar[2].draw();
            
            mButton[8].draw();
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
            mBInsert[i].draw();
        break;
    case 4: // Update
        break;
    case 5: // Search
        break;
    default:
        break;
    }

    for (int i = 0; i < mDataPoint.size(); i++)
        mDataPoint[i].draw();
}

void StaticArray::saveData(std::string fileName) {
    std::ofstream outFile(fileName.c_str());

    // if (!outFile) {
    //     std::cout << "Unable to open file." << endl;
    //     return;
    // }

    outFile << size << std::endl;

    for (int i = 0; i < size; i++) {
        outFile << array[i] << " ";
    }

    outFile.close();
}

void StaticArray::enter()
{
    array = new std::string[9];
    size = 0;

    mDataPoint.clear();
    std::ifstream inFile("data/create.data");

    int id = 0;
    while (inFile >> array[id++])
        ++size;
    
    for (int i = 0; i < size; i++) 
    {
        mDataPoint.push_back(DataPoint(mWindow, sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color::White));
    }

    for (int i = size; i < 9; i++)
    {
        mDataPoint.push_back(DataPoint(mWindow, sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), "", std::to_string(i), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color::White));
    }

    inFile.close();
}
/*
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
