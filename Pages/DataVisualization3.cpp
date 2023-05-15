#include "DataVisualization3.hpp"

DataVisualization_3::DataVisualization_3()
{
    //Fonts
    this->font = defautFont;
    this->titlefont = defautTitleFont;
    NotificationImage.setImage(WorkingPath + "media/img/noti_board.png");
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
    PauseButton.setImage(WorkingPath + "media/img/pause_button.png");
    PauseButton.setPosition(sf::Vector2f(960, 1000));
    ReplayButton.setImage(WorkingPath + "media/img/play_button.png");
    ReplayButton.setPosition(sf::Vector2f(960, 1000));
    NextButton.setImage(WorkingPath + "media/img/next_button.png");
    NextButton.setPosition(sf::Vector2f(1010, 1000));
    SkipButton.setImage(WorkingPath + "media/img/skip_button.png");
    SkipButton.setPosition(sf::Vector2f(1060, 1000));
    NextButtonReverse.setImage(WorkingPath + "media/img/next_button_reverse.png");
    NextButtonReverse.setPosition(sf::Vector2f(910, 1000));
    SkipButtonReverse.setImage(WorkingPath + "media/img/skip_button_reverse.png");
    SkipButtonReverse.setPosition(sf::Vector2f(860, 1000));
    IncreaseSpeedButton.setImage(WorkingPath + "media/img/add_button.png");
    IncreaseSpeedButton.setPosition(sf::Vector2f(330, 1002));
    DecreaseSpeedButton.setImage(WorkingPath + "media/img/minus_btn.png");
    DecreaseSpeedButton.setPosition(sf::Vector2f(380, 1002));
    DeleteCodeScriptButton.setImage(WorkingPath + "media/img/deleteCodeHightLight.png");
    DeleteCodeScriptButton.setPosition(sf::Vector2f(1870, 630));
    isPause = true;

    // Code Script
    CodeScriptPosition = sf::Vector2f(1520,640);
    CodeHighLightPosition = sf::Vector2f(1170, 697.5f);
    CodeScript.setPosition(CodeScriptPosition);
    CodeHighLight.setSize(sf::Vector2f(700, 30));
    CodeHighLight.setFillColor(sf::Color(106, 231, 255, 100));
    CodeHighLight.setOutlineColor(sf::Color(106, 231, 255));
    CodeHighLight.setPosition(CodeHighLightPosition); // 1170 - 697.5 ~ 35

    //Title
    sf::Text DV3Title("Singly Linked List", this->titlefont, 35);
    CreateTitle(DV3Title, 400, 60.f);
    this->Title = DV3Title;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 300.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 50.f);

    //Function Key #0
    this->ImportFromFileButton.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 75.f, sf::Color(106, 231, 255, 0), "Import", this->font, sf::Color(106, 231, 255));

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
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Add", this->font, sf::Color(106, 231, 255));
    this->InsertHead.CreateButton(130.f, 50.f, this->ControlMenu_btn2.rect.getPosition().x + this->ControlMenu_btn2.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Head", this->font, sf::Color(106, 231, 255));
    this->InsertHead.rect.setOutlineThickness(2.f);
    this->InsertHead.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->InsertHead_Textbox, 20, sf::Color::White, true, this->InsertHead.rect.getPosition().x, this->InsertHead.rect.getPosition().y + 50, font, true, 3);
    this->InsertHead_Textbox.EnterMessage.setString("Value: ");
    
    this->InsertBack.CreateButton(130.f, 50.f, this->InsertHead.rect.getPosition().x + this->InsertHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->InsertBack.rect.setOutlineThickness(2.f);
    this->InsertBack.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->InsertBack_Textbox, 20, sf::Color::White, true, this->InsertBack.rect.getPosition().x, this->InsertBack.rect.getPosition().y + 50, font, true, 3);
    this->InsertBack_Textbox.EnterMessage.setString("Value: ");
    this->InsertMid.CreateButton(130.f, 50.f, this->InsertBack.rect.getPosition().x + this->InsertBack.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Mid", this->font, sf::Color(106, 231, 255));
    this->InsertMid.rect.setOutlineThickness(2.f);
    this->InsertMid.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->InsertMid_Textbox, 20, sf::Color::White, true, this->InsertMid.rect.getPosition().x, this->InsertMid.rect.getPosition().y + 50, font, true, 3);
    this->InsertMid_Textbox.EnterMessage.setString("Value: ");

    //Function Key #3
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Delete", this->font, sf::Color(106, 231, 255));
    this->DeleteHead.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Head", this->font, sf::Color(106, 231, 255));
    this->DeleteHead.rect.setOutlineThickness(2.f);
    this->DeleteHead.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->DeleteBack.CreateButton(130.f, 50.f, this->DeleteHead.rect.getPosition().x + this->DeleteHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->DeleteBack.rect.setOutlineThickness(2.f);
    this->DeleteBack.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    this->DeleteMid.CreateButton(130.f, 50.f, this->DeleteBack.rect.getPosition().x + this->DeleteBack.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Mid", this->font, sf::Color(106, 231, 255));
    this->DeleteMid.rect.setOutlineThickness(2.f);
    this->DeleteMid.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    InitTextbox(this->DeleteMid_Textbox, 20, sf::Color::White, true, this->DeleteMid.rect.getPosition().x, this->DeleteMid.rect.getPosition().y + 50, font, true, 3);
    this->DeleteMid_Textbox.EnterMessage.setString("Index: ");

    //Function Key #4
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateNodeButton.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateNodeButton.rect.setOutlineThickness(2.f);
    this->UpdateNodeButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->UpdateNode_Textbox, 20, sf::Color::White, true, this->UpdateNodeButton.rect.getPosition().x, this->UpdateNodeButton.rect.getPosition().y + 50, font, true, 3);
    this->UpdateNode_Textbox.EnterMessage.setString("Index: ");

    //Function Key #5
    this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchNodeButton.CreateButton(130.f, 50.f, this->ControlMenu_btn5.rect.getPosition().x + this->ControlMenu_btn5.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchNodeButton.rect.setOutlineThickness(2.f);
    this->SearchNodeButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->SearchNode_Textbox, 20, sf::Color::White, true, this->SearchNodeButton.rect.getPosition().x, this->SearchNodeButton.rect.getPosition().y + 50, font, true, 3);
    this->SearchNode_Textbox.EnterMessage.setString("Value:");

    this->HeadText.setString("Head");
    this->HeadText.setFont(this->font);
    this->HeadText.setCharacterSize(20);
    this->HeadText.setOrigin(sf::Vector2f(this->HeadText.getLocalBounds().width / 2.f , this->HeadText.getLocalBounds().height / 2.f));
    
    this->vtxText.setString("vtx");
    this->vtxText.setFont(this->font);
    this->vtxText.setCharacterSize(20);
    this->vtxText.setOrigin(sf::Vector2f(this->vtxText.getLocalBounds().width / 2.f , this->vtxText.getLocalBounds().height / 2.f));
    
    this->aftText.setString("aft");
    this->aftText.setFont(this->font);
    this->aftText.setCharacterSize(20);
    this->aftText.setOrigin(sf::Vector2f(this->aftText.getLocalBounds().width / 2.f , this->aftText.getLocalBounds().height / 2.f));
    
    this->preText.setString("pre");
    this->preText.setFont(this->font);
    this->preText.setCharacterSize(20);
    this->preText.setOrigin(sf::Vector2f(this->preText.getLocalBounds().width / 2.f , this->preText.getLocalBounds().height / 2.f));
    
    this->delText.setString("del");
    this->delText.setFont(this->font);
    this->delText.setCharacterSize(20);
    this->delText.setOrigin(sf::Vector2f(this->delText.getLocalBounds().width / 2.f , this->delText.getLocalBounds().height / 2.f));
    
    this->tailText.setString("tail");
    this->tailText.setFont(this->font);
    this->tailText.setCharacterSize(20);
    this->tailText.setOrigin(sf::Vector2f(this->tailText.getLocalBounds().width / 2.f , this->tailText.getLocalBounds().height / 2.f));
    
    this->curText.setString("cur");
    this->curText.setFont(this->font);
    this->curText.setCharacterSize(20);
    this->curText.setOrigin(sf::Vector2f(this->curText.getLocalBounds().width / 2.f , this->curText.getLocalBounds().height / 2.f));
    
    this->size = 0;
    this->NodeArray = nullptr;
    funcstate = 0;
}

