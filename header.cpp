#include "header.hpp"

/*
sf::Font font;
sf::Color(22, 73, 154)
sf::Color sf::Color(22, 73, 154) = sf::Color(22, 73, 154);
const sf::Color Pink1(253, 0, 112);
const sf::Color Purple1(104, 0, 120);
*/

void CreateTitle(sf::Text &Title, float PosX, float PosY)
{
    Title.setOutlineColor(sf::Color::Red);
    Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color::White);
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

//---
MenuPage::MenuPage()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    sf::Text temp("Data Visualization", this->font, 150);
    CreateTitle(temp, 1920 / 2.f, 100.f);
    this->Title = temp;

    // this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
    this->startButton.CreateButton(600, 150, 1920 / 2.f, 530, sf::Color(104, 0, 120), "Start", font, sf::Color(253, 0, 112));
    this->startButton.rect.setOutlineThickness(5);
    this->startButton.rect.setOutlineColor(sf::Color(253, 0, 112));
    this->settingsButton.CreateButton(600, 150, 1920 / 2.f - settingsButton.rect.getSize().x / 2.f, startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, sf::Color(104, 0, 120), "Setting", font, sf::Color(253, 0, 112));
    this->settingsButton.rect.setOutlineThickness(5);
    this->settingsButton.rect.setOutlineColor(sf::Color(253, 0, 112));
}
void MenuPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    // this->backButton.displayButton(window);
    this->settingsButton.displayButton(window);
    this->startButton.displayButton(window);
}
void MenuPage::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->startButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
        else if (this->settingsButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Settings;
        }
    }
}
//---

SettingPage::SettingPage()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text SettingTitle("Setting", this->font, 120);
    CreateTitle(SettingTitle, 1920 / 2.f, 50.f);
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
            currentState = Start;
        }
    }
}

StartingPage::StartingPage()
{
    //Font
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text StartTitle("Menu", this->font, 100);
    CreateTitle(StartTitle, 1920 / 2.f, 50.f);
    this->Title = StartTitle;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);

    // Option
    // Rectangle dimensions
    const float rectWidth = 600.f;
    const float rectHeight = 180.f;
    const float padding = 20.f;
    // Start position
    const float startX1 = 1920 / 2.f - padding - rectWidth / 2.f;
    const float startY1 = StartTitle.getLocalBounds().height + padding * 5 + rectHeight / 2.f;
    const float startX2 = 1920 / 2.f + rectWidth / 2.f;
    const float startY2 = StartTitle.getLocalBounds().height + padding * 5 + rectHeight / 2.f;

    // #1. Static array rectangle
    this->rect1.CreateButton(rectWidth, rectHeight, startX1, startY1, sf::Color(0, 154, 172), "Static Array", font, sf::Color::White);
    // #2. Dynamic array rectangle
    rect2.CreateButton(rectWidth, rectHeight, startX1, startY1 + rectHeight + padding, sf::Color(218, 83, 44), "Dynamic array", font, sf::Color::White);
    // #3. Singly linked list rectangle
    rect3.CreateButton(rectWidth, rectHeight, startX1, startY1 + (rectHeight + padding) * 2.f, sf::Color(160, 0, 167), "Singly linked list", font, sf::Color::White);
    // #4. Doubly linked list rectangle
    rect4.CreateButton(rectWidth, rectHeight, startX2, startY2, sf::Color(186, 29, 71), "Doubly Linked List", font, sf::Color::White);
    // #5. Circular linked list rectangle
    rect5.CreateButton(rectWidth, rectHeight, startX2, startY2 + rectHeight + padding, sf::Color(124, 192, 204), "Circular Linked List", font, sf::Color::White);
    // #6. Stack rectangle
    rect6.CreateButton(rectWidth, rectHeight, startX2, startY2 + (rectHeight + padding) * 2.f, sf::Color(0, 160, 0), "Stack", font, sf::Color::White);
    // #7. Queue rectangle
    rect7.CreateButton(rectWidth + padding*2, rectHeight, 1920 / 2.f,  startY2 + (rectHeight + padding) * 3.f, sf::Color(38, 116, 236), "Queue", font, sf::Color::White);
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
        }
        if (this->rect1.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV1;
        } 
        if (this->rect2.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV2;
        } 
        if (this->rect3.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV3;
        } 
        if (this->rect4.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV4;
        } 
        if (this->rect5.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV5;
        } 
        if (this->rect6.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV6;
        } 
        if (this->rect7.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = DV7;
        } 
    }
}

DataVisualization_1::DataVisualization_1()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV1Title("Static Array", this->font, 90);
    CreateTitle(DV1Title, 1920 / 2.f, 50.f);
    this->Title = DV1Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}
void DataVisualization_1::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}
void DataVisualization_1::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}


DataVisualization_2::DataVisualization_2()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV2Title("Dynamic Array", this->font, 90);
    CreateTitle(DV2Title, 1920 / 2.f, 50.f);
    this->Title = DV2Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}
