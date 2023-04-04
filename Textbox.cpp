#include "Textbox.hpp"

Textbox::Textbox() {}

void Textbox::setFont(sf::Font& fonts) 
{
    textbox.setFont(fonts);
}

void Textbox::setPosition(sf::Vector2f point) 
{
    textbox.setPosition(point);
}

void Textbox::setLimit(bool ToF) 
{
    hasLimit = ToF;
}

void Textbox::setLimit(bool ToF, int lim) 
{
    hasLimit = ToF;
    limit = lim - 1;
}

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
    {
        window.draw(textbox);
        window.draw(this->EnterMessage);
    }
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
            if (text.str().length() <= limit) 
            {
                inputLogic(charTyped);
            }
            else if (text.str().length() > limit && charTyped == DELETE_KEY) 
            {
                deleteLastChar();
            }
        }
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
            ExportString(this->message);
            this->pressEnter = true;
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
    if (event.type == sf::Event::TextEntered)
    {
        this->typedOn(event);
        if (this->message != "")
        {
            Mes = this->message;
        }
    } 
}

void Textbox::setSize(int size)
{
    textbox.setCharacterSize(size);
}

void Textbox::ColoringBox(sf::Color &color)
{
    textbox.setFillColor(color);
}

void InitTextbox(Textbox &box, int size, sf::Color color, bool sel, float PosX, float PosY, sf::Font &font, bool ToF, int lim)
{
    box.setSize(size);
    box.ColoringBox(color);
    box.setSelected(sel);
    box.setPosition({PosX, PosY});
	box.setFont(font);
	box.setLimit(ToF, lim);
    if (box.isSelected)
        box.textbox.setString("_");
    else
        box.textbox.setString("");
    // box.isSelected = false;
    box.EnterMessage.setFont(font);
    box.EnterMessage.setFillColor(sf::Color::White);
    box.EnterMessage.setCharacterSize(20);
    box.EnterMessage.setPosition(PosX - 60, PosY);
}

