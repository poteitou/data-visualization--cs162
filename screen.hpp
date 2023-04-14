#include <SFML/Graphics.hpp>

class Screen
{
public:
    Screen(sf::RenderWindow& window);
    
    void draw();
    void setHovered();

private:
    sf::RenderWindow& mWindow;
    std::vector<Button> button;
};