void DataVisualization_2::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}
void DataVisualization_2::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

DataVisualization_3::DataVisualization_3()
{
    //Fonts
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV3Title("Singly Linked List", this->font, 90);
    CreateTitle(DV3Title, 1920 / 2.f, 50.f);
    this->Title = DV3Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    //Function Key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 125.f, sf::Color(255, 138, 39), "Create", this->font, sf::Color::White);
    // this->ControlMenu_btn1.rect.setOutlineThickness(0);
    this->CreateEmpty.CreateButton(130.f, 50.f, this->ControlMenu_btn1.rect.getPosition().x + this->ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Empty", this->font, sf::Color::White);
    this->CreateRadom.CreateButton(130.f, 50.f, this->CreateEmpty.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Random", this->font, sf::Color::White);
    this->CreateRandomSort.CreateButton(130.f, 50.f, this->CreateRadom.rect.getPosition().x + this->CreateRadom.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Random Sort", this->font, sf::Color::White);
    this->CreateRandomFixedSize.CreateButton(180.f, 50.f, this->CreateRandomSort.rect.getPosition().x + this->CreateRandomSort.rect.getSize().x / 2.f + 160.f / 2.f + 20.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Random Fixed Size", this->font, sf::Color::White);
    InitTextbox(this->CreateRandomFixedSize_Textbox, 20, sf::Color::White, true, this->CreateRandomFixedSize.rect.getPosition().x , this->CreateRandomFixedSize.rect.getPosition().y + 50, font, true, 3);
    this->CreateRandomFixedSize_Textbox.EnterMessage.setString("Size: ");
    this->CreateUserDefinedListButton.CreateButton(130.f, 50.f, this->CreateRandomFixedSize.rect.getPosition().x + this->CreateRandomFixedSize.rect.getSize().x / 2.f + 130.f/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "User Defined", this->font, sf::Color::White);
    InitTextbox(this->CreateUserDefinedList_Textbox, 20, sf::Color::White, true, this->CreateUserDefinedListButton.rect.getPosition().x, this->CreateUserDefinedListButton.rect.getPosition().y + 50, font, true, 3);
    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size: ");

    //Function Key #2: Adding
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 175.f, sf::Color(255, 138, 39), "Add", this->font, sf::Color::White);
    this->InsertHead.CreateButton(130.f, 50.f, this->ControlMenu_btn2.rect.getPosition().x + this->ControlMenu_btn2.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 175.f, sf::Color(255, 138, 39), "Head", this->font, sf::Color::White);
    InitTextbox(this->InsertHead_Textbox, 20, sf::Color::White, true, this->InsertHead.rect.getPosition().x, this->InsertHead.rect.getPosition().y + 50, font, true, 3);
    this->InsertHead_Textbox.EnterMessage.setString("Value: ");
    this->InsertBack.CreateButton(130.f, 50.f, this->InsertHead.rect.getPosition().x + this->InsertHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(255, 138, 39), "Back", this->font, sf::Color::White);
    InitTextbox(this->InsertBack_Textbox, 20, sf::Color::White, true, this->InsertBack.rect.getPosition().x, this->InsertBack.rect.getPosition().y + 50, font, true, 3);
    this->InsertBack_Textbox.EnterMessage.setString("Value: ");
    this->InsertMid.CreateButton(130.f, 50.f, this->InsertBack.rect.getPosition().x + this->InsertBack.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(255, 138, 39), "Mid", this->font, sf::Color::White);
    InitTextbox(this->InsertMid_Textbox, 20, sf::Color::White, true, this->InsertMid.rect.getPosition().x, this->InsertMid.rect.getPosition().y + 50, font, true, 3);
    this->InsertMid_Textbox.EnterMessage.setString("Value: ");

    //Function Key #3
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(255, 138, 39), "Delete", this->font, sf::Color::White);
    this->DeleteHead.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(255, 138, 39), "Head", this->font, sf::Color::White);
    this->DeleteBack.CreateButton(130.f, 50.f, this->DeleteHead.rect.getPosition().x + this->DeleteHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 225.f, sf::Color(255, 138, 39), "Back", this->font, sf::Color::White);
    this->DeleteMid.CreateButton(130.f, 50.f, this->DeleteBack.rect.getPosition().x + this->DeleteBack.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 225.f, sf::Color(255, 138, 39), "Mid", this->font, sf::Color::White);
    InitTextbox(this->DeleteMid_Textbox, 20, sf::Color::White, true, this->DeleteMid.rect.getPosition().x, this->DeleteMid.rect.getPosition().y + 50, font, true, 3);
    this->DeleteMid_Textbox.EnterMessage.setString("Index: ");

    //Function Key #4
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(255, 138, 39), "Update", this->font, sf::Color::White);
    this->UpdateNodeButton.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(255, 138, 39), "Update", this->font, sf::Color::White);
    InitTextbox(this->UpdateNode_Textbox, 20, sf::Color::White, true, this->UpdateNodeButton.rect.getPosition().x, this->UpdateNodeButton.rect.getPosition().y + 50, font, true, 3);
    this->UpdateNode_Textbox.EnterMessage.setString("Index: ");

    //Function Key #5
    this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(255, 138, 39), "Search", this->font, sf::Color::White);
    this->SearchNodeButton.CreateButton(130.f, 50.f, this->ControlMenu_btn5.rect.getPosition().x + this->ControlMenu_btn5.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 325.f, sf::Color(255, 138, 39), "Search", this->font, sf::Color::White);
    InitTextbox(this->SearchNode_Textbox, 20, sf::Color::White, true, this->SearchNodeButton.rect.getPosition().x, this->SearchNodeButton.rect.getPosition().y + 50, font, true, 3);
    this->SearchNode_Textbox.EnterMessage.setString("Value: ");

    this->size = 0;
    this->NodeArray = nullptr;

    funcstate = 0;
}

