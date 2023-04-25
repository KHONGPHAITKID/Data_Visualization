#include "header.hpp"

//---
MenuPage::MenuPage()
{
    if (!this->font.loadFromFile("Fonts/iCielBCCubano_Normal.otf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }

    if (!this->titlefont.loadFromFile("Fonts/SVN_Blade_runner.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }

    if (!page2texture.loadFromFile("media/img/menubackground.jpg")) // Replace "background.jpg" with the path to your image file
    {
        std::cerr << "Failed to load BackGround" << "\n";
        return;
    }

    sf::Text temp("Data Visualization", this->font, 120);
    CreateTitle(temp, 1920 / 2.f, 250.f);
    this->Title = temp;

    this->startButton.CreateButton(600, 120, 1920 / 2.f, 530, sf::Color(106, 231, 255, 0), "Start", titlefont, sf::Color(106, 231, 255));
    this->startButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->startButton.rect.setOutlineThickness(5);
    this->startButton.setSize(60);

    this->settingsButton.CreateButton(600, 120, 960, startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, sf::Color(106, 231, 255, 0), "Setting", titlefont, sf::Color(106, 231, 255));
    this->settingsButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->settingsButton.rect.setOutlineThickness(5);
    this->settingsButton.setSize(60);

    this->aboutButton.CreateButton(600, 120, 960, settingsButton.rect.getPosition().y + settingsButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, sf::Color(106, 231, 255, 0), "About", titlefont, sf::Color(106, 231, 255));
    this->aboutButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->aboutButton.rect.setOutlineThickness(5);
    this->aboutButton.setSize(60);
}
void MenuPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    this->settingsButton.displayButton(window);
    this->startButton.displayButton(window);
    this->aboutButton.displayButton(window);
}
void MenuPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->startButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
            DefaultBackground.setTexture(this->page2texture);
        }
        else if (this->settingsButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Settings;
            DefaultBackground.setTexture(this->page2texture);
        }
        else if (this->aboutButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = About;
            DefaultBackground.setTexture(this->page2texture);
        }
    }
    if (event.type == sf::Event::MouseMoved)
    {
        //------
        if (this->startButton.rect.getGlobalBounds().contains(mousePos))
        {
            this->startButton.rect.setFillColor(sf::Color(106, 231, 255));
            this->startButton.text.setFillColor(sf::Color::Black);
            this->startButton.rect.setScale(1.1, 1.1);
        } 
        else {
            this->startButton.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->startButton.text.setFillColor(sf::Color(106, 231, 255));
            this->startButton.rect.setScale(1, 1);
        }
        //-------
        if (this->settingsButton.rect.getGlobalBounds().contains(mousePos))
        {
            this->settingsButton.rect.setFillColor(sf::Color(106, 231, 255));
            this->settingsButton.text.setFillColor(sf::Color::Black);
            this->settingsButton.rect.setScale(1.1, 1.1);
        } else {
            this->settingsButton.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->settingsButton.text.setFillColor(sf::Color(106, 231, 255));
            this->settingsButton.rect.setScale(1, 1);
        }
        if (this->aboutButton.rect.getGlobalBounds().contains(mousePos))
        {
            this->aboutButton.rect.setFillColor(sf::Color(106, 231, 255));
            this->aboutButton.text.setFillColor(sf::Color::Black);
            this->aboutButton.rect.setScale(1.1, 1.1);
        } else {
            this->aboutButton.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->aboutButton.text.setFillColor(sf::Color(106, 231, 255));
            this->aboutButton.rect.setScale(1, 1);
        }
    }

}
//---

