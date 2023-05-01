#include "header.hpp"

MenuPage::MenuPage()
{
    this->font = defautFont;
    this->titlefont = defautTitleFont;

    sf::Text temp("Data Visualization", this->font, 120);
    CreateTitle(temp, 1920 / 2.f, 250.f);
    this->Title = temp;

    this->startButton.CreateButton(600, 120, 1920 / 2.f, 530, ButtonColor, "Start", titlefont, MainColor);
    this->startButton.rect.setOutlineColor(ButtonOutlineColor);
    this->startButton.rect.setOutlineThickness(5);
    this->startButton.setSize(60);

    this->settingsButton.CreateButton(600, 120, 960, startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, ButtonColor, "Setting", titlefont, MainColor);
    this->settingsButton.rect.setOutlineColor(ButtonOutlineColor);
    this->settingsButton.rect.setOutlineThickness(5);
    this->settingsButton.setSize(60);

    this->aboutButton.CreateButton(600, 120, 960, settingsButton.rect.getPosition().y + settingsButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, ButtonColor, "About", titlefont, MainColor);
    this->aboutButton.rect.setOutlineColor(ButtonOutlineColor);
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
            DefaultBackground.setTexture(BackGround1);
        }
        else if (this->settingsButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Settings;
            DefaultBackground.setTexture(BackGround1);
        }
        else if (this->aboutButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = About;
            DefaultBackground.setTexture(BackGround1);
        }
    }
    if (event.type == sf::Event::MouseMoved)
    {
        //------
        if (this->startButton.rect.getGlobalBounds().contains(mousePos))
        {
            this->startButton.rect.setFillColor(MainColor);
            this->startButton.text.setFillColor(sf::Color::Black);
            this->startButton.rect.setScale(1.1, 1.1);
        } 
        else {
            this->startButton.rect.setFillColor(ButtonColor);
            this->startButton.text.setFillColor(MainColor);
            this->startButton.rect.setScale(1, 1);
        }
        //-------
        if (this->settingsButton.rect.getGlobalBounds().contains(mousePos))
        {
            this->settingsButton.rect.setFillColor(MainColor);
            this->settingsButton.text.setFillColor(sf::Color::Black);
            this->settingsButton.rect.setScale(1.1, 1.1);
        } else {
            this->settingsButton.rect.setFillColor(ButtonColor);
            this->settingsButton.text.setFillColor(MainColor);
            this->settingsButton.rect.setScale(1, 1);
        }
        if (this->aboutButton.rect.getGlobalBounds().contains(mousePos))
        {
            this->aboutButton.rect.setFillColor(MainColor);
            this->aboutButton.text.setFillColor(sf::Color::Black);
            this->aboutButton.rect.setScale(1.1, 1.1);
        } else {
            this->aboutButton.rect.setFillColor(ButtonColor);
            this->aboutButton.text.setFillColor(MainColor);
            this->aboutButton.rect.setScale(1, 1);
        }
    }

}

void MenuPage::updateChanges()
{
    // coding
    this->font = defautFont;
    this->titlefont = defautTitleFont;

    sf::Text temp("Data Visualization", this->font, 120);
    CreateTitle(temp, 1920 / 2.f, 250.f);
    this->Title = temp;

    this->startButton.CreateButton(600, 120, 1920 / 2.f, 530, ButtonColor, "Start", titlefont, MainColor);
    this->startButton.rect.setOutlineColor(ButtonOutlineColor);
    this->startButton.rect.setOutlineThickness(5);
    this->startButton.setSize(60);

    this->settingsButton.CreateButton(600, 120, 960, startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, ButtonColor, "Setting", titlefont, MainColor);
    this->settingsButton.rect.setOutlineColor(ButtonOutlineColor);
    this->settingsButton.rect.setOutlineThickness(5);
    this->settingsButton.setSize(60);

    this->aboutButton.CreateButton(600, 120, 960, settingsButton.rect.getPosition().y + settingsButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, ButtonColor, "About", titlefont, MainColor);
    this->aboutButton.rect.setOutlineColor(ButtonOutlineColor);
    this->aboutButton.rect.setOutlineThickness(5);
    this->aboutButton.setSize(60);
}