void DataVisualization_3::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
    window.draw(this->menuTable);
    speedText.setString("Speed: x" + std::to_string(speed));
    window.draw(speedText);
    if (this->NodeArray != nullptr)
    {
        this->HeadText.setPosition(sf::Vector2f(this->NodeArray->circle.getPosition().x, this->NodeArray->circle.getPosition().y + 50));
        window.draw(this->HeadText);
    }
    if (CodeScriptVisible)
    {
        CodeScript.drawImage(window);
        DeleteCodeScriptButton.drawImage(window);
    }
    this->ImportFromFileButton.displayButton(window);
    this->ControlMenu_btn1.displayButton(window);
    this->ControlMenu_btn2.displayButton(window);
    this->ControlMenu_btn3.displayButton(window);
    this->ControlMenu_btn4.displayButton(window);
    this->ControlMenu_btn5.displayButton(window); 

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

void DataVisualization_3::NodeTextsetPos(sf::Text &text, SLL_Node* &pHead)
{
    if (pHead == nullptr) {
        return;
    }
    text.setPosition(sf::Vector2f(pHead->circle.getPosition().x, pHead->circle.getPosition().y + 50));
}

void DataVisualization_3::handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
            DefaultBackground.setTexture(BackGround1);
            this->NodeArray->DeleteSLL(this->NodeArray);
            this->NodeArray = nullptr;
            this->size = 0;
            this->funcstate = 0;
            this->speed = 2;
            this->CodeScriptVisible = false;
        }
        else if (this->ImportFromFileButton.rect.getGlobalBounds().contains(mousePos))
        {
            ImportFromFile(window);
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
        else if (this->DeleteCodeScriptButton.ImageHolder.getGlobalBounds().contains(mousePos))
        {
            CodeScriptVisible = false;
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
                this->NodeArray->DeleteSLL(this->NodeArray);
                this->NodeArray = nullptr;
                this->size = 0;
            }
            if (this->CreateRadom.rect.getGlobalBounds().contains(mousePos))
            {
                this->NodeArray->CreateRandomNodes(this->NodeArray, this->size, this->font);
            }
            if (this->CreateRandomSort.rect.getGlobalBounds().contains(mousePos))
            {
                this->NodeArray->CreateRandomSortSLL(this->NodeArray, this->size, this->font);
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
        if (this->ImportFromFileButton.rect.getGlobalBounds().contains(mousePos))
        {
            this->ImportFromFileButton.rect.setFillColor(sf::Color(106, 231, 255));
            this->ImportFromFileButton.text.setFillColor(sf::Color::Black);
        } else {
            this->ImportFromFileButton.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ImportFromFileButton.text.setFillColor(sf::Color(106, 231, 255));
        }
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
        if (this->ControlMenu_btn5.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn5.rect.setFillColor(sf::Color(106, 231, 255));
            this->ControlMenu_btn5.text.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn5.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ControlMenu_btn5.text.setFillColor(sf::Color(106, 231, 255));
        } 
    }
    // free
}

void DataVisualization_3::ImportFromFile(sf::RenderWindow &window)
{
    OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if (GetOpenFileName(&ofn) == TRUE)
    {
        std::ifstream inputFile(ofn.lpstrFile);

        if (inputFile.is_open())
        {
            // std::vector<int> array;
            // delete the Node
            this->NodeArray->DeleteSLL(this->NodeArray);
            int num;
            int i = 0;
            while (inputFile >> num)
            {
                SLL_Node* temp = this->NodeArray->createNode(250 + i * 150, 250, 30, this->font, num);
                this->NodeArray->addBack(this->NodeArray, temp);
                i++;
                if (i == 10)
                    break;
            }
            this->size = i;
            inputFile.close();
        }
        else
        {
            // Handle error
            std::cerr << "Error opening file." << std::endl;
        }
    }
    else
    {
        std::cout << "Cancelled" << std::endl;
    }
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
                this->NodeArray->CreateFixedNodes(this->NodeArray, this->size, this->font);
            } else {
                this->checkSize(window, size);
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
            if (num_values == 0) 
            {
                num_values = std::stoi(str);
                if (num_values > 10)
                {
                    this->printMessage(window, "Size must be from 1 to 10");
                    num_values = 0;
                    str = "";
                    values.clear();
                    this->CreateUserDefinedList_Textbox.isSelected = false;
                    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size:");
                    this->CreateUserDefinedList_Textbox.pressEnter = false;
                    return;
                }
                this->CreateUserDefinedList_Textbox.EnterMessage.setString("Value:");
            }
            else 
            {
                values.push_back(std::stoi(str));
                num_values--;
                if (num_values == 0) {
                    this->CreateUserDefinedList(window, values);
                    values.clear(); // clear Vector
                    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size:");
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
    this->NodeArray->DeleteSLL(this->NodeArray);
    int n = values.size();
    if (n < 0 || n > 10)
    {
        this->printMessage(window, "Size be must from 1 to 10");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        SLL_Node* temp = this->NodeArray->createNode(250 + i * 150, 250, 30, this->font, values[i]);
        this->NodeArray->addBack(this->NodeArray, temp);
    }
    this->size = n;
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
            this->NodeArray->drawArrow(window, first, second);
        }
        window.draw(temp->circle);
        window.draw(temp->text);
        temp = temp->next;
    }
}

