#ifndef SEARCHBAR_HPP
#define SEARCHBAR_HPP

#include <SFML/Graphics.hpp>
#include <string.h>

struct SearchBar
{
    SearchBar();
    SearchBar(sf::Vector2f size, sf::Vector2f position, sf::Font &font, std::string defaultText);

    void update(bool mousePress, sf::Vector2i mousePosition, char keyPress, int capacity);
    void draw(sf::RenderWindow &mWindow);

    std::string getValue(); //const;
    void reset(std::string defaultText);

    sf::RectangleShape mRect;
    sf::Text mText;
    std::string mValue;
    sf::Color mDefaultColor;
    sf::Color mHoveredColor;
    sf::Color mSelectedColor;
    bool mHovered;
    bool mSelected;

    bool contains(sf::Vector2f point) const;
};

#endif

/*
#include "interface/SearchBar.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Search Bar Example");

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        return EXIT_FAILURE;
    }

    // Create a search bar
    SearchBar searchBar;
    searchBar = SearchBar(sf::Vector2f(50, 50), sf::Vector2f(300, 40), font, " ");

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            searchBar.handleEvent(event, 20, window);
        }

        window.clear(sf::Color::White);
        searchBar.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
*/
