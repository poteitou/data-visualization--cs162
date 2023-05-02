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
    /* StaticArray(int size);
    StaticArray(int size, int *data);
    StaticArray(const StaticArray &other);
    ~StaticArray(); */

    void update(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void create(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt);
    void insert(bool mousePress, sf::Vector2i mousePosition, char &keyPress, int &mData, float dt)
    void draw(float dt);

    void saveData(std::string fileName);
    // void enter();
    void randomize();
    bool createData(std::string fileName);
    /*
    void add(int element);
    void insert(int index, int element);
    void remove(int index);
    void update(int index, int element);
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

    /* void expandArray(); */
};

#endif // STATICARRAY_HPP