DataVisualization_3::~DataVisualization_3()
{
    this->NodeArray->DeleteSLL(this->NodeArray);
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
    message.setPosition(window.getSize().x / 2.f + 20, window.getSize().y / 2.f - 240.f);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawNodes(window);
    if (this->funcstate != 2)
        window.draw(CodeHighLight);
    NotificationImage.drawImage(window);
    window.draw(message);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return false;
}

void DataVisualization_3::InsertNodeFront(sf::RenderWindow &window, int data)
{
    std::chrono::milliseconds delayTime(1000 / speed);
    std::chrono::milliseconds delayTime1(500 / speed);
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/InsertHead.png");
    CodeScriptVisible = true;

    if (this->NodeArray == nullptr)
    {
        this->NodeArray = this->NodeArray->createNode(250, 250, 30, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return;
    SLL_Node* newNode = this->NodeArray->createNode(this->NodeArray->circle.getPosition().x, this->NodeArray->circle.getPosition().y + 150, 30, this->font, data);
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(vtxText, newNode);
    this->display(window);
    this->drawNodes(window);
    window.draw(vtxText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime);
    pause_for(std::chrono::milliseconds(1000 / speed));

    //Draw the arrow + effect
    sf::CircleShape tempCircle;
    tempCircle.setPosition(sf::Vector2f(newNode->circle.getPosition().x, newNode->circle.getPosition().y - 60));
    CodeHighLight.move(0, 35);
    for (int i = 0; i < 50; i++)
    {
        tempCircle.move(0, -1.8f);
        window.clear();
        window.draw(DefaultBackground);
        window.draw(vtxText);
        this->NodeArray->drawArrow(window, newNode->circle.getPosition(), tempCircle.getPosition());
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.draw(CodeHighLight);
        window.display();
    }
    // std::this_thread::sleep_for(delayTime1);
    pause_for(std::chrono::milliseconds(500/speed));


    SLL_Node* temp = nullptr;
    CodeHighLight.move(0, 35);
    for (int i = 0; i < 50; i++)
    {
        temp = this->NodeArray;
        while (temp != nullptr)
        {
            temp->circle.move(3, 0);
            temp->text.move(3, 0);
            temp = temp->next;
        }
        window.clear();
        window.draw(DefaultBackground);
        NodeTextsetPos(vtxText, newNode);
        window.draw(vtxText);
        newNode->circle.move(0, -3);
        newNode->text.move(0, -3);
        this->NodeArray->drawArrow(window, newNode->circle.getPosition(), this->NodeArray->circle.getPosition());
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.draw(CodeHighLight);
        window.display();
    }
    newNode->next = this->NodeArray;
    this->NodeArray = newNode;
    this->size++;
    // std::this_thread::sleep_for(delayTime);
    pause_for(std::chrono::milliseconds(1000 / speed));
}

void DataVisualization_3::InsertNodeBack(sf::RenderWindow &window, int data)
{
    std::chrono::milliseconds delayTime(500 / speed); // 0.5 seconds
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/InsertBack.png");
    CodeScriptVisible = true;
    if (this->NodeArray == nullptr)
    {
        this->NodeArray = this->NodeArray->createNode(250, 250, 30, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return;
    SLL_Node* LastNode = this->NodeArray;
    while (LastNode->next != nullptr) 
    {
        LastNode = LastNode->next;
    }
    SLL_Node* newNode = this->NodeArray->createNode(LastNode->circle.getPosition().x + 150, LastNode->circle.getPosition().y + 150, 30, this->font, data);
    newNode->circle.setFillColor(sf::Color(106, 231, 255));
    newNode->text.setFillColor(sf::Color::Black);
    NodeTextsetPos(vtxText, newNode);
    window.draw(CodeHighLight);
    this->display(window);
    window.draw(vtxText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(CodeHighLight);
    window.display();
    pause_for(std::chrono::milliseconds(500 / speed));

    // create tail pointer
    HeadText.setString("Head/tail");
    CodeHighLight.move(0, 35);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawNodes(window);
    window.draw(vtxText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime);
    pause_for(std::chrono::milliseconds(500 / speed));
    //check the condition in the code highlight
    SLL_Node* temp = this->NodeArray;
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 72);
    temp->circle.setFillColor(sf::Color(106, 231, 255));
    temp->text.setFillColor(sf::Color::Black);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawNodes(window);
    window.draw(vtxText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime);
    pause_for(std::chrono::milliseconds(500 / speed));
    temp = temp->next;
    HeadText.setString("Head");

    if (temp != nullptr) {
        do
        {
            CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 108);
            window.clear();
            window.draw(DefaultBackground);
            NodeTextsetPos(tailText, temp);
            if (temp != NodeArray)
                window.draw(tailText);
            temp->circle.setFillColor(sf::Color(106, 231, 255));
            temp->text.setFillColor(sf::Color::Black);
            this->drawNodes(window);
            this->display(window);
            window.draw(vtxText);
            window.draw(newNode->circle);
            window.draw(newNode->text);
            window.draw(CodeHighLight);
            window.display();
            // std::this_thread::sleep_for(delayTime);
            pause_for(std::chrono::milliseconds(500 / speed));

        //check the condition
            CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 72);
            window.clear();
            window.draw(DefaultBackground);
            NodeTextsetPos(tailText, temp);
            if (temp != NodeArray)
                window.draw(tailText);
            this->drawNodes(window);
            this->display(window);
            window.draw(vtxText);
            window.draw(newNode->circle);
            window.draw(newNode->text);
            window.draw(CodeHighLight);
            window.display();
            // std::this_thread::sleep_for(delayTime);
            pause_for(std::chrono::milliseconds(500 / speed));
            temp = temp->next;
        } while (temp != nullptr);
    }
    
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 143);
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(tailText, temp);
    this->display(window);
    if (temp != NodeArray)
        window.draw(tailText);
    LastNode->next = newNode;
    window.draw(vtxText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(CodeHighLight);
    window.display();

    // moving
    for (int i = 0; i < 25; i++)
    {
        window.clear();
        window.draw(DefaultBackground);
        vtxText.setString("tail/vtx");
        newNode->circle.move(0, -6);
        newNode->text.move(0, -6);
        NodeTextsetPos(vtxText, newNode);
        window.draw(vtxText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
    }
    // std::this_thread::sleep_for(delayTime);
    pause_for(std::chrono::milliseconds(500 / speed));

    // Recolor the node
    SLL_Node* cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color(106, 231, 255, 0));
        cur->text.setFillColor(sf::Color(106, 231, 255));
        cur = cur->next;
    }
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    this->size++;
    vtxText.setString("vtx");
}

void DataVisualization_3::InsertNodeMid(sf::RenderWindow &window, int data, int index)
{
    CodeHighLight.setPosition(CodeHighLightPosition);
    std::chrono::milliseconds delayTime(500 / speed);
    CodeScript.setPosition(CodeScriptPosition);
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/InsertMid.png");
    CodeScriptVisible = true;

    // special case
    if (this->NodeArray == nullptr)
    {
        this->NodeArray = this->NodeArray->createNode(250, 250, 30, font, data);
        return;
    }
    if (checkSize(window, this->size) == false) return;
    if (index > this->size) 
    {
        std::string str = "Index must be from 1 to " + std::to_string(this->size);
        printMessage(window, str);
        return;
    }
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

    // create the new Node
    SLL_Node* iteratorNode = this->NodeArray;
    SLL_Node* pre = iteratorNode;
    for (int i = 1; i < index; i++)
    {
        pre = iteratorNode;
        iteratorNode = iteratorNode->next;
    }
    CodeHighLight.setPosition(CodeHighLightPosition);
    SLL_Node* newNode = this->NodeArray->createNode(pre->circle.getPosition().x + 150, pre->circle.getPosition().y + 150, 30, this->font, data);
    newNode->circle.setFillColor(sf::Color(106, 231, 255));
    newNode->text.setFillColor(sf::Color::Black);
    NodeTextsetPos(vtxText, newNode);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawNodes(window);
    window.draw(vtxText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime); 
    pause_for(std::chrono::milliseconds(500 / speed));

    // color the temp node
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 35));
    SLL_Node* temp = this->NodeArray;
    NodeTextsetPos(preText, NodeArray);
    HeadText.setString("head/pre");
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(preText, temp);
    if (temp != NodeArray)
        window.draw(preText);
    this->drawNodes(window);
    this->display(window);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(vtxText);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime); 
    pause_for(std::chrono::milliseconds(500 / speed));

    for (int i = 1; i < index; i++)
    {
        CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 108));
        window.clear();
        window.draw(DefaultBackground);
        temp->circle.setFillColor(sf::Color(106, 231, 255));
        temp->text.setFillColor(sf::Color::Black);
        NodeTextsetPos(preText, temp);
        if (temp != NodeArray)
            window.draw(preText);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.draw(vtxText);
        window.draw(CodeHighLight);
        window.display();
        // std::this_thread::sleep_for(delayTime); 
        pause_for(std::chrono::milliseconds(500 / speed));
        
        // checking for the condition
        CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 72));
        window.clear();
        window.draw(DefaultBackground);
        NodeTextsetPos(preText, temp);
        if (temp != NodeArray)
            window.draw(preText);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.draw(vtxText);
        window.draw(CodeHighLight);
        window.display();
        // std::this_thread::sleep_for(delayTime); 
        pause_for(std::chrono::milliseconds(500 / speed));
        temp = temp->next;
        if (index != 2)
            HeadText.setString("Head");
    }
    // after text
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 143));
    temp->circle.setFillColor(sf::Color(106, 231, 255));
    temp->text.setFillColor(sf::Color::Black);
    NodeTextsetPos(aftText, temp);
    window.clear();
    window.draw(DefaultBackground);
    if (pre != NodeArray)
        window.draw(preText);
    this->drawNodes(window);
    this->display(window);
    window.draw(aftText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(vtxText);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime); 
    pause_for(std::chrono::milliseconds(500 / speed));

    // create connection
    newNode->next = iteratorNode;
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 180));
    window.clear();
    window.draw(DefaultBackground);
    if (pre != NodeArray)
        window.draw(preText);
    this->drawNodes(window);
    this->display(window);
    NodeArray->drawArrow(window, newNode->circle.getPosition(), iteratorNode->circle.getPosition());
    window.draw(aftText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(vtxText);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime); 
    pause_for(std::chrono::milliseconds(500 / speed));

    pre->next = newNode;
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 217));
    window.clear();
    window.draw(DefaultBackground);
    if (pre != NodeArray)
        window.draw(preText);
    this->drawNodes(window);
    this->display(window);
    NodeArray->drawArrow(window, newNode->circle.getPosition(), iteratorNode->circle.getPosition());
    window.draw(aftText);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.draw(vtxText);
    window.draw(CodeHighLight);
    window.display();
    // std::this_thread::sleep_for(delayTime); 
    pause_for(std::chrono::milliseconds(500 / speed));
    // moving
    for (int i = 0; i < 25; i++)
    {
        window.clear();
        window.draw(DefaultBackground);
        newNode->circle.move(0, -6);
        newNode->text.move(0, -6);
        temp = iteratorNode;
        while (temp != nullptr)
        {
            temp->circle.move(6, 0);
            temp->text.move(6, 0);
            temp = temp->next;
        }
        NodeTextsetPos(aftText, iteratorNode);
        NodeTextsetPos(vtxText, newNode);
        NodeTextsetPos(preText, pre);
        window.draw(aftText);
        window.draw(vtxText);
        if (pre != NodeArray)
            window.draw(preText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
    }
    // std::this_thread::sleep_for(delayTime); 
    pause_for(std::chrono::milliseconds(500 / speed));

    // Recolor the node
    SLL_Node* cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color(106, 231, 255, 0));
        cur->text.setFillColor(sf::Color(106, 231, 255));
        cur = cur->next;
    }
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(aftText, iteratorNode);
    NodeTextsetPos(vtxText, newNode);
    NodeTextsetPos(preText, pre);
    window.draw(aftText);
    window.draw(vtxText);
    if (pre != NodeArray)
        window.draw(preText);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    HeadText.setString("Head");
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
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/RemoveHead.png");
    CodeScriptVisible = true;
    CodeScript.setPosition(CodeScriptPosition);
    std::chrono::milliseconds delayTime(1000 / speed); 
    std::chrono::milliseconds delayTime1(50); 
    std::chrono::milliseconds delayTime2(500 / speed); 
    this->HeadText.setString("Head");
    CodeHighLight.setPosition(CodeHighLightPosition);
    //handle special case
    if (this->NodeArray == nullptr)
    {
        printMessage(window, "There is no Node to be deleted!");
        return;
    }
    // one Node case
    if (this->NodeArray->next == nullptr)
    {
        HeadText.setString("Vtx/Head");
        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 35);
        this->NodeArray->circle.setFillColor(sf::Color::Red);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime); 

        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 71);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime); 


        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 107);
        while (this->NodeArray->circle.getRadius() > 16)
        {
            float radius = this->NodeArray->circle.getRadius();
            radius = radius * 0.75;
            this->NodeArray->circle.setRadius(radius);
            this->NodeArray->circle.setOrigin(radius, radius);
            this->NodeArray->text.setCharacterSize(radius / 3.f * 2.f);
            this->NodeArray->text.setOrigin(this->NodeArray->text.getLocalBounds().width / 2.f, this->NodeArray->text.getLocalBounds().height / 2.f);
            window.clear();
            window.draw(DefaultBackground);
            window.draw(this->NodeArray->circle);
            window.draw(this->NodeArray->text);
            this->drawNodes(window);
            this->display(window);
            window.draw(CodeHighLight);
            window.display();
            std::this_thread::sleep_for(delayTime1); 
        }
        SLL_Node* temp = this->NodeArray;
        this->NodeArray = nullptr;
        delete temp;
        this->size = 0;
        HeadText.setString("Head");
        return;
    }
    // the other case
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 35);
    SLL_Node* cur = this->NodeArray;
    this->HeadText.setString("Head/vtx");
    window.clear();
    window.draw(DefaultBackground);
    window.draw(cur->circle);
    window.draw(cur->text);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    this->HeadText.setString("Head");
    std::this_thread::sleep_for(delayTime); 

    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 71);
    this->NodeArray = this->NodeArray->next;
    window.clear();
    window.draw(DefaultBackground);
    cur->circle.setFillColor(sf::Color::Red);
    this->NodeArray->drawArrow(window, cur->circle.getPosition(), this->NodeArray->circle.getPosition());
    this->vtxText.setPosition(sf::Vector2f(cur->circle.getPosition().x, cur->circle.getPosition().y + 50));
    this->drawNodes(window);
    this->display(window);
    window.draw(vtxText);
    window.draw(cur->circle);
    window.draw(cur->text);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 108);
    while (cur->circle.getRadius() > 16)
    {
        float radius = cur->circle.getRadius();
        radius = radius * 0.75;
        cur->circle.setRadius(radius);
        cur->circle.setOrigin(radius, radius);
        cur->text.setCharacterSize(radius / 3.f * 2.f);
        cur->text.setOrigin(cur->text.getLocalBounds().width / 2.f, cur->text.getLocalBounds().height / 2.f);
        window.clear();
        window.draw(DefaultBackground);
        this->NodeArray->drawArrow(window, cur->circle.getPosition(), this->NodeArray->circle.getPosition());
        this->drawNodes(window);
        this->display(window);
        window.draw(vtxText);
        window.draw(cur->circle);
        window.draw(cur->text);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }
    delete cur;
    cur = nullptr;
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    // move left after delete
    for (int i = 0; i < 25; i++)
    {
        SLL_Node* temp = this->NodeArray;
        while (temp != nullptr)
        {
            window.clear();
            window.draw(DefaultBackground);
            temp->circle.move(-6, 0);
            temp->text.move(-6, 0);
            temp = temp->next;
        }
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
    }
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    this->size--;
}   

