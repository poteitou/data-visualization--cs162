#include "Queue.hpp"

Queue::Queue(sf::RenderWindow &window, sf::Font &font) : mWindow(window), mFont(font), mType(0), mSmallType(0)
{
    mButton.resize(12);
    mBCreate.resize(2);
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
    mDefaultText[0].setString("QUEUE");
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

    mDefaultText[0].setPosition(770, 40);
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

    std::string nameButton[] = {"Create", "Add", "Remove", "Clear", "Run step-by-step", "Run at-once", "Choose data structure", "R", "G", "B", "OK"};
    for (int i = 0; i < 4; i++)
        mButton[i] = Button(sf::Vector2f(100, 50), sf::Vector2f(100, 570 + i * 55), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[i], font, 22);

    mButton[4] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 420), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[4], font, 22);
    mButton[5] = Button(sf::Vector2f(200, 50), sf::Vector2f(100, 475), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[5], font, 22);
    mButton[6] = Button(sf::Vector2f(250, 50), sf::Vector2f(1050, 670), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[6], font, 22);

    pallete[0] = {sf::Color(255, 200, 200), sf::Color(255, 95, 95)};
    pallete[1] = {sf::Color(180, 255, 215), sf::Color(30, 190, 90)};
    pallete[2] = {sf::Color(180, 255, 255), sf::Color(0, 180, 240)};

    for (int i = 7; i < 10; i++)
        mButton[i] = Button(sf::Vector2f(50, 50), sf::Vector2f(1200 + (i - 7) * 70, 590), pallete[i - 7].first, pallete[i - 7].second, nameButton[i], font, 22);

    mButton[10] = Button(sf::Vector2f(75, 50), sf::Vector2f(750, 630 + 5), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameButton[10], font, 22);

    std::string nameBCreate[] = {"Randomize", "Data File"};
    for (int i = 0; i < 2; i++)
        mBCreate[i] = Button(sf::Vector2f(150, 50), sf::Vector2f(275 + i * 200, 570), sf::Color(160, 220, 255), sf::Color(50, 140, 200), nameBCreate[i], font, 22);

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
    front = rear = nullptr;
    size = 0;
    step = -1;
    speed = 0;
    firstTime = firstStep = true;
    runOption = -1; // no mode:-1       step:0      once:1
    color = 0;
}

Queue::Node::Node(std::string data)
{
    this->data = data;
    this->next = nullptr;
}

