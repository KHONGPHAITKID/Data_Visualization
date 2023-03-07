#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>


struct Node {
    sf::CircleShape circle;
    sf::Text text;
};

struct Button {
    sf::RectangleShape rect;
    sf::Text text;
};

void CreateTitle(sf::Text &Title, float PosX, float PosY);

// Button CreateButton(float recX, float recY, float PosX, float PosY, sf::Color bgcolor, sf::Color OutlineColor, sf::String text, sf::Font font, sf::Color text_color);

Button CreateButton(float recheight, float recwidth, float PosX, float PosY, sf::Color buttonbgcolor, sf::Color buttonOutlineColor, sf::String text, sf::Font &font, sf::Color text_color);

int randNum();

void CreateRandomNode(Node v[], int &n, sf::Font &font);

Node createNode(float x, float y, float radius, sf::Font &font);

void drawArrow(sf::RenderWindow window, sf::Vector2f first, sf::Vector2f second);

void swapNode(Node &a, Node &b);

void sortArray(Node v[], int n);



#endif