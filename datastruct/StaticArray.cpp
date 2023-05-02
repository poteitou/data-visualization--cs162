#include "StaticArray.hpp"

StaticArray::StaticArray(sf::RenderWindow &window, sf::Font &font) : mWindow(window), mFont(font), mType(0), mSmallType(0)
{
    mButton.resize(8);
    mBCreate.resize(2);
    mBInsert.resize(3);

    mSearchBar.resize(10);
    mDefaultText.resize(20);
    for (int i = 0; i < 10; i++)
    {
        mDefaultText[i].setFont(font);
        mDefaultText[i].setFillColor(sf::Color::Black);
    }

    // Top right
    mDefaultText[0].setString("STATIC ARRAY");
    mDefaultText[1].setString("Max size: 9");
    mDefaultText[2].setString("Value range: 0..99");
    mDefaultText[3].setString("Color tone:");

    // Create randomize, data file
    mDefaultText[4].setString("Value:");
    mDefaultText[5].setString("Directory: data/                                         .data");
    mDefaultText[6].setString("No such file or directory!");

    mDefaultText[7].setString("Position:");
    mDefaultText[8].setString("Value:");
    mDefaultText[9].setString("Index out of range!");

    mDefaultText[0].setCharacterSize(45);
    mDefaultText[1].setCharacterSize(25);
    mDefaultText[2].setCharacterSize(25);
    mDefaultText[3].setCharacterSize(25);

    mDefaultText[4].setCharacterSize(22);
    mDefaultText[5].setCharacterSize(22);
    mDefaultText[6].setCharacterSize(25);

    mDefaultText[7].setCharacterSize(22);
    mDefaultText[8].setCharacterSize(22);
    mDefaultText[9].setCharacterSize(25);

    mDefaultText[0].setPosition(650, 40);
    mDefaultText[1].setPosition(1050, 450);
    mDefaultText[2].setPosition(1050, 500);
    mDefaultText[3].setPosition(1050, 600);

    mDefaultText[4].setPosition(250, 630 + 19);
    mDefaultText[5].setPosition(250, 630 + 19);

    mDefaultText[7].setPosition(250, 630 + 19);
    mDefaultText[8].setPosition(480, 630 + 19);

    mDefaultText[6].setFillColor(sf::Color::Red);
    mDefaultText[6].setPosition(350, 630 + 50 + 19);
    mDefaultText[9].setFillColor(sf::Color::Red);
    mDefaultText[9].setPosition(350, 630 + 50 + 19);

    std::string nameButton[] = {"Create", "Insert", "Remove", "Update", "Search", "Run step-by-step", "Run at-once", "Choose data structure"};
    for (int i = 0; i < 5; i++)
        mButton[i] = Button(sf::Vector2f(100, 50), sf::Vector2f(100, 570 + i * 55), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[i], font, 22);

    mButton[5] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 420), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[5], font, 22);
    mButton[6] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 475), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[6], font, 22);
    mButton[7] = Button(sf::Vector2f(250, 50), sf::Vector2f(1050, 670), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[7], font, 22);

    std::string nameBCreate[] = {"Randomize", "Data File"};
    for (int i = 0; i < 2; i++)
        mBCreate[i] = Button(sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameBCreate[i], font, 22);

    std::string nameBInsert[] = {"At The First", "At The Last", "At The Middle"};
    for (int i = 0; i < 3; i++)
    {
        mBInsert[i] = Button(sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameBInsert[i], font, 22);
    }

    mSearchBar[0] = SearchBar(sf::Vector2f(350, 50), sf::Vector2f(350, 630 + 5), font, "", false);
    mSearchBar[1] = SearchBar(sf::Vector2f(230, 50), sf::Vector2f(410, 630 + 5), font, "datafile", true);
    mSearchBar[2] = SearchBar(sf::Vector2f(80, 50), sf::Vector2f(350, 630 + 5), font, "1", false);
    mSearchBar[3] = SearchBar(sf::Vector2f(80, 50), sf::Vector2f(560, 630 + 5), font, "9", false);

    array = new std::string[9];
    size = 0;
    step = -1;
    firstTime = true;
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
            nosuchfile = false;
        }

    if (mousePress && mButton[7].mHovered)
    {
        firstTime = true;
        step = -1;
        mType = 0;
        mData = 0;
        mButton[7].reset();
        mDataPoint.clear();
        return;
    }

    switch (mType)
    {
    case 1: // Create
        updateCreate(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 2: // Insert
        updateInsert(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 3: // Remove
        updateRemove(mousePress, mousePosition, keyPress, mData, dt);
        break;
    case 4: // Update
        mButton[3].mHovered = true;
        break;
    case 5: // Search
        mButton[4].mHovered = true;
        break;
    default:
        break;
    }

    if (step != -1)
        for (int i = 0; i < mDataPoint.size(); i++)
        {
            bool drawn = false;
            for (int j = 0; j < mDataPoint[i].size(); j++)
            {
                if (!mDataPoint[i][j].appear(100.f, dt))
                {
                    step = i;
                    drawn = true;
                }
            }
            if (drawn) break;
        }
}

void StaticArray::updateCreate(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt)
{
    mButton[0].mHovered = true;
    if (mBCreate[0].setMouseOver(mousePosition) && mousePress) // Randomize
    {
        mSmallType = 1;
        randomize();
        firstTime = true;
    }
    else if (mBCreate[1].setMouseOver(mousePosition) && mousePress) // Data file
    {
        mSearchBar[1].reset("datafile");
        mSmallType = 2;
        nosuchfile = false;
        firstTime = true;
    }
    switch (mSmallType)
    {
    case 1: // Randomize
        mBCreate[0].mHovered = true;
        mSearchBar[0].update(mousePress, mousePosition, keyPress, 26);

        if (mousePress && mButton[6].mHovered)
        {
            std::ofstream outFile("data/randomize.data");
            outFile << mSearchBar[0].mValue;
            outFile.close();
            create("data/randomize.data");
        }
        else firstTime = true;
        break;
    case 2: // Data file
        mBCreate[1].mHovered = true;
        mSearchBar[1].update(mousePress, mousePosition, keyPress, 10);
        if (mousePress && mButton[6].mHovered)
        {
            nosuchfile = false;
            create("data/" + mSearchBar[1].mValue + ".data");
        }
        else firstTime = true;
        break;
    default:
        break;
    }
}

void StaticArray::updateInsert(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt)
{
    char tempkeyPress;
    mButton[1].mHovered = true;
    for (int i = 0; i < 3; i++)
    {
        if (mBInsert[i].setMouseOver(mousePosition) && mousePress)
        {
            mSmallType = i + 1;
            nosuchfile = false;
            mSearchBar[2].reset("1");
            mSearchBar[3].reset("9");
            firstTime = true;
        }
    }
    switch (mSmallType)
    {
    case 1: // At the first
        mBInsert[0].mHovered = true;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 2);
        if (mousePress && mButton[6].mHovered && mSearchBar[2].mValue != "")
            insert(0, mSearchBar[2].mValue);
        else firstTime = true;
        break;
    case 2: // At the last
        mBInsert[1].mHovered = true;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 2);
        if (mousePress && mButton[6].mHovered && mSearchBar[2].mValue != "")
            insert(size, mSearchBar[2].mValue);
        else firstTime = true;
        break;
    case 3: // At the middle
        mBInsert[2].mHovered = true;
        tempkeyPress = keyPress;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 1);
        mSearchBar[3].update(mousePress, mousePosition, tempkeyPress, 2);
        if (mousePress && mButton[6].mHovered && mSearchBar[2].mValue != "" && mSearchBar[3].mValue != "")
            insert(stoi(mSearchBar[2].mValue), mSearchBar[3].mValue);
        else firstTime = true;
        break;
    default:
        break;
    }
}

void StaticArray::updateRemove(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt)
{
    mButton[2].mHovered = true;
    for (int i = 0; i < 3; i++)
    {
        if (mBInsert[i].setMouseOver(mousePosition) && mousePress)
        {
            mSmallType = i + 1;
            nosuchfile = false;
            mSearchBar[2].reset("1");
            firstTime = true;
        }
    }
    switch (mSmallType)
    {
    case 1: // At the first
        mBInsert[0].mHovered = true;
        if (mousePress && mButton[6].mHovered)
            remove(0);
        else firstTime = true;
        break;
    case 2: // At the last
        mBInsert[1].mHovered = true;
        if (mousePress && mButton[6].mHovered)
            remove(size - 1);
        else firstTime = true;
        break;
    case 3: // At the middle
        mBInsert[2].mHovered = true;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 1);
        if (mousePress && mButton[6].mHovered && mSearchBar[2].mValue != "")
            remove(stoi(mSearchBar[2].mValue));
        else firstTime = true;
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
        case 2: // Data file
            mWindow.draw(mDefaultText[5]);
            mSearchBar[1].draw(mWindow);

            if (nosuchfile)
                mWindow.draw(mDefaultText[6]);
            break;
        default:
            break;
        }
        break;
    case 2: // Insert
        for (int i = 0; i < 3; i++)
            mBInsert[i].draw(mWindow);
        switch (mSmallType)
        {
        case 1: // At the first
            mWindow.draw(mDefaultText[4]);
            mSearchBar[2].draw(mWindow);
            break;
        case 2: // At the last
            mWindow.draw(mDefaultText[4]);
            mSearchBar[2].draw(mWindow);
            break;
        case 3: // At the middle
            mWindow.draw(mDefaultText[7]);
            mWindow.draw(mDefaultText[8]);
            mSearchBar[2].draw(mWindow);
            mSearchBar[3].draw(mWindow);
            break;
        default:
            break;
        }
        if (nosuchfile) mWindow.draw(mDefaultText[9]);
        break;
    case 3: // Remove
        for (int i = 0; i < 3; i++)
            mBInsert[i].draw(mWindow);
        switch (mSmallType)
        {
        case 3: // At the middle
            mWindow.draw(mDefaultText[7]);
            mSearchBar[2].draw(mWindow);
            break;
        default:
            break;
        }
        if (nosuchfile) mWindow.draw(mDefaultText[9]);
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

