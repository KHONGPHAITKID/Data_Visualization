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

#endif