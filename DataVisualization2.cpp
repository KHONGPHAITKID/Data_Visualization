#include "DataVisualization2.hpp"


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
