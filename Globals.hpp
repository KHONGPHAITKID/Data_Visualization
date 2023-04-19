#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "ScreenState.hpp"
#include <SFML/Graphics.hpp>
#include "Image.hpp"

extern ScreenState currentState;

extern sf::Font font;
extern sf::Color BackGroundColor;
extern sf::Sprite DefaultBackground;
extern Image NotificationImage;


void CreateTitle(sf::Text &Title, float PosX, float PosY);


#endif // GLOBALS_HPP