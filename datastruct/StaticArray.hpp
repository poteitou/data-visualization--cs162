#ifndef STATICARRAY_HPP
#define STATICARRAY_HPP

#include <SFML/Graphics.hpp>
#include "../interface/Arrow.hpp"
#include "../interface/Button.hpp"
#include "../interface/DataPoint.hpp"
#include "../interface/SearchBar.hpp"
#include <string.h>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include <iostream>

struct StaticArray
{
    StaticArray(sf::RenderWindow &window, sf::Font &font);

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

    void draw();

    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    std::vector<Button> mButton;
    std::vector<Button> mBCreate;
    std::vector<Button> mBInsert;
    std::vector<Button> mBUpdate;

    std::vector<Button> mBOnce;
    std::vector<Button> mBStep;
    
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
    bool run;
};

#endif // STATICARRAY_HPP
