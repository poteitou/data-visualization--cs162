#include "CircularLinkedList.hpp"

CircularLinkedList::CircularLinkedList(sf::RenderWindow &window, sf::Font &font) : mWindow(window), mFont(font), mType(0), mSmallType(0)
{
    mButton.resize(12);
    mBCreate.resize(2);
    mBInsert.resize(3);
    mBStep.resize(3);
    mBOnce.resize(4);

    mSearchBar.resize(10);
    mDefaultText.resize(20);
    for (int i = 0; i < 10; i++)
    {
        mDefaultText[i].setFont(font);
        mDefaultText[i].setFillColor(sf::Color::Black);
    }

    // Top right
    mDefaultText[0].setString("CIRCULAR LINKED LIST ");
    mDefaultText[1].setString("Maximum capacity: 9");
    mDefaultText[2].setString("Value range: 0..99");
    mDefaultText[3].setString("Color tone:");

    // Create randomize, data file
    mDefaultText[4].setString("Value:");
    mDefaultText[5].setString("Directory: data/                                   .data");
    mDefaultText[6].setString("Error: No such file or directory!");

    mDefaultText[7].setString("Index:");
    mDefaultText[8].setString("Value:");
    mDefaultText[9].setString("Error: Index out of range or reaching capacity!");

    mDefaultText[0].setCharacterSize(45);
    mDefaultText[1].setCharacterSize(25);
    mDefaultText[2].setCharacterSize(25);
    mDefaultText[3].setCharacterSize(25);

    mDefaultText[4].setCharacterSize(25);
    mDefaultText[5].setCharacterSize(25);
    mDefaultText[6].setCharacterSize(25);

    mDefaultText[7].setCharacterSize(25);
    mDefaultText[8].setCharacterSize(25);
    mDefaultText[9].setCharacterSize(25);

    mDefaultText[0].setPosition(600, 40);
    mDefaultText[1].setPosition(1050, 420);
    mDefaultText[2].setPosition(1050, 470);
    mDefaultText[3].setPosition(1050, 600);

    mDefaultText[4].setPosition(250, 630 + 15);
    mDefaultText[5].setPosition(250, 630 + 15);

    mDefaultText[7].setPosition(250, 630 + 15);
    mDefaultText[8].setPosition(480, 630 + 15);

    mDefaultText[6].setFillColor(sf::Color::Red);
    mDefaultText[6].setPosition(350, 630 + 50 + 15);
    mDefaultText[9].setFillColor(sf::Color::Red);
    mDefaultText[9].setPosition(350, 630 + 50 + 15);

    std::string nameButton[] = {"Create", "Insert", "Remove", "Update", "Search", "Run step-by-step", "Run at-once", "Choose data structure", "R", "G", "B", "OK"};
    for (int i = 0; i < 5; i++)
        mButton[i] = Button(sf::Vector2f(100, 50), sf::Vector2f(100, 570 + i * 55), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[i], font, 22);

    mButton[5] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 420), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[5], font, 22);
    mButton[6] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 475), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[6], font, 22);
    mButton[7] = Button(sf::Vector2f(250, 50), sf::Vector2f(1050, 670), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[7], font, 22);

    pallete[0] = {sf::Color(255, 200, 200), sf::Color(255, 95, 95)};
    pallete[1] = {sf::Color(180, 255, 215), sf::Color(30, 190, 90)};
    pallete[2] = {sf::Color(180, 255, 255), sf::Color(0, 180, 240)};

    for (int i = 8; i < 11; i++)
        mButton[i] = Button(sf::Vector2f(50, 50), sf::Vector2f(1200 + (i - 8) * 70, 590), pallete[i - 8].first, pallete[i - 8].second, nameButton[i], font, 22);

    mButton[11] = Button(sf::Vector2f(75, 50), sf::Vector2f(750, 630 + 5), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[11], font, 22);

    std::string nameBCreate[] = {"Randomize", "Data File"};
    for (int i = 0; i < 2; i++)
        mBCreate[i] = Button(sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameBCreate[i], font, 22);

    std::string nameBInsert[] = {"At The First", "At The Last", "At The Middle"};
    for (int i = 0; i < 3; i++)
        mBInsert[i] = Button(sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameBInsert[i], font, 22);

    std::string nameBStep[] = {"Previous", "Next", "Final"};
    for (int i = 0; i < 3; i++)
        mBStep[i] = Button(sf::Vector2f(100, 50), sf::Vector2f(350 + i * 150, 420), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameBStep[i], font, 22);

    std::string nameBOnce[] = {"1x", "2x", "4x", "8x"};
    for (int i = 0; i < 4; i++)
        mBOnce[i] = Button(sf::Vector2f(100, 50), sf::Vector2f(350 + i * 150, 475), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameBOnce[i], font, 22);

    mSearchBar[0] = SearchBar(sf::Vector2f(350, 50), sf::Vector2f(350, 630 + 5), font, "", false);
    mSearchBar[1] = SearchBar(sf::Vector2f(230, 50), sf::Vector2f(430, 630 + 5), font, "datafile", true);
    mSearchBar[2] = SearchBar(sf::Vector2f(80, 50), sf::Vector2f(330, 630 + 5), font, std::to_string(Rand(9)), false);
    mSearchBar[3] = SearchBar(sf::Vector2f(80, 50), sf::Vector2f(560, 630 + 5), font, std::to_string(Rand(99)), false);

    for (int i = 0; i < 2; i++)
    {
        mRect[i].setOrigin(sf::Vector2f(0.f, 0.f));
        mRect[i].setFillColor(sf::Color::Transparent);
        mRect[i].setOutlineThickness(2.f);
        mRect[i].setOutlineColor(sf::Color::Black);
    }
    mRect[0].setSize(sf::Vector2f(900, 500));
    mRect[0].setPosition(sf::Vector2f(50, 380));

    mRect[1].setSize(sf::Vector2f(550, 500));
    mRect[1].setPosition(sf::Vector2f(1000, 380));

    array = new std::string[9];
    head = nullptr;
    size = 0;
    step = -1;
    speed = 0;
    firstTime = firstStep = true;
    runOption = -1; // no mode:-1       step:0      once:1
    color = 0;
}

