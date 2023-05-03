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
    void updateCreate(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void updateInsert(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void updateRemove(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void updateModify(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void draw(float dt);

    void saveData(std::string fileName);
    void randomize();
    void create(std::string fileName);
    void insert(int index, std::string element);
    void remove(int index);
    void modify(int index, std::string element);
    /*
    int search(int element) const;

    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int element); */

    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    std::vector<Button> mButton;
    std::vector<Button> mBCreate;
    std::vector<Button> mBInsert;
    std::vector<Button> mBUpdate;
    std::vector<Button> mBSearch;

    std::vector<sf::Text> mDefaultText;

    std::vector<SearchBar> mSearchBar;

    std::vector<std::vector<DataPoint>> mDataPoint;
    std::string *array;
    int step;
    int size;
    int mType;
    int mSmallType;
    bool nosuchfile;
    bool firstTime;
};

#endif // STATICARRAY_HPP
