#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include <SFML/Graphics.hpp>
#include "../interface/Arrow.hpp"
#include "../interface/Button.hpp"
#include "../interface/DataPoint.hpp"
#include "../interface/SearchBar.hpp"
#include <string.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <utility> 

#include <iostream>

struct SinglyLinkedList
{
    SinglyLinkedList(sf::RenderWindow &window, sf::Font &font);

    void update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void updateCreate(bool mousePress, sf::Vector2i mousePosition, char &keyPress);
    void updateInsert(bool mousePress, sf::Vector2i mousePosition, char &keyPress);
    void updateRemove(bool mousePress, sf::Vector2i mousePosition, char &keyPress);
    void updateModify(bool mousePress, sf::Vector2i mousePosition, char &keyPress);
    void updateSearch(bool mousePress, sf::Vector2i mousePosition, char &keyPress);

    void randomize();
    void create(std::string fileName);
    void insert(int index, std::string element);
    void remove(int index);
    void modify(int index, std::string element);
    void search(std::string element);

    void setColor();
    void draw();

    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    std::vector<Button> mButton;
    std::vector<Button> mBCreate;
    std::vector<Button> mBInsert;
    std::vector<Button> mBUpdate;

    std::vector<Button> mBStep;
    std::vector<Button> mBOnce;
    
    std::vector<sf::Text> mDefaultText;
    std::vector<SearchBar> mSearchBar;

    std::vector<std::vector<DataPoint>> mDataPoint;
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

#endif // SINGLYLINKEDLIST_HPP
