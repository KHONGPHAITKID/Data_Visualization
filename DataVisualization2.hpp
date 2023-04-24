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

class VectorElement // one memory slot
{
public:
    int value;
    sf::RectangleShape rect;
    sf::Text data;

    void setValue();
};

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
    VectorElement Array[10];


    DataVisualization_2();
    
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &ev);
    void drawArray(sf::RenderWindow &window);

    // #1
    void createRandomArray();
    void createRandomSort();
    void createRandomFixedSizeArray(sf::RenderWindow &window, sf::Event &event);
    void createRandomFixedSize(int size);

    void createUserDefinedArray(sf::RenderWindow &window, sf::Event &event);
    void createUserDefined(sf::RenderWindow &window, std::vector<int> &values);

    void UpdateArray(sf::RenderWindow &window, sf::Event &event);
    void Update(sf::RenderWindow &window, int index, int value);

    void swapNodes(sf::RenderWindow &window, int index1, int index2);

    void SearchArray(sf::RenderWindow &window, sf::Event &event);
    void Search(sf::RenderWindow &window, int value);

    // void SortAscendingArray();
    void SortAscendingArray(sf::RenderWindow& window);
    void SortDescendingArray(sf::RenderWindow& window);

    void PushBackVectorInput(sf::RenderWindow &window, sf::Event &event);
    void PushBackVector(sf::RenderWindow &window, int value);

    // void SortDescendingArray();
    void sortAscending();
    void sortDescending();

    bool checksize(sf::RenderWindow &window, int size);
    // void createUserDefinedArray(sf::RenderWindow &window, sf::Event &event);

    bool printMessage(sf::RenderWindow &window, std::string message);

};

#endif