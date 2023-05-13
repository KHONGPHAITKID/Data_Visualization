#ifndef _Queue_HPP_
#define _Queue_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

struct Queue_Node
{
    int data;
    Queue_Node* next;
    sf::CircleShape circle;
    sf::Text text;
    void DeleteQueue(Queue_Node* &pHead);

    void SortQueue(Queue_Node* &pHead);

    void addBack(Queue_Node* &pHead, Queue_Node* &temp);

    void CreateRandomSortQueue(Queue_Node* &head, int &n, sf::Font &font);

    // create a Node
    Queue_Node* createNode(float x, float y, float radius, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(Queue_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(Queue_Node* &v, int &n, sf::Font &font);

    void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second);
};

class QueueArrow : public sf::Drawable
{
private:    
public:
    sf::RectangleShape body;
    sf::ConvexShape head;
    sf::Vector2f position;
    sf::Vector2f HeadPosition;
    float length;
    float angle;
    sf::Color color;

    QueueArrow();
    QueueArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif