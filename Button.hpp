#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>

class Button
{
private:
public:
    sf::RectangleShape rect;
    sf::Text text;
    
    Button();
    void CreateButton(float recwidth, float recheight, float PosX, float PosY, sf::Color buttonbgcolor, sf::String text, sf::Font &font, sf::Color text_color);
    void displayButton(sf::RenderWindow &window);
};

#endif