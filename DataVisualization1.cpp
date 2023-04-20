#include "DataVisualization1.hpp"


DataVisualization_1::DataVisualization_1()
{
//Fonts
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
    if (!page2texture.loadFromFile("media/img/menubackground.jpg")) 
    {
        std::cerr << "Failed to load BackGround" << "\n";
        return;
    }

    NotificationImage.setImage("media/img/noti_board.png");
    NotificationImage.setPosition(sf::Vector2f(1920/2.f, 1080/4.f - 150));

    this->speed = 2;
    speedText.setCharacterSize(20);
    speedText.setFont(font);
    speedText.setFillColor(sf::Color::White);
    speedText.setString("Speed: x" + std::to_string(speed));
    speedText.setOrigin(sf::Vector2f(speedText.getLocalBounds().width / 2.f, speedText.getLocalBounds().height / 2.f));
    speedText.setPosition(sf::Vector2f(250, 1010));

    FlowControlMenu.setFillColor(sf::Color::Black);
    FlowControlMenu.setOutlineColor(sf::Color::White);
    FlowControlMenu.setOutlineThickness(2);
    FlowControlMenu.setSize(sf::Vector2f(1920, 100));
    FlowControlMenu.setPosition(sf::Vector2f(0, 980));
    PauseButton.setImage("media/img/pause_button.png");
    PauseButton.setPosition(sf::Vector2f(960, 1000));
    ReplayButton.setImage("media/img/play_button.png");
    ReplayButton.setPosition(sf::Vector2f(960, 1000));
    NextButton.setImage("media/img/next_button.png");
    NextButton.setPosition(sf::Vector2f(1010, 1000));
    SkipButton.setImage("media/img/skip_button.png");
    SkipButton.setPosition(sf::Vector2f(1060, 1000));
    NextButtonReverse.setImage("media/img/next_button_reverse.png");
    NextButtonReverse.setPosition(sf::Vector2f(910, 1000));
    SkipButtonReverse.setImage("media/img/skip_button_reverse.png");
    SkipButtonReverse.setPosition(sf::Vector2f(860, 1000));
    IncreaseSpeedButton.setImage("media/img/add_button.png");
    IncreaseSpeedButton.setPosition(sf::Vector2f(330, 1002));
    DecreaseSpeedButton.setImage("media/img/minus_btn.png");
    DecreaseSpeedButton.setPosition(sf::Vector2f(380, 1002));
    isPause = true;

    // Code Script
    CodeScriptPosition = sf::Vector2f(1520,640);
    CodeHighLightPosition = sf::Vector2f(1170, 697.5f);
    CodeScript.setPosition(CodeScriptPosition);
    CodeHighLight.setSize(sf::Vector2f(700, 30));
    CodeHighLight.setFillColor(sf::Color(106, 231, 255, 100));
    CodeHighLight.setOutlineColor(sf::Color(106, 231, 255));
    //---------------------
    CodeHighLight.setPosition(CodeHighLightPosition); // 1170 - 697.5 ~ 35
    //---------------------

    //Title
    sf::Text DV3Title("Static Array", this->titlefont, 35);
    CreateTitle(DV3Title, 400, 60.f);
    this->Title = DV3Title;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 250.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 100.f);

    //Function Key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 125.f, sf::Color(106, 231, 255, 0), "Create", this->font, sf::Color(106, 231, 255));

    this->CreateEmpty.CreateButton(130.f, 50.f, this->ControlMenu_btn1.rect.getPosition().x + this->ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Empty", this->font, sf::Color(106, 231, 255));
    this->CreateEmpty.rect.setOutlineThickness(2.f);
    this->CreateEmpty.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->CreateRadom.CreateButton(130.f, 50.f, this->CreateEmpty.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random", this->font, sf::Color(106, 231, 255));
    this->CreateRadom.rect.setOutlineThickness(2.f);
    this->CreateRadom.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->CreateRandomSort.CreateButton(130.f, 50.f, this->CreateRadom.rect.getPosition().x + this->CreateRadom.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random Sort", this->font, sf::Color(106, 231, 255));
    this->CreateRandomSort.rect.setOutlineThickness(2.f);
    this->CreateRandomSort.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    this->CreateRandomFixedSize.CreateButton(180.f, 50.f, this->CreateRandomSort.rect.getPosition().x + this->CreateRandomSort.rect.getSize().x / 2.f + 160.f / 2.f + 20.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random Fixed Size", this->font, sf::Color(106, 231, 255));
    this->CreateRandomFixedSize.rect.setOutlineThickness(2.f);
    this->CreateRandomFixedSize.rect.setOutlineColor(sf::Color(106, 231, 255));

    InitTextbox(this->CreateRandomFixedSize_Textbox, 20, sf::Color::White, true, this->CreateRandomFixedSize.rect.getPosition().x , this->CreateRandomFixedSize.rect.getPosition().y + 50, font, true, 3);
    this->CreateRandomFixedSize_Textbox.EnterMessage.setString("Size: ");
    
    this->CreateUserDefinedListButton.CreateButton(130.f, 50.f, this->CreateRandomFixedSize.rect.getPosition().x + this->CreateRandomFixedSize.rect.getSize().x / 2.f + 130.f/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "User Defined", this->font, sf::Color(106, 231, 255));
    this->CreateUserDefinedListButton.rect.setOutlineThickness(2.f);
    this->CreateUserDefinedListButton.rect.setOutlineColor(sf::Color(106, 231, 255));

    InitTextbox(this->CreateUserDefinedList_Textbox, 20, sf::Color::White, true, this->CreateUserDefinedListButton.rect.getPosition().x, this->CreateUserDefinedListButton.rect.getPosition().y + 50, font, true, 3);
    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size: ");

    //Function Key #2: Adding
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateButton.CreateButton(130.f, 50.f, this->ControlMenu_btn2.rect.getPosition().x + this->ControlMenu_btn2.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateButton.rect.setOutlineThickness(2.f);
    this->UpdateButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->UpdateButton_Textbox, 20, sf::Color::White, true, this->UpdateButton.rect.getPosition().x, this->UpdateButton.rect.getPosition().y + 50, font, true, 3);
    this->UpdateButton_Textbox.EnterMessage.setString("Value: ");
    
    // this->InsertBack.CreateButton(130.f, 50.f, this->InsertHead.rect.getPosition().x + this->InsertHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    // this->InsertBack.rect.setOutlineThickness(2.f);
    // this->InsertBack.rect.setOutlineColor(sf::Color(106, 231, 255));
    // InitTextbox(this->InsertBack_Textbox, 20, sf::Color::White, true, this->InsertBack.rect.getPosition().x, this->InsertBack.rect.getPosition().y + 50, font, true, 3);
    // this->InsertBack_Textbox.EnterMessage.setString("Value: ");
    // this->InsertMid.CreateButton(130.f, 50.f, this->InsertBack.rect.getPosition().x + this->InsertBack.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Mid", this->font, sf::Color(106, 231, 255));
    // this->InsertMid.rect.setOutlineThickness(2.f);
    // this->InsertMid.rect.setOutlineColor(sf::Color(106, 231, 255));
    // InitTextbox(this->InsertMid_Textbox, 20, sf::Color::White, true, this->InsertMid.rect.getPosition().x, this->InsertMid.rect.getPosition().y + 50, font, true, 3);
    // this->InsertMid_Textbox.EnterMessage.setString("Value: ");

    //Function Key #3
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.rect.setOutlineThickness(2.f);
    this->SearchButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->SearchButton_Textbox, 20, sf::Color::White, true, this->SearchButton.rect.getPosition().x, this->SearchButton.rect.getPosition().y + 50, font, true, 3);
    this->SearchButton_Textbox.EnterMessage.setString("Index: ");
    // this->DeleteHead.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Head", this->font, sf::Color(106, 231, 255));
    // this->DeleteHead.rect.setOutlineThickness(2.f);
    // this->DeleteHead.rect.setOutlineColor(sf::Color(106, 231, 255));

    // this->DeleteBack.CreateButton(130.f, 50.f, this->DeleteHead.rect.getPosition().x + this->DeleteHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    // this->DeleteBack.rect.setOutlineThickness(2.f);
    // this->DeleteBack.rect.setOutlineColor(sf::Color(106, 231, 255));
    

    //Function Key #4
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Sort", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Ascending", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.rect.setOutlineThickness(2.f);
    this->SortButtonAscending.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->SortButtonDescending.CreateButton(130.f, 50.f, this->SortButtonAscending.rect.getPosition().x + this->SortButtonAscending.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Descending", this->font, sf::Color(106, 231, 255));
    this->SortButtonDescending.rect.setOutlineThickness(2.f);
    this->SortButtonDescending.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    // InitTextbox(this->UpdateNode_Textbox, 20, sf::Color::White, true, this->UpdateNodeButton.rect.getPosition().x, this->UpdateNodeButton.rect.getPosition().y + 50, font, true, 3);
    // this->UpdateNode_Textbox.EnterMessage.setString("Index: ");
    // //Function Key #5
    // this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    // this->SearchNodeButton.CreateButton(130.f, 50.f, this->ControlMenu_btn5.rect.getPosition().x + this->ControlMenu_btn5.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    // this->SearchNodeButton.rect.setOutlineThickness(2.f);
    // this->SearchNodeButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    // InitTextbox(this->SearchNode_Textbox, 20, sf::Color::White, true, this->SearchNodeButton.rect.getPosition().x, this->SearchNodeButton.rect.getPosition().y + 50, font, true, 3);
    // this->SearchNode_Textbox.EnterMessage.setString("Value:");

    this->size = 0;
    // this->NodeArray = nullptr;
    funcstate = 0;    
}

void DataVisualization_1::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
    window.draw(this->menuTable);
    speedText.setString("Speed: x" + std::to_string(speed));
    window.draw(speedText);
    CodeScript.drawImage(window);
    this->ControlMenu_btn1.displayButton(window);
    this->ControlMenu_btn2.displayButton(window);
    this->ControlMenu_btn3.displayButton(window);
    this->ControlMenu_btn4.displayButton(window);
    // this->ControlMenu_btn5.displayButton(window); 

    window.draw(FlowControlMenu);
    this->NextButtonReverse.drawImage(window);
    this->SkipButtonReverse.drawImage(window);
    this->NextButton.drawImage(window);
    this->SkipButton.drawImage(window);
    this->IncreaseSpeedButton.drawImage(window);
    this->DecreaseSpeedButton.drawImage(window);
    if (this->isPause)
        this->PauseButton.drawImage(window);
    else 
        this->ReplayButton.drawImage(window);
    speedText.setString("Speed: x" + std::to_string(speed));
    window.draw(speedText);

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
        this->UpdateButton.displayButton(window);
        this->UpdateButton_Textbox.drawTo(window);
        // this->InsertHead.displayButton(window);
        // this->InsertBack.displayButton(window);
        // this->InsertMid.displayButton(window);
        // this->InsertHead_Textbox.drawTo(window);
        // this->InsertBack_Textbox.drawTo(window);
        // this->InsertMid_Textbox.drawTo(window);
        break;
    case 3:
        this->SearchButton.displayButton(window);
        this->SearchButton_Textbox.drawTo(window);
        // this->DeleteBack.displayButton(window);
        // this->DeleteHead.displayButton(window);
        // this->DeleteMid.displayButton(window);
        // this->DeleteMid_Textbox.drawTo(window);
        break;
    case 4:
        this->SortButtonAscending.displayButton(window);
        this->SortButtonDescending.displayButton(window);
        // this->UpdateNodeButton.displayButton(window);
        // this->UpdateNode_Textbox.drawTo(window);
        break;
    default: // NONE - 0
        break;
    }
}

void DataVisualization_1::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
            // DefaultBackground.setTexture(this->page2texture);
            // this->NodeArray->DeleteSLL(this->NodeArray);
            // this->NodeArray = nullptr;
            this->size = 0;
            this->funcstate = 0;
            this->speed = 2;
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
        else if (this->PauseButton.ImageHolder.getGlobalBounds().contains(mousePos))
        {
            this->isPause = !this->isPause;
        }
        else if (this->IncreaseSpeedButton.ImageHolder.getGlobalBounds().contains(mousePos))
        {
            if (this->speed < 4) {
                this->speed++;
            }
        }
        else if (this->DecreaseSpeedButton.ImageHolder.getGlobalBounds().contains(mousePos))
        {
            if (this->speed > 1) {
                this->speed--;
            }
        }
        else {
            // this->CreateRandomFixedSize_Textbox.isSelected = false;
            // this->InsertBack_Textbox.isSelected = false;
            // this->InsertHead_Textbox.isSelected = false;
            // this->DeleteMid_Textbox.isSelected = false;
            // this->SearchNode_Textbox.isSelected = false;
            // this->InsertMid_Textbox.isSelected = false;
            // this->CreateUserDefinedList_Textbox.isSelected = false;
            // this->UpdateNode_Textbox.isSelected = false;
        }
        switch (this->funcstate)
        {
        // case 1:
        //     if (this->CreateEmpty.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->NodeArray->DeleteSLL(this->NodeArray);
        //         this->NodeArray = nullptr;
        //         this->size = 0;
        //     }
        //     if (this->CreateRadom.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->NodeArray->CreateRandomNodes(this->NodeArray, this->size, this->font);
        //     }
        //     if (this->CreateRandomSort.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->NodeArray->CreateRandomSortSLL(this->NodeArray, this->size, this->font);
        //     }
        //     if (this->CreateRandomFixedSize.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->CreateRandomFixedSize_Textbox.isSelected = !this->CreateRandomFixedSize_Textbox.isSelected;
        //     } else {
        //         this->CreateRandomFixedSize_Textbox.isSelected = false;
        //     }
        //     if (this->CreateUserDefinedListButton.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->CreateUserDefinedList_Textbox.isSelected = !this->CreateUserDefinedList_Textbox.isSelected;
        //     } else {
        //         this->CreateUserDefinedList_Textbox.isSelected = false;
        //     }
        //     break;  
            
        // case 2:
        //     if (this->InsertHead.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->InsertHead_Textbox.isSelected = !this->InsertHead_Textbox.isSelected;
        //     } else {
        //         this->InsertHead_Textbox.isSelected = false;
        //     }
        //     if (this->InsertBack.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->InsertBack_Textbox.isSelected = !this->InsertBack_Textbox.isSelected;
        //     } else {
        //         this->InsertBack_Textbox.isSelected = false;
        //     }
        //     if (this->InsertMid.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->InsertMid_Textbox.isSelected = !this->InsertMid_Textbox.isSelected;
        //     } else {
        //         this->InsertMid_Textbox.isSelected = false;
        //     }
        //     break;
        // case 3:
        //     if (this->DeleteHead.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->DeleteNodeFront(window);
        //     }
        //     if (this->DeleteBack.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->DeleteNodeBack(window);
        //     }
        //     if (this->DeleteMid.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->DeleteMid_Textbox.isSelected = !this->DeleteMid_Textbox.isSelected;
        //     } else {
        //         this->DeleteMid_Textbox.isSelected = false;
        //     }
        //     break;
        // case 4:
        //     if (this->UpdateNodeButton.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->UpdateNode_Textbox.isSelected = !this->UpdateNode_Textbox.isSelected;
        //     } else {
        //         this->UpdateNode_Textbox.isSelected = false;
        //     }
        // case 5:
        //     if (this->SearchNodeButton.rect.getGlobalBounds().contains(mousePos))
        //     {
        //         this->SearchNode_Textbox.isSelected = !this->SearchNode_Textbox.isSelected;
        //     } else {
        //         this->SearchNode_Textbox.isSelected = false;
        //     }
        default:
            break;
        }
    }
    else if (ev.type == sf::Event::TextEntered)
    {
        // CreateRandomFixedSizeSLL(window, ev); 
        // CreateUserDefinedListSLL(window, ev);
        // InsertNodeFrontSLL(window, ev);
        // InsertNodeBackSLL(window, ev);
        // InsertNodeMidSLL(window, ev);
        // DeleteNodeMidSLL(window, ev);
        // SearchNodeSLL(window, ev);
        // UpdateNodeSLL(window, ev);
    }
    else if (ev.type == sf::Event::MouseMoved)
    {
        if (this->ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn1.rect.setFillColor(sf::Color(106, 231, 255));
            this->ControlMenu_btn1.text.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn1.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ControlMenu_btn1.text.setFillColor(sf::Color(106, 231, 255));
        }
        if (this->ControlMenu_btn2.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn2.rect.setFillColor(sf::Color(106, 231, 255));
            this->ControlMenu_btn2.text.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn2.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ControlMenu_btn2.text.setFillColor(sf::Color(106, 231, 255));
        }
        if (this->ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn3.rect.setFillColor(sf::Color(106, 231, 255));
            this->ControlMenu_btn3.text.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn3.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ControlMenu_btn3.text.setFillColor(sf::Color(106, 231, 255));
        }
        if (this->ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn4.rect.setFillColor(sf::Color(106, 231, 255));
            this->ControlMenu_btn4.text.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn4.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ControlMenu_btn4.text.setFillColor(sf::Color(106, 231, 255));
        }
    }
}