void DataVisualization_3::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
    this->ControlMenu_btn1.displayButton(window);
    this->ControlMenu_btn2.displayButton(window);
    this->ControlMenu_btn3.displayButton(window);
    this->ControlMenu_btn4.displayButton(window);
    this->ControlMenu_btn5.displayButton(window);
    switch (this->funcstate)
    {
    case 1:
        this->CreateEmpty.displayButton(window);
        this->CreateRadom.displayButton(window);;
        this->CreateRandomSort.displayButton(window);
        this->CreateRandomFixedSize.displayButton(window);
        this->CreateUserDefinedListButton.displayButton(window);
        this->CreateRandomFixedSize_Textbox.drawTo(window);
        this->CreateUserDefinedList_Textbox.drawTo(window);
        break;
    case 2:
        this->InsertHead_Textbox.drawTo(window);
        this->InsertHead.displayButton(window);
        this->InsertBack.displayButton(window);
        this->InsertBack_Textbox.drawTo(window);
        this->InsertMid.displayButton(window);
        this->InsertMid_Textbox.drawTo(window);
        break;
    case 3:
        this->DeleteBack.displayButton(window);
        this->DeleteHead.displayButton(window);
        this->DeleteMid.displayButton(window);
        this->DeleteMid_Textbox.drawTo(window);
        break;
    case 4:
        this->UpdateNodeButton.displayButton(window);
        this->UpdateNode_Textbox.drawTo(window);
        break;
    case 5:
        this->SearchNodeButton.displayButton(window);
        this->SearchNode_Textbox.drawTo(window);
        break;
    default: // NONE - 0
        break;
    }
}

