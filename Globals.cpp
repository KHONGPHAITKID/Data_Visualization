#include "Globals.hpp"

ScreenState currentState = Menu;

sf::Font font;
sf::Color BackGroundColor = sf::Color(22, 73, 154);
sf::Sprite DefaultBackground;
Image NotificationImage;

void CreateTitle(sf::Text &Title, float PosX, float PosY)
{
    Title.setFillColor(sf::Color(106, 231, 255));
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

