#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include "Pages/DataVisualization1.hpp"
#include "Pages/DataVisualization2.hpp"
#include "Pages/DataVisualization3.hpp"
#include "Pages/DataVisualization4.hpp"
#include "Pages/DataVisualization5.hpp"
#include "Pages/DataVisualization6.hpp"
#include "Pages/DataVisualization7.hpp"
#include "Components/DropDownBox.hpp"

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
    // sf::Texture page2texture;
    MenuPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
    void updateChanges();
};

class SettingPage
{
private:
public:
    sf::Font font;
    sf::Font titlefont;
    sf::Font tempFont;

    sf::Text Title;
    Button backButton;
    // sf::Texture page1texture;
    Button ApplyButton;

    sf::Text pageText;
    DropdownBox Pagedropdown{ sf::Vector2f(400, 380), sf::Vector2f(200, 50), "Select an option", { "Static Array", "Dynamic Array", "Singly Linked List", "Doubly Linked List", "Circular Linked List", "Stack", "Queue" } };

    sf::Text FontText;
    Button FontTextButton;
    DropdownBox Fontdropdown{ sf::Vector2f(400, 580), sf::Vector2f(200, 50), "Select an option", { "Button", "Title", "Node" } };

    sf::Text ColorText;
    DropdownBox Colordropdown{ sf::Vector2f(400, 780), sf::Vector2f(200, 50), "Select an option", { "Main Color", "Button Color", "Outline Color" } };


    SettingPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event, DataVisualization_1 &dv1, DataVisualization_2 &dv2, DataVisualization_3 &dv3, DataVisualization_4 &dv4, DataVisualization_5 &dv5, DataVisualization_6 &dv6, DataVisualization_7 &dv7);
    void updateChanges();
    void updateChangeGlobals(DataVisualization_1 &dv1, DataVisualization_2 &dv2, DataVisualization_3 &dv3, DataVisualization_4 &dv4, DataVisualization_5 &dv5, DataVisualization_6 &dv6, DataVisualization_7 &dv7);
    
    void loadFont();

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

    sf::Text paragraph;

    AboutPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};
#endif
