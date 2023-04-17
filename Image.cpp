#include "Image.hpp"

void Image::setImage(std::string path)
{
    // sf::Texture texture;
    if (!image.loadFromFile(path)) 
    {
        std::cerr << "Failed to load Image" << "\n";
        return;
    }
    sf::IntRect currentRect = ImageHolder.getTextureRect();
    ImageHolder.setTexture(image);
    sf::IntRect newRect(0, 0, image.getSize().x, image.getSize().y);
    ImageHolder.setTextureRect(newRect);
    ImageHolder.setOrigin(sf::Vector2f(ImageHolder.getLocalBounds().width / 2.f, 0));
}

void Image::drawImage(sf::RenderWindow &window)
{
    window.draw(this->ImageHolder);
}

void Image::setPosition(sf::Vector2f pos)
{
    this->ImageHolder.setPosition(pos);
}