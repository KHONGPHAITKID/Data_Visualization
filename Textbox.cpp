#include "Textbox.hpp"

Textbox::Textbox() 
{
    //int size, sf::Color color, bool sel
    // textbox.setCharacterSize(size);
    // textbox.setColor(color);
    // isSelected = sel;

    // Check if the textbox is selected upon creation and display it accordingly:
    // if (isSelected)
    //     textbox.setString("_");
    // else
    //     textbox.setString("");
}

// Make sure font is passed by reference:
void Textbox::setFont(sf::Font& fonts) 
{
    textbox.setFont(fonts);
}

void Textbox::setPosition(sf::Vector2f point) 
{
    textbox.setPosition(point);
}

// Set char limits:
void Textbox::setLimit(bool ToF) 
{
    hasLimit = ToF;
}

void Textbox::setLimit(bool ToF, int lim) 
{
    hasLimit = ToF;
    limit = lim - 1;
}

// Change selected state:
void Textbox::setSelected(bool sel) 
{
    isSelected = sel;

    // If not selected, remove the '_' at the end:
    if (!sel) 
    {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++) 
        {
            newT += t[i];
        }
        textbox.setString(newT);
    }
}

std::string Textbox::getText() 
{
    return text.str();
}

void Textbox::drawTo(sf::RenderWindow& window) 
{
    if (isSelected)
        window.draw(textbox);
}

// Function for event loop:
void Textbox::typedOn(sf::Event input) 
{
    int charTyped = input.text.unicode;

    // Only allow normal inputs:
    if (charTyped < 128) 
    {
        if (hasLimit) 
        {
            // If there's a limit, don't go over it:
            if (text.str().length() <= limit) 
            {
                inputLogic(charTyped);
            }
            // But allow for char deletions:
            else if (text.str().length() > limit && charTyped == DELETE_KEY) 
            {
                deleteLastChar();
            }
        }
        // If no limit exists, just run the function:
        else {
            inputLogic(charTyped);
        }
    }
}

// Delete the last character of the text:
void Textbox::deleteLastChar() 
{
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++) 
    {
        newT += t[i];
    }
    text.str("");
    text << newT;
    textbox.setString(text.str() + "_");
}

// Get user input:
void Textbox::inputLogic(int charTyped) {
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY && isdigit(charTyped) && text.str().length() < limit) {
        if (text.str().length() == 0 && charTyped == '0') {
            return;
        }
        else if (text.str().length() == 1 && (charTyped > '9' || charTyped < '0')) {
            return;
        }
        text << static_cast<char>(charTyped);
    }
    else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }
    else if (charTyped == ENTER_KEY) {
        if (text.str().length() > 0) {
            std::string temp = "";
            ExportString(this->message);
            std::cout << this->message << std::endl;
        }
    }
    textbox.setString(text.str() + "_");
}

void Textbox::ExportString(std::string &destination)
{
    destination = text.str();
    text.str("");
}

void Textbox::TextboxHandleEvent(sf::Event event, std::string &Mes)
{
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
    //     setSelected(true);
    // }
    // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    //     setSelected(false);
    // }
    // switch (event.type)
    // {
    //     case sf::Event::TextEntered:
    //         std::cout << 1 << std::endl;
    //         typedOn(event);
    //         break;
    //     default:
    //         std::cout << 2 << std::endl;
    //         break;
    // }
    if (event.type == sf::Event::TextEntered)
    {
        this->typedOn(event);
        if (this->message != "")
        {
            Mes = this->message;
        }
    } 
    // else if (event.type == sf::Event::MouseButtonPressed) 
    // {
    //     // if (!textBox.shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
    //     this->isSelected = false;
    //     std::cout << 1 << std::endl;
    // }
}

void Textbox::setSize(int size)
{
    textbox.setCharacterSize(size);
}

void Textbox::Coloring(sf::Color color)
{
    textbox.setColor(color);
}

void InitTextbox(Textbox &box, int size, sf::Color color, bool sel)
{
    box.setSize(size);
    box.Coloring(color);
    box.setSelected(sel);
    if (box.isSelected)
        box.textbox.setString("_");
    else
        box.textbox.setString("");
}