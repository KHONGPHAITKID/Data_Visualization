#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include "SFML/Graphics.hpp"
#include <iostream>

class Image
{
private:
public:
    sf::Texture image;
    sf::Sprite ImageHolder;
    void setImage(std::string path);
    void drawImage(sf::RenderWindow &window);
    void setPosition(sf::Vector2f pos);
};

#endif