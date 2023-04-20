#ifndef _DATAVISUALIZATION1_HPP_
#define _DATAVISUALIZATION1_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <sstream>
#include <vector>
#include <functional>
#include <windows.h>
#include <chrono> // for std::chrono
#include <thread> // for std::this_thread::sleep_for
#include <unistd.h>
#include "Button.hpp"
#include "Textbox.hpp"
#include "Globals.hpp"
#include "Image.hpp"

class DataVisualization_1
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

// HighLight Code
    Image CodeScript;
    sf::Vector2f CodeScriptPosition;
    sf::RectangleShape CodeHighLight;
    sf::Vector2f CodeHighLightPosition;

    sf::RectangleShape menuTable;

// Create Buttons
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
    Button UpdateButton;
    Textbox UpdateButton_Textbox;
    // Button InsertHead;
    // sf::Texture InsertHeadImg;
    // Button InsertBack;
    // sf::Texture InsertBackImg;
    // Textbox InsertBack_Textbox;
    // Button InsertMid;
    // Textbox InsertMid_Textbox; // 2 input: index, value
    // sf::Texture InsertMidImg;
    // #3
    Button ControlMenu_btn3;
    Button SearchButton;
    Textbox SearchButton_Textbox;
    // Button DeleteHead;
    // Button DeleteBack;
    // Button DeleteMid;
    // #4
    Button ControlMenu_btn4;
    Button SortButtonAscending;
    Button SortButtonDescending;
    // Button UpdateNodeButton;
    // Textbox UpdateNode_Textbox; // index + value
    // #5
    // Button ControlMenu_btn5;
    // Button SearchNodeButton; // value
    // Textbox SearchNode_Textbox;

    int size;

    int funcstate;

    DataVisualization_1();
    
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &ev);
};

#endif