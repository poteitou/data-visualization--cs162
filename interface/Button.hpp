#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(sf::RenderWindow &window, sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, std::string textString, sf::Font &font, int sizeText);

    void draw();
    bool isMouseOver();
    bool checkPress();
    void setHovered(bool value);

private:
    sf::RenderWindow &mWindow;
    sf::RectangleShape mRect;
    sf::Text mText;
    sf::Color mColor;
    sf::Color mHoverColor;
    bool mHovered;
};

#endif // BUTTON_HPP

/*#include <SFML/Graphics.hpp>
#include "interface/Button.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Button Example");

    sf::Font font;
    font.loadFromFile("resources/fonts/arial.ttf");
    // Create a button
    Button button(window, sf::Vector2f(200.f, 50.f), sf::Vector2f(300.f, 275.f), sf::Color::Green, sf::Color::Red, "Click me!", font, 20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved)
            {
                // Check if the mouse is over the button
                button.setHovered(button.isMouseOver());
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if the left mouse button is pressed while the mouse is over the button
                if (button.checkPress())
                {
                    // std::cout << "Button clicked!" << std::endl;
                }
            }
        }

        window.clear(sf::Color::White);

        // Draw the button
        button.draw();

        window.display();
    }

    return 0;
}
*/