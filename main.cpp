#include "header.hpp"
#include <vector>

sf::Font font;

//Color
const sf::Color Pink1(253, 0, 112);
const sf::Color Purple1(104, 0, 120);


int main()
{
    srand(time(NULL)); // Seed random number generator
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Data Visualization", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return 1;
    }
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
    Button settingsButton = CreateButton(600, 150, 
    window.getSize().x / 2.f - settingsButton.rect.getSize().x / 2.f, 
    startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, 
    Purple1, Pink1, "Setting", font, Pink1);
    // sf::RectangleShape settingsButton(sf::Vector2f(600.f, 150.f));
    // settingsButton.setFillColor(sf::Color(104, 0, 120));
    // settingsButton.setOutlineColor(sf::Color(253, 0, 112));
    // settingsButton.setOutlineThickness(5.f);
    // settingsButton.setPosition(window.getSize().x / 2.f - settingsButton.getSize().x / 2.f, 640.f);
    // sf::Text settingsText("Settings", font, 50);
    // settingsText.setFillColor(sf::Color(253, 0, 112));
    // settingsText.setOrigin(settingsText.getLocalBounds().width / 2.f, settingsText.getLocalBounds().height / 2.f);
    // settingsText.setPosition(window.getSize().x / 2.f, 700.f);
    
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
    const float startY1 = StartTitle.getLocalBounds().height + padding * 5;
    const float startX2 = window.getSize().x / 2.f ;
    const float startY2 = StartTitle.getLocalBounds().height + padding * 5;

    // #1. Static array rectangle
    sf::RectangleShape rect1(sf::Vector2f(rectWidth, rectHeight));
    rect1.setFillColor(sf::Color(0, 154, 172));
    rect1.setOrigin(rect1.getSize().x, 0.f);
    rect1.setPosition(startX1, startY1);
    sf::Text rect1_text("Static Array", font, 40);
    rect1_text.setFillColor(sf::Color::White);
    rect1_text.setOrigin(rect1_text.getLocalBounds().width / 2.f, rect1_text.getLocalBounds().height / 2.f);
    rect1_text.setPosition(rect1.getPosition().x - rect1.getSize().x / 2.f, rect1.getPosition().y + rect1.getSize().y / 2.f - rect1_text.getLocalBounds().height / 2.f);
    // menu
    sf::Text StaticArrayTitle("Static Array", font, 90);
    StaticArrayTitle.setOutlineThickness(3);
    StaticArrayTitle.setOutlineColor(sf::Color::Red);
    StaticArrayTitle.setFillColor(sf::Color::White);
    StaticArrayTitle.setOrigin(StaticArrayTitle.getLocalBounds().width / 2.f, StaticArrayTitle.getLocalBounds().height / 2.f);
    StaticArrayTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // #2. Dynamic array rectangle
    sf::RectangleShape rect2(sf::Vector2f(rectWidth, rectHeight));
    rect2.setFillColor(sf::Color(218, 83, 44));
    rect2.setOrigin(rect2.getSize().x, 0.f);
    rect2.setPosition(startX1, startY1 + rectHeight + padding);
    sf::Text rect2_text("Dynamic array", font, 40);
    rect2_text.setFillColor(sf::Color::White);
    rect2_text.setOrigin(rect2_text.getLocalBounds().width / 2.f, rect2_text.getLocalBounds().height / 2.f);
    rect2_text.setPosition(rect2.getPosition().x - rect2.getSize().x / 2.f, rect2.getPosition().y + rect2.getSize().y / 2.f - rect2_text.getLocalBounds().height / 2.f);
    // menu
    sf::Text DynamicArrayTitle("Dynamic Array", font, 90);
    DynamicArrayTitle.setOutlineThickness(3);
    DynamicArrayTitle.setOutlineColor(sf::Color::Red);
    DynamicArrayTitle.setFillColor(sf::Color::White);
    DynamicArrayTitle.setOrigin(DynamicArrayTitle.getLocalBounds().width / 2.f, DynamicArrayTitle.getLocalBounds().height / 2.f);
    DynamicArrayTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // #3. Singly linked list rectangle
    sf::RectangleShape rect3(sf::Vector2f(rectWidth, rectHeight));
    rect3.setFillColor(sf::Color(160, 0, 167));
    rect3.setOrigin(rect3.getSize().x, 0.f);
    rect3.setPosition(startX1, startY1 + (rectHeight + padding) * 2.f);
    sf::Text rect3_text("Singly linked list", font, 40);
    rect3_text.setFillColor(sf::Color::White);
    rect3_text.setOrigin(rect3_text.getLocalBounds().width / 2.f, rect3_text.getLocalBounds().height / 2.f);
    rect3_text.setPosition(rect3.getPosition().x - rect3.getSize().x / 2.f, rect3.getPosition().y + rect3.getSize().y / 2.f - rect3_text.getLocalBounds().height / 2.f);
    // menu
    sf::Text SingleLLTitle("Singly Linked List", font, 90);
    SingleLLTitle.setOutlineThickness(3);
    SingleLLTitle.setOutlineColor(sf::Color::Red);
    SingleLLTitle.setFillColor(sf::Color::White);
    SingleLLTitle.setOrigin(SingleLLTitle.getLocalBounds().width / 2.f, SingleLLTitle.getLocalBounds().height / 2.f);
    SingleLLTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // #4. Doubly linked list rectangle
    sf::RectangleShape rect4(sf::Vector2f(rectWidth, rectHeight));
    rect4.setFillColor(sf::Color(186, 29, 71));
    rect4.setPosition(startX2, startY2);
    sf::Text rect4_text("Doubly linked list", font, 40);
    rect4_text.setFillColor(sf::Color::White);
    rect4_text.setOrigin(rect4_text.getLocalBounds().width / 2.f, rect4_text.getLocalBounds().height / 2.f);
    rect4_text.setPosition(rect4.getPosition().x + rect4.getSize().x / 2.f, rect4.getPosition().y + rect4.getSize().y / 2.f - rect4_text.getLocalBounds().height / 2.f);
    // menu
    sf::Text DoublyLLTitle("Doubly Linked List", font, 90);
    DoublyLLTitle.setOutlineThickness(3);
    DoublyLLTitle.setOutlineColor(sf::Color::Red);
    DoublyLLTitle.setFillColor(sf::Color::White);
    DoublyLLTitle.setOrigin(DoublyLLTitle.getLocalBounds().width / 2.f, DoublyLLTitle.getLocalBounds().height / 2.f);
    DoublyLLTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // #5. Circular linked list rectangle
    sf::RectangleShape rect5(sf::Vector2f(rectWidth, rectHeight));
    rect5.setFillColor(sf::Color(124, 192, 204));
    rect5.setPosition(startX2, startY2 + rectHeight + padding);
    sf::Text rect5_text("Circular linked list", font, 40);
    rect5_text.setFillColor(sf::Color::White);
    rect5_text.setOrigin(rect5_text.getLocalBounds().width / 2.f, rect5_text.getLocalBounds().height / 2.f);
    rect5_text.setPosition(rect5.getPosition().x + rect5.getSize().x / 2.f, rect5.getPosition().y + rect5.getSize().y / 2.f - rect5_text.getLocalBounds().height / 2.f);
    // menu
    sf::Text CircularLLTitle("Circular Linked List", font, 90);
    CircularLLTitle.setOutlineThickness(3);
    CircularLLTitle.setOutlineColor(sf::Color::Red);
    CircularLLTitle.setFillColor(sf::Color::White);
    CircularLLTitle.setOrigin(CircularLLTitle.getLocalBounds().width / 2.f, CircularLLTitle.getLocalBounds().height / 2.f);
    CircularLLTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // #6. Stack rectangle
    sf::RectangleShape rect6(sf::Vector2f(rectWidth, rectHeight));
    rect6.setFillColor(sf::Color(0, 160, 0));
    rect6.setPosition(startX2, startY2 + (rectHeight + padding) * 2.f);
    sf::Text rect6_text("Stack", font, 40);
    rect6_text.setFillColor(sf::Color::White);
    rect6_text.setOrigin(rect6_text.getLocalBounds().width / 2.f, rect6_text.getLocalBounds().height / 2.f);
    rect6_text.setPosition(rect6.getPosition().x + rect6.getSize().x / 2.f, rect6.getPosition().y + rect6.getSize().y / 2.f - rect6_text.getLocalBounds().height / 2.f);
    // menu
    sf::Text StackTitle("Stack", font, 90);
    StackTitle.setOutlineThickness(3);
    StackTitle.setOutlineColor(sf::Color::Red);
    StackTitle.setFillColor(sf::Color::White);
    StackTitle.setOrigin(StackTitle.getLocalBounds().width / 2.f, StackTitle.getLocalBounds().height / 2.f);
    StackTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // #7. Queue rectangle
    sf::RectangleShape rect7(sf::Vector2f(rectWidth + padding*2, rectHeight));
    rect7.setFillColor(sf::Color(38, 116, 236));
    rect7.setOrigin(rect7.getSize().x / 2.f, 0.f);
    rect7.setPosition(window.getSize().x / 2.f,  startY2 + (rectHeight + padding) * 3.f);
    sf::Text rect7_text("Queue", font, 40);
    rect7_text.setFillColor(sf::Color::White);
    rect7_text.setOrigin(rect7_text.getLocalBounds().width / 2.f, rect7_text.getLocalBounds().height / 2.f);
    rect7_text.setPosition(rect7.getPosition().x, rect7.getPosition().y + rect7.getSize().y / 2.f - rect7_text.getLocalBounds().height / 2.f);
    // menu
    sf::Text QueueTitle("Queue", font, 90);
    QueueTitle.setOutlineThickness(3);
    QueueTitle.setOutlineColor(sf::Color::Red);
    QueueTitle.setFillColor(sf::Color::White);
    QueueTitle.setOrigin(QueueTitle.getLocalBounds().width / 2.f, QueueTitle.getLocalBounds().height / 2.f);
    QueueTitle.setPosition(window.getSize().x / 2.f, 50.f);

    // control menu
    // #1
    sf::RectangleShape ControlMenu_btn1(sf::Vector2f(200.f, 50.f));
    ControlMenu_btn1.setFillColor(sf::Color(255, 138, 39));
    ControlMenu_btn1.setPosition(150.f, window.getSize().y / 2.f + 100.f);
    sf::Text Func1_text("Create", font, 23);
    Func1_text.setFillColor(sf::Color::White);
    Func1_text.setOrigin(Func1_text.getLocalBounds().width / 2.f, Func1_text.getLocalBounds().height / 2.f);
    Func1_text.setPosition(ControlMenu_btn1.getPosition().x + ControlMenu_btn1.getSize().x / 2.f, ControlMenu_btn1.getPosition().y + ControlMenu_btn1.getSize(). y / 2.f - Func1_text.getLocalBounds().height / 2.f);
    
    sf::RectangleShape CreateEmpty(sf::Vector2f(130.f, 50.f));
    CreateEmpty.setFillColor(sf::Color(255, 138, 39));
    CreateEmpty.setPosition(ControlMenu_btn1.getPosition().x + ControlMenu_btn1.getSize().x +20.f, ControlMenu_btn1.getPosition().y);
    sf::Text CreateEmptyText("Empty", font, 23);
    CreateEmptyText.setFillColor(sf::Color::White);
    CreateEmptyText.setOrigin(CreateEmptyText.getLocalBounds().width / 2.f, CreateEmptyText.getLocalBounds().height / 2.f);
    CreateEmptyText.setPosition(CreateEmpty.getPosition().x + CreateEmpty.getSize().x / 2.f, CreateEmpty.getPosition().y + CreateEmpty.getSize().y / 2.f - CreateEmptyText.getLocalBounds().height / 2.f);

    sf::RectangleShape CreateRandom(sf::Vector2f(150.f, 50.f));
    sf::RectangleShape CreateRandomSort(sf::Vector2f(180.f, 50.f));
    sf::RectangleShape CreateRandomFixedSize(sf::Vector2f(200.f, 50.f));
    sf::RectangleShape CreateUserDefinedList(sf::Vector2f(200.f, 50.f));

    // #2
    sf::RectangleShape ControlMenu_btn2(sf::Vector2f(200.f, 50.f));
    ControlMenu_btn2.setFillColor(sf::Color(255, 138, 39));
    ControlMenu_btn2.setPosition(150.f, window.getSize().y / 2.f + 150.f);
    sf::Text Func2_text("Add", font, 23);
    Func2_text.setFillColor(sf::Color::White);
    Func2_text.setOrigin(Func2_text.getLocalBounds().width / 2.f, Func2_text.getLocalBounds().height / 2.f);
    Func2_text.setPosition(ControlMenu_btn2.getPosition().x + ControlMenu_btn2.getSize().x / 2.f, ControlMenu_btn1.getPosition().y + ControlMenu_btn1.getSize(). y / 2.f - Func1_text.getLocalBounds().height / 2.f + 50.f);
    // #3
    sf::RectangleShape ControlMenu_btn3(sf::Vector2f(200.f, 50.f));
    ControlMenu_btn3.setFillColor(sf::Color(255, 138, 39));
    ControlMenu_btn3.setPosition(150.f, window.getSize().y / 2.f + 200.f);
    sf::Text Func3_text("Delete", font, 23);
    Func3_text.setFillColor(sf::Color::White);
    Func3_text.setOrigin(Func3_text.getLocalBounds().width / 2.f, Func3_text.getLocalBounds().height / 2.f);
    Func3_text.setPosition(ControlMenu_btn3.getPosition().x + ControlMenu_btn3.getSize().x / 2.f, ControlMenu_btn1.getPosition().y + ControlMenu_btn1.getSize(). y / 2.f - Func1_text.getLocalBounds().height / 2.f + 100.f);
    // #4
    sf::RectangleShape ControlMenu_btn4(sf::Vector2f(200.f, 50.f));
    ControlMenu_btn4.setFillColor(sf::Color(255, 138, 39));
    ControlMenu_btn4.setPosition(150.f, window.getSize().y / 2.f + 250.f);
    sf::Text Func4_text("Update", font, 23);
    Func4_text.setFillColor(sf::Color::White);
    Func4_text.setOrigin(Func4_text.getLocalBounds().width / 2.f, Func4_text.getLocalBounds().height / 2.f);
    Func4_text.setPosition(ControlMenu_btn4.getPosition().x + ControlMenu_btn4.getSize().x / 2.f, ControlMenu_btn1.getPosition().y + ControlMenu_btn1.getSize(). y / 2.f - Func1_text.getLocalBounds().height / 2.f + 150.f);
    // #5
    sf::RectangleShape ControlMenu_btn5(sf::Vector2f(200.f, 50.f));
    ControlMenu_btn5.setFillColor(sf::Color(255, 138, 39));
    ControlMenu_btn5.setPosition(150.f, window.getSize().y / 2.f + 300.f);
    sf::Text Func5_text("Search", font, 23);
    Func5_text.setFillColor(sf::Color::White);
    Func5_text.setOrigin(Func5_text.getLocalBounds().width / 2.f, Func5_text.getLocalBounds().height / 2.f);
    Func5_text.setPosition(ControlMenu_btn5.getPosition().x + ControlMenu_btn5.getSize().x / 2.f, ControlMenu_btn1.getPosition().y + ControlMenu_btn1.getSize(). y / 2.f - Func1_text.getLocalBounds().height / 2.f + 200.f);

    
    Node v[10];
    int n = 0;
    CreateRandomNode(v, n, font);
    sortArray(v, n);

    enum ScreenState { Menu, Start, Settings, DV1, DV2, DV3, DV4, DV5, DV6, DV7 };
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
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        if (rect1.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV1;
                        } 
                        if (rect2.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV2;
                        } 
                        if (rect3.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV3;
                        } 
                        if (rect4.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV4;
                        } 
                        if (rect5.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV5;
                        } 
                        if (rect6.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV6;
                        } 
                        if (rect7.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV7;
                        } 
                        break;

                    case Settings:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        break;
                    case DV1:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV2:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV3:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        if (CreateEmpty.getGlobalBounds().contains(mousePos))
                        {
                            CreateRandomNode(v, n, font);
                        }
                        break;
                    case DV4:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV5:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV6:
                        if (backButton.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV7:
                        if (backButton.getGlobalBounds().contains(mousePos))
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
                        if (ControlMenu_btn1.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn1.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn1.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn2.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn2.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn2.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn3.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn3.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn3.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn4.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn4.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn4.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (ControlMenu_btn5.getGlobalBounds().contains(mousePos))
                        {
                            ControlMenu_btn5.setFillColor(sf::Color::Black);
                        } else {
                            ControlMenu_btn5.setFillColor(sf::Color(255, 138, 39));
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
                window.draw(settingsButton.rect);
                window.draw(settingsButton.text);
                window.draw(startButton.rect);
                window.draw(startButton.text);
                break;

            case Start:
                window.draw(backButton);
                window.draw(StartTitle);
                window.draw(backText);
                window.draw(rect1);
                window.draw(rect1_text);
                window.draw(rect2);
                window.draw(rect2_text);
                window.draw(rect3);
                window.draw(rect3_text);
                window.draw(rect4);
                window.draw(rect4_text);
                window.draw(rect5);
                window.draw(rect5_text);
                window.draw(rect6);
                window.draw(rect6_text);
                window.draw(rect7);
                window.draw(rect7_text);
                break;  
            case Settings:
                window.draw(SettingTitle);
                window.draw(backButton);
                window.draw(backText);
                break;
            case DV1: // Static Array
                window.draw(backButton);
                window.draw(backText);
                window.draw(StaticArrayTitle);
                break;
            case DV2: // Dynamic Array
                window.draw(backButton);
                window.draw(backText);
                window.draw(DynamicArrayTitle);
                break;
            case DV3: // Singly LL
                window.draw(backButton);
                window.draw(backText);
                window.draw(SingleLLTitle);
                window.draw(ControlMenu_btn1);
                window.draw(Func1_text);
                window.draw(CreateEmpty);
                window.draw(CreateEmptyText);
                window.draw(ControlMenu_btn2);
                window.draw(Func2_text);
                window.draw(ControlMenu_btn3);
                window.draw(Func3_text);
                window.draw(ControlMenu_btn4);
                window.draw(Func4_text);
                window.draw(ControlMenu_btn5);
                window.draw(Func5_text);
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
                        line[0].color.a = 200;
                        line[1].color.a = 200;
                        line[0].texCoords = sf::Vector2f(0.f, 0.f);
                        line[1].texCoords = sf::Vector2f(30.f, 30.f);
                        window.draw(line);
                    }
                }
                break;
            case DV4: // Doubly LL
                window.draw(backButton);
                window.draw(backText);
                window.draw(DoublyLLTitle);
                break;
            case DV5: // Circular LL
                window.draw(backButton);
                window.draw(backText);
                window.draw(CircularLLTitle);
                break;
            case DV6: // Stack
                window.draw(backButton);
                window.draw(backText);
                window.draw(StackTitle);
                break;
            case DV7: // Queue
                window.draw(backButton);
                window.draw(backText);
                window.draw(QueueTitle);
                break;
            default:
                break;
        }
        window.display();
    }
    return 0;
}