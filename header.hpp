#ifndef _HEADER_HPP_
#define _HEADER_HPP_

// #include <iostream>
// #include <string>
// #include <SFML/Graphics.hpp>
// #include <ctime>
// #include <cmath>
// #include <sstream>
// #include <vector>
// #include <functional>
// #include <windows.h>
// //---
// #include <chrono> // for std::chrono
// #include <thread> // for std::this_thread::sleep_for
// //---
// #include <unistd.h>
// #include "Button.hpp"
// #include "Textbox.hpp"
// #include "Globals.hpp"
// #include "RoundedRectangle.hpp"
#include "DataVisualization1.hpp"
#include "DataVisualization2.hpp"
#include "DataVisualization3.hpp"
#include "DataVisualization4.hpp"
#include "DataVisualization5.hpp"
#include "DataVisualization6.hpp"
#include "DataVisualization7.hpp"

#include <regex>

//--------------------------------------------------------------------------------------------
// TESTING

//--------------------------------------------------------------------------------------------

class MenuPage
{
private:
public:
    sf::Text Title;
    sf::Font font;
    sf::Font titlefont;
    Button startButton;
    Button settingsButton;
    Button aboutButton;
    sf::Texture page2texture;
    MenuPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};

class SettingPage
{
private:
public:
    sf::Font font;
    sf::Font titlefont;
    sf::Text Title;
    Button backButton;
    sf::Texture page1texture;

    // Style
    sf::Text StyleTitle;
    Button StyleBox;

    // font
    sf::Text FontTitle;
    Button FontBox; // Comboboxes

    // titlefont
    sf::Text TitleFontTitle;
    Button TitleFontBox;

    // music theme
    sf::Text MusicThemeTitle;
    Button MusicThemeBox;


    SettingPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};

class StartingPage
{
private:
public:
    sf::Font font;
    sf::Font titlefont;
    sf::Text Title;
    Button backButton;
    Button rect1;
    Button rect2;
    Button rect3;
    Button rect4;
    Button rect5;
    Button rect6;
    Button rect7;

    sf::Texture page1texture;
    sf::Texture page3texture;

    StartingPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};

class AboutPage
{
private:
public:
    sf::Font font;
    sf::Font titlefont;
    sf::Text Title;
    Button backButton;
    sf::Texture page1texture;

    AboutPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};
#endif