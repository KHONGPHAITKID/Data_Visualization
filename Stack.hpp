#ifndef _Stack_HPP_
#define _Stack_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

// int randNumNode();

struct Stack_Node
{
    int data;
    Stack_Node* next;
    sf::CircleShape circle;
    sf::Text text;
    void DeleteStack(Stack_Node* &pHead);

    void SortStack(Stack_Node* &pHead);

    void addBack(Stack_Node* &pHead, Stack_Node* &temp);

    // void addSort(Stack_Node* &pHead, Stack_Node* &temp);

    void CreateRandomSortStack(Stack_Node* &head, int &n, sf::Font &font); // chua

    // create a Node
    Stack_Node* createNode(float x, float y, float radius, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(Stack_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(Stack_Node* &v, int &n, sf::Font &font);

    void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second);
};

class StackArrow : public sf::Drawable
{
public:
    StackArrow();
    StackArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
    ~StackArrow();

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