CircularLinkedList::Node::Node(std::string data)
{
    this->data = data;
    this->next = nullptr;
}

void CircularLinkedList::update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt)
{
    for (int i = 0; i < 8; i++)
        mButton[i].setMouseOver(mousePosition);
    for (int i = 8; i < 11; i++)
    {
        if (mButton[i].setMouseOver(mousePosition) && mousePress)
        {
            color = i - 8;
            setColor();
        }
    }
    mButton[8 + color].mHovered = true;
    for (int i = 0; i < 5; i++)
        if (mousePress && mButton[i].mHovered)
        {
            mType = i + 1;
            mSmallType = 0;
            nosuchfile = false;
            if (i >= 3)
                firstTime = true;
            if (i == 3)
                nosuchfile = false;
            mSearchBar[2].reset(std::to_string(Rand(i < 4 ? 9 : 99)));
            mSearchBar[3].reset(std::to_string(Rand(99)));
        }

    if (runOption == 1 && mousePress && mButton[5].mHovered)
    {
        runOption = 0;
        mButton[5].mHovered = true;
        for (int i = 0; i < 4; i++) mBOnce[i].mHovered = false;
        for (int i = 0; i < 3; i++)
            mBStep[i].setMouseOver(mousePosition);
        speed = 0;
        step = 0;
        for (int i = 0; i < mDataNode.size(); i++)
        {
            for (int j = 0; j < mDataNode[i].size(); j++)
                mDataNode[i][j].reset();
        }
    }
    else if (runOption == 0) // Run step-by-step
    {
        mButton[5].mHovered = true;

        if (mBStep[0].setMouseOver(mousePosition) && mousePress)
        {
            if (step > 0 && firstStep) 
            {
                --step;
                for (int i = 0; i < mDataNode[step].size(); i++)
                    mDataNode[step][i].reset();
            }
            firstStep = false;
        }
        else if (mBStep[1].setMouseOver(mousePosition) && mousePress)
        {
            if (step + 1 < (int)mDataNode.size() && firstStep) 
            {
                ++step;
                for (int i = 0; i < mDataNode[step].size(); i++)
                    mDataNode[step][i].reset();
            }
            firstStep = false;
        }
        else if (mBStep[2].setMouseOver(mousePosition) && mousePress)
        {
            if (firstStep) 
            {
                step = (int)mDataNode.size() - 1;
                for (int i = 0; i < mDataNode[step].size(); i++)
                    mDataNode[step][i].reset();
            }
            firstStep = false;
        }
        else firstStep = true;
    }
    if ((runOption == 0 && mousePress && mButton[6].mHovered) || runOption == 1) // Run at-once
    {
        runOption = 1;
        mButton[6].mHovered = true;
        for (int i = 0; i < 4; i++)
        {
            if (speed == 0) speed = 1; // auto 1x speed
            if (mBOnce[i].setMouseOver(mousePosition) && mousePress)
            {
                speed = 1 << i;
                mBOnce[i].mHovered = true;
                for (int i = 0; i < mDataNode.size(); i++)
                {
                    for (int j = 0; j < mDataNode[i].size(); j++)
                        mDataNode[i][j].reset();
                }
            }
            if (speed == (1 << i)) mBOnce[i].mHovered = true;
        }
    }

    if (mousePress && mButton[7].mHovered)
    {
        size = 0;
        firstTime = firstStep = true;
        runOption = step = -1;
        speed = mType = mData = 0;
        color = 0;
        mButton[7].reset();
        mDataNode.clear();
        mCir.clear();
        Node *tmp;
        for (int i = 0; i < size; i++)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        head = nullptr;
        return;
    }

    switch (mType)
    {
    case 1: // Create
        updateCreate(mousePress, mousePosition, keyPress);
        break;
    case 2: // Insert
        updateInsert(mousePress, mousePosition, keyPress);
        break;
    case 3: // Remove
        updateRemove(mousePress, mousePosition, keyPress);
        break;
    case 4: // Update
        updateModify(mousePress, mousePosition, keyPress);
        break;
    case 5: // Search
        updateSearch(mousePress, mousePosition, keyPress);
        break;
    default:
        break;
    }

    if (runOption == 1)
    {
        bool drawn = false;
        for (int i = 0; i < mDataNode.size(); i++)
        {
            for (int j = 0; j < mDataNode[i].size(); j++)
            {
                if (!mDataNode[i][j].appear(100.f, speed * dt))
                {
                    step = i;
                    drawn = true;
                }
            }
            if (drawn) break;
        }
        if (drawn == false)
            step = (int)mDataNode.size() - 1;
    }
}

