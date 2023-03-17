#include "header.hpp"

sf::Font font;
sf::Color BackGroundColor = sf::Color(22, 73, 154);
const sf::Color Pink1(253, 0, 112);
const sf::Color Purple1(104, 0, 120);

int main()
{
    srand(time(NULL)); // Random number generate
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Data Visualization", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    enum ScreenState { Menu, Start, Settings, DV1, DV2, DV3, DV4, DV5, DV6, DV7 };
    ScreenState currentState = Menu;
    
    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return 1;
    }

    MenuPage menu;
    SettingPage setting;
    StartingPage StartMenu;
    DataVisualization_1 dv1;
    DataVisualization_2 dv2;
    DataVisualization_3 dv3;
    DataVisualization_4 dv4;
    DataVisualization_5 dv5;
    DataVisualization_6 dv6;
    DataVisualization_7 dv7;


//---------------------------
    // int n = 0;
    // SLL_Node* temp = nullptr;
    // CreateRandomNodes(dv3.NodeArray, dv3.size, dv3.font);
    // SLL_Node* curr = dv3.NodeArray;
    // while (curr != nullptr) {
    //     std::cout << curr->data << " ";
    //     curr = curr->next;
    // }
    // std::cout << std::endl;
//---------------------------
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
                        if (menu.startButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        else if (menu.settingsButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Settings;
                        }
                        break;

                    case Start:
                        if (StartMenu.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        if (StartMenu.rect1.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV1;
                        } 
                        if (StartMenu.rect2.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV2;
                        } 
                        if (StartMenu.rect3.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV3;
                        } 
                        if (StartMenu.rect4.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV4;
                        } 
                        if (StartMenu.rect5.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV5;
                        } 
                        if (StartMenu.rect6.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV6;
                        } 
                        if (StartMenu.rect7.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV7;
                        } 
                        break;

                    case Settings:
                        if (setting.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        break;
                    case DV1:
                        if (dv1.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV2:
                        if (dv2.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV3:
                        if (dv3.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        if (dv3.ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.funcstate = 1;
                        }
                        if (dv3.ControlMenu_btn2.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.funcstate = 2;
                        }
                        if (dv3.ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.funcstate = 3;
                        }
                        if (dv3.ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.funcstate = 4;
                        }
                        if (dv3.ControlMenu_btn5.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.funcstate = 5;
                        }
                        dv3.handleEvent(window, mousePos, event);
                        break;
                    case DV4:
                        if (dv4.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV5:
                        if (dv5.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV6:
                        if (dv6.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;
                    case DV7:
                        if (dv7.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Start;
                        }
                        break;                    
                }
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                switch (currentState)
                {
                    case DV3:
                        if (dv3.ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.ControlMenu_btn1.rect.setFillColor(sf::Color::Black);
                        } else {
                            dv3.ControlMenu_btn1.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (dv3.ControlMenu_btn2.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.ControlMenu_btn2.rect.setFillColor(sf::Color::Black);
                        } else {
                            dv3.ControlMenu_btn2.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (dv3.ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.ControlMenu_btn3.rect.setFillColor(sf::Color::Black);
                        } else {
                            dv3.ControlMenu_btn3.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (dv3.ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.ControlMenu_btn4.rect.setFillColor(sf::Color::Black);
                        } else {
                            dv3.ControlMenu_btn4.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        if (dv3.ControlMenu_btn5.rect.getGlobalBounds().contains(mousePos))
                        {
                            dv3.ControlMenu_btn5.rect.setFillColor(sf::Color::Black);
                        } else {
                            dv3.ControlMenu_btn5.rect.setFillColor(sf::Color(255, 138, 39));
                        }
                        break;
                }
            }
        }
        window.clear(BackGroundColor);
        switch (currentState)
        {
            case Menu:
                menu.display(window);
                break;
            case Start:
                StartMenu.display(window);
                break;  
            case Settings:
                setting.display(window);
                break;
            case DV1: // Static Array
                dv1.display(window);
                break;
            case DV2: // Dynamic Array
                dv2.display(window);
                break;
            case DV3: // Singly LL
                dv3.display(window);
                dv3.drawNodes(window);
                break;
            case DV4: // Doubly LL
                dv4.display(window);
                break;
            case DV5: // Circular LL
                dv5.display(window);
                break;
            case DV6: // Stack
                dv6.display(window);
                break;
            case DV7: // Queue
                dv7.display(window);
                break;
            default:
                break;
        }
        window.display();
    }
    return 0;
}