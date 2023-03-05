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
    startButton.setFillColor(sf::Color(104, 0, 120));
    startButton.setOutlineColor(sf::Color(253, 0, 112));
    startButton.setOutlineThickness(5.f);
    startButton.setPosition(window.getSize().x / 2.f - startButton.getSize().x / 2.f, 440.f);
    sf::Text startText("Start", font, 50);
    startText.setFillColor(sf::Color(253, 0, 112));
    startText.setOrigin(startText.getLocalBounds().width / 2.f, startText.getLocalBounds().height / 2.f);
    startText.setPosition(window.getSize().x / 2.f, 500.f);

    // Create "Settings" button
    sf::RectangleShape settingsButton(sf::Vector2f(600.f, 150.f));
    settingsButton.setFillColor(sf::Color(104, 0, 120));
    settingsButton.setOutlineColor(sf::Color(253, 0, 112));
    settingsButton.setOutlineThickness(5.f);
    settingsButton.setPosition(window.getSize().x / 2.f - settingsButton.getSize().x / 2.f, 640.f);
    sf::Text settingsText("Settings", font, 50);
    settingsText.setFillColor(sf::Color(253, 0, 112));
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
    const float rectWidth = 600.f;
    const float rectHeight = 180.f;
    const float padding = 20.f;

    // Start position
    const float startX1 = window.getSize().x / 2.f - padding;
    const float startY1 = startText.getGlobalBounds().height + padding + 120.f;
    const float startX2 = window.getSize().x / 2.f ;
    const float startY2 = startText.getGlobalBounds().height + padding + 120.f;

    // #1. Static array rectangle
    sf::RectangleShape rect1(sf::Vector2f(rectWidth, rectHeight));
    rect1.setFillColor(sf::Color(0, 154, 172));
    rect1.setOrigin(rect1.getSize().x, 0.f);
    rect1.setPosition(startX1, startY1);

    // #2. Dynamic array rectangle
    sf::RectangleShape rect2(sf::Vector2f(rectWidth, rectHeight));
    rect2.setFillColor(sf::Color(218, 83, 44));
    rect2.setOrigin(rect2.getSize().x, 0.f);
    rect2.setPosition(startX1, startY1 + rectHeight + padding);

    // #3. Singly linked list rectangle
    sf::RectangleShape rect3(sf::Vector2f(rectWidth, rectHeight));
    rect3.setFillColor(sf::Color(160, 0, 167));
    rect3.setOrigin(rect3.getSize().x, 0.f);
    rect3.setPosition(startX1, startY1 + (rectHeight + padding) * 2.f);

    // #4. Doubly linked list rectangle
    sf::RectangleShape rect4(sf::Vector2f(rectWidth, rectHeight));
    rect4.setFillColor(sf::Color(186, 29, 71));
    rect4.setPosition(startX2, startY2);

    // #5. Circular linked list rectangle
    sf::RectangleShape rect5(sf::Vector2f(rectWidth, rectHeight));
    rect5.setFillColor(sf::Color(124, 192, 204));
    rect5.setPosition(startX2, startY2 + rectHeight + padding);

    // #6. Stack rectangle
    sf::RectangleShape rect6(sf::Vector2f(rectWidth, rectHeight));
    rect6.setFillColor(sf::Color(0, 160, 0));
    rect6.setPosition(startX2, startY2 + (rectHeight + padding) * 2.f);

    // #7. Queue rectangle
    sf::RectangleShape rect7(sf::Vector2f(rectWidth, rectHeight));
    rect7.setFillColor(sf::Color(38, 116, 236));
    rect7.setOrigin(rect7.getSize().x / 2.f, 0.f);
    rect7.setPosition(window.getSize().x / 2.f,  startY2 + (rectHeight + padding) * 3.f);

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

        window.clear(sf::Color(22, 73, 154));
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