#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Components/ScreenState.hpp"
#include <SFML/Graphics.hpp>
#include "Components/Image.hpp"

extern ScreenState currentState;
extern sf::Font defautFont;
extern sf::Font defautTitleFont;
extern sf::Color BackGroundColor;
extern sf::Sprite DefaultBackground;
extern sf::Texture BackGround0;
extern sf::Texture BackGround1;
extern sf::Texture BackGround2;
extern sf::Color ButtonColor;
extern sf::Color ButtonOutlineColor;
extern sf::Color MainColor;
extern Image NotificationImage;

void CreateTitle(sf::Text &Title, float PosX, float PosY);

extern std::string getCurrentPath();
extern std::string WorkingPath;


#endif // GLOBALS_HPP