void CircularLinkedList::updateCreate(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
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
        if (mButton[11].setMouseOver(mousePosition) && mousePress)
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
        if (mButton[11].setMouseOver(mousePosition) && mousePress)
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

void CircularLinkedList::updateInsert(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
{
    char tempkeyPress;
    mButton[1].mHovered = true;
    for (int i = 0; i < 3; i++)
    {
        if (mBInsert[i].setMouseOver(mousePosition) && mousePress)
        {
            mSmallType = i + 1;
            nosuchfile = false;
            mSearchBar[2].reset(std::to_string(Rand(i < 2 ? 99 : 9)));
            mSearchBar[3].reset(std::to_string(Rand(99)));
            firstTime = true;
        }
    }
    switch (mSmallType)
    {
    case 1: // At the first
        mBInsert[0].mHovered = true;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 2);
        if (mButton[11].setMouseOver(mousePosition) && mousePress && mSearchBar[2].mValue != "")
            insert(0, mSearchBar[2].mValue);
        else firstTime = true;
        break;
    case 2: // At the last
        mBInsert[1].mHovered = true;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 2);
        if (mButton[11].setMouseOver(mousePosition) && mousePress && mSearchBar[2].mValue != "")
            insert(size, mSearchBar[2].mValue);
        else firstTime = true;
        break;
    case 3: // At the middle
        mBInsert[2].mHovered = true;
        tempkeyPress = keyPress;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 1);
        mSearchBar[3].update(mousePress, mousePosition, tempkeyPress, 2);
        if (mButton[11].setMouseOver(mousePosition) && mousePress && mSearchBar[2].mValue != "" && mSearchBar[3].mValue != "")
            insert(stoi(mSearchBar[2].mValue), mSearchBar[3].mValue);
        else firstTime = true;
        break;
    default:
        break;
    }
}