void DataVisualization_3::DeleteNodeBack(sf::RenderWindow &window)
{   
    std::chrono::milliseconds delayTime(1000 / speed);
    std::chrono::milliseconds delayTime1(50); 
    std::chrono::milliseconds delayTime2(500 / speed);
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/RemoveTail.png");
    CodeScriptVisible = true;
    CodeScript.setPosition(CodeScriptPosition);


    CodeHighLight.setPosition(CodeHighLightPosition);

    // handle special case
    if (this->NodeArray == nullptr) 
    {
        window.draw(CodeHighLight);
        printMessage(window, "There is no Node to be deleted!");
        return;
    }
    if (this->NodeArray->next == nullptr) // 1 Nodes
    {
        DeleteNodeFront(window);
        return;
    }
    // 2+ Nodes!
    SLL_Node* cur = this->NodeArray;
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 35);
    HeadText.setString("Head/cur");
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 
    
    // color the first Node;
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 71);
    cur->circle.setFillColor(sf::Color(106, 231, 255));
    cur->text.setFillColor(sf::Color::Black);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 
    //----
    cur = this->NodeArray->next;
    NodeTextsetPos(curText, cur);
    SLL_Node* pre = this->NodeArray;
    HeadText.setString("Head/pre");
    window.clear();
    window.draw(DefaultBackground);
    window.draw(curText);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();

    while (cur->next != nullptr)
    {
        if (pre == NodeArray)
        {
            HeadText.setString("Head/pre");
            preText.setString("");
        } else {
            HeadText.setString("Head");
            preText.setString("Pre");
        }   
        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 107);
        window.clear();
        window.draw(DefaultBackground);
        NodeTextsetPos(preText, pre);
        NodeTextsetPos(curText, cur);
        window.draw(preText);
        window.draw(curText);
        cur->circle.setFillColor(sf::Color(106, 231, 255));
        cur->text.setFillColor(sf::Color::Black);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2); 
        pre = cur;
        cur = cur->next;

        // checking the condition:
        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 71);
        window.clear();
        window.draw(DefaultBackground);
        window.draw(preText);
        window.draw(curText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2); 
        HeadText.setString("Head");
        preText.setString("Pre");
    }
    // Last node highlight
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 107);
    window.clear();
    window.draw(DefaultBackground);
    cur->circle.setFillColor(sf::Color::Red);
    cur->text.setFillColor(sf::Color::Black);
    NodeTextsetPos(preText, pre);
    NodeTextsetPos(curText, cur);
    if (pre != NodeArray)
        window.draw(preText);
    window.draw(curText);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime); 

