#ifndef _CLL_HPP_
#define _CLL_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

struct CLL_Node
{
    int data;
    CLL_Node* next;
    sf::CircleShape circle;
    sf::Text text;
    void DeleteCLL(CLL_Node* &pHead);

    void SortCLL(CLL_Node* &pHead);

    void addBack(CLL_Node* &pHead, CLL_Node* &temp);

    void CreateRandomSortCLL(CLL_Node* &head, int &n, sf::Font &font);

    // create a Node
    CLL_Node* createNode(float x, float y, float radius, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(CLL_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(CLL_Node* &v, int &n, sf::Font &font);

    void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second);
};

class CLLArrow : public sf::Drawable
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

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

    CLLArrow();
    CLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
};

#endif