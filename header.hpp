#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>
#include <vector>
#include "Button.hpp"
#include "SLL.hpp"
// #include "Textbox.hpp"


int randNum();
void CreateTitle(sf::Text &Title, float PosX, float PosY);

struct Node {
    sf::CircleShape circle;
    sf::Text text;
};

// void CreateRandomNodes(Node v[], int &n, sf::Font &font);
// void swapNode(sf::Text &a, sf::Text &b);
// void CreateRandomSortNodes(Node v[], int &n, sf::Font &font);
// Node createNode(float x, float y, float radius, sf::Font &font);
// void sortArray(Node v[], int n);
// void drawArrow(sf::RenderWindow window, sf::Vector2f first, sf::Vector2f second);

class MenuPage
{
private:
public:
    sf::Text Title;
    sf::Font font;
    Button startButton;
    Button settingsButton;
    MenuPage();
    void display(sf::RenderWindow &window);
};

class SettingPage
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    SettingPage();
    void display(sf::RenderWindow &window);
};

class StartPage
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    Button rect1;
    Button rect2;
    Button rect3;
    Button rect4;
    Button rect5;
    Button rect6;
    Button rect7;

    StartPage();
    void display(sf::RenderWindow &window);
};

class DataVisualization_1
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    DataVisualization_1();
    void display(sf::RenderWindow &window);
};

class DataVisualization_2
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    DataVisualization_2();
    void display(sf::RenderWindow &window);
};

class DataVisualization_3
{
private:
public:
    sf::Font font;
    sf::Text Title;

    Button backButton;

    Button ControlMenu_btn1;
    Button CreateEmpty;
    Button CreateRadom;
    Button CreateRandomSort;
    Button CreateRandomFixedSize;
    Button CreateUserDefinedList;
    // Textbox FixedSizeTextBox;

    // ADD button
    Button ControlMenu_btn2;
    Button InsertHead;
    Button InsertBack;
    Button InsertMid;

    Button ControlMenu_btn3;
    
    Button ControlMenu_btn4;
    
    Button ControlMenu_btn5;
    Button Search;

    // Node NodeArray[10];
    int size;

    SLL_Node* NodeArray;

    int funcstate;

    DataVisualization_3();
    ~DataVisualization_3();
    void handleEvent(sf::Vector2f &mousePos, sf::Event &ev);
    void display(sf::RenderWindow &window);
    void drawNodes(sf::RenderWindow &window);
};

class DataVisualization_4
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    DataVisualization_4();
    void display(sf::RenderWindow &window);
};

class DataVisualization_5
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    DataVisualization_5();
    void display(sf::RenderWindow &window);
};

class DataVisualization_6
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    DataVisualization_6();
    void display(sf::RenderWindow &window);
};

class DataVisualization_7
{
private:
public:
    sf::Font font;
    sf::Text Title;
    Button backButton;
    DataVisualization_7();
    void display(sf::RenderWindow &window);
};

//------------ testing


#endif