void DataVisualization_3::handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
        else if (this->ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 1;
        }
        else if (this->ControlMenu_btn2.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 2;
        }
        else if (this->ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 3;
        }
        else if (this->ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 4;
        }
        else if (this->ControlMenu_btn5.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 5;
        }
        else {
            this->CreateRandomFixedSize_Textbox.isSelected = false;
            this->InsertBack_Textbox.isSelected = false;
            this->InsertHead_Textbox.isSelected = false;
            this->DeleteMid_Textbox.isSelected = false;
            this->SearchNode_Textbox.isSelected = false;
            this->InsertMid_Textbox.isSelected = false;
            this->CreateUserDefinedList_Textbox.isSelected = false;
            this->UpdateNode_Textbox.isSelected = false;
        }
        switch (this->funcstate)
        {
        case 1:
            if (this->CreateEmpty.rect.getGlobalBounds().contains(mousePos))
            {
                DeleteSLL(this->NodeArray);
                this->NodeArray = nullptr;
                this->size = 0;
            }
            if (this->CreateRadom.rect.getGlobalBounds().contains(mousePos))
            {
                CreateRandomNodes(this->NodeArray, this->size, this->font);
            }
            if (this->CreateRandomSort.rect.getGlobalBounds().contains(mousePos))
            {
                CreateRandomSortSLL(this->NodeArray, this->size, this->font);
            }
            if (this->CreateRandomFixedSize.rect.getGlobalBounds().contains(mousePos))
            {
                this->CreateRandomFixedSize_Textbox.isSelected = !this->CreateRandomFixedSize_Textbox.isSelected;
            } else {
                this->CreateRandomFixedSize_Textbox.isSelected = false;
            }
            if (this->CreateUserDefinedListButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->CreateUserDefinedList_Textbox.isSelected = !this->CreateUserDefinedList_Textbox.isSelected;
            } else {
                this->CreateUserDefinedList_Textbox.isSelected = false;
            }
            break;  
            
        case 2:
            if (this->InsertHead.rect.getGlobalBounds().contains(mousePos))
            {
                this->InsertHead_Textbox.isSelected = !this->InsertHead_Textbox.isSelected;
            } else {
                this->InsertHead_Textbox.isSelected = false;
            }
            if (this->InsertBack.rect.getGlobalBounds().contains(mousePos))
            {
                this->InsertBack_Textbox.isSelected = !this->InsertBack_Textbox.isSelected;
            } else {
                this->InsertBack_Textbox.isSelected = false;
            }
            if (this->InsertMid.rect.getGlobalBounds().contains(mousePos))
            {
                // this->InsertNodeMid(window, 69);
                this->InsertMid_Textbox.isSelected = !this->InsertMid_Textbox.isSelected;
            } else {
                this->InsertMid_Textbox.isSelected = false;
            }
            break;
        case 3:
            if (this->DeleteHead.rect.getGlobalBounds().contains(mousePos))
            {
                this->DeleteNodeFront(window);
            }
            if (this->DeleteBack.rect.getGlobalBounds().contains(mousePos))
            {
                this->DeleteNodeBack(window);
            }
            if (this->DeleteMid.rect.getGlobalBounds().contains(mousePos))
            {
                this->DeleteMid_Textbox.isSelected = !this->DeleteMid_Textbox.isSelected;
            } else {
                this->DeleteMid_Textbox.isSelected = false;
            }
            break;
        case 4:
            if (this->UpdateNodeButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->UpdateNode_Textbox.isSelected = !this->UpdateNode_Textbox.isSelected;
            } else {
                this->UpdateNode_Textbox.isSelected = false;
            }
        case 5:
            if (this->SearchNodeButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->SearchNode_Textbox.isSelected = !this->SearchNode_Textbox.isSelected;
            } else {
                this->SearchNode_Textbox.isSelected = false;
            }
        default:
            break;
        }
    }
    else if (ev.type == sf::Event::TextEntered)
    {
        CreateRandomFixedSizeSLL(window, ev); 
        CreateUserDefinedListSLL(window, ev);
        InsertNodeFrontSLL(window, ev);
        InsertNodeBackSLL(window, ev);
        InsertNodeMidSLL(window, ev);
        DeleteNodeMidSLL(window, ev);
        SearchNodeSLL(window, ev);
        UpdateNodeSLL(window, ev);
    }
    else if (ev.type == sf::Event::MouseMoved)
    {
        if (this->ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn1.rect.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn1.rect.setFillColor(sf::Color(255, 138, 39));
        }
        if (this->ControlMenu_btn2.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn2.rect.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn2.rect.setFillColor(sf::Color(255, 138, 39));
        }
        if (this->ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn3.rect.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn3.rect.setFillColor(sf::Color(255, 138, 39));
        }
        if (this->ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn4.rect.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn4.rect.setFillColor(sf::Color(255, 138, 39));
        }
        if (this->ControlMenu_btn5.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn5.rect.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn5.rect.setFillColor(sf::Color(255, 138, 39));
        }
    }
    // free
}

void DataVisualization_3::CreateRandomFixedSizeSLL(sf::RenderWindow &window, sf::Event &event)
{
    if (this->CreateRandomFixedSize_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->CreateRandomFixedSize_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->CreateRandomFixedSize_Textbox.pressEnter == true)
        {
            int size = std::stoi(str);
            if (size <= 10)
            {
                this->size = size;
                CreateFixedNodes(this->NodeArray, this->size, this->font);
            } else {
                checkSize(window, size);
            }
        }
        this->CreateRandomFixedSize_Textbox.pressEnter = false;
    }
}

void DataVisualization_3::CreateUserDefinedListSLL(sf::RenderWindow &window, sf::Event &event)
{
    if (this->CreateUserDefinedList_Textbox.isSelected)
    {
        static std::vector<int> values;
        static int num_values = 0;

        std::string str = "";
        this->CreateUserDefinedList_Textbox.TextboxHandleEvent(event, str);

        if (str != "" && this->CreateUserDefinedList_Textbox.pressEnter == true)
        {
            if (num_values == 0) {
                num_values = std::stoi(str);
                this->CreateUserDefinedList_Textbox.EnterMessage.setString("Value: ");
            }
            else {
                values.push_back(std::stoi(str));
                num_values--;
                if (num_values == 0) {
                    this->CreateUserDefinedList(window, values);
                    values.clear(); // delete Vector
                    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size: ");
                    this->CreateUserDefinedList_Textbox.isSelected = false;
                }
                else {
                    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Value:");
                }
            }
            this->CreateUserDefinedList_Textbox.pressEnter = false;
        }
    }
}

void DataVisualization_3::CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values)
{
    DeleteSLL(this->NodeArray);
    int n = values.size();
    if (n < 0 || n > 10)
    {
        printMessage(window, "Size be must from 1 to 10");
    }
    for (int i = 0; i < n; i++)
    {
        SLL_Node* temp = createNode(250 + i * 150, 250, 30, this->font, values[i]);
        addBack(this->NodeArray, temp);
    }
}

void DataVisualization_3::InsertNodeFrontSLL(sf::RenderWindow &window, sf::Event &event)
{
    if (this->InsertHead_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->InsertHead_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->InsertHead_Textbox.pressEnter == true)
        {
            int value = std::stoi(str);
            this->InsertNodeFront(window, value);
        }
        this->InsertHead_Textbox.pressEnter = false;
    }
}