void StaticArray::saveData(std::string fileName)
{
    std::ofstream outFile(fileName.c_str());

    // if (!outFile) {
    //     std::cout << "Unable to open file." << endl;
    //     return;
    // }

    outFile << size << std::endl;

    for (int i = 0; i < size; i++)
    {
        outFile << array[i] << " ";
    }

    outFile.close();
}

void StaticArray::randomize()
{
    std::ofstream outFile("data/randomize.data");

    srand(time(NULL));
    int randSize = rand() % 9 + 1;
    step = -1;
    std::string temp = "";
    for (int i = 0; i < randSize; i++)
    {
        std::string value = std::to_string(rand() % 100);
        outFile << value << ' ';
        temp += value + ' ';
    }
    mSearchBar[0].mValue = temp;
    mSearchBar[0].mText.setString(temp);
    outFile.close();
}

void StaticArray::create(std::string filename)
{

    std::ifstream inFile(filename);
    if (!inFile)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;

    if (firstTime == false) return;
    firstTime = false;
    step = 0; // activate
    mDataPoint.clear();
    std::vector<DataPoint> temp(9);

    size = 0;
    while (size < 9 && inFile >> array[size++]);
    --size;
    for (int i = size; i < 9; i++)
        array[i] = "";

    for (int i = 0; i < 9; i++)
    {
        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), "", "", mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color::White, i < 8 ? 100.f : 0, 0);
    }
    mDataPoint.push_back(temp);

    for (int i = size; i < 9; i++)
        temp[i].mAppearTime = 100.f;
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            temp[i - 1].mAppearTime = temp[i - 1].mDefaultAppear = 100.f;
            temp[i - 1].mAppear = true;
        }
        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::White, sf::Color(255, 95, 95), sf::Color(255, 95, 95), 0, 0);
        mDataPoint.push_back(temp);
        temp[i].setTextColor(sf::Color::Black, sf::Color::Black);
        temp[i].setBackgroundColor(sf::Color(255, 200, 200));
        mDataPoint.push_back(temp);
    }
    mDataPoint.push_back(temp);
    inFile.close();
}