SettingPage::SettingPage()
{
    if (!this->font.loadFromFile("Fonts/iCielBCCubano_Normal.otf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }

    if (!this->titlefont.loadFromFile("Fonts/SVN_Blade_runner.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }

    if (!page1texture.loadFromFile("media/img/background1.jpg")) // Replace "background.jpg" with the path to your image file
    {
        std::cerr << "Failed to load BackGround" << "\n";
        return ;
    }

    //Title
    sf::Text SettingTitle("Setting", this->titlefont, 130);
    CreateTitle(SettingTitle, 1920 / 2.f, 250.f);
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
            currentState = Menu;
            DefaultBackground.setTexture(page1texture);
        }
    }
}

StartingPage::StartingPage()
{
    //Font
    if (!this->font.loadFromFile("Fonts/iCielBCCubano_Normal.otf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }

    if (!this->titlefont.loadFromFile("Fonts/SVN_Blade_runner.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }


    // background
    if (!page1texture.loadFromFile("media/img/background1.jpg")) // Replace "background.jpg" with the path to your image file
    {
        std::cerr << "Failed to load BackGround" << "\n";
        return ;
    }
    if (!page3texture.loadFromFile("media/img/background2.jpg")) // Replace "background.jpg" with the path to your image file
    {
        std::cerr << "Failed to load BackGround" << "\n";
        return ;
    }

    //Title
    sf::Text StartTitle("Menu", this->titlefont, 130);
    CreateTitle(StartTitle, 1920 / 2.f, 250.f);
    this->Title = StartTitle;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);

    // Option
    // Rectangle dimensions
    const float rectWidth = 450.f;
    const float rectHeight = 90.f;
    const float padding = 40.f;
    // Start position
    const float startX1 = 1920 / 2.f - padding - rectWidth / 2.f - 70.f;
    const float startY1 = StartTitle.getPosition().y + StartTitle.getLocalBounds().height / 2.f + padding * 2 + rectHeight / 2.f;
    const float startX2 = 1920 / 2.f + rectWidth / 2.f + 70.f;
    const float startY2 = StartTitle.getPosition().y + StartTitle.getLocalBounds().height / 2.f + padding * 2 + rectHeight / 2.f;

    // #1. Static array rectangle
    rect1.CreateButton(rectWidth, rectHeight, startX1, startY1, sf::Color(0, 154, 172, 0), "Static Array", font, sf::Color(106, 231, 255));
    rect1.rect.setOutlineColor(sf::Color(106, 231, 255));
    rect1.rect.setOutlineThickness(5);
    rect1.setSize(40);
    
    // #2. Dynamic array rectangle
    rect2.CreateButton(rectWidth, rectHeight, startX1, startY1 + rectHeight + padding, sf::Color(218, 83, 44, 0), "Dynamic Array", font, sf::Color(106, 231, 255));
    rect2.rect.setOutlineColor(sf::Color(106, 231, 255));
    rect2.rect.setOutlineThickness(5);
    rect2.setSize(40);
    // #3. Singly linked list rectangle
    rect3.CreateButton(rectWidth, rectHeight, startX1, startY1 + (rectHeight + padding) * 2.f, sf::Color(160, 0, 167, 0), "Singly Linked List", font, sf::Color(106, 231, 255));
    rect3.rect.setOutlineColor(sf::Color(106, 231, 255));
    rect3.rect.setOutlineThickness(5);
    rect3.setSize(40);
    // #4. Doubly linked list rectangle
    rect4.CreateButton(rectWidth, rectHeight, startX2, startY2, sf::Color(186, 29, 71, 0), "Doubly Linked List", font, sf::Color(106, 231, 255));
    rect4.rect.setOutlineColor(sf::Color(106, 231, 255));
    rect4.rect.setOutlineThickness(5);
    rect4.setSize(40);
    // #5. Circular linked list rectangle
    rect5.CreateButton(rectWidth, rectHeight, startX2, startY2 + rectHeight + padding, sf::Color(124, 192, 204, 0), "Circular Linked List", font, sf::Color(106, 231, 255));
    rect5.rect.setOutlineColor(sf::Color(106, 231, 255));
    rect5.rect.setOutlineThickness(5);
    rect5.setSize(40);
    // #6. Stack rectangle
    rect6.CreateButton(rectWidth, rectHeight, startX2, startY2 + (rectHeight + padding) * 2.f, sf::Color(0, 160, 0, 0), "Stack", font, sf::Color(106, 231, 255));
    rect6.rect.setOutlineColor(sf::Color(106, 231, 255));
    rect6.rect.setOutlineThickness(5);
    rect6.setSize(40);
    // #7. Queue rectangle
    rect7.CreateButton(rectWidth + padding*2, rectHeight, 1920 / 2.f,  startY2 + (rectHeight + padding) * 3.f, sf::Color(38, 116, 236, 0), "Queue", font, sf::Color(106, 231, 255));
    rect7.rect.setOutlineColor(sf::Color(106, 231, 255));
    rect7.rect.setOutlineThickness(5);
    rect7.setSize(40);
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
            DefaultBackground.setTexture(page1texture);
        }
        if (this->rect1.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV1;
            DefaultBackground.setTexture(page3texture);
        } 
        if (this->rect2.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV2;
            DefaultBackground.setTexture(page3texture);
        } 
        if (this->rect3.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV3;
            DefaultBackground.setTexture(page3texture);
        } 
        if (this->rect4.rect.getGlobalBounds().contains(mousePos))
        {
            DefaultBackground.setTexture(page3texture);
            currentState = DV4;
        } 
        if (this->rect5.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV5;
            DefaultBackground.setTexture(page3texture);
        } 
        if (this->rect6.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV6;
            DefaultBackground.setTexture(page3texture);
        } 
        if (this->rect7.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV7;
            DefaultBackground.setTexture(page3texture);
        } 
    }
    if (event.type == sf::Event::MouseMoved)
    {
        //------
        if (this->rect1.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect1.rect.setFillColor(sf::Color(106, 231, 255));
            this->rect1.text.setFillColor(sf::Color::Black);
            this->rect1.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect1.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->rect1.text.setFillColor(sf::Color(106, 231, 255));
            this->rect1.rect.setScale(1, 1);
        }
        if (this->rect2.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect2.rect.setFillColor(sf::Color(106, 231, 255));
            this->rect2.text.setFillColor(sf::Color::Black);
            this->rect2.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect2.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->rect2.text.setFillColor(sf::Color(106, 231, 255));
            this->rect2.rect.setScale(1, 1);
        }
        if (this->rect3.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect3.rect.setFillColor(sf::Color(106, 231, 255));
            this->rect3.text.setFillColor(sf::Color::Black);
            this->rect3.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect3.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->rect3.text.setFillColor(sf::Color(106, 231, 255));
            this->rect3.rect.setScale(1, 1);
        }
        if (this->rect4.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect4.rect.setFillColor(sf::Color(106, 231, 255));
            this->rect4.text.setFillColor(sf::Color::Black);
            this->rect4.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect4.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->rect4.text.setFillColor(sf::Color(106, 231, 255));
            this->rect4.rect.setScale(1, 1);
        }
        if (this->rect5.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect5.rect.setFillColor(sf::Color(106, 231, 255));
            this->rect5.text.setFillColor(sf::Color::Black);
            this->rect5.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect5.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->rect5.text.setFillColor(sf::Color(106, 231, 255));
            this->rect5.rect.setScale(1, 1);
        }
        if (this->rect6.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect6.rect.setFillColor(sf::Color(106, 231, 255));
            this->rect6.text.setFillColor(sf::Color::Black);
            this->rect6.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect6.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->rect6.text.setFillColor(sf::Color(106, 231, 255));
            this->rect6.rect.setScale(1, 1);
        }
        if (this->rect7.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect7.rect.setFillColor(sf::Color(106, 231, 255));
            this->rect7.text.setFillColor(sf::Color::Black);
            this->rect7.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect7.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->rect7.text.setFillColor(sf::Color(106, 231, 255));
            this->rect7.rect.setScale(1, 1);
        }
    }   
}

AboutPage::AboutPage()
{
    if (!this->font.loadFromFile("Fonts/iCielBCCubano_Normal.otf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }

    if (!this->titlefont.loadFromFile("Fonts/SVN_Blade_runner.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }

    if (!page1texture.loadFromFile("media/img/background1.jpg")) // Replace "background.jpg" with the path to your image file
    {
        std::cerr << "Failed to load BackGround" << "\n";
        return ;
    }

    //Title
    sf::Text SettingTitle("About me", this->titlefont, 100);
    CreateTitle(SettingTitle, 1920 / 2.f, 250.f);
    this->Title = SettingTitle;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void AboutPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    this->backButton.displayButton(window);
}

void AboutPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Menu;
            DefaultBackground.setTexture(page1texture);
        }
    }
}