void DataVisualization_3::InsertNodeBackSLL(sf::RenderWindow &window, sf::Event &event)
{
    if (this->InsertBack_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->InsertBack_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->InsertBack_Textbox.pressEnter == true)
        {
            int value = std::stoi(str);
            this->InsertNodeBack(window, value);
        }
        this->InsertBack_Textbox.pressEnter = false;
    }
}

void DataVisualization_3::InsertNodeMidSLL(sf::RenderWindow& window, sf::Event& event)
{
    if (this->InsertMid_Textbox.isSelected)
    {
        static int value = -1;
        static int index = -1;

        // Receive input string
        std::string str = "";
        this->InsertMid_Textbox.TextboxHandleEvent(event, str);

        // Check if input is valid
        if (str != "" && this->InsertMid_Textbox.pressEnter == true)
        {
            if (value == -1) {
                value = std::stoi(str);
                this->InsertMid_Textbox.EnterMessage.setString("Index: ");
            }
            else {
                index = std::stoi(str);
                this->InsertNodeMid(window, value, index);
                this->InsertMid_Textbox.EnterMessage.setString("Value: ");
                value = -1;
                index = -1;
            }
            this->InsertMid_Textbox.pressEnter = false;
        }
    }
}

void DataVisualization_3::drawNodes(sf::RenderWindow &window)
{
    SLL_Node* temp = this->NodeArray;
    while (temp != nullptr)
    {
        if (temp->next != nullptr)
        {
            sf::Vector2f first(temp->circle.getPosition());
            sf::Vector2f second(temp->next->circle.getPosition());
            drawArrow(window, first, second);
        }
        window.draw(temp->circle);
        window.draw(temp->text);
        temp = temp->next;
    }
}

DataVisualization_3::~DataVisualization_3()
{
    DeleteSLL(this->NodeArray);
}

bool DataVisualization_3::checkSize(sf::RenderWindow &window, int size)
{
    if (size < 10) return true;
    std::chrono::milliseconds delayTime(750);
    sf::Text message;
    message.setString("Size must be from 0 to 10");
    message.setCharacterSize(50);
    message.setFillColor(sf::Color::White);
    message.setOutlineColor(sf::Color::Red);
    message.setOutlineThickness(5);
    message.setFont(this->font);
    message.setOrigin(message.getLocalBounds().width/2.f, message.getLocalBounds().height/2.f);
    message.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    window.draw(message);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return false;
}

