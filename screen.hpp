#include <SFML/Graphics.hpp>
#include "button.hpp"

class Screen
{
public:
    Screen(sf::RenderWindow& window, sf::Font& font);
    
    void draw();
    void setHovered();

private:
    sf::RenderWindow& mWindow;

    std::vector<Button> mButton;
};