SettingPage::SettingPage()
{
    this->font = defautFont;
    this->tempFont = defautFont;
    this->titlefont = defautTitleFont;

    //Title
    sf::Text SettingTitle("Setting", this->titlefont, 130);
    CreateTitle(SettingTitle, 1920 / 2.f, 250.f);
    this->Title = SettingTitle;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
    //Apply Button
    ApplyButton.CreateButton(400, 120, 1920 / 2.f, 900, MainColor, "Apply", font, sf::Color::Black);
    ApplyButton.rect.setOutlineColor(ButtonOutlineColor);
    ApplyButton.rect.setOutlineThickness(2.f);

    pageText.setFont(this->font);
    pageText.setCharacterSize(30);
    pageText.setFillColor(MainColor);
    pageText.setString("Page: ");
    pageText.setPosition(280, 400);
    pageText.setOrigin(pageText.getLocalBounds().width / 2.f, pageText.getLocalBounds().height / 2.f);

    FontText.setFont(this->font);
    FontText.setCharacterSize(30);
    FontText.setFillColor(MainColor);
    FontText.setString("Font: ");
    FontText.setPosition(280, 600);
    FontText.setOrigin(FontText.getLocalBounds().width / 2.f, FontText.getLocalBounds().height / 2.f);
    // Button FontTextButton;
    FontTextButton.CreateButton(100, 50, 750, 610, ButtonColor, "Import", font, sf::Color::White);
    FontTextButton.rect.setOutlineColor(ButtonOutlineColor);
    FontTextButton.rect.setOutlineThickness(2.f);

    ColorText.setFont(this->font);
    ColorText.setCharacterSize(30);
    ColorText.setFillColor(MainColor);
    ColorText.setString("Color: ");
    ColorText.setPosition(280, 800);
    ColorText.setOrigin(ColorText.getLocalBounds().width / 2.f, ColorText.getLocalBounds().height / 2.f);
}
void SettingPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    this->backButton.displayButton(window);

    ApplyButton.displayButton(window);

    window.draw(FontText);
    window.draw(pageText);
    window.draw(ColorText);
    this->FontTextButton.displayButton(window);
    Colordropdown.draw(window);
    Fontdropdown.draw(window);
    Pagedropdown.draw(window);
}
void SettingPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event, DataVisualization_1 &dv1, DataVisualization_2 &dv2, DataVisualization_3 &dv3, DataVisualization_4 &dv4, DataVisualization_5 &dv5, DataVisualization_6 &dv6, DataVisualization_7 &dv7)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Menu;
            DefaultBackground.setTexture(BackGround0);
        }
        if (this->FontTextButton.rect.getGlobalBounds().contains(mousePos))
        {
            loadFont();
        }
        if (this->ApplyButton.rect.getGlobalBounds().contains(mousePos))
        {
            updateChangeGlobals(dv1, dv2, dv3, dv4, dv5, dv6, dv7);
        }
    }
    Fontdropdown.handleEvent(event);
    Pagedropdown.handleEvent(event);
    Colordropdown.handleEvent(event);
}

void SettingPage::updateChanges()
{
    //Title
    sf::Text SettingTitle("Setting", this->titlefont, 130); 
    CreateTitle(SettingTitle, 1920 / 2.f, 250.f);
    this->Title = SettingTitle;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);

    FontText.setFont(this->font);
    FontText.setCharacterSize(30);
    FontText.setFillColor(MainColor);
    FontText.setString("Font: ");
    FontText.setPosition(280, 400);
    FontText.setOrigin(FontText.getLocalBounds().width / 2.f, FontText.getLocalBounds().height / 2.f);
    // Button FontTextButton;
    FontTextButton.CreateButton(200, 100, 450, 400, ButtonColor, "Import", font, sf::Color::White);
}

