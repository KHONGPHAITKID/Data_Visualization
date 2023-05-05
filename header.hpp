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
#include <string>
#include <filesystem>
//--------------------------------------------------------------------------------------------
// TESTING
//--------------------------------------------------------------------------------------------

struct MenuPage
{
    sf::Text Title;
    sf::Font font;
    sf::Font titlefont;
    Button startButton;
    Button settingsButton;
    Button aboutButton;
    MenuPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
    void updateChanges(sf::Font tempFont);
};


struct StartingPage
{
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
    
    void updateChanges(sf::Font tempFont);
};

struct AboutPage
{
    sf::Font font;
    sf::Font titlefont;
    sf::Text Title;
    Button backButton;

    sf::Text paragraph;

    AboutPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
};
struct SettingPage
{
    sf::Font font;
    sf::Font titlefont;
    sf::Font tempFont;

    sf::Text Title;
    Button backButton;
    Button ApplyButton;

    sf::Text pageText;
    DropdownBox Pagedropdown{ sf::Vector2f(400, 380), sf::Vector2f(200, 50), "Select an option", { "All", "Start Page", "Menu Page", "Setting Page", "Static Array", "Dynamic Array", "Singly Linked List", "Doubly Linked List", "Circular Linked List", "Stack", "Queue" } };

    sf::Text FontText;
    Button FontTextButton;
    sf::Text TempFontText;
    bool haveImportedFont;
    // DropdownBox Fontdropdown{ sf::Vector2f(400, 580), sf::Vector2f(200, 50), "Select an option", { "Button", "Title", "Node" } };

    sf::Text ColorText;
    DropdownBox Colordropdown{ sf::Vector2f(1000, 380), sf::Vector2f(200, 50), "Select an option", { "Default", "Red", "Blue", "Green", "Yellow", "Black", "White", "Brown", "Purple"} };


    SettingPage();
    bool printMessage(sf::RenderWindow &window, std::string message);
    void display(sf::RenderWindow &window);
    // void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event, DataVisualization_1 &dv1, DataVisualization_2 &dv2, DataVisualization_3 &dv3, DataVisualization_4 &dv4, DataVisualization_5 &dv5, DataVisualization_6 &dv6, DataVisualization_7 &dv7);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event, DataVisualization_1 &dv1, DataVisualization_2 &dv2, DataVisualization_3 &dv3, DataVisualization_4 &dv4, DataVisualization_5 &dv5, DataVisualization_6 &dv6, DataVisualization_7 &dv7, MenuPage &menu, SettingPage &setting, StartingPage &StartMenu);
    void updateChanges(sf::Font tempFont);
    void updateChangeGlobals(DataVisualization_1 &dv1, DataVisualization_2 &dv2, DataVisualization_3 &dv3, DataVisualization_4 &dv4, DataVisualization_5 &dv5, DataVisualization_6 &dv6, DataVisualization_7 &dv7, MenuPage &menu, SettingPage &setting, StartingPage &StartMenu);
    
    void loadFont();

};

#endif
