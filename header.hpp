#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>
#include <vector>
#include <functional>
#include <windows.h>
//---
#include <chrono> // for std::chrono
#include <thread> // for std::this_thread::sleep_for
//---
#include <unistd.h>
#include "Button.hpp"
#include "SLL.hpp"
#include "Textbox.hpp"
#include "Globals.hpp"


int randNum();
void CreateTitle(sf::Text &Title, float PosX, float PosY);

struct Node {
    sf::CircleShape circle;
    sf::Text text;
};

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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};

class StartingPage
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

    StartingPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
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
    Textbox CreateRandomFixedSize_Textbox;

    // ADD button
    Button ControlMenu_btn2;
    Button InsertHead;
    Button InsertBack;
    Button InsertMid;

    Button ControlMenu_btn3;
    Button DeleteHead;
    Button DeleteBack;
    Button DeleteMid;

    Button ControlMenu_btn4;
    Button UpdateNode;

    Button ControlMenu_btn5;
    Button SearchNode;

    int size;

    SLL_Node* NodeArray;

    int funcstate;

    DataVisualization_3();
    ~DataVisualization_3();

    void handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev);
    void display(sf::RenderWindow &window);
    void drawNodes(sf::RenderWindow &window);

    bool checkSize(sf::RenderWindow &window);

    void CreateRandomFixedSizeSLL(sf::RenderWindow &window, sf::Event &event);
    int getSLLSize();
    void InsertNodeFront(sf::RenderWindow &window);
    void InsertNodeBack(sf::RenderWindow &window);
    void InsertNodeMid(sf::RenderWindow &window);
    void DeleteNodeFront(sf::RenderWindow &window);
    void DeleteNodeBack(sf::RenderWindow &window);
    void DeleteNodeMid(sf::RenderWindow &window);
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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
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
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};

#endif