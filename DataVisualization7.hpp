#ifndef _DATAVISUALIZATION7_HPP_
#define _DATAVISUALIZATION7_HPP_

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
#include "Queue.hpp"
#include "Textbox.hpp"
#include "Globals.hpp"

/*
chinh ngang
delete
push
peek - 2 buttons - front - back 
*/

void CreateTitle7(sf::Text &Title, float PosX, float PosY);

class DataVisualization_7
{
private:
public:
    sf::Font font;
    sf::Text Title;

    Button backButton;

    sf::RectangleShape Queue1;
    sf::RectangleShape Queue2;

    Button ControlMenu_btn1;
    Button CreateEmpty;
    Button CreateRadom;
    Button CreateRandomSort;
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

    void CreateRandomFixedSizeQueue(sf::RenderWindow &window, sf::Event &event);

    void CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values);
    void CreateUserDefinedListQueue(sf::RenderWindow &window, sf::Event &event);

    int getQueueSize();
    void InsertNodeFront(sf::RenderWindow &window, int data);
    void InsertNodeFrontQueue(sf::RenderWindow &window, sf::Event &event);

    void DeleteNodeFront(sf::RenderWindow &window);

    void PeekFrontQueue(sf::RenderWindow &window);
    void PeekBackQueue(sf::RenderWindow &window);

    bool printMessage(sf::RenderWindow &window, std::string message);
};


#endif