// delete the arrow:
    pre->next = nullptr;
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 143);
    window.clear();
    window.draw(DefaultBackground);
    cur->circle.setFillColor(sf::Color::Red);
    cur->text.setFillColor(sf::Color::Black);
    NodeTextsetPos(preText, pre);
    NodeTextsetPos(curText, cur);
    if (pre != NodeArray)
        window.draw(preText);
    window.draw(curText);
    this->drawNodes(window);
    this->display(window);
    window.draw(cur->circle);
    window.draw(cur->text);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime);

    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 181);
    while (cur->circle.getRadius() > 16)
    {
        float radius = cur->circle.getRadius();
        radius = radius * 0.75;
        cur->circle.setRadius(radius);
        cur->circle.setOrigin(radius, radius);
        cur->text.setCharacterSize(radius / 3.f * 2.f);
        cur->text.setOrigin(cur->text.getLocalBounds().width / 2.f, cur->text.getLocalBounds().height / 2.f);
        window.clear();
        window.draw(DefaultBackground);
        if (pre != NodeArray)
        {
            NodeTextsetPos(preText, pre);
            window.draw(preText);
        }
        this->drawNodes(window);
        this->display(window);
        window.draw(cur->circle);
        window.draw(cur->text);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }

    // delete
    // pre->next = nullptr;
    delete cur;
    cur = nullptr;
    window.clear();
    window.draw(DefaultBackground);
    if (pre != NodeArray){
        NodeTextsetPos(preText, pre);
        window.draw(preText);
    }
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 
  
    // recolor the Nodes
    cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color(106, 231, 255, 0));
        cur->text.setFillColor(sf::Color(106, 231, 255));
        cur = cur->next;
    }
    HeadText.setString("Head");
    preText.setString("pre");
    this->size--;
}   

