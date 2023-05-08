#ifndef STACK_HPP
#define STACK_HPP

#include <SFML/Graphics.hpp>
#include "../interface/Button.hpp"
#include "../interface/DataNode.hpp"
#include "../interface/SearchBar.hpp"
#include <string.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <utility>

struct Stack
{
    Stack(sf::RenderWindow &window, sf::Font &font);

    struct Node
    {
        std::string data;
        Node *next;

        Node(std::string data);
    };

    Node *top;

    void update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void updateCreate(bool mousePress, sf::Vector2i mousePosition, char &keyPress);
    void updatePush(bool mousePress, sf::Vector2i mousePosition, char &keyPress);
    void updatePop(bool mousePress, sf::Vector2i mousePosition, char &keyPress);
    void updateClear(bool mousePress, sf::Vector2i mousePosition, char &keyPress);

    int Rand(int MAX);
    void randomize();
    void setPos(std::vector<DataNode> &temp, int id, float start, Node* tmp);
    void create(std::string fileName);
    void push(int index, std::string element);
    void pop(int index);
    void clear(int index, std::string element);

    void setColor();
    void draw();

    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    std::vector<Button> mButton;
    std::vector<Button> mBCreate;
    std::vector<Button> mBInsert;

    std::vector<Button> mBStep;
    std::vector<Button> mBOnce;

    std::vector<sf::Text> mDefaultText;
    std::vector<SearchBar> mSearchBar;

    std::vector<std::vector<DataNode>> mDataNode;
    std::string *array;

    int step;
    int size;
    int mType;
    int mSmallType;
    int speed;
    bool nosuchfile;
    bool firstTime;
    bool firstStep;
    int runOption;
    std::pair<sf::Color, sf::Color> pallete[3];
    sf::RectangleShape mRect[2];
    int color;
};

#endif // STACK_HPP
