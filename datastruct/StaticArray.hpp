#ifndef STATICARRAY_HPP
#define STATICARRAY_HPP

#include <SFML/Graphics.hpp>
#include "../interface/Arrow.hpp"
#include "../interface/Button.hpp"
#include "../interface/DataPoint.hpp"
#include "../interface/SearchBar.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

class StaticArray
{
public:
    StaticArray(sf::RenderWindow &window, sf::Font &font);
    /* StaticArray(int size);
    StaticArray(int size, int *data);
    StaticArray(const StaticArray &other);
    ~StaticArray(); */

    void handle(sf::Event event, int &mData);
    void draw(float dt);
    /* void randomize(int min = 0, int max = 100);
    void add(int element);
    void insert(int index, int element);
    void remove(int index);
    void update(int index, int element);
    int search(int element) const;

    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int element); */

private:
    sf::RenderWindow &mWindow;
    sf::Font &mFont;
    std::vector<Button> mButton;
    std::vector<Button> mBCreate;
    std::vector<Button> mBInsert;
    std::vector<Button> mBRemove;
    std::vector<Button> mBUpdate;
    std::vector<Button> mBSearch;

    std::vector<sf::Text> mDefaultText;

    std::vector<SearchBar> mSearchBar;
    int *array;
    int size;
    int mType;
    int mSmallType;

    /* void expandArray(); */
};

#endif // STATICARRAY_HPP
