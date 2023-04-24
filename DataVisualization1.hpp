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

class ArrayElement // one memory slot
{
public:
    int value;
    sf::RectangleShape rect;
    sf::Text data;

    // void sortAscending();
    // void sortDescending();
    void setValue();
};

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
    // #3
    Button ControlMenu_btn3;
    Button SearchButton;
    Textbox SearchButton_Textbox;
    // #4
    Button ControlMenu_btn4;
    Button SortButtonAscending;
    Button SortButtonDescending;

    int size;
    ArrayElement Array[10];
    int funcstate;

    DataVisualization_1();
    
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

    // void SortDescendingArray();
    void sortAscending();
    void sortDescending();

    bool checksize(sf::RenderWindow &window, int size);
    // void createUserDefinedArray(sf::RenderWindow &window, sf::Event &event);

    bool printMessage(sf::RenderWindow &window, std::string message);

};


#endif