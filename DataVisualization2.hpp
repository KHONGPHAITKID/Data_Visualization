#ifndef _DATAVISUALIZATION2_HPP_
#define _DATAVISUALIZATION2_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <sstream>
#include <vector>
#include <functional>
#include <windows.h>
#include <chrono> 
#include <thread>
#include <unistd.h>
#include "Button.hpp"
#include "Textbox.hpp"
#include "Globals.hpp"
#include "Image.hpp"

class DataVisualization_2
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
    Textbox CreateUserDefinedList_Textbox;
// #2 ADD button
    Button ControlMenu_btn2;
    Button UpdateButton;
    Textbox UpdateButton_Textbox;
// #3
    Button ControlMenu_btn3;
    Button SearchButton;
    Textbox SearchButton_Textbox;
// #4
    Button ControlMenu_btn4;
    Button SortButtonAscending;
    Button SortButtonDescending;
// #5
    Button ControlMenu_btn5;
    Button PushBackButton;
    Textbox PushBack_Textbox;

    int size;

    int funcstate;

    DataVisualization_2();
    
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &ev);
};

#endif