void DataVisualization_3::InsertNodeFront(sf::RenderWindow &window, int data)
{
    if (this->NodeArray == nullptr)
    {
        this->NodeArray = createNode(250, 250, 30, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return;
    SLL_Node* newNode = createNode(this->NodeArray->circle.getPosition().x, this->NodeArray->circle.getPosition().y + 150, 30, this->font, data);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();
    sleep(1.25);
    for (int i = 0; i < 25; i++)
    {
        SLL_Node* temp = this->NodeArray;
        while (temp != nullptr)
        {
            window.clear(sf::Color(22, 73, 154));
            temp->circle.move(6, 0);
            temp->text.move(6, 0);
            temp = temp->next;
        }
        newNode->circle.move(0, -6);
        newNode->text.move(0, -6);
        drawArrow(window, newNode->circle.getPosition(), this->NodeArray->circle.getPosition());
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
    }
    newNode->next = this->NodeArray;
    this->NodeArray = newNode;
    this->size++;
}

void DataVisualization_3::InsertNodeBack(sf::RenderWindow &window, int data)
{
    std::chrono::milliseconds delayTime(500); // 0.5 seconds
    // std::this_thread::sleep_for(delayTime); 
    if (this->NodeArray == nullptr)
    {
        this->NodeArray = createNode(250, 250, 30, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return;
    SLL_Node* LastNode = this->NodeArray;
    while (LastNode->next != nullptr) LastNode = LastNode->next;
    SLL_Node* newNode = createNode(LastNode->circle.getPosition().x + 150, LastNode->circle.getPosition().y + 150, 30, this->font, data);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();
    std::this_thread::sleep_for(delayTime);

    SLL_Node* temp = this->NodeArray;
    while (temp != nullptr)
    {
        window.clear(sf::Color(22, 73, 154));
        temp->circle.setFillColor(sf::Color::Green);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
        std::this_thread::sleep_for(delayTime);
        temp = temp->next;
    }
    LastNode->next = newNode;
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();

    // moving
    for (int i = 0; i < 25; i++)
    {
        window.clear(sf::Color(22, 73, 154));
        newNode->circle.move(0, -6);
        newNode->text.move(0, -6);
        this->drawNodes(window);
        this->display(window);
        window.display();
    }
    std::this_thread::sleep_for(delayTime);

    // Recolor the node
    SLL_Node* cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color::Yellow);
        cur = cur->next;
    }
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    this->size++;
}

void DataVisualization_3::InsertNodeMid(sf::RenderWindow &window, int data, int index)
{
    std::chrono::milliseconds delayTime(500); // 0.5 seconds
    // special case
    if (this->NodeArray == nullptr)
    {
        this->NodeArray = createNode(250, 250, 30, font, data);
        return;
    }
    if (checkSize(window, this->size) == false) return;
    if (index > this->size) 
    {
        std::string str = "Index must be from 1 to " + std::to_string(this->size);
        printMessage(window, str);
        return;
    }
    // index = 1 + rand() % (this->getSLLSize());
    if (index == 1) 
    {
        this->InsertNodeFront(window, data);
        return;
    }
    if (index == this->size) 
    {
        this->InsertNodeBack(window, data);
        return;
    }
    //
    SLL_Node* iteratorNode = this->NodeArray;
    SLL_Node* pre = iteratorNode;
    for (int i = 1; i < index; i++)
    {
        pre = iteratorNode;
        iteratorNode = iteratorNode->next;
    }
    SLL_Node* newNode = createNode(pre->circle.getPosition().x + 150, pre->circle.getPosition().y + 150, 30, this->font, data);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();
    std::this_thread::sleep_for(delayTime); 

    SLL_Node* temp = this->NodeArray;
    do {
        window.clear(sf::Color(22, 73, 154));
        temp->circle.setFillColor(sf::Color::Green);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
        std::this_thread::sleep_for(delayTime); 
        temp = temp->next;
    }
    while (temp != iteratorNode);

    pre->next = newNode;
    newNode->next = iteratorNode;
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();

    // moving
    for (int i = 0; i < 25; i++)
    {
        window.clear(sf::Color(22, 73, 154));
        newNode->circle.move(0, -6);
        newNode->text.move(0, -6);
        temp = iteratorNode;
        while (temp != nullptr)
        {
            temp->circle.move(6, 0);
            temp->text.move(6, 0);
            temp = temp->next;
        }
        this->drawNodes(window);
        this->display(window);
        window.display();
    }
    std::this_thread::sleep_for(delayTime); 

    // Recolor the node
    SLL_Node* cur = this->NodeArray;
    while (cur != newNode)
    {
        cur->circle.setFillColor(sf::Color::Yellow);
        cur = cur->next;
    }
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    this->size++;
}

int DataVisualization_3::getSLLSize()
{
    SLL_Node* temp = this->NodeArray;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void DataVisualization_3::DeleteNodeFront(sf::RenderWindow &window)
{   
    if (this->NodeArray == nullptr)
    {
        printMessage(window, "There is no Node to be deleted!");
        return;
    }
    std::chrono::milliseconds delayTime(1000); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05
    SLL_Node* cur = this->NodeArray;
    this->NodeArray = this->NodeArray->next;

    window.clear(sf::Color(22, 73, 154));
    cur->circle.setFillColor(sf::Color::Red);
    drawArrow(window, cur->circle.getPosition(), this->NodeArray->circle.getPosition());
    window.draw(cur->circle);
    window.draw(cur->text);
    this->drawNodes(window);
    this->display(window);
    window.display();

    std::this_thread::sleep_for(delayTime); 
    while (cur->circle.getRadius() > 16)
    {
        float radius = cur->circle.getRadius();
        radius = radius * 0.75;
        cur->circle.setRadius(radius);
        cur->circle.setOrigin(radius, radius);
        cur->text.setCharacterSize(radius / 3.f * 2.f);
        cur->text.setOrigin(cur->text.getLocalBounds().width / 2.f, cur->text.getLocalBounds().height / 2.f);
        window.clear(sf::Color(22, 73, 154));
        drawArrow(window, cur->circle.getPosition(), this->NodeArray->circle.getPosition());
        window.draw(cur->circle);
        window.draw(cur->text);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }
    delete cur;
    cur = nullptr;
    window.clear(sf::Color(22, 73, 154));   
    this->drawNodes(window);
    this->display(window);
    window.display();
    // move left after delete
    for (int i = 0; i < 25; i++)
    {
        SLL_Node* temp = this->NodeArray;
        while (temp != nullptr)
        {
            window.clear(sf::Color(22, 73, 154));
            temp->circle.move(-6, 0);
            temp->text.move(-6, 0);
            temp = temp->next;
        }
        this->drawNodes(window);
        this->display(window);
        window.display();
    }
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    this->size--;
}   

void DataVisualization_3::DeleteNodeBack(sf::RenderWindow &window)
{   
    if (this->NodeArray == nullptr) 
    {
        printMessage(window, "There is no Node to be deleted!");
        return;
    }
    std::chrono::milliseconds delayTime(1000); // 1 second
    std::chrono::milliseconds delayTime1(50); // 0.05
    std::chrono::milliseconds delayTime2(500);
    SLL_Node* cur = this->NodeArray;
    SLL_Node* pre = cur;
    sf::Vector2f Pos = cur->circle.getPosition();

    while (cur->next != nullptr)
    {
        window.clear(sf::Color(22, 73, 154));
        cur->circle.setFillColor(sf::Color::Green);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime2); 
        pre = cur;
        cur = cur->next;
    }
    cur->circle.setFillColor(sf::Color::Red);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    while (cur->circle.getRadius() > 16)
    {
        float radius = cur->circle.getRadius();
        radius = radius * 0.75;
        cur->circle.setRadius(radius);
        cur->circle.setOrigin(radius, radius);
        cur->text.setCharacterSize(radius / 3.f * 2.f);
        cur->text.setOrigin(cur->text.getLocalBounds().width / 2.f, cur->text.getLocalBounds().height / 2.f);
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }


    // delete
    pre->next = nullptr;
    if (cur == NodeArray) {
        delete cur;
        NodeArray = nullptr;
        return;
    }
    delete cur;
    cur = nullptr;
    window.clear(sf::Color(22, 73, 154));   
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2); 
    cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color::Yellow);
        cur = cur->next;
    }
    this->size--;
}   

