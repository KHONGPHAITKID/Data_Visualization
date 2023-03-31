#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
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
#include "SLLArrow.hpp"
#include "DataVisualization3.hpp"


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

// class DataVisualization_3
// {
// private:
// public:
//     sf::Font font;
//     sf::Text Title;

//     Button backButton;

//     Button ControlMenu_btn1;
//     Button CreateEmpty;
//     Button CreateRadom;
//     Button CreateRandomSort;
//     Button CreateRandomFixedSize;
//     Textbox CreateRandomFixedSize_Textbox;
//     Button CreateUserDefinedListButton;
//     Textbox CreateUserDefinedList_Textbox; // Input many times

//     // ADD button
//     Button ControlMenu_btn2;
//     Button InsertHead;
//     Textbox InsertHead_Textbox;
//     Button InsertBack;
//     Textbox InsertBack_Textbox;
//     Button InsertMid;
//     Textbox InsertMid_Textbox; // 2 input: index, value

//     Button ControlMenu_btn3;
//     Button DeleteHead;
//     Button DeleteBack;
//     Button DeleteMid;
//     Textbox DeleteMid_Textbox;

//     Button ControlMenu_btn4;
//     Button UpdateNodeButton;
//     Textbox UpdateNode_Textbox; // index + value

//     Button ControlMenu_btn5;
//     Button SearchNodeButton; // value
//     Textbox SearchNode_Textbox;

//     int size;

//     SLL_Node* NodeArray;

//     int funcstate;

//     DataVisualization_3();
//     ~DataVisualization_3();

//     void handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev);
//     void display(sf::RenderWindow &window);
//     void drawNodes(sf::RenderWindow &window);

//     bool checkSize(sf::RenderWindow &window, int size);

//     void CreateRandomFixedSizeSLL(sf::RenderWindow &window, sf::Event &event);

//     void CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values);
//     void CreateUserDefinedListSLL(sf::RenderWindow &window, sf::Event &event);

//     int getSLLSize();
//     void InsertNodeFront(sf::RenderWindow &window, int data);
//     void InsertNodeFrontSLL(sf::RenderWindow &window, sf::Event &event);
//     void InsertNodeBack(sf::RenderWindow &window, int data);
//     void InsertNodeBackSLL(sf::RenderWindow &window, sf::Event &event);
//     void InsertNodeMid(sf::RenderWindow &window, int data, int index);
//     void InsertNodeMidSLL(sf::RenderWindow &window, sf::Event &event);
    

//     void DeleteNodeFront(sf::RenderWindow &window);
//     void DeleteNodeBack(sf::RenderWindow &window);
//     void DeleteNodeMid(sf::RenderWindow &window, int index);
//     void DeleteNodeMidSLL(sf::RenderWindow &window, sf::Event &event);

//     void UpdateNode(sf::RenderWindow &window, int index, int value);
//     void UpdateNodeSLL(sf::RenderWindow &window, sf::Event &event);

//     void SearchNode(sf::RenderWindow &window, int value);
//     void SearchNodeSLL(sf::RenderWindow &window, sf::Event &event);

//     bool printMessage(sf::RenderWindow &window, std::string message);
// };

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