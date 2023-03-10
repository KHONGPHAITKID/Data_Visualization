#include "header.hpp"

sf::Font font;
sf::Color BackGroundColor = sf::Color(22, 73, 154);
const sf::Color Pink1(253, 0, 112);
const sf::Color Purple1(104, 0, 120);
Node v[10];
int n = 0;

int main()
{
    srand(time(NULL)); // Random number generator
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
    StartPage start;
    DataVisualization_1 dv1;
    DataVisualization_2 dv2;
    DataVisualization_3 dv3;
    DataVisualization_4 dv4;
    DataVisualization_5 dv5;
    DataVisualization_6 dv6;
    DataVisualization_7 dv7;

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
                        if (start.backButton.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = Menu;
                        }
                        if (start.rect1.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV1;
                        } 
                        if (start.rect2.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV2;
                        } 
                        if (start.rect3.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV3;
                        } 
                        if (start.rect4.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV4;
                        } 
                        if (start.rect5.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV5;
                        } 
                        if (start.rect6.rect.getGlobalBounds().contains(mousePos))
                        {
                            currentState = DV6;
                        } 
                        if (start.rect7.rect.getGlobalBounds().contains(mousePos))
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
                            dv3.CreateEmpty.display = !dv3.CreateEmpty.display;
                            dv3.CreateRadom.display = !dv3.CreateRadom.display;
                            dv3.CreateRandomFixedSize.display = !dv3.CreateRandomFixedSize.display;
                            dv3.CreateRandomSort.display = !dv3.CreateRandomSort.display;
                            dv3.CreateUserDefinedList.display = !dv3.CreateUserDefinedList.display;
                        }
                        if (dv3.CreateEmpty.display)
                        {
                            if (dv3.CreateEmpty.rect.getGlobalBounds().contains(mousePos))
                            {
                                n = 0;
                            }
                            if (dv3.CreateRadom.rect.getGlobalBounds().contains(mousePos))
                            {
                                CreateRandomNodes(v, n, font);
                            }
                            if (dv3.CreateRandomSort.rect.getGlobalBounds().contains(mousePos))
                            {
                                CreateRandomSortNodes(v, n, font);
                            }
                        }
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
                switch (currentState){
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
                start.display(window);
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