void StaticArray::insert(int index, std::string element)
{
    if (firstTime == false) return;

    firstTime = false;
    std::vector<DataPoint> temp(9);
    if (mDataPoint.empty())
    {
        for (int i = 0; i < 9; i++)
        {
            temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), "", "", mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color::White, i < 8 ? 100.f : 0, 0);
        }
        mDataPoint.push_back(temp);
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            mDataPoint.back()[i].reset();
            temp[i] = mDataPoint.back()[i];
        }
        mDataPoint.clear();
        mDataPoint.push_back(temp);
    }

    if (index > size || index >= 9)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;

    step = 0; // activate
    ++size;
    for (int i = size - 1; i > index; i--)
    {
        if (i < size - 1)
        {
            temp[i + 1].mAppearTime = temp[i + 1].mDefaultAppear = 100.f;
            temp[i + 1].mAppear = true;
        }

        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::White, sf::Color(255, 95, 95), sf::Color(255, 95, 95), 0, 0);
        temp[i - 1] = DataPoint(sf::Vector2f(350 + (i - 1) * 100, 150), sf::Vector2f(50, 50), array[i - 1], std::to_string(i - 1), mFont, 22, 22, sf::Color::White, sf::Color(255, 95, 95), sf::Color(255, 95, 95), 100.f, 0);
        mDataPoint.push_back(temp);

        array[i] = array[i - 1];
        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color(255, 200, 200), 0, 0);
        temp[i - 1].setTextColor(sf::Color::Black, sf::Color::Black);
        temp[i - 1].setBackgroundColor(sf::Color(255, 200, 200));
        mDataPoint.push_back(temp);
    }

    temp[index] = DataPoint(sf::Vector2f(350 + index * 100, 150), sf::Vector2f(50, 50), array[index], std::to_string(index), mFont, 22, 22, sf::Color::White, sf::Color(255, 95, 95), sf::Color(255, 95, 95), 0, 0);
    mDataPoint.push_back(temp);
    array[index] = element;
    temp[index] = DataPoint(sf::Vector2f(350 + index * 100, 150), sf::Vector2f(50, 50), array[index], std::to_string(index), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color(255, 200, 200), 0, 0);
    mDataPoint.push_back(temp);
}

void StaticArray::remove(int index)
{
    if (firstTime == false) return;
    firstTime = false;
    if (mDataPoint.empty() || index < 0 || index >= size)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;

    std::vector<DataPoint> temp(9);
    for (int i = 0; i < 9; i++)
    {
        mDataPoint.back()[i].reset();
        temp[i] = mDataPoint.back()[i];
    }
    mDataPoint.clear();
    mDataPoint.push_back(temp);

    step = 0; // activate
    for (int i = index; i < size - 1; i++)
    {
        if (i > index)
        {
            temp[i - 1].mAppearTime = temp[i - 1].mDefaultAppear = 100.f;
            temp[i - 1].mAppear = true;
        }

        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::White, sf::Color(255, 95, 95), sf::Color(255, 95, 95), 0, 0);
        temp[i + 1] = DataPoint(sf::Vector2f(350 + (i + 1) * 100, 150), sf::Vector2f(50, 50), array[i + 1], std::to_string(i + 1), mFont, 22, 22, sf::Color::White, sf::Color(255, 95, 95), sf::Color(255, 95, 95), 100.f, 0);
        mDataPoint.push_back(temp);

        array[i] = array[i + 1];
        temp[i] = DataPoint(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(50, 50), array[i], std::to_string(i), mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color(255, 200, 200), 0, 0);
        temp[i + 1].setTextColor(sf::Color::Black, sf::Color::Black);
        temp[i + 1].setBackgroundColor(sf::Color(255, 200, 200));
        mDataPoint.push_back(temp);
    }
    --size;
    
    temp[size] = DataPoint(sf::Vector2f(350 + size * 100, 150), sf::Vector2f(50, 50), array[size], std::to_string(size), mFont, 22, 22, sf::Color::White, sf::Color(255, 95, 95), sf::Color(255, 95, 95), 0, 0);
    mDataPoint.push_back(temp);
    array[size] = "";
    temp[size] = DataPoint(sf::Vector2f(350 + size * 100, 150), sf::Vector2f(50, 50), array[size], "", mFont, 22, 22, sf::Color::Black, sf::Color::Black, sf::Color::White, 0, 0);
    mDataPoint.push_back(temp);
}
/*
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
 */
