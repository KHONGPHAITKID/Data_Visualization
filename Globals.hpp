#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>
#include <functional>
#include <windows.h>
#include <chrono> 
#include <thread>
#include <unistd.h>
#include <cstdlib>
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
void pause_for(std::chrono::milliseconds duration);

extern std::string getCurrentPath();
extern std::string WorkingPath;


#endif // GLOBALS_HPP