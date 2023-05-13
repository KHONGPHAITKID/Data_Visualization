#ifndef _SLL_HPP_
#define _SLL_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

struct SLL_Node
{
    int data;
    SLL_Node* next;
    sf::CircleShape circle;
    sf::Text text;

    void DeleteSLL(SLL_Node* &pHead);

    void SortSLL(SLL_Node* &pHead);

    void addBack(SLL_Node* &pHead, SLL_Node* &temp);

    void CreateRandomSortSLL(SLL_Node* &head, int &n, sf::Font &font);

    // Create a Node
    SLL_Node* createNode(float x, float y, float radius, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(SLL_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(SLL_Node* &v, int &n, sf::Font &font);

    void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second);
};

class SLLArrow : public sf::Drawable
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

    SLLArrow();
    SLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
};

#endif