void DataVisualization_3::DeleteNodeMid(sf::RenderWindow &window, int index)
{   
    if (this->NodeArray == nullptr) 
    {
        printMessage(window, "There is no Node to be deleted!");
        return;
    }
    // int index = 1 + rand() % (this->getSLLSize());
    if (index <= 0 || index > this->getSLLSize())
    {
        std::string mess = "Index must be from 1 to " + std::to_string(this->getSLLSize());
        printMessage(window, mess);
        return;
    }
    // handle special event
    if (index == 1) 
    {
        DeleteNodeFront(window);
        return;
    } else if (index == this->getSLLSize())
    {
        DeleteNodeBack(window);
        return;
    }

    std::chrono::milliseconds delayTime(1000); // 1 second
    std::chrono::milliseconds delayTime1(50); // 0.05
    std::chrono::milliseconds delayTime2(500);
    
    // color Green
    SLL_Node* cur = this->NodeArray;
    SLL_Node* pre = nullptr;
    for (int i = 1; i < index; i++)
    {
        cur->circle.setFillColor(sf::Color::Green);
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
        pre = cur;
        cur = cur->next;
        std::this_thread::sleep_for(delayTime2); 
    }
    // color Red
    cur->circle.setFillColor(sf::Color::Red);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2); 
    // delete it 
    for (int i = 0; i < 25; i++)
    {
        cur->circle.move(0, 6);
        cur->text.move(0, 6);
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
    }

    std::this_thread::sleep_for(delayTime2); 
    pre->next = cur->next;
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.draw(cur->circle);
    window.draw(cur->text);
    window.display();

    // move left for the rest
    pre = pre->next;
    for (int i = 0; i < 25; i++)
    {
        SLL_Node* temp = pre;
        while (temp != nullptr)
        {
            temp->circle.move(-6, 0);
            temp->text.move(-6, 0);
            temp = temp->next;
        }
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.draw(cur->circle);
        window.draw(cur->text);
        window.display();
    }
    std::this_thread::sleep_for(delayTime2); 
    
    delete cur;
    cur = nullptr;
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    // recolor yellow
    cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color::Yellow);
        cur = cur->next;
    }
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    this->size--;
}   

void DataVisualization_3::DeleteNodeMidSLL(sf::RenderWindow &window, sf::Event &event)
{
    if (this->DeleteMid_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->DeleteMid_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->DeleteMid_Textbox.pressEnter == true)
        {
            int index = std::stoi(str);
            this->DeleteNodeMid(window, index);
        }
        this->DeleteMid_Textbox.pressEnter = false;
    }
}

void DataVisualization_3::UpdateNode(sf::RenderWindow &window, int index, int value)
{
    if (index <= 0 || index > this->size)
    {
        std::string str = "Index must be from 1 to " + std::to_string(this->size);
        printMessage(window, str);
        return;
    } 

    std::chrono::milliseconds delayTime(1000); // 1 second
    std::chrono::milliseconds delayTime1(50); // 0.05
    std::chrono::milliseconds delayTime2(500);

    // std::cout << "Update success" << std::endl;
    // std::cout << "Index: " << index << std::endl;
    // std::cout << "Value: " << value << std::endl;
    SLL_Node* temp = this->NodeArray;
    for (int i = 1; i < index; i++)
    {
        temp->circle.setFillColor(sf::Color::Green);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime2); 
        temp = temp->next;
    }

    temp->circle.setFillColor(sf::Color::Red);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2);

    while (temp->circle.getRadius() < 40)
    {
        float radius = temp->circle.getRadius();
        radius = radius + 2;
        temp->circle.setRadius(radius);
        temp->circle.setOrigin(radius, radius);
        temp->text.setCharacterSize(radius / 3.f * 2.f);
        temp->text.setOrigin(temp->text.getLocalBounds().width / 2.f, temp->text.getLocalBounds().height / 2.f);
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }
    temp->text.setString(std::to_string(value));
    while (temp->circle.getRadius() > 30)
    {
        float radius = temp->circle.getRadius();
        radius = radius - 2;
        temp->circle.setRadius(radius);
        temp->circle.setOrigin(radius, radius);
        temp->text.setCharacterSize(radius / 3.f * 2.f);
        temp->text.setOrigin(temp->text.getLocalBounds().width / 2.f, temp->text.getLocalBounds().height / 2.f);
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }
    //recoloring
    temp = this->NodeArray;
    while (temp != nullptr)
    {
        temp->circle.setFillColor(sf::Color::Yellow);
        temp = temp->next;
    }
}

