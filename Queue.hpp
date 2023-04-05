#ifndef _Queue_HPP_
#define _Queue_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

// int randNumNode();

struct Queue_Node
{
    int data;
    Queue_Node* next;
    sf::CircleShape circle;
    sf::Text text;
    void DeleteQueue(Queue_Node* &pHead);

    void SortQueue(Queue_Node* &pHead);

    void addBack(Queue_Node* &pHead, Queue_Node* &temp);

    // void addSort(Queue_Node* &pHead, Queue_Node* &temp);

    void CreateRandomSortQueue(Queue_Node* &head, int &n, sf::Font &font); // chua

    // create a Node
    Queue_Node* createNode(float x, float y, float radius, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(Queue_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(Queue_Node* &v, int &n, sf::Font &font);

    void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second);
};

class QueueArrow : public sf::Drawable
{
public:
    QueueArrow();
    QueueArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
    ~QueueArrow();

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