#ifndef SEARCHBAR_HPP
#define SEARCHBAR_HPP

#include <SFML/Graphics.hpp>

class SearchBar
{
public:
    SearchBar(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, sf::Font &font, std::string defaultText);

    void handleEvent(sf::Event event);
    void draw();

    std::string getValue() const;

private:
    sf::RenderWindow &mWindow;
    sf::RectangleShape mRectangle;
    sf::Text mText;
    std::string mValue;
    sf::Color mDefaultColor;
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
    SearchBar searchBar = SearchBar(window, sf::Vector2f(50, 50), sf::Vector2f(300, 40), font, " ");

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            searchBar.handleEvent(event);
        }

        window.clear(sf::Color::White);
        searchBar.draw();
        window.display();
    }

    return EXIT_SUCCESS;
}
*/
