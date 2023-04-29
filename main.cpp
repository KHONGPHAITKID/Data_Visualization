#include "header.hpp"

int main()
{
    currentState = Menu;
    srand(time(NULL)); // Random number generate
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Data Visualization", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

// Set icon
    sf::Image icon;
    if (!icon.loadFromFile("media/img/binary.png"))
    {
        std::cerr << "Failed to load image" << "\n";
        return 1;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

// Load background1

    if (!BackGround0.loadFromFile("media/img/background1.jpg")) 
    {
        std::cerr << "Failed to load BackGround0" << "\n";
        return 1;
    }
    if (!BackGround1.loadFromFile("media/img/menubackground.jpg")) 
    {
        std::cerr << "Failed to load BackGround2" << "\n";
        return 1;
    }
    if (!BackGround2.loadFromFile("media/img/background2.jpg")) 
    {
        std::cerr << "Failed to load BackGround1" << "\n";
        return 1;
    }
    DefaultBackground.setTexture(BackGround0);    
    ButtonColor = sf::Color(106, 231, 255, 0);
    ButtonOutlineColor = sf::Color(106, 231, 255);
    MainColor = sf::Color(106, 231, 255);

    if (!defautFont.loadFromFile("Fonts/iCielBCCubano_Normal.otf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return 0;
    }

    if (!defautTitleFont.loadFromFile("Fonts/SVN_Blade_runner.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return 0;
    }

    //----------TESTING------------
    // sf::ColorPicker colorPicker;
    // colorPicker.setPosition(100, 100);
    // colorPicker.setFillColor(sf::Color::White);
    //----------TESTING------------

    MenuPage menu;
    SettingPage setting;
    StartingPage StartMenu;
    AboutPage aboutMenu;
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
                case About:
                    aboutMenu.handleEvent(window, mousePos, event);
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
        window.clear();
        window.draw(DefaultBackground);
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
            case About:
                aboutMenu.display(window);
                break;
            case DV1: // Static Array
                dv1.display(window);
                dv1.drawArray(window);
                break;
            case DV2: // Dynamic Array
                dv2.display(window);
                dv2.drawVector(window);
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
                dv6.drawNodes(window);
                break;
            case DV7: // Queue
                dv7.display(window);
                dv7.drawNodes(window);
                break;
            default:
                break;
        }
    window.display();
    }
    return 0;
}