#include "Globals.hpp"

ScreenState currentState = Menu;

sf::Font defautFont;
sf::Font defautTitleFont;

sf::Color BackGroundColor = sf::Color(22, 73, 154);
sf::Sprite DefaultBackground;
sf::Texture BackGround0;
sf::Texture BackGround1;
sf::Texture BackGround2;

sf::Color ButtonColor;
sf::Color ButtonOutlineColor;
sf::Color MainColor;

Image NotificationImage;

std::string WorkingPath;

void CreateTitle(sf::Text &Title, float PosX, float PosY)
{
    Title.setFillColor(sf::Color(106, 231, 255));
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

void pause_for(std::chrono::milliseconds duration) 
{
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + duration;
    
    while (std::chrono::steady_clock::now() < end_time) {
        std::this_thread::yield();
    }
}

std::string getCurrentPath()
{
    system("cd > tmp.txt");
    std::ifstream file("tmp.txt");
    std::string path;
    std::getline(file, path);
    file.close();
    path += '/';
    std::remove("tmp.txt");
    return path;
}

