#include "SLLArrow.hpp"
#include <iostream>

//define those function in SLLArrow.hpp
SLLArrow::SLLArrow()
{
    this->length = 0;
    this->angle = 0;
    this->color = sf::Color::White;
    this->position = sf::Vector2f(0, 0);
    this->update();
}

SLLArrow::SLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color)
{
    this->color = color;
    // not in the same line
    if (position1.y != position2.y) 
    {
        //find the 2 true points
        sf::Vector2f truePos1, truePos2;
        this->angle = atan2(position2.y - position1.y, position2.x - position1.x);
        truePos1.x = position1.x + 30*cos(this->angle);
        truePos1.y = position1.y + 30*sin(this->angle);
        truePos2.x = position2.x - 30*cos(this->angle);
        truePos2.y = position2.y - 30*sin(this->angle);

        this->length = sqrt(pow(truePos2.x - truePos1.x, 2) + pow(truePos2.y - truePos1.y, 2)) - 20;
        this->position.x = truePos1.x;
        this->position.y = truePos1.y;
        this->HeadPosition.x = truePos1.x + length*cos(this->angle);
        this->HeadPosition.y = truePos1.y + length*sin(this->angle);
    } else { 
        position1.x += 30;
        position2.x -= 30;
        this->angle = 0;
        this->length = position2.x - position1.x - 20;
        this->HeadPosition.x = position1.x + length;
        this->HeadPosition.y = position1.y;
        this->position.x = position1.x;
        this->position.y = position1.y;
    }
    this->update();
}

SLLArrow::~SLLArrow()
{
}

void SLLArrow::setLength(float length)
{
    this->length = length;
    this->update();
}

void SLLArrow::setAngle(float angle)
{
    this->angle = angle;
    this->update();
}

void SLLArrow::setColor(sf::Color color)
{
    this->color = color;
    this->update();
}

void SLLArrow::setPosition(sf::Vector2f position)
{
    this->position = position;
    this->update();
}

void SLLArrow::setHeadPosition(sf::Vector2f HeadPosition)
{
    this->HeadPosition = HeadPosition;
    this->update();
}

float SLLArrow::getLength() const
{
    return this->length;
}

float SLLArrow::getAngle() const
{
    return this->angle;
}

sf::Color SLLArrow::getColor() const
{
    return this->color;
}

sf::Vector2f SLLArrow::getPosition() const
{
    return this->position;
}

sf::Vector2f SLLArrow::getHeadPosition() const
{
    return this->HeadPosition;
}

void SLLArrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->body);
    target.draw(this->head);
}

void SLLArrow::update()
{
    this->body.setSize(sf::Vector2f(this->length, 5));
    this->body.setOrigin(sf::Vector2f(0, 2.5));
    this->body.setPosition(this->position);
    this->body.setRotation(this->angle * 180 / 3.1415 );
    this->body.setFillColor(this->color);

    this->head.setPointCount(3);
    this->head.setPoint(0, sf::Vector2f(0, 0));
    this->head.setPoint(1, sf::Vector2f(20, 10));
    this->head.setPoint(2, sf::Vector2f(0, 20));
    this->head.setOrigin(sf::Vector2f(0, 10));
    this->head.setPosition(this->HeadPosition);
    this->head.setRotation(this->angle * 180 / 3.1415);
    this->head.setFillColor(this->color);
}