void SettingPage::loadFont()
{
    OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "Font Files (*.ttf)\0*.ttf\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "ttf";

    if (GetOpenFileName(&ofn) == TRUE)
    {
        if (!this->tempFont.loadFromFile(ofn.lpstrFile))
        {
            // Handle error
            std::cerr << "Error loading font file." << std::endl;
        }
    }
    else
    {
        std::cout << "Cancelled" << std::endl;
    }
}

void SettingPage::updateChangeGlobals(DataVisualization_1 &dv1, DataVisualization_2 &dv2, DataVisualization_3 &dv3, DataVisualization_4 &dv4, DataVisualization_5 &dv5, DataVisualization_6 &dv6, DataVisualization_7 &dv7)
{
    if (this->Pagedropdown.storage == "Static Array")
    {
        dv1.updateChanges(tempFont);
        std::cout << 1 << std::endl;
    }
    else if (this->Pagedropdown.storage == "Dynamic Array")
    {

    }
    else if (this->Pagedropdown.storage == "Singly Linked List")
    {

    }
    else if (this->Pagedropdown.storage == "Doubly Linked List")
    {

    }
    else if (this->Pagedropdown.storage == "Circular Linked List")
    {

    }
    else if (this->Pagedropdown.storage == "Stack")
    {

    }
    else if (this->Pagedropdown.storage == "Queue")
    {

    }
}


