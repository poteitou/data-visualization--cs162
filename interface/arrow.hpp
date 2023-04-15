#ifndef ARROW_HPP
#define ARROW_HPP

#include <SFML/Graphics.hpp>
#include <algorithm>

class Arrow {
public:
    Arrow(float length = 100.f, float thickness = 10.f, float triangleSize = 20.f);
    void setPosition(sf::Vector2f pos);
    void setRotation(float angle);
    void setScale(sf::Vector2f scale);
    void setColor(sf::Color color);
    void draw(sf::RenderWindow& window);
    void update(float dt);
    void makeLonger(float length, float dt);

private:
    sf::RectangleShape m_rect;
    sf::ConvexShape m_triangle;
    sf::Vector2f m_pos;
    float m_angle;
    sf::Vector2f m_scale;
    sf::Color m_color;
    float m_length;
    float m_thickness;
    float m_triangleSize;
};

#endif // ARROW_HPP
