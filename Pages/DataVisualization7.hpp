#ifndef _DATAVISUALIZATION7_HPP_
#define _DATAVISUALIZATION7_HPP_

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
#include <cstdlib>
#include "../Components/Button.hpp"
#include "../Components/Queue.hpp"
#include "../Components/Textbox.hpp"
#include "../Components/Image.hpp"
#include "../Globals.hpp"

class DataVisualization_7
{
private:
public:
    sf::Font font;
    sf::Font titlefont;
    sf::Text Title;

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

    Button backButton;

    // building queue image
    sf::RectangleShape Queue1;
    sf::RectangleShape Queue2;

    Button ControlMenu_btn1;
    Button CreateEmpty;
    Button CreateRadom;
    Button ImportFromFileButton; // CreateRandomSort
    Button CreateRandomFixedSize;
    Textbox CreateRandomFixedSize_Textbox;
    Button CreateUserDefinedListButton;
    Textbox CreateUserDefinedList_Textbox; 

    // ADD button
    Button ControlMenu_btn2; //push
    Textbox InsertHead_Textbox;

    Button ControlMenu_btn3; // pop
    Button DeleteHead;

    Button ControlMenu_btn4; // Peek
    Button PeekFront;
    Button PeekBack;

    int size;

    Queue_Node* NodeArray;

    int funcstate;

    DataVisualization_7();
    ~DataVisualization_7();

    void handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev);
    void display(sf::RenderWindow &window);
    void drawNodes(sf::RenderWindow &window);

    bool checkSize(sf::RenderWindow &window, int size);

    void ImportFromFile(sf::RenderWindow &window);

    void CreateRandomFixedSizeQueue(sf::RenderWindow &window, sf::Event &event);

    void CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values);
    void CreateUserDefinedListQueue(sf::RenderWindow &window, sf::Event &event);

    int getQueueSize();
    void InsertNodeBack(sf::RenderWindow &window, int data);
    void InsertNodeBackQueue(sf::RenderWindow &window, sf::Event &event);

    void DeleteNodeFront(sf::RenderWindow &window);

    void PeekFrontQueue(sf::RenderWindow &window);
    void PeekBackQueue(sf::RenderWindow &window);

    bool printMessage(sf::RenderWindow &window, std::string message);
};


#endif