StartingPage::StartingPage()
{
    //Font
    this->font = defautFont;
    this->titlefont = defautTitleFont;

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
    rect1.CreateButton(rectWidth, rectHeight, startX1, startY1, sf::Color(0, 154, 172, 0), "Static Array", font, MainColor);
    rect1.rect.setOutlineColor(ButtonOutlineColor);
    rect1.rect.setOutlineThickness(5);
    rect1.setSize(40);
    
    // #2. Dynamic array rectangle
    rect2.CreateButton(rectWidth, rectHeight, startX1, startY1 + rectHeight + padding, sf::Color(218, 83, 44, 0), "Dynamic Array", font, MainColor);
    rect2.rect.setOutlineColor(ButtonOutlineColor);
    rect2.rect.setOutlineThickness(5);
    rect2.setSize(40);
    // #3. Singly linked list rectangle
    rect3.CreateButton(rectWidth, rectHeight, startX1, startY1 + (rectHeight + padding) * 2.f, sf::Color(160, 0, 167, 0), "Singly Linked List", font, MainColor);
    rect3.rect.setOutlineColor(ButtonOutlineColor);
    rect3.rect.setOutlineThickness(5);
    rect3.setSize(40);
    // #4. Doubly linked list rectangle
    rect4.CreateButton(rectWidth, rectHeight, startX2, startY2, sf::Color(186, 29, 71, 0), "Doubly Linked List", font, MainColor);
    rect4.rect.setOutlineColor(ButtonOutlineColor);
    rect4.rect.setOutlineThickness(5);
    rect4.setSize(40);
    // #5. Circular linked list rectangle
    rect5.CreateButton(rectWidth, rectHeight, startX2, startY2 + rectHeight + padding, sf::Color(124, 192, 204, 0), "Circular Linked List", font, MainColor);
    rect5.rect.setOutlineColor(ButtonOutlineColor);
    rect5.rect.setOutlineThickness(5);
    rect5.setSize(40);
    // #6. Stack rectangle
    rect6.CreateButton(rectWidth, rectHeight, startX2, startY2 + (rectHeight + padding) * 2.f, sf::Color(0, 160, 0, 0), "Stack", font, MainColor);
    rect6.rect.setOutlineColor(ButtonOutlineColor);
    rect6.rect.setOutlineThickness(5);
    rect6.setSize(40);
    // #7. Queue rectangle
    rect7.CreateButton(rectWidth + padding*2, rectHeight, 1920 / 2.f,  startY2 + (rectHeight + padding) * 3.f, sf::Color(38, 116, 236, 0), "Queue", font, MainColor);
    rect7.rect.setOutlineColor(ButtonOutlineColor);
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
            DefaultBackground.setTexture(BackGround0);
        }
        if (this->rect1.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV1;
            DefaultBackground.setTexture(BackGround2);
        } 
        if (this->rect2.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV2;
            DefaultBackground.setTexture(BackGround2);
        } 
        if (this->rect3.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV3;
            DefaultBackground.setTexture(BackGround2);
        } 
        if (this->rect4.rect.getGlobalBounds().contains(mousePos))
        {
            DefaultBackground.setTexture(BackGround2);
            currentState = DV4;
        } 
        if (this->rect5.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV5;
            DefaultBackground.setTexture(BackGround2);
        } 
        if (this->rect6.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV6;
            DefaultBackground.setTexture(BackGround2);
        } 
        if (this->rect7.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV7;
            DefaultBackground.setTexture(BackGround2);
        } 
    }
    if (event.type == sf::Event::MouseMoved)
    {
        //------
        if (this->rect1.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect1.rect.setFillColor(MainColor);
            this->rect1.text.setFillColor(sf::Color::Black);
            this->rect1.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect1.rect.setFillColor(ButtonColor);
            this->rect1.text.setFillColor(MainColor);
            this->rect1.rect.setScale(1, 1);
        }
        if (this->rect2.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect2.rect.setFillColor(MainColor);
            this->rect2.text.setFillColor(sf::Color::Black);
            this->rect2.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect2.rect.setFillColor(ButtonColor);
            this->rect2.text.setFillColor(MainColor);
            this->rect2.rect.setScale(1, 1);
        }
        if (this->rect3.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect3.rect.setFillColor(MainColor);
            this->rect3.text.setFillColor(sf::Color::Black);
            this->rect3.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect3.rect.setFillColor(ButtonColor);
            this->rect3.text.setFillColor(MainColor);
            this->rect3.rect.setScale(1, 1);
        }
        if (this->rect4.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect4.rect.setFillColor(MainColor);
            this->rect4.text.setFillColor(sf::Color::Black);
            this->rect4.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect4.rect.setFillColor(ButtonColor);
            this->rect4.text.setFillColor(MainColor);
            this->rect4.rect.setScale(1, 1);
        }
        if (this->rect5.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect5.rect.setFillColor(MainColor);
            this->rect5.text.setFillColor(sf::Color::Black);
            this->rect5.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect5.rect.setFillColor(ButtonColor);
            this->rect5.text.setFillColor(MainColor);
            this->rect5.rect.setScale(1, 1);
        }
        if (this->rect6.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect6.rect.setFillColor(MainColor);
            this->rect6.text.setFillColor(sf::Color::Black);
            this->rect6.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect6.rect.setFillColor(ButtonColor);
            this->rect6.text.setFillColor(MainColor);
            this->rect6.rect.setScale(1, 1);
        }
        if (this->rect7.rect.getGlobalBounds().contains(mousePos))
        {
            this->rect7.rect.setFillColor(MainColor);
            this->rect7.text.setFillColor(sf::Color::Black);
            this->rect7.rect.setScale(1.1, 1.1);
        } 
        else {
            this->rect7.rect.setFillColor(ButtonColor);
            this->rect7.text.setFillColor(MainColor);
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

    //Title
    sf::Text SettingTitle("About me", this->titlefont, 100);
    CreateTitle(SettingTitle, 1920 / 2.f, 250.f);
    this->Title = SettingTitle;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);


    paragraph.setFont(font);
    paragraph.setString("Hello and welcome to my project!\n\nMy name is Huynh Cao Tuan Kiet (ID: 22127219).\n\nI would like to take a moment to express my gratitude to my teacher:\n\n          Teacher: Nguyen Le Hoang Dung\n\n          Teacher: HO Tuan Thanh\n\n          Teacher: Dinh Ba Tien\n\n for their guidance and support throughout this project.\n\nTheir expertise have been invaluable, and I'm so grateful to have had the opportunity to learn from them.\n\nI hope you enjoy exploring my project and having awesome experience!");
    paragraph.setCharacterSize(22);
    paragraph.setFillColor(sf::Color::White);
    paragraph.setPosition(280, 380);
}
void AboutPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    this->backButton.displayButton(window);
    window.draw(paragraph);
}
void AboutPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Menu;
            DefaultBackground.setTexture(BackGround0);
        }
    }
}
