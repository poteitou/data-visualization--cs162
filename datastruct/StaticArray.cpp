#include "StaticArray.hpp"

StaticArray::StaticArray(sf::RenderWindow &window, sf::Font &font) : mWindow(window), mFont(font), mType(0), mSmallType(0)
{
    mButton.resize(8);
    mBCreate.resize(2);
    mBInsert.resize(3);

    mSearchBar.resize(3);
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

    mDefaultText[0].setPosition(650, 40);
    mDefaultText[1].setPosition(1050, 450);
    mDefaultText[2].setPosition(1050, 500);
    mDefaultText[3].setPosition(1050, 600);

    mDefaultText[4].setPosition(250, 620 + 19);

    std::string nameButton[] = {"Create", "Insert", "Remove", "Update", "Search", "Run step-by-step", "Run at-once", "Choose data structure"};
    for (int i = 0; i < 5; i++)
        mButton[i] = Button(sf::Vector2f(100, 50), sf::Vector2f(100, 570 + i * 55), sf::Color::Cyan, sf::Color::Blue, nameButton[i], font, 22);

    mButton[5] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 420), sf::Color::Cyan, sf::Color::Blue, nameButton[5], font, 22);
    mButton[6] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 475), sf::Color::Cyan, sf::Color::Blue, nameButton[6], font, 22);
    mButton[7] = Button(sf::Vector2f(250, 50), sf::Vector2f(1050, 670), sf::Color::Cyan, sf::Color::Blue, nameButton[7], font, 22);
    
    std::string nameBCreate[] = {"Randomize", "Data File"};
    for (int i = 0; i < 2; i++)
        mBCreate[i] = Button(sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color::Cyan, sf::Color::Blue, nameBCreate[i], font, 22);

    std::string nameBInsert[] = {"At The First", "At The Last", "At The Middle"};
    for (int i = 0; i < 3; i++)
    {
        mBInsert[i] = Button(sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color::Cyan, sf::Color::Blue, nameBInsert[i], font, 22);
    }

    mSearchBar[0] = SearchBar(sf::Vector2f(370, 50), sf::Vector2f(350, 620 + 5), font, "");
    mSearchBar[1] = SearchBar(sf::Vector2f(100, 50), sf::Vector2f(350, 620 + 5), font, "");
    mSearchBar[2] = SearchBar(sf::Vector2f(100, 50), sf::Vector2f(350, 620 + 50 + 10), font, "");

    array = new std::string[9];
    size = 0;
    step = -1;
}

void StaticArray::update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt)
{
    for (int i = 0; i < 8; i++)
        mButton[i].setMouseOver(mousePosition);
    for (int i = 0; i < 5; i++)
        if (mousePress && mButton[i].mHovered)
        {
            mType = i + 1;
            mSmallType = 0;
        }

    if (mousePress && mButton[7].mHovered)
    {
        mType = 0;
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

        if (mBCreate[0].setMouseOver(mousePosition) && mousePress) // Randomize
        {
            mSmallType = 1;
            randomize();
        }
        else if (mBCreate[1].setMouseOver(mousePosition) && mousePress) // Data file
        {
            mSmallType = 2;
        }
        switch (mSmallType)
        {
        case 1: // Randomize
            mSearchBar[0].update(mousePress, mousePosition, keyPress, 26);

            if (mousePress && mButton[6].mHovered)
            {
                std::ofstream outFile("data/randomize.data");
                outFile << mSearchBar[0].mValue;
                outFile.close();
                create("data/randomize.data");
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
            mBInsert[i].setMouseOver(mousePosition);
        break;
    case 3: // Remove
        for (int i = 0; i < 3; i++)
            mBInsert[i].setMouseOver(mousePosition);
        break;
    case 4: // Update
        break;
    case 5: // Search
        break;
    default:
        break;
    }

    if (step != -1)
    for (int i = 0; i < mDataPoint.size(); i++)
    {
        for (int j = 0; j < mDataPoint[i].size(); j++)
        {
            if (!mDataPoint[i][j].appear(100.f, dt))
            {
                step = i;
                i = 1000;
                break;
            }
        }
    }
}

void StaticArray::draw(float dt)
{
    for (int i = 0; i < 4; i++)
        mWindow.draw(mDefaultText[i]);
    for (int i = 0; i < 8; i++)
        mButton[i].draw(mWindow);
    switch (mType)
    {
    case 1: // Create
        for (int i = 0; i < 2; i++)
            mBCreate[i].draw(mWindow);
        switch (mSmallType)
        {
        case 1: // Randomize
            mWindow.draw(mDefaultText[4]);
            mSearchBar[0].draw(mWindow);
            break;
        case 2:
            break;
        default:
            break;
        }
        break;
    case 2: // Insert
        for (int i = 0; i < 3; i++)
            mBInsert[i].draw(mWindow);
        break;
    case 3: // Remove
        for (int i = 0; i < 3; i++)
            mBInsert[i].draw(mWindow);
        break;
    case 4: // Update
        break;
    case 5: // Search
        break;
    default:
        break;
    }

    if (step != -1 && !mDataPoint.empty())
    {
        for (int j = 0; j < mDataPoint[step].size(); j++)
        {
            mDataPoint[step][j].draw(mWindow);
        }
    }
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

/* void StaticArray::enter()
{
    array = new std::string[9];
    size = 0;

    mDataPoint.clear();
    std::ifstream inFile("data/create.data");

    int id = 0;
    while (inFile >> array[id++])
        ++size;
    mDataPoint.resize(size);
    
    for (int i = 0; i < size; i++) 
    {
        mDataPoint[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color(255, 200, 200, 0));
    }

    for (int i = size; i < 9; i++)
    {
        mDataPoint[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), "", std::to_string(i), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color(255, 255, 255, 0));
    }

    inFile.close();
} */

void StaticArray::randomize()
{
    std::ofstream outFile("data/randomize.data");

    srand(time(NULL));
    size = rand() % 10;
    step = -1;
    std::string temp = "";

    for (int i = 0; i < size; i++)
    {
        array[i] = std::to_string(rand() % 100);
        outFile << array[i] << ' ';
        temp += array[i] + ' ';
    }
    mSearchBar[0].mValue = temp;
    mSearchBar[0].mText.setString(temp);
    outFile.close();
}

void StaticArray::create(std::string filename)
{
    std::ifstream inFile(filename);
    step = 0; // activate
    mDataPoint.clear();
    std::vector<DataPoint> temp(9);

    size = 0;
    while (size < 9 && inFile >> array[size++]);
    std::cout << size;
    
    for (int i = 0; i < 9; i++)
    {
        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), "", "", mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color::White, i < 8 ? 100.f : 0, 0);
    }
    mDataPoint.push_back(temp);

    for (int i = size; i < 9; i++)
    {
        temp[i].mAppearTime = 100.f;
    }
    for (int i = 0; i < size; i++) 
    {
        if (i > 0) 
        {
            temp[i - 1].setBackgroundColor(sf::Color(255, 200, 200));
            temp[i - 1].mAppearTime = 100.f;
            temp[i - 1].mAppear = true;
        }
        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color(255, 105, 105), 0, 0);
        mDataPoint.push_back(temp);
    }

    temp[size - 1].setBackgroundColor(sf::Color(255, 200, 200));
    mDataPoint.push_back(temp);
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
