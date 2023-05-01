#ifndef _DROPDOWNBOX_HPP_
#define _DROPDOWNBOX_HPP_
#include <SFML/Graphics.hpp>
#include "Globals.hpp"
#include <iostream>

struct DropdownBox
{
    sf::RectangleShape background;
    sf::RectangleShape Titlebackground;

    std::string storage;
    sf::Text title;
    sf::Font font;
    bool isExpanded;
    std::vector<sf::Text> options;
    int selectedOptionIndex;

    DropdownBox(sf::Vector2f position, sf::Vector2f size, std::string titleText, std::vector<std::string> optionTexts);
    void draw(sf::RenderWindow& window);
    void expand();
    void collapse();
    bool handleEvent(sf::Event event);
};

#endif