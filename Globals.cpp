#include "Globals.hpp"

ScreenState currentState = Menu;

sf::Font font;
sf::Color BackGroundColor = sf::Color(22, 73, 154);
sf::Sprite DefaultBackground;

// if (!font.loadFromFile("Fonts/arial.ttf"))
// {
//     std::cerr << "Failed to load Fonts" << "\n";
//     return 1;
// }

void CreateTitle(sf::Text &Title, float PosX, float PosY)
{
    // Title.setOutlineColor(sf::Color::Red);
    // Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color(106, 231, 255));
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

