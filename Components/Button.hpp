#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>

struct Button
{
    sf::RectangleShape rect;
    sf::Text text;
    
    Button();
    void CreateButton(float recwidth, float recheight, float PosX, float PosY, sf::Color buttonbgcolor, sf::String text, sf::Font &font, sf::Color text_color);
    void setSize(float size);
    void displayButton(sf::RenderWindow &window);
};

#endif