void Queue::update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt)
{
    for (int i = 0; i < 7; i++)
        mButton[i].setMouseOver(mousePosition);
    for (int i = 7; i < 10; i++)
    {
        if (mButton[i].setMouseOver(mousePosition) && mousePress)
        {
            color = i - 7;
            setColor();
        }
    }
    mButton[7 + color].mHovered = true;
    for (int i = 0; i < 4; i++)
        if (mousePress && mButton[i].mHovered)
        {
            mType = i + 1;
            mSmallType = 0;
            nosuchfile = false;
            if (i > 0)
            {
                firstTime = true;
                nosuchfile = false;
            }
            mSearchBar[2].reset(std::to_string(Rand(i < 4 ? 9 : 99)));
            mSearchBar[3].reset(std::to_string(Rand(99)));
        }

    if (runOption == 1 && mousePress && mButton[4].mHovered)
    {
        runOption = 0;
        mButton[4].mHovered = true;
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
        mButton[4].mHovered = true;

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
    if ((runOption == 0 && mousePress && mButton[5].mHovered) || runOption == 1) // Run at-once
    {
        runOption = 1;
        mButton[5].mHovered = true;
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

    if (mousePress && mButton[6].mHovered)
    {
        size = 0;
        firstTime = firstStep = true;
        runOption = step = -1;
        speed = mType = mData = 0;
        color = 0;
        mButton[6].reset();
        mDataNode.clear();
        Node *tmp;
        while (front != nullptr)
        {
            tmp = front;
            front = front->next;
            delete tmp;
        }
        front = rear = nullptr;
        return;
    }

    switch (mType)
    {
    case 1: // Create
        updateCreate(mousePress, mousePosition, keyPress);
        break;
    case 2: // Add
        updateAdd(mousePress, mousePosition, keyPress);
        break;
    case 3: // Remove
        updateRemove(mousePress, mousePosition, keyPress);
        break;
    case 4: // Clear
        updateClear(mousePress, mousePosition, keyPress);
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

void Queue::updateCreate(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
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
        if (mButton[10].setMouseOver(mousePosition) && mousePress)
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
        if (mButton[10].setMouseOver(mousePosition) && mousePress)
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

void Queue::updateAdd(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
{
    mButton[1].mHovered = true;

    mSearchBar[2].update(mousePress, mousePosition, keyPress, 2);
    if (mButton[10].setMouseOver(mousePosition) && mousePress && mSearchBar[2].mValue != "")
        add(mSearchBar[2].mValue);
    else firstTime = true;
}

void Queue::updateRemove(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
{
    mButton[2].mHovered = true;
    if (mButton[10].setMouseOver(mousePosition) && mousePress)
        remove();
    else firstTime = true;
}

void Queue::updateClear(bool mousePress, sf::Vector2i mousePosition, char &keyPress)
{
    mButton[3].mHovered = true;
    if (mButton[10].setMouseOver(mousePosition) && mousePress)
        clear();
    else firstTime = true;
}

int Queue::Rand(int MAX)
{
    srand(time(NULL));
    return rand() % MAX;
}

void Queue::randomize()
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

void Queue::setPos(std::vector<DataNode> &temp, int id, float start, Node* tmp)
{
    if (tmp == nullptr)
        return;
    if (size == 1)
    {
        temp[0] = DataNode(sf::Vector2f(start + 0 * 100, 150), sf::Vector2f(start + 0 * 100, 150), sf::Vector2f(start + 1 * 100, 150), tmp->data, "front-rear-0", mFont, sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black, 100.f, false, tmp->next != nullptr);
        return;
    }
    for (int i = id; i < size; i++)
    {
        if (tmp == nullptr) 
            return;
        temp[i] = DataNode(sf::Vector2f(start + i * 100, 150), sf::Vector2f(start + (i > 0 ? i - 1 : i) * 100, 150), sf::Vector2f(start + (i < size - 1 ? i + 1 : i) * 100, 150), tmp->data, i == 0 ? "front-0" : (i == size - 1 ? "rear-" + std::to_string(i) : std::to_string(i)), mFont, sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black, 100.f, false, tmp->next != nullptr);
        tmp = tmp->next;
    }
}

void Queue::create(std::string filename)
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
    Node *tmp;
    while (front != nullptr)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
    rear = nullptr;

    size = 0;
    while (size < 9 && inFile >> array[size]) ++size;
    if (size == 0)
    {
        inFile.close();
        return;
    }
    
    std::vector<DataNode> temp;
    front = new Node(array[0]);
    rear = front;

    if (size == 1)
    {
        temp.push_back(DataNode(sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 1 * 100, 150), front->data, "front-rear-0", mFont, sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second, 0.f, false, false));
        mDataNode.push_back(temp);
        tmp = front;
        setPos(temp, 0, 350, tmp);
        mDataNode.push_back(temp);
        inFile.close();
        return;
    }

    temp.push_back(DataNode(sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 0 * 100, 150), sf::Vector2f(350 + 1 * 100, 150), front->data, "front-0", mFont, sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second, 0.f, false, false));
    mDataNode.push_back(temp);

    for (int i = 1; i < size; i++)
    {
        temp[i - 1].mNext = true;
        mDataNode.push_back(temp);
        tmp = new Node(array[i]);
        rear->next = tmp;
        rear = rear->next;

        temp[i - 1].mAppearTime = temp[i - 1].mDefaultAppear = 100.f;
        temp[i - 1].mAppear = true;
        temp[i - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
        temp.push_back(DataNode(sf::Vector2f(350 + i * 100, 150), sf::Vector2f(350 + (i > 0 ? i - 1 : i) * 100, 150), sf::Vector2f(350 + (i < size - 1 ? i + 1 : i) * 100, 150), tmp->data, i == size - 1 ? "rear-" + std::to_string(i) : std::to_string(i), mFont, sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second, 0.f, false, false));
        mDataNode.push_back(temp);
    }
    temp[size - 1].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
    mDataNode.push_back(temp);
    inFile.close();
}

void Queue::add(std::string element)
{
    if (firstTime == false) return;

    firstTime = false;
    if (size == 9)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;

    std::vector<DataNode> temp(size + 1);
    Node *tmp = front;
    setPos(temp, 0, 350, tmp);
    mDataNode.clear();
    mDataNode.push_back(temp);

    runOption = 1;
    step = 0; // activate
    Node *newNode = new Node(element);
    temp[size] = DataNode(sf::Vector2f(350 + 0 * 100, 250), sf::Vector2f(350 + 0 * 100, 250), sf::Vector2f(350 + 0 * 100, 250), newNode->data, "", mFont, sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black, 0, false, newNode->next != nullptr);
    mDataNode.push_back(temp);

    temp[size].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
    mDataNode.push_back(temp);

    tmp = front;
    setPos(temp, 0, 450, tmp);
    if (front != nullptr) mDataNode.push_back(temp);

    newNode->next = front;
    temp[size].setPosition(sf::Vector2f(350 + 0 * 100, 250), sf::Vector2f(350 + 0 * 100, 250), sf::Vector2f(450 + 0 * 100, 150));
    temp[size].mNext = newNode->next != nullptr;
    if (newNode->next != nullptr) mDataNode.push_back(temp);
    front = newNode;

    ++size;
    tmp = front;
    setPos(temp, 0, 350, tmp);
    mDataNode.push_back(temp);
}

void Queue::remove()
{
    if (firstTime == false) return;
    firstTime = false;
    if (mDataNode.empty() || 0 >= size)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;

    std::vector<DataNode> temp(size);
    Node *tmp = front;
    setPos(temp, 0, 350, tmp);
    mDataNode.clear();
    mDataNode.push_back(temp);

    runOption = 1;
    step = 0; // activate

    tmp = front;
    temp[0].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
    temp[0].mAppear = false;
    temp[0].mAppearTime = temp[0].mDefaultAppear = 0.f;
    mDataNode.push_back(temp);

    temp[0].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
    mDataNode.push_back(temp);

    front = front->next;
    if (front != nullptr)
    {
        temp[0].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
        temp[0 + 1].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
        mDataNode.push_back(temp);
    }
    delete tmp;

    --size;
    temp.resize(size);
    tmp = front;
    setPos(temp, 0, 350, tmp);
    mDataNode.push_back(temp);
}

void Queue::clear()
{
    if (firstTime == false) return;

    firstTime = false;
    if (mDataNode.empty() || 0 >= size)
    {
        nosuchfile = true;
        return;
    }
    nosuchfile = false;
    
    std::vector<DataNode> temp(size);
    Node *tmp = front;
    setPos(temp, 0, 350, tmp);
    mDataNode.clear();
    mDataNode.push_back(temp);

    runOption = 1;
    step = 0; // activate

    while (front != nullptr)
    {
        tmp = front;
        temp[0].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
        temp[0].mAppear = false;
        temp[0].mAppearTime = temp[0].mDefaultAppear = 0.f;
        mDataNode.push_back(temp);
        temp[0].setColor(sf::Color::White, pallete[color].second, pallete[color].second, pallete[color].second);
        mDataNode.push_back(temp);
        front = front->next;
        if (front != nullptr)
        {
            temp[0].setColor(sf::Color::Black, sf::Color::Black, pallete[color].first, sf::Color::Black);
            temp[0 + 1].setColor(sf::Color::White, pallete[color].second, pallete[color].second, sf::Color::Black);
            mDataNode.push_back(temp);
        }
        delete tmp;
        --size;
        temp.resize(size);
        tmp = front;
        setPos(temp, 0, 350, tmp);
        mDataNode.push_back(temp);
    }
}

void Queue::setColor()
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


void Queue::draw()
{
    mWindow.draw(mRect[0]);
    mWindow.draw(mRect[1]);
    for (int i = 0; i < 4; i++)
        mWindow.draw(mDefaultText[i]);
    for (int i = 0; i < 10; i++)
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
            mButton[10].draw(mWindow);
            break;
        case 2: // Data file
            mWindow.draw(mDefaultText[5]);
            mSearchBar[1].draw(mWindow);
            mButton[10].draw(mWindow);
            if (nosuchfile)
                mWindow.draw(mDefaultText[6]);
            break;
        default:
            break;
        }
        break;
    case 2: // Add
        mWindow.draw(mDefaultText[4]);
        mSearchBar[2].draw(mWindow);
        mButton[10].draw(mWindow);
        if (nosuchfile) mWindow.draw(mDefaultText[9]);
        break;
    case 3: // Remove
        mButton[10].draw(mWindow);
        if (nosuchfile) mWindow.draw(mDefaultText[9]);
        break;
    case 4: // Clear
        mButton[10].draw(mWindow);
        if (nosuchfile) mWindow.draw(mDefaultText[9]);
        break;
    default:
        break;
    }

    if (runOption != -1 && step != -1)
    {
        for (int i = 0; i < mDataNode[step].size(); i++)
            mDataNode[step][i].draw(mWindow);
    }
}
