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
#include "Textbox.hpp"
#include "Globals.hpp"
#include "DataVisualization3.hpp"
#include "DataVisualization4.hpp"

int randNum();
void CreateTitle(sf::Text &Title, float PosX, float PosY);

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

// class DataVisualization_4
// {
// private:
// public:
//     sf::Font font;
//     sf::Text Title;
//     Button backButton;
//     DataVisualization_4();
//     void display(sf::RenderWindow &window);
//     void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
// };

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