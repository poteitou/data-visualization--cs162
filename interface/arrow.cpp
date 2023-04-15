#include "arrow.hpp"

Arrow::Arrow(float length, float thickness, float triangleSize)
    : m_pos(0.f, 0.f), m_angle(0.f), m_scale(1.f, 1.f), m_color(sf::Color::White),
      m_length(length), m_thickness(thickness), m_triangleSize(triangleSize)
{
    m_rect.setSize(sf::Vector2f(m_length - m_triangleSize, m_thickness));
    m_rect.setOrigin(sf::Vector2f(0.f, m_thickness / 2.f));
    m_rect.setFillColor(m_color);
    m_rect.setPosition(sf::Vector2f(0.f, m_triangleSize / 2.f));

    m_triangle.setPointCount(3);
    m_triangle.setPoint(0, sf::Vector2f(m_length - m_triangleSize, 0.f + m_triangleSize / 2.f));
    m_triangle.setPoint(1, sf::Vector2f(m_length, m_triangleSize / 2.f + m_triangleSize / 2.f));
    m_triangle.setPoint(2, sf::Vector2f(m_length - m_triangleSize, m_triangleSize + m_triangleSize / 2.f));
    m_triangle.setOrigin(sf::Vector2f(0.f, m_triangleSize / 2.f));
    m_triangle.setFillColor(m_color);
}

void Arrow::setPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

void Arrow::setRotation(float angle)
{
    m_angle = angle;
}

void Arrow::setScale(sf::Vector2f scale)
{
    m_scale = scale;
}

void Arrow::setColor(sf::Color color)
{
    m_color = color;
    m_triangle.setFillColor(m_color);
    m_rect.setFillColor(m_color);
}

void Arrow::draw(sf::RenderWindow& window)
{
    sf::Transform transform;
    transform.translate(m_pos);
    transform.rotate(m_angle);
    transform.scale(m_scale);
    window.draw(m_rect, transform);
    window.draw(m_triangle, transform);
}

void Arrow::update(float dt)
{
    // TODO: Implement arrow updates here
    m_pos.x += 100.f * dt; // Move the arrow to the right at a speed of 100 pixels per second
}

void Arrow::makeLonger(float length, float dt)
{
    if (m_length < length)
    {
        m_length += 25.f * dt; // Move the arrow to the right at a speed of 100 pixels per second
        m_rect.setSize(sf::Vector2f(m_length - m_triangleSize, m_thickness));

        m_triangle.setPoint(0, sf::Vector2f(m_length - m_triangleSize, 0.f + m_triangleSize / 2.f));
        m_triangle.setPoint(1, sf::Vector2f(m_length, m_triangleSize / 2.f + m_triangleSize / 2.f));
        m_triangle.setPoint(2, sf::Vector2f(m_length - m_triangleSize, m_triangleSize + m_triangleSize / 2.f));
        m_length = std::min(m_length, length);
    }
}