void DataVisualization_3::DeleteNodeMid(sf::RenderWindow &window, int index)
{   
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/RemoveMid.png");
    CodeScriptVisible = true;
    CodeScript.setPosition(CodeScriptPosition);
    CodeHighLight.setPosition(CodeHighLightPosition);
    std::chrono::milliseconds delayTime(1000 / speed); // 1 second
    std::chrono::milliseconds delayTime1(50); // 05
    std::chrono::milliseconds delayTime2(500 / speed);
    // special case
    if (this->NodeArray == nullptr) 
    {
        window.draw(CodeHighLight);
        printMessage(window, "There is no Node to be deleted!");
        return;
    }
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
    
    // color Green
    SLL_Node* pre = this->NodeArray;
    SLL_Node* cur = nullptr;
    SLL_Node* aft = nullptr;
    HeadText.setString("Head/pre");
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 35);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 71);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    for (int i = 1; i < index - 1; i++)
    {
        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 108);
        pre->circle.setFillColor(sf::Color(106, 231, 255));
        pre->text.setFillColor(sf::Color::Black);
        window.clear();
        window.draw(DefaultBackground);
        if (pre != NodeArray)
        {
            NodeTextsetPos(preText, pre);
            window.draw(preText);
        }
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        pre = pre->next;
        // cur = cur->next;
        std::this_thread::sleep_for(delayTime2); 

        //cheking the for loops condition
        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 71);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        if (pre != NodeArray)
        {
            NodeTextsetPos(preText, pre);
            window.draw(preText);
        }
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2); 
        HeadText.setString("Head");
    }
    // ????
    pre->circle.setFillColor(sf::Color(106, 231, 255));
    pre->text.setFillColor(sf::Color::Black);
    window.clear();
    window.draw(DefaultBackground);
    if (pre != NodeArray)
    {
        NodeTextsetPos(preText, pre);
        window.draw(preText);
    }
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    // color Red
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 144);
    cur = pre->next;
    cur->circle.setFillColor(sf::Color::Red);
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(preText, pre);
    NodeTextsetPos(curText, cur);
    if (pre != NodeArray)
        window.draw(preText);
    window.draw(curText);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    aft = cur->next;
    aft->circle.setFillColor(sf::Color(106, 231, 255));
    aft->text.setFillColor(sf::Color::Black);
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(preText, pre);
    NodeTextsetPos(curText, cur);
    NodeTextsetPos(aftText, aft);
    if (pre != NodeArray)
        window.draw(preText);
    window.draw(curText);
    window.draw(aftText);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    // delete it 
    for (int i = 0; i < 25; i++)
    {   //moving down
        cur->circle.move(0, 6);
        cur->text.move(0, 6);
        window.clear();
        window.draw(DefaultBackground);
        // NodeTextsetPos(preText, pre);
        NodeTextsetPos(curText, cur);
        // NodeTextsetPos(aftText, aft);
        if (pre != NodeArray)
            window.draw(preText);
        window.draw(curText);
        window.draw(aftText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
    }
    std::this_thread::sleep_for(delayTime2); 
    pre->next = aft;
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(preText, pre);
    NodeTextsetPos(curText, cur);
    NodeTextsetPos(aftText, aft);
    if (pre != NodeArray)
        window.draw(preText);
    window.draw(curText);
    window.draw(aftText);
    this->drawNodes(window);
    this->display(window);
    window.draw(cur->circle);
    window.draw(cur->text);
    window.draw(CodeHighLight);
    window.display();

    // move left for the rest
    // pre = pre->next;
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 177);
    for (int i = 0; i < 25; i++)
    {
        SLL_Node* temp = pre->next;
        while (temp != nullptr)
        {
            temp->circle.move(-6, 0);
            temp->text.move(-6, 0);
            temp = temp->next;
        }
        window.clear();
        window.draw(DefaultBackground);
        NodeArray->drawArrow(window, cur->circle.getPosition(), aft->circle.getPosition());
        NodeTextsetPos(curText, cur);
        NodeTextsetPos(aftText, aft);
        if (pre != NodeArray)
            window.draw(preText);
        window.draw(curText);
        window.draw(aftText);
        this->drawNodes(window);
        this->display(window);
        window.draw(cur->circle);
        window.draw(cur->text);
        window.draw(CodeHighLight);
        window.display();
    }
    std::this_thread::sleep_for(delayTime2); 
    
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 217);
    delete cur;
    cur = nullptr;
    window.clear();
    window.draw(DefaultBackground);
    if (pre != NodeArray)
        window.draw(preText);
    window.draw(aftText);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime); 

    // recolor
    cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color(106, 231, 255, 0));
        cur->text.setFillColor(sf::Color(106, 231, 255));
        cur = cur->next;
    }
    HeadText.setString("Head");
    window.clear();
    window.draw(DefaultBackground);
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
    CodeScript.setPosition(CodeScriptPosition);
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/Update.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    std::chrono::milliseconds delayTime(1000 / speed); // 2 second
    std::chrono::milliseconds delayTime1(50); // 50ms
    std::chrono::milliseconds delayTime2(500 / speed); // 1 second
    
    // handle special case
    if (this->size == 0)
    {
        window.draw(CodeHighLight);
        printMessage(window, "There is no Node to be Update");
        return;
    }
    
    if (index <= 0 || index > this->size)
    {
        std::string str = "Index must be from 1 to " + std::to_string(this->size);
        printMessage(window, str);
        return;
    } 


    SLL_Node* temp = this->NodeArray;
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 35);
    HeadText.setString("Head/cur");
    for (int i = 1; i < index; i++)
    {
        if (i == 1){
            CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 35);
        } else {
            CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 108);
        }
        temp->circle.setFillColor(sf::Color(106, 231, 255));
        temp->text.setFillColor(sf::Color::Black);
        window.clear();
        window.draw(DefaultBackground);
        NodeTextsetPos(curText, temp);
        if (temp != NodeArray)
            window.draw(curText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2); 

        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 72);
        window.clear();
        window.draw(DefaultBackground);
        NodeTextsetPos(curText, temp);
        if (temp != NodeArray)
            window.draw(curText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2); 

        temp = temp->next;
        HeadText.setString("Head");
    }
    // color the given Node
    temp->circle.setFillColor(sf::Color::Red);
    window.clear();
    window.draw(DefaultBackground);
    NodeTextsetPos(curText, temp);
    if (temp != NodeArray)
        window.draw(curText);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2);

    //change the value
    CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 144);
    while (temp->circle.getRadius() < 40)
    {
        float radius = temp->circle.getRadius();
        radius = radius + 2;
        temp->circle.setRadius(radius);
        temp->circle.setOrigin(radius, radius);
        temp->text.setCharacterSize(radius / 3.f * 2.f);
        temp->text.setOrigin(temp->text.getLocalBounds().width / 2.f, temp->text.getLocalBounds().height / 2.f);
        window.clear();
        window.draw(DefaultBackground);
        NodeTextsetPos(curText, temp);
        if (temp != NodeArray)
            window.draw(curText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }
    temp->text.setString(std::to_string(value));
    temp->data = value;
    while (temp->circle.getRadius() > 30)
    {
        float radius = temp->circle.getRadius();
        radius = radius - 2;
        temp->circle.setRadius(radius);
        temp->circle.setOrigin(radius, radius);
        temp->text.setCharacterSize(radius / 3.f * 2.f);
        temp->text.setOrigin(temp->text.getLocalBounds().width / 2.f, temp->text.getLocalBounds().height / 2.f);
        window.clear();
        window.draw(DefaultBackground);
        NodeTextsetPos(curText, temp);
        if (temp != NodeArray)
            window.draw(curText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }
    //recoloring
    temp = this->NodeArray;
    while (temp != nullptr)
    {
        temp->circle.setFillColor(sf::Color(106, 231, 255, 0));
        temp->text.setFillColor(sf::Color(106, 231, 255));
        temp = temp->next;
    }
    HeadText.setString("Head");
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
    CodeScript.setPosition(CodeScriptPosition);
    CodeScript.setImage(WorkingPath + "media/DataVisualization3/Search.png");
    CodeScriptVisible = true;
    std::chrono::milliseconds delayTime(1000 / speed); 
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);
    CodeHighLight.setPosition(CodeHighLightPosition);

    // handle special case;
    if (NodeArray == nullptr)
    {
        CodeScript.drawImage(window);
        window.draw(CodeHighLight);
        printMessage(window, "There is no Node to be searched");
        return;
    }
    int index = 0;
    HeadText.setString("Head/cur");
    SLL_Node* temp = NodeArray;
    while (temp != nullptr)
    {
        if (index == 0)
        {
            CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 35);
        } else {
            CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 107);
        }
        index++;
        temp->circle.setFillColor(sf::Color(106, 231, 255));
        temp->text.setFillColor(sf::Color::Black);
        NodeTextsetPos(curText, temp);
        window.clear();
        window.draw(DefaultBackground);
        if (temp != NodeArray)
            window.draw(curText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2);

        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 71);
        window.clear();
        window.draw(DefaultBackground);
        if (temp != NodeArray)
            window.draw(curText);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2);
        HeadText.setString("Head");

        if (temp->data == value) {
            CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 216);
            std::string mess = "Founded at index " + std::to_string(index);
            temp->circle.setFillColor(sf::Color::Red);
            window.clear();
            window.draw(DefaultBackground);
            this->drawNodes(window);
            this->display(window);
            window.draw(CodeHighLight);
            window.display();
            std::this_thread::sleep_for(delayTime2);
            printMessage(window, mess);
            break;
        }
        temp = temp->next;
    }
    if (temp == nullptr) // case that value not found
    {
        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 144);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2);

        CodeHighLight.setPosition(CodeHighLightPosition.x, CodeHighLightPosition.y + 179);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime2);
        printMessage(window, "Value not found!");
    }
    // recolor yellow again
    temp = NodeArray;
    while (temp != nullptr)
    {
        temp->circle.setFillColor(sf::Color(106, 231, 255, 0));
        temp->text.setFillColor(sf::Color(106, 231, 255));
        temp = temp->next;
    }
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.draw(CodeHighLight);
    window.display();
    HeadText.setString("Head");
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

