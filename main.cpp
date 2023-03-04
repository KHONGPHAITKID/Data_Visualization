#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Data Visualization");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("media/img/background.jfif"))
    {
        std::cerr << "Failed to load img!" << "\n";
        return 1;
    }
    sf::Sprite sprite(texture);
    sprite.setScale(window.getSize().x / sprite.getLocalBounds().width, 
                    window.getSize().y / sprite.getLocalBounds().height);

    sf::Font font;
    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return 1;
    }
    // Create MenuTitle
    sf::Text MenuTitle("Data Visualization", font, 120);
    MenuTitle.setOutlineThickness(3);
    MenuTitle.setOutlineColor(sf::Color::Red);
    MenuTitle.setFillColor(sf::Color::White);
    MenuTitle.setOrigin(MenuTitle.getLocalBounds().width / 2.f, MenuTitle.getLocalBounds().height / 2.f);
    MenuTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // Create StartTitle
    sf::Text StartTitle("Start Mode", font, 100);
    StartTitle.setOutlineThickness(3);
    StartTitle.setOutlineColor(sf::Color::Red);
    StartTitle.setFillColor(sf::Color::White);
    StartTitle.setOrigin(StartTitle.getLocalBounds().width / 2.f, StartTitle.getLocalBounds().height / 2.f);
    StartTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // Create SettingTitle
    sf::Text SettingTitle("Setting Mode", font, 120);
    SettingTitle.setOutlineThickness(3);
    SettingTitle.setOutlineColor(sf::Color::Red);
    SettingTitle.setFillColor(sf::Color::White);
    SettingTitle.setOrigin(SettingTitle.getLocalBounds().width / 2.f, SettingTitle.getLocalBounds().height / 2.f);
    SettingTitle.setPosition(window.getSize().x / 2.f, 50.f);


    // Create "Start" button
    sf::RectangleShape startButton(sf::Vector2f(600.f, 150.f));
    startButton.setFillColor(sf::Color(128, 128, 128));
    startButton.setPosition(window.getSize().x / 2.f - startButton.getSize().x / 2.f, 440.f);
    sf::Text startText("Start", font, 30);
    startText.setFillColor(sf::Color::Red);
    startText.setOrigin(startText.getLocalBounds().width / 2.f, startText.getLocalBounds().height / 2.f);
    startText.setPosition(window.getSize().x / 2.f, 500.f);

    // Create "Settings" button
    sf::RectangleShape settingsButton(sf::Vector2f(600.f, 150.f));
    settingsButton.setFillColor(sf::Color::Blue);
    settingsButton.setPosition(window.getSize().x / 2.f - settingsButton.getSize().x / 2.f, 640.f);
    sf::Text settingsText("Settings", font, 30);
    settingsText.setFillColor(sf::Color::Red);
    settingsText.setOrigin(settingsText.getLocalBounds().width / 2.f, settingsText.getLocalBounds().height / 2.f);
    settingsText.setPosition(window.getSize().x / 2.f, 700.f);
    
    // Back button
    sf::RectangleShape backButton(sf::Vector2f(100.f, 50.f));
    backButton.setFillColor(sf::Color(128, 128, 128));
    backButton.setPosition(10.f, 10.f);
    sf::Text backText("Back", font, 20);
    backText.setFillColor(sf::Color::White);
    backText.setOrigin(backText.getLocalBounds().width / 2.f, backText.getLocalBounds().height / 2.f);
    backText.setPosition(backButton.getPosition() + backButton.getSize() / 2.f);

        // Rectangle dimensions
    const float rectWidth = 200.f;
    const float rectHeight = 50.f;
    const float padding = 20.f;

    // Start position
    const float startX = (window.getSize().x - rectWidth) / 2.f;
    const float startY = window.getSize().y / 4.f;

    // Static array rectangle
    sf::RectangleShape rect1(sf::Vector2f(rectWidth, rectHeight));
    rect1.setFillColor(sf::Color::Red);
    rect1.setPosition(startX, startY);

    // Dynamic array rectangle
    sf::RectangleShape rect2(sf::Vector2f(rectWidth, rectHeight));
    rect2.setFillColor(sf::Color::Green);
    rect2.setPosition(startX, startY + rectHeight + padding);

    // Singly linked list rectangle
    sf::RectangleShape rect3(sf::Vector2f(rectWidth, rectHeight));
    rect3.setFillColor(sf::Color::Blue);
    rect3.setPosition(startX, startY + (rectHeight + padding) * 2.f);

    // Doubly linked list rectangle
    sf::RectangleShape rect4(sf::Vector2f(rectWidth, rectHeight));
    rect4.setFillColor(sf::Color::Yellow);
    rect4.setPosition(startX, startY + (rectHeight + padding) * 3.f);

    // Circular linked list rectangle
    sf::RectangleShape rect5(sf::Vector2f(rectWidth, rectHeight));
    rect5.setFillColor(sf::Color::Magenta);
    rect5.setPosition(startX, startY + (rectHeight + padding) * 4.f);

    // Stack rectangle
    sf::RectangleShape rect6(sf::Vector2f(rectWidth, rectHeight));
    rect6.setFillColor(sf::Color::Cyan);
    rect6.setPosition(startX, startY + (rectHeight + padding) * 5.f);

    // Queue rectangle
    sf::RectangleShape rect7(sf::Vector2f(rectWidth, rectHeight));
    rect7.setFillColor(sf::Color::White);
    rect7.setPosition(startX, startY + (rectHeight + padding) * 6.f);

    enum ScreenState { Menu, Start, Settings };
    ScreenState currentState = Menu;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                switch (currentState)
                {
                    case Menu:
                        if (startButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        else if (settingsButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Settings;
                        }
                        break;

                    case Start:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        break;

                    case Settings:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        break;
                }
            }
        }

        window.clear(sf::Color::White);
        switch (currentState)
        {
            case Menu:
                window.draw(MenuTitle);
                window.draw(startButton);
                window.draw(startText);
                window.draw(settingsButton);
                window.draw(settingsText);
                break;

            case Start:
                window.draw(backButton);
                window.draw(StartTitle);
                window.draw(backText);
                window.draw(rect1);
                window.draw(rect2);
                window.draw(rect3);
                window.draw(rect4);
                window.draw(rect5);
                window.draw(rect6);
                window.draw(rect7);
                break;  
            case Settings:
                window.draw(SettingTitle);
                window.draw(backButton);
                window.draw(backText);
                break;
            default:
                break;
        }
        window.display();
    }
    return 0;
}