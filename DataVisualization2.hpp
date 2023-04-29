#ifndef _DATAVISUALIZATION2_HPP_
#define _DATAVISUALIZATION2_HPP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
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

    // void sortAscending();
    // void sortDescending();
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

// HighLight Code
    Image CodeScript;
    sf::Vector2f CodeScriptPosition;
    sf::RectangleShape CodeHighLight;
    sf::Vector2f CodeHighLightPosition;

    sf::RectangleShape menuTable;

// Create Buttons
    // #1
    Button ControlMenu_btn1;
    Button CreateFromFileButton;
    Button CreateRadom;
    Button CreateRandomSort;
    Button CreateRandomFixedSize;
    Textbox CreateRandomFixedSize_Textbox;
    Button CreateUserDefinedListButton;
    Textbox CreateUserDefinedList_Textbox;
    
    // #2
    Button ControlMenu_btn2;
    Button AddFrontButton;
    Textbox AddFront_Textbox;
    Button AddBackButton;
    Textbox AddBack_Textbox;
    Button AddMiddleButton;
    Textbox AddMiddle_Textbox;
    Button AllocateSizeButton;
    Textbox AllocateSize_Textbox;

    // #3
    Button ControlMenu_btn3;
    Button DeleteFrontButton;
    // Textbox DeleteFront_Textbox;
    Button DeleteBackButton;
    // Textbox DeleteBack_Textbox;
    Button DeleteMiddleButton;
    Textbox DeleteMiddle_Textbox;
    Button ClearVectorButton;

    // #4
    Button ControlMenu_btn4;
    Button UpdateButton;
    Textbox UpdateButton_Textbox;
    Button AccessButton;
    Textbox AccessButton_Textbox;
    // #5
    Button ControlMenu_btn5;
    Button SearchButton;
    Textbox SearchButton_Textbox;
    // #6
    Button ControlMenu_btn6;
    Button SortButtonAscending;
    Button SortButtonDescending;

    int size;
    int capacity;
    int funcstate;
    // VectorElement Vector[10];
    std::vector<VectorElement> Vector = std::vector<VectorElement>(10);


    DataVisualization_2();
    
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &ev);
    void drawVector(sf::RenderWindow &window);

    // #1
    void createVectorFromFile();
    void createRandomVector();
    void createRandomSort();
    void createRandomFixedSizeVector(sf::RenderWindow &window, sf::Event &event);
    void createRandomFixedSize(int size);
    void createUserDefinedVector(sf::RenderWindow &window, sf::Event &event);
    void createUserDefined(sf::RenderWindow &window, std::vector<int> &values);

    void AddFrontVector(sf::RenderWindow &window, sf::Event &event);
    void AddFront(sf::RenderWindow &window, int value);
    void AddBackVector(sf::RenderWindow &window, sf::Event &event);
    void AddBack(sf::RenderWindow &window, int value);
    void AddMiddleVector(sf::RenderWindow &window, sf::Event &event);
    void AddMiddle(sf::RenderWindow &window, int index, int value);
    void AllocateSizeVector(sf::RenderWindow &window, sf::Event &event);
    void AllocateSize(sf::RenderWindow &window, int size);

    void DeleteFront(sf::RenderWindow &window);
    void DeleteBack(sf::RenderWindow &window);
    void DeleteMiddleVector(sf::RenderWindow &window, sf::Event &event);
    void DeleteMiddle(sf::RenderWindow &window, int index);

    void UpdateVector(sf::RenderWindow &window, sf::Event &event);
    void Update(sf::RenderWindow &window, int index, int value);
    void AccessVector(sf::RenderWindow &window, sf::Event &event);
    void AccessValue(sf::RenderWindow &window, int index);

    void SearchVector(sf::RenderWindow &window, sf::Event &event);
    void Search(sf::RenderWindow &window, int value);

    void swapNodes(sf::RenderWindow &window, int index1, int index2);
    void SortAscendingVector(sf::RenderWindow& window);
    void SortDescendingVector(sf::RenderWindow& window);

    // void sortAscending();
    // void sortDescending();

    bool checksize(sf::RenderWindow &window, int size);
    bool printMessage(sf::RenderWindow &window, std::string message);
};


#endif