bool DataVisualization_3::printMessage(sf::RenderWindow &window, std::string message)
{
    std::chrono::milliseconds delayTime(1000);
    sf::Text WarningMessage;
    WarningMessage.setString(message);
    WarningMessage.setCharacterSize(50);
    WarningMessage.setFillColor(sf::Color::White);
    WarningMessage.setOutlineColor(sf::Color::Red);
    WarningMessage.setOutlineThickness(5);
    WarningMessage.setFont(this->font);
    WarningMessage.setOrigin(WarningMessage.getLocalBounds().width/2.f, WarningMessage.getLocalBounds().height/2.f);
    WarningMessage.setPosition(window.getSize().x / 2.f + 20, window.getSize().y / 2.f - 240.f);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawNodes(window);
    window.draw(CodeHighLight);
    NotificationImage.drawImage(window);
    window.draw(WarningMessage);
    window.display();
    pause_for(std::chrono::milliseconds(1000));
    // std::this_thread::sleep_for(delayTime);
    return true;
}

void DataVisualization_3::updateChanges(sf::Font tempFont)
{
    //Fonts
    this->font = tempFont;
    this->titlefont = tempFont;
    NotificationImage.setImage(WorkingPath + "media/img/noti_board.png");
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
    PauseButton.setImage(WorkingPath + "media/img/pause_button.png");
    PauseButton.setPosition(sf::Vector2f(960, 1000));
    ReplayButton.setImage(WorkingPath + "media/img/play_button.png");
    ReplayButton.setPosition(sf::Vector2f(960, 1000));
    NextButton.setImage(WorkingPath + "media/img/next_button.png");
    NextButton.setPosition(sf::Vector2f(1010, 1000));
    SkipButton.setImage(WorkingPath + "media/img/skip_button.png");
    SkipButton.setPosition(sf::Vector2f(1060, 1000));
    NextButtonReverse.setImage(WorkingPath + "media/img/next_button_reverse.png");
    NextButtonReverse.setPosition(sf::Vector2f(910, 1000));
    SkipButtonReverse.setImage(WorkingPath + "media/img/skip_button_reverse.png");
    SkipButtonReverse.setPosition(sf::Vector2f(860, 1000));
    IncreaseSpeedButton.setImage(WorkingPath + "media/img/add_button.png");
    IncreaseSpeedButton.setPosition(sf::Vector2f(330, 1002));
    DecreaseSpeedButton.setImage(WorkingPath + "media/img/minus_btn.png");
    DecreaseSpeedButton.setPosition(sf::Vector2f(380, 1002));
    isPause = true;

    // Code Script
    CodeScriptPosition = sf::Vector2f(1520,640);
    CodeHighLightPosition = sf::Vector2f(1170, 697.5f);
    CodeScript.setPosition(CodeScriptPosition);
    CodeHighLight.setSize(sf::Vector2f(700, 30));
    CodeHighLight.setFillColor(sf::Color(106, 231, 255, 100));
    CodeHighLight.setOutlineColor(sf::Color(106, 231, 255));
    CodeHighLight.setPosition(CodeHighLightPosition); // 1170 - 697.5 ~ 35

    //Title
    sf::Text DV3Title("Singly Linked List", this->titlefont, 35);
    CreateTitle(DV3Title, 400, 60.f);
    this->Title = DV3Title;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 300.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 50.f);

    //Function Key #0
    this->ImportFromFileButton.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 75.f, sf::Color(106, 231, 255, 0), "Import", this->font, sf::Color(106, 231, 255));

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
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Add", this->font, sf::Color(106, 231, 255));
    this->InsertHead.CreateButton(130.f, 50.f, this->ControlMenu_btn2.rect.getPosition().x + this->ControlMenu_btn2.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Head", this->font, sf::Color(106, 231, 255));
    this->InsertHead.rect.setOutlineThickness(2.f);
    this->InsertHead.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->InsertHead_Textbox, 20, sf::Color::White, true, this->InsertHead.rect.getPosition().x, this->InsertHead.rect.getPosition().y + 50, font, true, 3);
    this->InsertHead_Textbox.EnterMessage.setString("Value: ");
    
    this->InsertBack.CreateButton(130.f, 50.f, this->InsertHead.rect.getPosition().x + this->InsertHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->InsertBack.rect.setOutlineThickness(2.f);
    this->InsertBack.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->InsertBack_Textbox, 20, sf::Color::White, true, this->InsertBack.rect.getPosition().x, this->InsertBack.rect.getPosition().y + 50, font, true, 3);
    this->InsertBack_Textbox.EnterMessage.setString("Value: ");
    this->InsertMid.CreateButton(130.f, 50.f, this->InsertBack.rect.getPosition().x + this->InsertBack.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Mid", this->font, sf::Color(106, 231, 255));
    this->InsertMid.rect.setOutlineThickness(2.f);
    this->InsertMid.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->InsertMid_Textbox, 20, sf::Color::White, true, this->InsertMid.rect.getPosition().x, this->InsertMid.rect.getPosition().y + 50, font, true, 3);
    this->InsertMid_Textbox.EnterMessage.setString("Value: ");

    //Function Key #3
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Delete", this->font, sf::Color(106, 231, 255));
    this->DeleteHead.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Head", this->font, sf::Color(106, 231, 255));
    this->DeleteHead.rect.setOutlineThickness(2.f);
    this->DeleteHead.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->DeleteBack.CreateButton(130.f, 50.f, this->DeleteHead.rect.getPosition().x + this->DeleteHead.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->DeleteBack.rect.setOutlineThickness(2.f);
    this->DeleteBack.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    this->DeleteMid.CreateButton(130.f, 50.f, this->DeleteBack.rect.getPosition().x + this->DeleteBack.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Mid", this->font, sf::Color(106, 231, 255));
    this->DeleteMid.rect.setOutlineThickness(2.f);
    this->DeleteMid.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    InitTextbox(this->DeleteMid_Textbox, 20, sf::Color::White, true, this->DeleteMid.rect.getPosition().x, this->DeleteMid.rect.getPosition().y + 50, font, true, 3);
    this->DeleteMid_Textbox.EnterMessage.setString("Index: ");

    //Function Key #4
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateNodeButton.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateNodeButton.rect.setOutlineThickness(2.f);
    this->UpdateNodeButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->UpdateNode_Textbox, 20, sf::Color::White, true, this->UpdateNodeButton.rect.getPosition().x, this->UpdateNodeButton.rect.getPosition().y + 50, font, true, 3);
    this->UpdateNode_Textbox.EnterMessage.setString("Index: ");

    //Function Key #5
    this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchNodeButton.CreateButton(130.f, 50.f, this->ControlMenu_btn5.rect.getPosition().x + this->ControlMenu_btn5.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchNodeButton.rect.setOutlineThickness(2.f);
    this->SearchNodeButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->SearchNode_Textbox, 20, sf::Color::White, true, this->SearchNodeButton.rect.getPosition().x, this->SearchNodeButton.rect.getPosition().y + 50, font, true, 3);
    this->SearchNode_Textbox.EnterMessage.setString("Value:");

    this->HeadText.setString("Head");
    this->HeadText.setFont(this->font);
    this->HeadText.setCharacterSize(20);
    this->HeadText.setOrigin(sf::Vector2f(this->HeadText.getLocalBounds().width / 2.f , this->HeadText.getLocalBounds().height / 2.f));
    
    this->vtxText.setString("vtx");
    this->vtxText.setFont(this->font);
    this->vtxText.setCharacterSize(20);
    this->vtxText.setOrigin(sf::Vector2f(this->vtxText.getLocalBounds().width / 2.f , this->vtxText.getLocalBounds().height / 2.f));
    
    this->aftText.setString("aft");
    this->aftText.setFont(this->font);
    this->aftText.setCharacterSize(20);
    this->aftText.setOrigin(sf::Vector2f(this->aftText.getLocalBounds().width / 2.f , this->aftText.getLocalBounds().height / 2.f));
    
    this->preText.setString("pre");
    this->preText.setFont(this->font);
    this->preText.setCharacterSize(20);
    this->preText.setOrigin(sf::Vector2f(this->preText.getLocalBounds().width / 2.f , this->preText.getLocalBounds().height / 2.f));
    
    this->delText.setString("del");
    this->delText.setFont(this->font);
    this->delText.setCharacterSize(20);
    this->delText.setOrigin(sf::Vector2f(this->delText.getLocalBounds().width / 2.f , this->delText.getLocalBounds().height / 2.f));
    
    this->tailText.setString("tail");
    this->tailText.setFont(this->font);
    this->tailText.setCharacterSize(20);
    this->tailText.setOrigin(sf::Vector2f(this->tailText.getLocalBounds().width / 2.f , this->tailText.getLocalBounds().height / 2.f));
    
    this->curText.setString("cur");
    this->curText.setFont(this->font);
    this->curText.setCharacterSize(20);
    this->curText.setOrigin(sf::Vector2f(this->curText.getLocalBounds().width / 2.f , this->curText.getLocalBounds().height / 2.f));
    
    this->size = 0;
    this->NodeArray = nullptr;
    funcstate = 0;
}