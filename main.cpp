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

    currentState = Menu;

    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return 1;
    }

    //----------TESTING------------

    //----------TESTING------------

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
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //----
            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
            switch (currentState)
            {
                case Menu:
                    menu.handleEvent(window, mousePos, event);
                    break;
                case Start:
                    StartMenu.handleEvent(window, mousePos, event);
                    break;
                case Settings:
                    setting.handleEvent(window, mousePos, event);
                    break;
                case DV1:
                    dv1.handleEvent(window, mousePos, event);
                    break;
                case DV2:
                    dv2.handleEvent(window, mousePos, event);
                    break;
                case DV3:
                    dv3.handleEvent(window, mousePos, event);
                    break;
                case DV4:
                    dv4.handleEvent(window, mousePos, event);
                    break;
                case DV5:
                    dv5.handleEvent(window, mousePos, event);
                    break;
                case DV6:
                    dv6.handleEvent(window, mousePos, event);
                    break;
                case DV7:
                    dv7.handleEvent(window, mousePos, event);
                    break;  
                default:
                    break;
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //-----------------
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
                dv4.drawNodes(window);
                break;
            case DV5: // Circular LL
                dv5.display(window);
                dv5.drawNodes(window);
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