void CircularLinkedList::updateRemove(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
{
    mButton[2].mHovered = true;
    for (int i = 0; i < 3; i++)
    {
        if (mBInsert[i].setMouseOver(mousePosition) && mousePress)
        {
            mSmallType = i + 1;
            nosuchfile = false;
            mSearchBar[2].reset(std::to_string(Rand(9)));
            firstTime = true;
        }
    }
    switch (mSmallType)
    {
    case 1: // At the first
        mBInsert[0].mHovered = true;
        if (mButton[11].setMouseOver(mousePosition) && mousePress) remove(0);
        else firstTime = true;
        break;
    case 2: // At the last
        mBInsert[1].mHovered = true;
        if (mButton[11].setMouseOver(mousePosition) && mousePress) remove(size - 1);
        else firstTime = true;
        break;
    case 3: // At the middle
        mBInsert[2].mHovered = true;
        mSearchBar[2].update(mousePress, mousePosition, keyPress, 1);
        if (mButton[11].setMouseOver(mousePosition) && mousePress && mSearchBar[2].mValue != "")
            remove(stoi(mSearchBar[2].mValue));
        else firstTime = true;
        break;
    default:
        break;
    }
}

void CircularLinkedList::updateModify(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
{
    mButton[3].mHovered = true;

    char tempkeyPress = keyPress;
    mSearchBar[2].update(mousePress, mousePosition, keyPress, 1);
    mSearchBar[3].update(mousePress, mousePosition, tempkeyPress, 2);
    if (mButton[11].setMouseOver(mousePosition) && mousePress && mSearchBar[2].mValue != "" && mSearchBar[3].mValue != "")
        modify(stoi(mSearchBar[2].mValue), mSearchBar[3].mValue);
    else firstTime = true;
}

void CircularLinkedList::updateSearch(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
{
    mButton[4].mHovered = true;
    
    mSearchBar[2].update(mousePress, mousePosition, keyPress, 2);
    if (mButton[11].setMouseOver(mousePosition) && mousePress && mSearchBar[2].mValue != "")
        search(mSearchBar[2].mValue);
    else firstTime = true;
}

int CircularLinkedList::Rand(int MAX)
{
    srand(time(NULL));
    return rand() % MAX;
}

void CircularLinkedList::randomize()
{
    std::ofstream outFile("data/randomize.data");

    srand(time(NULL));
    int randSize = rand() % 9 + 1;
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

void CircularLinkedList::setPos(std::vector<DataNode> &temp, int id, float start, Node* tmp, CircularArr &cir)
{
    if (tmp == nullptr)
        return;
    for (int i = id; i < size; i++)
    {
        temp[i] = DataNode(sf::Vector2f(start + i * 100, 150), sf::Vector2f(start + (i > 0 ? i - 1 : i) * 100, 150), sf::Vector2f(start + (i < size - 1 ? i + 1 : i) * 100, 150), tmp->data, i == 0 ? "head-0" : std::to_string(i), mFont, sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black, 100.f, false, i < size - 1 && tmp->next != nullptr);
        tmp = tmp->next;
    }
    cir = CircularArr(sf::Vector2f(start + 0 * 100, 150), sf::Vector2f(start + (size - 1) * 100, 150), sf::Color::Black, true);
}

void CircularLinkedList::create(std::string filename)
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
    runOption = 1;
    step = 0; // activate
    mDataNode.clear();
    mCir.clear();
    Node *tmp;
    for (int i = 0; i < size; i++)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;

    size = 0;
    while (size < 9 && inFile >> array[size]) ++size;
    if (size == 0)
    {
        inFile.close();
        return;
    }
    
    std::vector<DataNode> temp;
    CircularArr cir = CircularArr(sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 0 * 100, 150), sf::Color::Black, false);
    head = new Node(array[0]);
    Node *cur = head;

    temp.push_back(DataNode(sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 1 * 100, 150), head->data, "head-0", mFont, sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second, 0.f, false, false));
    mDataNode.push_back(temp);
    mCir.push_back(cir);

    for (int i = 1; i < size; i++)
    {
        temp[i - 1].mNext = true;
        mDataNode.push_back(temp);
        mCir.push_back(cir);
        tmp = new Node(array[i]);
        cur->next = tmp;
        cur = cur->next;

        temp[i - 1].mAppearTime = temp[i - 1].mDefaultAppear = 100.f;
        temp[i - 1].mAppear = true;
        temp[i - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
        temp.push_back(DataNode(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(350 + (i > 0 ? i - 1 : i) * 100, 150), sf::Vector2f(350 + (i < size - 1 ? i + 1 : i) * 100, 150), tmp->data, std::to_string(i), mFont, sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second, 0.f, false, false));
        mDataNode.push_back(temp);
        mCir.push_back(cir);
    }
    cir = CircularArr(sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + (size - 1) * 100, 150), pallete[color].second, true);
    mDataNode.push_back(temp);
    mCir.push_back(cir);
    cur->next = head;

    cir.setColor(sf::Color::Black);
    temp[size - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
    mDataNode.push_back(temp);
    mCir.push_back(cir);
    inFile.close();
}

void CircularLinkedList::insert(int index, std::string element)
{
    if (firstTime == false) return;

    firstTime = false;
    if (size == 9 || index > size || index >= 9)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;

    std::vector<DataNode> temp(size + 1);
    CircularArr cir;
    Node *tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.clear();
    mCir.clear();
    mDataNode.push_back(temp);
    mCir.push_back(cir);

    runOption = 1;
    step = 0; // activate
    Node *newNode = new Node(element);
    temp[size] = DataNode(sf::Vector2f(350 + index * 100, 250), sf::Vector2f(350 + index * 100, 250), sf::Vector2f(350 + index * 100, 250), newNode->data, "", mFont, sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black, 0, false, newNode->next != nullptr);
    mDataNode.push_back(temp);
    mCir.push_back(cir);

    if (index == 0)
    {
        temp[size].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
        mDataNode.push_back(temp);
        mCir.push_back(cir);
        if (head == nullptr)
        {
            temp[size].setPosition(sf::Vector2f(350 + index * 100, 150), sf::Vector2f(350 + index * 100, 150), sf::Vector2f(350 + index * 100, 150));
            mDataNode.push_back(temp);
            mCir.push_back(cir);
            head = newNode;
            cir = CircularArr(sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 0 * 100, 150), pallete[color].second, true);
            mDataNode.push_back(temp);
            mCir.push_back(cir);
            head->next = head;
        }
        else
        {
            tmp = head;
            setPos(temp, 0, 450, tmp, cir);
            temp[0].mAppear = false;
            temp[0].mAppearTime = temp[index].mDefaultAppear = 0.f;
            mDataNode.push_back(temp);
            mCir.push_back(cir);

            newNode->next = head;
            temp[size].setPosition(sf::Vector2f(350 + index * 100, 250), sf::Vector2f(350 + index * 100, 250), sf::Vector2f(450 + 0 * 100, 150));
            temp[size].mNext = newNode->next != nullptr;
            mDataNode.push_back(temp);
            mCir.push_back(cir);

        head = newNode;
    }
    else
    {
        Node *previous = head;

        for (int i = 0; i <= index - 1; i++)
        {
            if (i > 0)
            {
                temp[i - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
            }
            temp[i] = DataNode(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(350 + (i > 0 ? i - 1 : i) * 100, 150), sf::Vector2f(350 + (i < size - 1 ? i + 1 : i) * 100, 150), previous->data, i == 0 ? "head-0" : std::to_string(i), mFont, sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black, 100.f, false, previous->next != nullptr);
            mDataNode.push_back(temp);

            if (i < index - 1)
            {
                temp[i].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
                mDataNode.push_back(temp);
                previous = previous->next;
            }
        }

        temp[size].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
        mDataNode.push_back(temp);

        tmp = previous->next;
        setPos(temp, index, 450, tmp, cir);
        if (tmp != nullptr) 
        {
            temp[index - 1].setPosition(sf::Vector2f(350 + (index - 1) * 100, 150), sf::Vector2f(350 + (index - 1 > 0 ? index - 2 : index - 1) * 100, 150), sf::Vector2f(450 + index * 100, 150));
            mDataNode.push_back(temp);
        }

        newNode->next = previous->next;
        temp[size].setPosition(sf::Vector2f(350 + index * 100, 250), sf::Vector2f(350 + index * 100, 250), sf::Vector2f(350 + (index + 1) * 100, 150));
        temp[size].mNext = newNode->next != nullptr;
        if (newNode->next != nullptr) mDataNode.push_back(temp);

        previous->next = newNode;
        temp[index - 1].setPosition(sf::Vector2f(350 + (index - 1) * 100, 150), sf::Vector2f(350 + (index - 1 > 0 ? index - 2 : index - 1) * 100, 150), sf::Vector2f(350 + index * 100, 250));
        temp[index - 1].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
        temp[index - 1].mNext = previous->next != nullptr;
        mDataNode.push_back(temp);
    }
    ++size;
    tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.push_back(temp);
    mCir.push_back(cir);
}

void CircularLinkedList::remove(int index)
{
    if (firstTime == false) return;
    firstTime = false;
    if (mDataNode.empty() || index < 0 || index >= size)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;

    std::vector<DataNode> temp(size);
    CircularArr cir;
    Node *tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.clear();
    mCir.clear();
    mDataNode.push_back(temp);

    runOption = 1;
    step = 0; // activate
    if (index == 0)
    {
        tmp = head;
        temp[index].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
        temp[index].mAppear = false;
        temp[index].mAppearTime = temp[index].mDefaultAppear = 0.f;
        mDataNode.push_back(temp);

        temp[index].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
        mDataNode.push_back(temp);

        head = head->next;
        if (head != nullptr)
        {
            temp[index].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
            temp[index + 1].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
            mDataNode.push_back(temp);
        }

        delete tmp;
    }
    else
    {
        temp[index].mAppear = false;
        temp[index].mAppearTime = temp[index].mDefaultAppear = 0.f;
        Node *previous = head;

        for (int i = 0; i <= index - 1; i++)
        {
            if (i > 0)
            {
                temp[i - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
            }
            temp[i] = DataNode(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(350 + (i > 0 ? i - 1 : i) * 100, 150), sf::Vector2f(350 + (i < size - 1 ? i + 1 : i) * 100, 150), previous->data, i == 0 ? "head-0" : std::to_string(i), mFont, sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black, 100.f, false, previous->next != nullptr);
            mDataNode.push_back(temp);

            if (i < index - 1)
            {
                temp[i].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
                mDataNode.push_back(temp);
                previous = previous->next;
            }
        }

        temp[index - 1].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
        mDataNode.push_back(temp);

        tmp = previous->next;
        
        temp[index].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
        mDataNode.push_back(temp);

        temp[index - 1].setPosition(sf::Vector2f(350 + (index - 1) * 100, 150), sf::Vector2f(350 + (index - 1 > 0 ? index - 2 : index - 1) * 100, 150), sf::Vector2f(350 + index * 100, 250));
        temp[index].setPosition(sf::Vector2f(350 + index * 100, 250), sf::Vector2f(350 + (index - 1) * 100, 150), sf::Vector2f(350 + (index < size - 1 ? index + 1 : index) * 100, 150));
        mDataNode.push_back(temp);

        previous->next = tmp->next;
        temp[index - 1].setPosition(sf::Vector2f(350 + (index - 1) * 100, 150), sf::Vector2f(350 + (index - 1 > 0 ? index - 2 : index - 1) * 100, 150), sf::Vector2f(450 + index * 100, 150));
        temp[index - 1].mNext = previous->next != nullptr;
        if (previous->next) mDataNode.push_back(temp);
        delete tmp;
    }
    --size;
    temp.resize(size);
    tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.push_back(temp);
}

void CircularLinkedList::modify(int index, std::string element)
{
    if (firstTime == false) return;

    firstTime = false;
    if (mDataNode.empty() || index >= size)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;
    
    std::vector<DataNode> temp(size);
    CircularArr cir;
    Node *tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.clear();
    mCir.clear();
    mDataNode.push_back(temp);

    runOption = 1;
    step = 0; // activate
    tmp = head;
    temp[0].mAppear = false;
    temp[0].mAppearTime = temp[0].mDefaultAppear = 0.f;

    for (int i = 0; i <= index; i++)
    {
        if (i > 0)
        {
            temp[i - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
        }
        temp[i].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
        mDataNode.push_back(temp);

        if (i < index)
        {
            temp[i].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
            mDataNode.push_back(temp);
            tmp = tmp->next;
        }
    }
    tmp->data = element;
    tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.push_back(temp);
}

void CircularLinkedList::search(std::string element) 
{
    if (firstTime == false || mDataNode.empty()) return;
    firstTime = false;

    if (size == 0)
        return;
    std::vector<DataNode> temp(size);
    CircularArr cir;
    Node *tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.clear();
    mCir.clear();
    mDataNode.push_back(temp);

    runOption = 1;
    step = 0; // activate
    tmp = head;
    temp[0].mAppear = false;
    temp[0].mAppearTime = temp[0].mDefaultAppear = 0.f;
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            temp[i - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
        }
        temp[i].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
        mDataNode.push_back(temp);

        if (tmp->data == element)
            return;

        if (i < size - 1)
        {
            temp[i].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
            mDataNode.push_back(temp);
            tmp = tmp->next;
        }
    }
    tmp = head;
    setPos(temp, 0, 350, tmp, cir);
    mDataNode.push_back(temp);
}

void CircularLinkedList::setColor()
{
    for (int i = 0; i < mDataNode.size(); i++)
    {
        for (int j = 0; j < mDataNode[i].size(); j++) if (mDataNode[i][j].mColor != sf::Color::White)
        {
            if (mDataNode[i][j].mInColor == sf::Color::Black)
            {
                mDataNode[i][j].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
            }
            else 
            {
                bool ok = mDataNode[i][j].mArrColor != sf::Color::Black;
                mDataNode[i][j].setColor(sf::Color::White, pallete[color].second, pallete[color].second, ok ? pallete[color].second : sf::Color::Black);
            }
        }
    }
}


void CircularLinkedList::draw()
{
    mWindow.draw(mRect[0]);
    mWindow.draw(mRect[1]);
    for (int i = 0; i < 4; i++)
        mWindow.draw(mDefaultText[i]);
    for (int i = 0; i < 11; i++)
        mButton[i].draw(mWindow);
    if (runOption == 0)
    {
        for (int i = 0; i < 3; i++)
            mBStep[i].draw(mWindow);
    }
    if (runOption == 1)
    {
        for (int i = 0; i < 4; i++)
            mBOnce[i].draw(mWindow);
    }
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
            mButton[11].draw(mWindow);
            break;
        case 2: // Data file
            mWindow.draw(mDefaultText[5]);
            mSearchBar[1].draw(mWindow);
            mButton[11].draw(mWindow);
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
            mButton[11].draw(mWindow);
            break;
        case 2: // At the last
            mWindow.draw(mDefaultText[4]);
            mSearchBar[2].draw(mWindow);
            mButton[11].draw(mWindow);
            break;
        case 3: // At the middle
            mWindow.draw(mDefaultText[7]);
            mWindow.draw(mDefaultText[8]);
            mSearchBar[2].draw(mWindow);
            mSearchBar[3].draw(mWindow);
            mButton[11].draw(mWindow);
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
        case 1: // At the first
            mButton[11].draw(mWindow);
            break;
        case 2: // At the last
            mButton[11].draw(mWindow);
            break;
        case 3: // At the middle
            mWindow.draw(mDefaultText[7]);
            mSearchBar[2].draw(mWindow);
            mButton[11].draw(mWindow);
            break;
        default:
            break;
        }
        if (nosuchfile) mWindow.draw(mDefaultText[9]);
        break;
    case 4: // Update
        mWindow.draw(mDefaultText[7]);
        mWindow.draw(mDefaultText[8]);
        mSearchBar[2].draw(mWindow);
        mSearchBar[3].draw(mWindow);
        mButton[11].draw(mWindow);
        if (nosuchfile) mWindow.draw(mDefaultText[9]);
        break;
    case 5: // Search
        mWindow.draw(mDefaultText[4]);
        mSearchBar[2].draw(mWindow);
        mButton[11].draw(mWindow);
        break;
    default:
        break;
    }

    if (runOption != -1 && step != -1)
    {
        for (int i = 0; i < mDataNode[step].size(); i++)
            mDataNode[step][i].draw(mWindow);
        mCir[step].draw(mWindow);
    }
}
