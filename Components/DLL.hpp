#ifndef _DLL_HPP_
#define _DLL_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

struct DLL_Node
{
    int data;
    DLL_Node* next;
    sf::CircleShape circle;
    sf::Text text;
    void DeleteDLL(DLL_Node* &pHead);

    void SortDLL(DLL_Node* &pHead);

    void addBack(DLL_Node* &pHead, DLL_Node* &temp);

    void CreateRandomSortDLL(DLL_Node* &head, int &n, sf::Font &font);

    // create a Node
    DLL_Node* createNode(float x, float y, float radius, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(DLL_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(DLL_Node* &v, int &n, sf::Font &font);

    void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second);
};

class DLLArrow : public sf::Drawable
{
private:
public:
    sf::RectangleShape body;
    sf::ConvexShape head;
    sf::ConvexShape tail;
    sf::Vector2f position;
    sf::Vector2f HeadPosition;
    sf::Vector2f TailPosition;
    float length;
    float angle;
    sf::Color color;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

    DLLArrow();
    DLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color);
};

#endif