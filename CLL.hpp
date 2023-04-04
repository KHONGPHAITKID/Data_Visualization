#ifndef _CLL_HPP_
#define _CLL_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

// int randNumNode();

struct CLL_Node
{
    int data;
    CLL_Node* next;
    sf::CircleShape circle;
    sf::Text text;
    void DeleteCLL(CLL_Node* &pHead);

    void SortCLL(CLL_Node* &pHead);

    void addBack(CLL_Node* &pHead, CLL_Node* &temp);

    // void addSort(CLL_Node* &pHead, CLL_Node* &temp);

    void CreateRandomSortCLL(CLL_Node* &head, int &n, sf::Font &font); // chua

    // create a Node
    CLL_Node* createNode(float x, float y, float radius, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(CLL_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(CLL_Node* &v, int &n, sf::Font &font);

    void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second);
};

class CLLArrow : public sf::Drawable
{
public:
    CLLArrow();
    CLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
    ~CLLArrow();

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