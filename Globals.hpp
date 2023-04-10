#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "ScreenState.hpp"
#include <SFML/Graphics.hpp>

extern ScreenState currentState;

extern sf::Font font;
extern sf::Color BackGroundColor;
extern sf::Sprite DefaultBackground;

void CreateTitle(sf::Text &Title, float PosX, float PosY);


#endif // GLOBALS_HPP