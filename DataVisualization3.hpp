#ifndef _DATAVISUALIZATION3_HPP_
#define _DATAVISUALIZATION3_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
#include <functional>
#include <windows.h>
#include <chrono> // for std::chrono
#include <thread> // for std::this_thread::sleep_for
#include <unistd.h>
#include "Button.hpp"
#include "SLL.hpp"
#include "Textbox.hpp"
#include "Globals.hpp"
#include "Image.hpp"

void CreateTitle3(sf::Text &Title, float PosX, float PosY);

class DataVisualization_3
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

    // background
    sf::Texture page2texture;

    Image CodeScript;
    sf::Vector2f CodeScriptPosition;
    sf::RectangleShape CodeHighLight;
    sf::Vector2f CodeHighLightPosition;

    sf::RectangleShape menuTable;
    // Create Buttons
    Button ImportFromFileButton;
    Button ControlMenu_btn1;
    Button CreateEmpty;
    Button CreateRadom;
    Button CreateRandomSort;
    Button CreateRandomFixedSize;
    Textbox CreateRandomFixedSize_Textbox;
    Button CreateUserDefinedListButton;
    Textbox CreateUserDefinedList_Textbox; // Input many times
    // ADD button
    Button ControlMenu_btn2;
    Button InsertHead;
    sf::Texture InsertHeadImg;
    Textbox InsertHead_Textbox;
    Button InsertBack;
    sf::Texture InsertBackImg;
    Textbox InsertBack_Textbox;
    Button InsertMid;
    Textbox InsertMid_Textbox; // 2 input: index, value
    sf::Texture InsertMidImg;
    // #3
    Button ControlMenu_btn3;
    Button DeleteHead;
    Button DeleteBack;
    Button DeleteMid;
    Textbox DeleteMid_Textbox;
    // #4
    Button ControlMenu_btn4;
    Button UpdateNodeButton;
    Textbox UpdateNode_Textbox; // index + value
    // #5
    Button ControlMenu_btn5;
    Button SearchNodeButton; // value
    Textbox SearchNode_Textbox;

    int size;

    SLL_Node* NodeArray;
    sf::Text HeadText;
    sf::Text vtxText;
    sf::Text aftText;
    sf::Text preText;
    sf::Text delText;
    sf::Text tailText;
    sf::Text curText;
    // sf::Text 

    int funcstate;

    DataVisualization_3();
    ~DataVisualization_3();

    void NodeTextsetPos(sf::Text &text, SLL_Node* &pHead);

    void handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev);
    void display(sf::RenderWindow &window);
    void drawNodes(sf::RenderWindow &window);

    bool checkSize(sf::RenderWindow &window, int size);

    void ImportFromFile(sf::RenderWindow &window);

    void CreateRandomFixedSizeSLL(sf::RenderWindow &window, sf::Event &event);

    void CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values);
    void CreateUserDefinedListSLL(sf::RenderWindow &window, sf::Event &event);

    int getSLLSize();
    void InsertNodeFront(sf::RenderWindow &window, int data);
    void InsertNodeFrontSLL(sf::RenderWindow &window, sf::Event &event);
    void InsertNodeBack(sf::RenderWindow &window, int data);
    void InsertNodeBackSLL(sf::RenderWindow &window, sf::Event &event);
    void InsertNodeMid(sf::RenderWindow &window, int data, int index);
    void InsertNodeMidSLL(sf::RenderWindow &window, sf::Event &event);
    
    void DeleteNodeFront(sf::RenderWindow &window);
    void DeleteNodeBack(sf::RenderWindow &window);
    void DeleteNodeMid(sf::RenderWindow &window, int index);
    void DeleteNodeMidSLL(sf::RenderWindow &window, sf::Event &event);

    void UpdateNode(sf::RenderWindow &window, int index, int value);
    void UpdateNodeSLL(sf::RenderWindow &window, sf::Event &event);

    void SearchNode(sf::RenderWindow &window, int value);
    void SearchNodeSLL(sf::RenderWindow &window, sf::Event &event);

    bool printMessage(sf::RenderWindow &window, std::string message);
};


#endif