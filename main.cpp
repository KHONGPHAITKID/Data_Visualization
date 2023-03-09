#include "header.hpp"
#include <vector>

sf::Font font;
sf::Color BackGroundColor = sf::Color(22, 73, 154);
//Color
const sf::Color Pink1(253, 0, 112);
const sf::Color Purple1(104, 0, 120);

Node v[10];
int n = 0;

int main()
{
    srand(time(NULL)); // Seed random number generator
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Data Visualization", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    enum ScreenState { Menu, Start, Settings, DV1, DV2, DV3, DV4, DV5, DV6, DV7 };
    ScreenState currentState = Menu;
    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return 1;
    }
    CreateRandomNodes(v, n, font);
    // Create MenuTitle
    sf::Text MenuTitle("Data Visualization", font, 150);
    CreateTitle(MenuTitle, window.getSize().x / 2.f, 100.f);
    // Create StartTitle
    sf::Text StartTitle("Menu", font, 100);
    CreateTitle(StartTitle, window.getSize().x / 2.f, 50.f);
    // Create SettingTitle
    sf::Text SettingTitle("Setting Mode", font, 120);
    CreateTitle(SettingTitle, window.getSize().x / 2.f, 50.f);
    // Create "Start" button
    Button startButton = CreateButton(600, 150, window.getSize().x / 2.f, 530, Purple1, Pink1, "Start", font, Pink1);
    // Create "Settings" button
    Button settingsButton = CreateButton(600, 150, window.getSize().x / 2.f - settingsButton.rect.getSize().x / 2.f, startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, Purple1, Pink1, "Setting", font, Pink1);
    // Back button
    Button backButton = CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);

    // Rectangle dimensions
    const float rectWidth = 600.f;
    const float rectHeight = 180.f;
    const float padding = 20.f;
    // Start position
    const float startX1 = window.getSize().x / 2.f - padding - rectWidth / 2.f;
    const float startY1 = StartTitle.getLocalBounds().height + padding * 5 + rectHeight / 2.f;
    const float startX2 = window.getSize().x / 2.f + rectWidth / 2.f;
    const float startY2 = StartTitle.getLocalBounds().height + padding * 5 + rectHeight / 2.f;

    // #1. Static array rectangle
    Button rect1 = CreateButton(rectWidth, rectHeight, startX1, startY1, sf::Color(0, 154, 172), BackGroundColor, "Static Array", font, sf::Color::White);
    sf::Text StaticArrayTitle("Static Array", font, 90);
    CreateTitle(StaticArrayTitle, window.getSize().x / 2.f, 50.f);
    // #2. Dynamic array rectangle
    Button rect2 = CreateButton(rectWidth, rectHeight, startX1, startY1 + rectHeight + padding, sf::Color(218, 83, 44), BackGroundColor, "Dynamic array", font, sf::Color::White);
    sf::Text DynamicArrayTitle("Dynamic Array", font, 90);
    CreateTitle(DynamicArrayTitle, window.getSize().x / 2.f, 50.f);
    // #3. Singly linked list rectangle
    Button rect3 = CreateButton(rectWidth, rectHeight, startX1, startY1 + (rectHeight + padding) * 2.f, sf::Color(160, 0, 167), BackGroundColor, "Singly linked list", font, sf::Color::White);
    sf::Text SingleLLTitle("Singly Linked List", font, 90);
    CreateTitle(SingleLLTitle, window.getSize().x / 2.f, 50.f);
    // #4. Doubly linked list rectangle
    Button rect4 = CreateButton(rectWidth, rectHeight, startX2, startY2, sf::Color(186, 29, 71), BackGroundColor, "Doubly Linked List", font, sf::Color::White);
    sf::Text DoublyLLTitle("Doubly Linked List", font, 90);
    CreateTitle(DoublyLLTitle, window.getSize().x / 2.f, 50.f);
    // #5. Circular linked list rectangle
    Button rect5 = CreateButton(rectWidth, rectHeight, startX2, startY2 + rectHeight + padding, sf::Color(124, 192, 204), BackGroundColor, "Circular Linked List", font, sf::Color::White);
    sf::Text CircularLLTitle("Circular Linked List", font, 90);
    CreateTitle(CircularLLTitle, window.getSize().x / 2.f, 50.f);
    // #6. Stack rectangle
    Button rect6 = CreateButton(rectWidth, rectHeight, startX2, startY2 + (rectHeight + padding) * 2.f, sf::Color(0, 160, 0), BackGroundColor, "Stack", font, sf::Color::White);
    sf::Text StackTitle("Stack", font, 90);
    CreateTitle(StackTitle, window.getSize().x / 2.f, 50.f);
    // #7. Queue rectangle
    Button rect7 = CreateButton(rectWidth + padding*2, rectHeight, window.getSize().x / 2.f,  startY2 + (rectHeight + padding) * 3.f, sf::Color(38, 116, 236), BackGroundColor, "Queue", font, sf::Color::White);
    sf::Text QueueTitle("Queue", font, 90);
    CreateTitle(QueueTitle, window.getSize().x / 2.f, 50.f);

    // CONTROLL MENU
    // #1
    Button ControlMenu_btn1 = CreateButton(200.f, 50.f, 250.f, window.getSize().y / 2.f + 125.f, sf::Color(255, 138, 39), BackGroundColor, "Create", font, sf::Color::White);
    ControlMenu_btn1.rect.setOutlineThickness(0);

    Button CreateEmpty = CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + padding + 130/2.f, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), BackGroundColor, "Empty", font, sf::Color::White);
    CreateEmpty.display = false;
    Button CreateRadom = CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + padding + 130/2.f + 130.f, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), BackGroundColor, "Random", font, sf::Color::White);
    CreateRadom.display = false;
    Button CreateRandomSort = CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + padding + 130/2.f + 130.f * 2, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), BackGroundColor, "Random Sort", font, sf::Color::White);
    CreateRandomSort.display = false;
    Button CreateRandomFixedSize = CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + padding + 130/2.f + 130.f * 3, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), BackGroundColor, "Random Fixed Size", font, sf::Color::White);
    CreateRandomFixedSize.display = false;
    Button CreateUserDefinedList = CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + padding + 130/2.f + 130.f * 4, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), BackGroundColor, "User Defined", font, sf::Color::White);
    CreateUserDefinedList.display = false;

    // #2
    Button ControlMenu_btn2 = CreateButton(200.f, 50.f, 250.f, window.getSize().y / 2.f + 175.f, sf::Color(255, 138, 39), BackGroundColor, "Add", font, sf::Color::White);
    ControlMenu_btn2.rect.setOutlineThickness(0);
    // #3 
    Button ControlMenu_btn3 = CreateButton(200.f, 50.f, 250.f, window.getSize().y / 2.f + 225.f, sf::Color(255, 138, 39), BackGroundColor, "Delete", font, sf::Color::White);
    ControlMenu_btn3.rect.setOutlineThickness(0);
    // #4
    Button ControlMenu_btn4 = CreateButton(200.f, 50.f, 250.f, window.getSize().y / 2.f + 275.f, sf::Color(255, 138, 39), BackGroundColor, "Update", font, sf::Color::White);
    ControlMenu_btn4.rect.setOutlineThickness(0);
    // #5
    Button ControlMenu_btn5 = CreateButton(200.f, 50.f, 250.f, window.getSize().y / 2.f + 325.f, sf::Color(255, 138, 39), BackGroundColor, "Search", font, sf::Color::White);
    ControlMenu_btn5.rect.setOutlineThickness(0);


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
                        if (startButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        else if (settingsButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Settings;
                        }
                        break;

                    case Start:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        if (rect1.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV1;
                        } 
                        if (rect2.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV2;
                        } 
                        if (rect3.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV3;
                        } 
                        if (rect4.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV4;
                        } 
                        if (rect5.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV5;
                        } 
                        if (rect6.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV6;
                        } 
                        if (rect7.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV7;
                        } 
                        break;

                    case Settings:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        break;
                    case DV1:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV2:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV3:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        if (ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
                        {
                            CreateEmpty.display = !CreateEmpty.display;
                            CreateRadom.display = !CreateRadom.display;
                            CreateRandomFixedSize.display = !CreateRandomFixedSize.display;
                            CreateRandomSort.display = !CreateRandomSort.display;
                            CreateUserDefinedList.display = !CreateUserDefinedList.display;
                        }
                        if (CreateEmpty.rect.getGlobalBounds().contains(mousePos))
                        {
                            n = 0;
                        }
                        if (CreateRadom.rect.getGlobalBounds().contains(mousePos))
                        {
                            CreateRandomNodes(v, n, font);
                        }
                        break;
                    case DV4:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV5:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV6:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV7:
                        if (backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;                    
                }
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                switch (currentState){
                    case DV3:
                        if (ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn1.rect.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn1.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn2.rect.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn2.rect.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn2.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn3.rect.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn3.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn4.rect.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn4.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn5.rect.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn5.rect.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn5.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        break;
                }
            }
        }

        window.clear(BackGroundColor);
        switch (currentState)
        {
            case Menu:
                window.draw(MenuTitle);
                window.draw(settingsButton.rect);
                window.draw(settingsButton.text);
                window.draw(startButton.rect);
                window.draw(startButton.text);
                break;

            case Start:
                window.draw(backButton.rect);
                window.draw(StartTitle);
                window.draw(backButton.text);
                window.draw(rect1.rect);
                window.draw(rect1.text);
                window.draw(rect2.rect);
                window.draw(rect2.text);
                window.draw(rect3.rect);
                window.draw(rect3.text);
                window.draw(rect4.rect);
                window.draw(rect4.text);
                window.draw(rect5.rect);
                window.draw(rect5.text);
                window.draw(rect6.rect);
                window.draw(rect6.text);
                window.draw(rect7.rect);
                window.draw(rect7.text);
                break;  
            case Settings:
                window.draw(SettingTitle);
                window.draw(backButton.rect);
                window.draw(backButton.text);
                break;
            case DV1: // Static Array
                window.draw(backButton.rect);
                window.draw(backButton.text);
                window.draw(StaticArrayTitle);
                break;
            case DV2: // Dynamic Array
                window.draw(backButton.rect);
                window.draw(backButton.text);
                window.draw(DynamicArrayTitle);
                break;
            case DV3: // Singly LL
                window.draw(backButton.rect);
                window.draw(backButton.text);
                window.draw(SingleLLTitle);
                window.draw(ControlMenu_btn1.rect);
                window.draw(ControlMenu_btn1.text);
                window.draw(ControlMenu_btn2.rect);
                window.draw(ControlMenu_btn2.text);
                window.draw(ControlMenu_btn3.rect);
                window.draw(ControlMenu_btn3.text);
                window.draw(ControlMenu_btn4.rect);
                window.draw(ControlMenu_btn4.text);
                window.draw(ControlMenu_btn5.rect);
                window.draw(ControlMenu_btn5.text);
                if (CreateEmpty.display)
                {
                    window.draw(CreateEmpty.rect);
                    window.draw(CreateEmpty.text);
                    window.draw(CreateRadom.rect);
                    window.draw(CreateRadom.text);
                    window.draw(CreateRandomSort.rect);
                    window.draw(CreateRandomSort.text);
                    window.draw(CreateRandomFixedSize.rect);
                    window.draw(CreateRandomFixedSize.text);
                    window.draw(CreateUserDefinedList.rect);
                    window.draw(CreateUserDefinedList.text);
                }
                // CreateRandomNode
                for (int i = 0; i < n; i++)
                {
                    window.draw(v[i].circle);
                    window.draw(v[i].text);
                    if (i != n - 1)
                    {
                        sf::Vector2f first(v[i].circle.getPosition().x + 60, v[i].circle.getPosition().y + 30);
                        sf::Vector2f second(v[i + 1].circle.getPosition().x, v[i + 1].circle.getPosition().y + 30);
                        sf::VertexArray line(sf::Lines, 2);
                        line[0].position = first;
                        line[1].position = second;
                        line[0].color = sf::Color::Red;
                        line[1].color = sf::Color::Red;
                        window.draw(line);
                    }
                }
                break;
            case DV4: // Doubly LL
                window.draw(backButton.rect);
                window.draw(backButton.text);
                window.draw(DoublyLLTitle);
                break;
            case DV5: // Circular LL
                window.draw(backButton.rect);
                window.draw(backButton.text);
                window.draw(CircularLLTitle);
                break;
            case DV6: // Stack
                window.draw(backButton.rect);
                window.draw(backButton.text);
                window.draw(StackTitle);
                break;
            case DV7: // Queue
                window.draw(backButton.rect);
                window.draw(backButton.text);
                window.draw(QueueTitle);
                break;
            default:
                break;
        }
        window.display();
    }
    return 0;
}