void DataVisualization_3::UpdateNodeSLL(sf::RenderWindow &window, sf::Event &event)
{
    if (this->UpdateNode_Textbox.isSelected)
    {
        static int value = -1;
        static int index = -1;

        // Receive input string
        std::string str = "";
        this->UpdateNode_Textbox.TextboxHandleEvent(event, str);

        // Check if input is valid
        if (str != "" && this->UpdateNode_Textbox.pressEnter == true)
        {
            if (index == -1) {
                index = std::stoi(str);
                this->UpdateNode_Textbox.EnterMessage.setString("Value: ");
            }
            else {
                value = std::stoi(str);
                this->UpdateNode(window, index, value);
                this->UpdateNode_Textbox.EnterMessage.setString("Index: ");
                value = -1;
                index = -1;
            }
            this->UpdateNode_Textbox.pressEnter = false;
        }
    }
}

void DataVisualization_3::SearchNode(sf::RenderWindow &window, int value)
{
    if (NodeArray == nullptr)
    {
        printMessage(window, "There is no Node to be searched");
        return;
    }
    SLL_Node* temp = NodeArray;
    std::chrono::milliseconds delayTime(1000); // 1 second
    std::chrono::milliseconds delayTime1(50); // 0.05
    std::chrono::milliseconds delayTime2(500);
    int index = 0;

    while (temp != nullptr)
    {
        index++;
        temp->circle.setFillColor(sf::Color::Green);
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime2);

        if (temp->data == value) {
            std::string mess = "Founded at index " + std::to_string(index);
            temp->circle.setFillColor(sf::Color::Red);
            window.clear(sf::Color(22, 73, 154));
            this->drawNodes(window);
            this->display(window);
            window.display();
            std::this_thread::sleep_for(delayTime2);
            printMessage(window, mess);
            break;
        }
        temp = temp->next;
    }
    if (temp == nullptr) // case that value not found
    {
        printMessage(window, "Value not found!");
    }
    // recolor yellow again
    temp = NodeArray;
    while (temp != nullptr)
    {
        temp->circle.setFillColor(sf::Color::Yellow);
        temp = temp->next;
    }
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
}

void DataVisualization_3::SearchNodeSLL(sf::RenderWindow &window, sf::Event &event)
{
    if (this->SearchNode_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->SearchNode_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->SearchNode_Textbox.pressEnter == true)
        {
            int value = std::stoi(str);
            this->SearchNode(window, value);
        }
        this->SearchNode_Textbox.pressEnter = false;
    }
}

bool DataVisualization_3::printMessage(sf::RenderWindow &window, std::string message/*, int min_range, int max_range, int value*/)
{
    // if (size < 10) return true;
    std::chrono::milliseconds delayTime(750);
    sf::Text WarningMessage;
    WarningMessage.setString(message);
    WarningMessage.setCharacterSize(50);
    WarningMessage.setFillColor(sf::Color::White);
    WarningMessage.setOutlineColor(sf::Color::Red);
    WarningMessage.setOutlineThickness(5);
    WarningMessage.setFont(this->font);
    WarningMessage.setOrigin(WarningMessage.getLocalBounds().width/2.f, WarningMessage.getLocalBounds().height/2.f);
    WarningMessage.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    window.draw(WarningMessage);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return true;
}

DataVisualization_4::DataVisualization_4()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV4Title("Doubly Linked List", this->font, 90);
    CreateTitle(DV4Title, 1920 / 2.f, 50.f);
    this->Title = DV4Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_4::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

void DataVisualization_4::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

DataVisualization_5::DataVisualization_5()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV5Title("Circular Linked List", this->font, 90);
    CreateTitle(DV5Title, 1920 / 2.f, 50.f);
    this->Title = DV5Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_5::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

void DataVisualization_5::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

DataVisualization_6::DataVisualization_6()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV6Title("Stack", this->font, 90);
    CreateTitle(DV6Title, 1920 / 2.f, 50.f);
    this->Title = DV6Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_6::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

void DataVisualization_6::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}

DataVisualization_7::DataVisualization_7()
{
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV7Title("Queue", this->font, 90);
    CreateTitle(DV7Title, 1920 / 2.f, 50.f);
    this->Title = DV7Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_7::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

void DataVisualization_7::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
        }
    }
}
// Testing------------------------------------------------------