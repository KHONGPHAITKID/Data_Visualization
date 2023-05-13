#ifndef _Stack_HPP_
#define _Stack_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

struct Stack_Node
{
    int data;
    Stack_Node* next;
    sf::RectangleShape rec;
    sf::Text text;
    void DeleteStack(Stack_Node* &pHead);

    void SortStack(Stack_Node* &pHead);

    void addBack(Stack_Node* &pHead, Stack_Node* &temp);

    void CreateRandomSortStack(Stack_Node* &head, int &n, sf::Font &font);

    // create a Node
    Stack_Node* createNode(float x, float y, float height, float width, sf::Font &font, int value);

    // Create many Node
    void CreateRandomNodes(Stack_Node* &v, int &n, sf::Font &font);

    void CreateFixedNodes(Stack_Node* &v, int &n, sf::Font &font);

};

#endif