#ifndef _HEADER_HPP_
#define _HEADER_HPP_

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
    sf::Text Title;
    Button backButton;
    // sf::Texture page1texture;

    sf::Text FontText;
    Button FontTextButton;

    // music theme
    sf::Text MusicThemeTitle;
    Button MusicThemeBox;

    SettingPage();
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event);
    void updateChanges();

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
