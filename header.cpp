#include "header.hpp"

/*
sf::Font font;
sf::Color(22, 73, 154)
sf::Color sf::Color(22, 73, 154) = sf::Color(22, 73, 154);
const sf::Color Pink1(253, 0, 112);
const sf::Color Purple1(104, 0, 120);
*/

void CreateTitle(sf::Text &Title, float PosX, float PosY)
{
    Title.setOutlineColor(sf::Color::Red);
    Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color::White);
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

//---
MenuPage::MenuPage()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    sf::Text temp("Data Visualization", this->font, 150);
    CreateTitle(temp, 1920 / 2.f, 100.f);
    this->Title = temp;

    // this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
    this->startButton.CreateButton(600, 150, 1920 / 2.f, 530, sf::Color(104, 0, 120), "Start", font, sf::Color(253, 0, 112));
    this->startButton.rect.setOutlineThickness(5);
    this->startButton.rect.setOutlineColor(sf::Color(253, 0, 112));
    this->settingsButton.CreateButton(600, 150, 1920 / 2.f - settingsButton.rect.getSize().x / 2.f, startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, sf::Color(104, 0, 120), "Setting", font, sf::Color(253, 0, 112));
    this->settingsButton.rect.setOutlineThickness(5);
    this->settingsButton.rect.setOutlineColor(sf::Color(253, 0, 112));
}
void MenuPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    // this->backButton.displayButton(window);
    this->settingsButton.displayButton(window);
    this->startButton.displayButton(window);
}
void MenuPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->startButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
        else if (this->settingsButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Settings;
        }
    }
}
//---

SettingPage::SettingPage()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text SettingTitle("Setting", this->font, 120);
    CreateTitle(SettingTitle, 1920 / 2.f, 50.f);
    this->Title = SettingTitle;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);

}
void SettingPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    this->backButton.displayButton(window);
}
void SettingPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

StartingPage::StartingPage()
{
    //Font
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text StartTitle("Menu", this->font, 100);
    CreateTitle(StartTitle, 1920 / 2.f, 50.f);
    this->Title = StartTitle;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);

    // Option
    // Rectangle dimensions
    const float rectWidth = 600.f;
    const float rectHeight = 180.f;
    const float padding = 20.f;
    // Start position
    const float startX1 = 1920 / 2.f - padding - rectWidth / 2.f;
    const float startY1 = StartTitle.getLocalBounds().height + padding * 5 + rectHeight / 2.f;
    const float startX2 = 1920 / 2.f + rectWidth / 2.f;
    const float startY2 = StartTitle.getLocalBounds().height + padding * 5 + rectHeight / 2.f;

    // #1. Static array rectangle
    this->rect1.CreateButton(rectWidth, rectHeight, startX1, startY1, sf::Color(0, 154, 172), "Static Array", font, sf::Color::White);
    // #2. Dynamic array rectangle
    rect2.CreateButton(rectWidth, rectHeight, startX1, startY1 + rectHeight + padding, sf::Color(218, 83, 44), "Dynamic Array", font, sf::Color::White);
    // #3. Singly linked list rectangle
    rect3.CreateButton(rectWidth, rectHeight, startX1, startY1 + (rectHeight + padding) * 2.f, sf::Color(160, 0, 167), "Singly Linked List", font, sf::Color::White);
    // #4. Doubly linked list rectangle
    rect4.CreateButton(rectWidth, rectHeight, startX2, startY2, sf::Color(186, 29, 71), "Doubly Linked List", font, sf::Color::White);
    // #5. Circular linked list rectangle
    rect5.CreateButton(rectWidth, rectHeight, startX2, startY2 + rectHeight + padding, sf::Color(124, 192, 204), "Circular Linked List", font, sf::Color::White);
    // #6. Stack rectangle
    rect6.CreateButton(rectWidth, rectHeight, startX2, startY2 + (rectHeight + padding) * 2.f, sf::Color(0, 160, 0), "Stack", font, sf::Color::White);
    // #7. Queue rectangle
    rect7.CreateButton(rectWidth + padding*2, rectHeight, 1920 / 2.f,  startY2 + (rectHeight + padding) * 3.f, sf::Color(38, 116, 236), "Queue", font, sf::Color::White);
}
void StartingPage::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    this->rect1.displayButton(window);
    this->rect2.displayButton(window);
    this->rect3.displayButton(window);
    this->rect4.displayButton(window);
    this->rect5.displayButton(window);
    this->rect6.displayButton(window);
    this->rect7.displayButton(window);
    window.draw(this->Title);
}
void StartingPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {   
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Menu;
        }
        if (this->rect1.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV1;
        } 
        if (this->rect2.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV2;
        } 
        if (this->rect3.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV3;
        } 
        if (this->rect4.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV4;
        } 
        if (this->rect5.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV5;
        } 
        if (this->rect6.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV6;
        } 
        if (this->rect7.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV7;
        } 
    }
}

DataVisualization_1::DataVisualization_1()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV1Title("Static Array", this->font, 90);
    CreateTitle(DV1Title, 1920 / 2.f, 50.f);
    this->Title = DV1Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}
void DataVisualization_1::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}
void DataVisualization_1::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

DataVisualization_2::DataVisualization_2()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV2Title("Dynamic Array", this->font, 90);
    CreateTitle(DV2Title, 1920 / 2.f, 50.f);
    this->Title = DV2Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}
void DataVisualization_2::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}
void DataVisualization_2::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

// DataVisualization_4::DataVisualization_4()
// {
//     if (!this->font.loadFromFile("Fonts/arial.ttf"))
//     {
//         std::cerr << "Failed to load Fonts" << "\n";
//         return;
//     }
//     //Title
//     sf::Text DV4Title("Doubly Linked List", this->font, 90);
//     CreateTitle(DV4Title, 1920 / 2.f, 50.f);
//     this->Title = DV4Title;
//     //Back button
//     this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
// }

// void DataVisualization_4::display(sf::RenderWindow &window)
// {
//     this->backButton.displayButton(window);
//     window.draw(this->Title);
// }

// void DataVisualization_4::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
// {
//     if (event.type == sf::Event::MouseButtonPressed)
//     {
//         if (this->backButton.rect.getGlobalBounds().contains(mousePos))
//         {
//             currentState = Start;
//         }
//     }
// }

DataVisualization_5::DataVisualization_5()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV5Title("Circular Linked List", this->font, 90);
    CreateTitle(DV5Title, 1920 / 2.f, 50.f);
    this->Title = DV5Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_5::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

void DataVisualization_5::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

DataVisualization_6::DataVisualization_6()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV6Title("Stack", this->font, 90);
    CreateTitle(DV6Title, 1920 / 2.f, 50.f);
    this->Title = DV6Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_6::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

void DataVisualization_6::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

DataVisualization_7::DataVisualization_7()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV7Title("Queue", this->font, 90);
    CreateTitle(DV7Title, 1920 / 2.f, 50.f);
    this->Title = DV7Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_7::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

void DataVisualization_7::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}
// Testing------------------------------------------------------