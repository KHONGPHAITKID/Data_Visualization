#ifndef _DATAVISUALIZATION6_HPP_
#define _DATAVISUALIZATION6_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
#include <functional>
#include <windows.h>
#include <chrono> 
#include <thread>
#include <unistd.h>
#include "Button.hpp"
#include "Stack.hpp"
#include "Textbox.hpp"
#include "Globals.hpp"
#include "Image.hpp"

void CreateTitle6(sf::Text &Title, float PosX, float PosY);

class DataVisualization_6
{
private:
public:
    sf::Font font;
    sf::Font titlefont;
    sf::Text Title;

    Button backButton;

    //Flow Control
    sf::RectangleShape FlowControlMenu;
    Image PauseButton;
    Image ReplayButton;
    Image NextButton;
    Image SkipButton;
    Image NextButtonReverse;
    Image SkipButtonReverse;
    bool isPause;

    int speed;
    sf::Text speedText;

    Image IncreaseSpeedButton;
    Image DecreaseSpeedButton;

    // code script
    Image CodeScript;
    sf::Vector2f CodeScriptPosition;
    sf::RectangleShape CodeHighLight;
    sf::Vector2f CodeHighLightPosition;

    sf::RectangleShape menuTable;
//----
    Button ControlMenu_btn1;
    Button CreateEmpty;
    Button CreateRadom;
    Button ImportFromFileButton; // CreateRandomSort
    Button CreateRandomFixedSize;
    Textbox CreateRandomFixedSize_Textbox;
    Button CreateUserDefinedListButton;
    Textbox CreateUserDefinedList_Textbox; 

    //building the stack image
    sf::RectangleShape Stackbody1;
    sf::RectangleShape Stackbody2;
    sf::RectangleShape Stackbody3;

    // ADD button
    Button ControlMenu_btn2; //push
    Textbox InsertHead_Textbox;

    Button ControlMenu_btn3; // pop
    Button DeleteHead;

    Button ControlMenu_btn4; // Peek

    int size;

    Stack_Node* NodeArray;
    sf::Text HeadText;
    sf::Text vtxText;
    sf::Text aftText;
    sf::Text preText;
    sf::Text delText;
    sf::Text tailText;
    sf::Text curText;

    int funcstate;

    DataVisualization_6();
    ~DataVisualization_6();

    void handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev);
    void display(sf::RenderWindow &window);
    void drawNodes(sf::RenderWindow &window);

    void ImportFromFile(sf::RenderWindow &window);

    bool checkSize(sf::RenderWindow &window, int size);

    void CreateRandomFixedSizeStack(sf::RenderWindow &window, sf::Event &event);

    void CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values);
    void CreateUserDefinedListStack(sf::RenderWindow &window, sf::Event &event);

    int getStackSize();
    void InsertNodeFront(sf::RenderWindow &window, int data);
    void InsertNodeFrontStack(sf::RenderWindow &window, sf::Event &event);

    void DeleteNodeFront(sf::RenderWindow &window);

    void PeekNode(sf::RenderWindow &window);

    bool printMessage(sf::RenderWindow &window, std::string message);
};


#endif