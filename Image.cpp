#include "Image.hpp"

void Image::setImage(std::string path)
{
    if (!image.loadFromFile(path)) 
    {
        std::cerr << "Failed to load Image" << "\n";
        return;
    }
    ImageHolder.setTexture(image);
    ImageHolder.setOrigin(sf::Vector2f(ImageHolder.getLocalBounds().width / 2.f, ImageHolder.getLocalBounds().height / 2.f));
}
void Image::drawImage(sf::RenderWindow &window)
{
    window.draw(this->ImageHolder);
}

void Image::setPosition(sf::Vector2f pos)
{
    this->ImageHolder.setPosition(pos);
}