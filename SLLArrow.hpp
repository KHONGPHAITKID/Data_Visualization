#ifndef _SLLARROW_HPP_
#define _SLLARROW_HPP_

#include <SFML/Graphics.hpp>
#include <cmath>

// arrow that the body is rectangle and head is triangle, it can lengthen and shorten its body and rotate
class SLLArrow : public sf::Drawable
{
public:
    SLLArrow();
    SLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
    ~SLLArrow();

    void setLength(float length);
    void setAngle(float angle);
    void setColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    void setHeadPosition(sf::Vector2f HeadPosition);

    float getLength() const;
    float getAngle() const;
    sf::Color getColor() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getHeadPosition() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:    
    sf::RectangleShape body;
    sf::ConvexShape head;
    sf::Vector2f position;
    sf::Vector2f HeadPosition;
    float length;
    float angle;
    sf::Color color;

    void update();
};


#endif