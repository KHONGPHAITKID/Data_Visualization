#ifndef _TEXTBOX_HPP_
#define _TEXTBOX_HPP_

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
    sf::Text textbox;

    std::string message = "";

    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = true;
    int limit;

    // Delete the last character of the text:
    void deleteLastChar();

    // Get user input:
    void inputLogic(int charTyped);

    void ExportString(std::string &destination);
//-----------------
    Textbox();

    void TextboxHandleEvent(sf::Event event, std::string &Mes);

    void setFont(sf::Font& fonts);

    void setPosition(sf::Vector2f point);

    void setSize(int size);

    void Coloring(sf::Color color);

    void setLimit(bool ToF);

    void setLimit(bool ToF, int lim);

    void setSelected(bool sel);

    std::string getText();

    void drawTo(sf::RenderWindow& window);

    void typedOn(sf::Event input);
};

void InitTextbox(Textbox &box, int size, sf::Color color, bool sel);

#endif 
