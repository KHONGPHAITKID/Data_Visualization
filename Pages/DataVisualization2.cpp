#include "DataVisualization2.hpp"

void VectorElement::setValue()
{
    this->data.setString(std::to_string(this->value));
    this->data.setOrigin(this->data.getLocalBounds().width / 2.f , this->data.getLocalBounds().height / 2.f);
    this->data.setPosition(sf::Vector2f(this->rect.getPosition().x, this->rect.getPosition().y - this->data.getLocalBounds().height / 2.f));
}

DataVisualization_2::DataVisualization_2()
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
    sf::Text DV1Title("Dynamic Array", this->titlefont, 35);
    CreateTitle(DV1Title, 400, 60.f);
    this->Title = DV1Title;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 300.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 100.f);

    //Function Key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 125.f, sf::Color(106, 231, 255, 0), "Create", this->font, sf::Color(106, 231, 255));

    this->CreateFromFileButton.CreateButton(130.f, 50.f, this->ControlMenu_btn1.rect.getPosition().x + this->ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Import", this->font, sf::Color(106, 231, 255));
    this->CreateFromFileButton.rect.setOutlineThickness(2.f);
    this->CreateFromFileButton.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->CreateRadom.CreateButton(130.f, 50.f, this->CreateFromFileButton.rect.getPosition().x + this->CreateFromFileButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random", this->font, sf::Color(106, 231, 255));
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

    // Function Key #2: Add
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Add/Allocate", this->font, sf::Color(106, 231, 255));
    this->AddFrontButton.CreateButton(130.f, 50.f, this->ControlMenu_btn2.rect.getPosition().x + this->ControlMenu_btn2.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Add Front", this->font, sf::Color(106, 231, 255));
    this->AddFrontButton.rect.setOutlineThickness(2.f);
    this->AddFrontButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AddFront_Textbox, 20, sf::Color::White, true, this->AddFrontButton.rect.getPosition().x, this->AddFrontButton.rect.getPosition().y + 50, font, true, 3);
    this->AddFront_Textbox.EnterMessage.setString("Value: ");
    this->AddMiddleButton.CreateButton(130.f, 50.f, this->AddFrontButton.rect.getPosition().x + this->AddFrontButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Add Mid", this->font, sf::Color(106, 231, 255));
    this->AddMiddleButton.rect.setOutlineThickness(2.f);
    this->AddMiddleButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AddMiddle_Textbox, 20, sf::Color::White, true, this->AddMiddleButton.rect.getPosition().x, this->AddMiddleButton.rect.getPosition().y + 50, font, true, 3);
    this->AddMiddle_Textbox.EnterMessage.setString("Index: ");
    this->AddBackButton.CreateButton(130.f, 50.f, this->AddMiddleButton.rect.getPosition().x + this->AddMiddleButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Add Back", this->font, sf::Color(106, 231, 255));
    this->AddBackButton.rect.setOutlineThickness(2.f);
    this->AddBackButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AddBack_Textbox, 20, sf::Color::White, true, this->AddBackButton.rect.getPosition().x, this->AddBackButton.rect.getPosition().y + 50, font, true, 3);
    this->AddBack_Textbox.EnterMessage.setString("Value: ");
    this->AllocateSizeButton.CreateButton(130.f, 50.f, this->AddBackButton.rect.getPosition().x + this->AddBackButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Allocate", this->font, sf::Color(106, 231, 255));
    this->AllocateSizeButton.rect.setOutlineThickness(2.f);
    this->AllocateSizeButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AllocateSize_Textbox, 20, sf::Color::White, true, this->AllocateSizeButton.rect.getPosition().x, this->AllocateSizeButton.rect.getPosition().y + 50, font, true, 3);
    this->AllocateSize_Textbox.EnterMessage.setString("Size: ");

    // Function Key #3: Delete
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Delete", this->font, sf::Color(106, 231, 255));
    this->DeleteFrontButton.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Front", this->font, sf::Color(106, 231, 255));
    this->DeleteFrontButton.rect.setOutlineThickness(2.f);
    this->DeleteFrontButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->DeleteMiddleButton.CreateButton(130.f, 50.f, this->DeleteFrontButton.rect.getPosition().x + this->DeleteFrontButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Middle", this->font, sf::Color(106, 231, 255));
    this->DeleteMiddleButton.rect.setOutlineThickness(2.f);
    this->DeleteMiddleButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->DeleteMiddle_Textbox, 20, sf::Color::White, true, this->DeleteMiddleButton.rect.getPosition().x, this->DeleteMiddleButton.rect.getPosition().y + 50, font, true, 3);
    this->DeleteMiddle_Textbox.EnterMessage.setString("Index: ");
    this->DeleteBackButton.CreateButton(130.f, 50.f, this->DeleteMiddleButton.rect.getPosition().x + this->DeleteMiddleButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->DeleteBackButton.rect.setOutlineThickness(2.f);
    this->DeleteBackButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->ClearVectorButton.CreateButton(130.f, 50.f, this->DeleteBackButton.rect.getPosition().x + this->DeleteBackButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "DeAllocate", this->font, sf::Color(106, 231, 255));
    this->ClearVectorButton.rect.setOutlineThickness(2.f);
    this->ClearVectorButton.rect.setOutlineColor(sf::Color(106, 231, 255));

    //Function Key #4: Access
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Access", this->font, sf::Color(106, 231, 255));
    this->UpdateButton.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateButton.rect.setOutlineThickness(2.f);
    this->UpdateButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->UpdateButton_Textbox, 20, sf::Color::White, true, this->UpdateButton.rect.getPosition().x, this->UpdateButton.rect.getPosition().y + 50, font, true, 3);
    this->UpdateButton_Textbox.EnterMessage.setString("Index: ");
    this->AccessButton.CreateButton(130.f, 50.f, this->UpdateButton.rect.getPosition().x + this->UpdateButton.rect.getSize().x / 2.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Access", this->font, sf::Color(106, 231, 255));
    this->AccessButton.rect.setOutlineThickness(2.f);
    this->AccessButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AccessButton_Textbox, 20, sf::Color::White, true, this->AccessButton.rect.getPosition().x, this->AccessButton.rect.getPosition().y + 50, font, true, 3);
    this->AccessButton_Textbox.EnterMessage.setString("Index: ");

    //Function Key #5: Search
    this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.CreateButton(130.f, 50.f, this->ControlMenu_btn5.rect.getPosition().x + this->ControlMenu_btn5.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.rect.setOutlineThickness(2.f);
    this->SearchButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->SearchButton_Textbox, 20, sf::Color::White, true, this->SearchButton.rect.getPosition().x, this->SearchButton.rect.getPosition().y + 50, font, true, 3);
    this->SearchButton_Textbox.EnterMessage.setString("Value: ");

    //Function Key #6: Sort
    this->ControlMenu_btn6.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Sort", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.CreateButton(130.f, 50.f, this->ControlMenu_btn6.rect.getPosition().x + this->ControlMenu_btn6.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Ascending", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.rect.setOutlineThickness(2.f);
    this->SortButtonAscending.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->SortButtonDescending.CreateButton(130.f, 50.f, this->SortButtonAscending.rect.getPosition().x + this->SortButtonAscending.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Descending", this->font, sf::Color(106, 231, 255));
    this->SortButtonDescending.rect.setOutlineThickness(2.f);
    this->SortButtonDescending.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    for (int i = 0; i < 10; i++)
    {
        this->Vector.at(i).value = i;
        this->Vector.at(i).rect.setSize(sf::Vector2f(100.f, 100.f));
        this->Vector.at(i).rect.setPosition(sf::Vector2f(450 + 100 * i, 400));
        this->Vector.at(i).rect.setOrigin(sf::Vector2f(50, 50));
        this->Vector.at(i).rect.setFillColor(sf::Color(106, 231, 255));
        this->Vector.at(i).rect.setOutlineColor(sf::Color::Black);
        this->Vector.at(i).rect.setOutlineThickness(2.f);

        this->Vector.at(i).data.setCharacterSize(30);
        this->Vector.at(i).data.setFont(this->font);
        this->Vector.at(i).data.setFillColor(sf::Color::Black);
        this->Vector.at(i).data.setString(std::to_string(this->Vector.at(i).value));
        this->Vector.at(i).setValue();
    }
    this->size = 0;
    this->capacity = 0;
    funcstate = 0;    
}

void DataVisualization_2::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
    window.draw(this->menuTable);
    speedText.setString("Speed: x" + std::to_string(speed));
    window.draw(speedText);
    if (CodeScriptVisible)
    {
        CodeScript.drawImage(window);
        DeleteCodeScriptButton.drawImage(window);
    }
    this->ControlMenu_btn1.displayButton(window);
    this->ControlMenu_btn2.displayButton(window);
    this->ControlMenu_btn3.displayButton(window);
    this->ControlMenu_btn4.displayButton(window);
    this->ControlMenu_btn5.displayButton(window);
    this->ControlMenu_btn6.displayButton(window);

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
        this->CreateFromFileButton.displayButton(window);
        this->CreateRadom.displayButton(window);;
        this->CreateRandomSort.displayButton(window);
        this->CreateRandomFixedSize.displayButton(window);
        this->CreateUserDefinedListButton.displayButton(window);
        this->CreateRandomFixedSize_Textbox.drawTo(window);
        this->CreateUserDefinedList_Textbox.drawTo(window);
        break;
    case 2:
        this->AddFrontButton.displayButton(window);
        this->AddFront_Textbox.drawTo(window);
        this->AddMiddleButton.displayButton(window);
        this->AddMiddle_Textbox.drawTo(window);
        this->AddBackButton.displayButton(window);
        this->AddBack_Textbox.drawTo(window);
        this->AllocateSizeButton.displayButton(window);
        this->AllocateSize_Textbox.drawTo(window);
        break;
    case 3:
        this->DeleteFrontButton.displayButton(window);
        this->DeleteMiddleButton.displayButton(window);
        this->DeleteMiddle_Textbox.drawTo(window);
        this->DeleteBackButton.displayButton(window);
        this->ClearVectorButton.displayButton(window);
        break;
    case 4:
        this->UpdateButton.displayButton(window);
        this->UpdateButton_Textbox.drawTo(window);
        this->AccessButton.displayButton(window);
        this->AccessButton_Textbox.drawTo(window);
        break;
    case 5:
        this->SearchButton.displayButton(window);
        this->SearchButton_Textbox.drawTo(window);
        break;
    case 6:
        this->SortButtonAscending.displayButton(window);
        this->SortButtonDescending.displayButton(window);
        break;
    default: // NONE - 0
        break;
    }
}

void DataVisualization_2::handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
            DefaultBackground.setTexture(BackGround1);
            this->size = 0;
            this->capacity = 0;
            this->funcstate = 0;
            this->speed = 2;
            this->CodeScriptVisible = false;
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
        else if (this->ControlMenu_btn6.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 6;
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
            this->CreateUserDefinedList_Textbox.isSelected = false;
            this->UpdateButton_Textbox.isSelected = false;
            this->SearchButton_Textbox.isSelected = false;
            this->AddFront_Textbox.isSelected = false;
            this->AddMiddle_Textbox.isSelected = false;
            this->AddBack_Textbox.isSelected = false;
            this->DeleteMiddle_Textbox.isSelected = false;
            this->AccessButton_Textbox.isSelected = false;
            this->AllocateSize_Textbox.isSelected = false;
        }
        switch (this->funcstate)
        {
        case 1:
            if (this->CreateFromFileButton.rect.getGlobalBounds().contains(mousePos))
            {
                createVectorFromFile();
            }
            if (this->CreateRadom.rect.getGlobalBounds().contains(mousePos))
            {
                createRandomVector();
            }
            if (this->CreateRandomSort.rect.getGlobalBounds().contains(mousePos))
            {
                createRandomSort();
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
            if (this->AddFrontButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->AddFront_Textbox.isSelected = !this->AddFront_Textbox.isSelected;
            } else {
                this->AddFront_Textbox.isSelected = false;
            }
            if (this->AddMiddleButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->AddMiddle_Textbox.isSelected = !this->AddMiddle_Textbox.isSelected;
            } else {
                this->AddMiddle_Textbox.isSelected = false;
            }
            if (this->AddBackButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->AddBack_Textbox.isSelected = !this->AddBack_Textbox.isSelected;
            } else {
                this->AddBack_Textbox.isSelected = false;
            }
            if (this->AllocateSizeButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->AllocateSize_Textbox.isSelected = !this->AllocateSize_Textbox.isSelected;
            } else {
                this->AllocateSize_Textbox.isSelected = false;
            }
            break;
        case 3:
            if (this->DeleteFrontButton.rect.getGlobalBounds().contains(mousePos))
            {
                DeleteFront(window);
            }
            if (this->DeleteMiddleButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->DeleteMiddle_Textbox.isSelected = !this->DeleteMiddle_Textbox.isSelected;
            } else {
                this->DeleteMiddle_Textbox.isSelected = false;
            }
            if (this->DeleteBackButton.rect.getGlobalBounds().contains(mousePos))
            {
                DeleteBack(window);
            }
            if (this->ClearVectorButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->capacity = 0;
                this->size = 0;
                CodeScript.setImage(WorkingPath + "media/DataVisualization2/DeAllocated.png");
                CodeScriptVisible = true;
            }
            break;
        case 4:
            if (this->UpdateButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->UpdateButton_Textbox.isSelected = !this->UpdateButton_Textbox.isSelected;
            } else {
                this->UpdateButton_Textbox.isSelected = false;
            }
            if (this->AccessButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->AccessButton_Textbox.isSelected = !this->AccessButton_Textbox.isSelected;
            } else {
                this->AccessButton_Textbox.isSelected = false;
            }
            break;
        case 5:
            if (this->SearchButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->SearchButton_Textbox.isSelected = !this->SearchButton_Textbox.isSelected;
            } else {
                this->SearchButton_Textbox.isSelected = false;
            }
            break;
        case 6:
            if (this->SortButtonAscending.rect.getGlobalBounds().contains(mousePos))
            {
                SortAscendingVector(window);
            } 
            if (this->SortButtonDescending.rect.getGlobalBounds().contains(mousePos))
            {
                SortDescendingVector(window);
            } 
            break;
        default:
            break;
        }
    }
    else if (ev.type == sf::Event::TextEntered)
    {
        createRandomFixedSizeVector(window, ev);
        createUserDefinedVector(window, ev);
        UpdateVector(window, ev);
        SearchVector(window, ev);
        AddFrontVector(window, ev);
        AddMiddleVector(window, ev);
        AddBackVector(window, ev);
        DeleteMiddleVector(window, ev);
        AccessVector(window, ev);
        AllocateSizeVector(window, ev);
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
        if (this->ControlMenu_btn5.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn5.rect.setFillColor(sf::Color(106, 231, 255));
            this->ControlMenu_btn5.text.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn5.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ControlMenu_btn5.text.setFillColor(sf::Color(106, 231, 255));
        }
        if (this->ControlMenu_btn6.rect.getGlobalBounds().contains(mousePos))
        {
            this->ControlMenu_btn6.rect.setFillColor(sf::Color(106, 231, 255));
            this->ControlMenu_btn6.text.setFillColor(sf::Color::Black);
        } else {
            this->ControlMenu_btn6.rect.setFillColor(sf::Color(106, 231, 255, 0));
            this->ControlMenu_btn6.text.setFillColor(sf::Color(106, 231, 255));
        }
    }
}

void DataVisualization_2::drawVector(sf::RenderWindow &window)
{
    if (this->capacity != 0)
    {
        sf::Text IndexText;
        IndexText.setCharacterSize(30);
        IndexText.setString("Index: ");
        IndexText.setFont(font);
        IndexText.setPosition(300, 500);
        IndexText.setOrigin(IndexText.getLocalBounds().width / 2.f, IndexText.getLocalBounds().height / 2.f);
        window.draw(IndexText);
    }
    for (int i = 0; i < this->size; i++)
    {
        sf::Text index;
        index.setCharacterSize(30);
        index.setString(std::to_string(i));
        index.setFont(font);
        index.setPosition(this->Vector.at(i).rect.getPosition().x, this->Vector.at(i).rect.getPosition().y + 100);
        index.setOrigin(index.getLocalBounds().width / 2.f, index.getLocalBounds().height / 2.f);
        window.draw(this->Vector.at(i).rect);
        window.draw(this->Vector.at(i).data);
        window.draw(index);
    }
    for (int i = this->size; i < this->capacity; i++)
    {
        Vector.at(i).rect.setFillColor(sf::Color(7, 155, 184));
        window.draw(this->Vector.at(i).rect);
        window.draw(this->Vector.at(i).data);
    }
}

void DataVisualization_2::createVectorFromFile()
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
            int num; int index = 0;
            inputFile >> this->size;
            if (this->size > 10)
            {
                this->size = 10;
            }
            this->capacity = this->size;
            int i = 0;
            while (inputFile >> num)
            {
                this->Vector.at(index).value = num;
                this->Vector.at(index).rect.setFillColor(sf::Color(106, 231, 255));
                this->Vector.at(index++).setValue();
                i++;
                if (i == this->capacity)
                    break;
            }
            while (i < this->capacity)
            {
                this->Vector.at(index).value = -1;
                this->Vector.at(index).rect.setFillColor(sf::Color(106, 231, 255));
                this->Vector.at(index++).setValue();                
                i++;
            }
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

void DataVisualization_2::createRandomVector()
{ 
    this->size = 2 + rand() % 8;
    this->capacity = this->size;
    for (int i = 0; i < this->size; i++)
    {
        this->Vector.at(i).value = 1 + rand() % 99;
        this->Vector.at(i).rect.setFillColor(sf::Color(106, 231, 255));
        this->Vector.at(i).setValue();
    }
}

void DataVisualization_2::createRandomSort()
{
    this->size = 2 + rand() % 8;
    this->capacity = this->size;
    for (int i = 0; i < this->size; i++)
    {
        this->Vector.at(i).value = 1 + rand() % 99;
        this->Vector.at(i).rect.setFillColor(sf::Color(106, 231, 255));
        this->Vector.at(i).setValue();
    }
}

void DataVisualization_2::createRandomFixedSize(int size)
{
    this->size = size;
    this->capacity = this->size;
    for (int i = 0; i < this->size; i++)
    {
        this->Vector.at(i).value = 1 + rand() % 99;
        this->Vector.at(i).rect.setFillColor(sf::Color(106, 231, 255));
        this->Vector.at(i).setValue();
    }
}

void DataVisualization_2::createRandomFixedSizeVector(sf::RenderWindow &window, sf::Event &event)
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
                this->capacity = this->size;
                this->createRandomFixedSize(size);
            } else {
                this->checksize(window, size);
            }
        }
        this->CreateRandomFixedSize_Textbox.pressEnter = false;
    }
}

void DataVisualization_2::createUserDefinedVector(sf::RenderWindow &window, sf::Event &event)
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
                if (num_values > 10 || num_values < 1)
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
                    this->createUserDefined(window, values);
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

void DataVisualization_2::createUserDefined(sf::RenderWindow &window, std::vector<int> &values)
{
    this->size = values.size();
    this->capacity = this->size;
    for (int i = 0; i < this->size; i++)
    {
        this->Vector.at(i).value = values[i];
        this->Vector.at(i).rect.setFillColor(sf::Color(106, 231, 255));
        this->Vector.at(i).setValue();
    }
}

void DataVisualization_2::AddFrontVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->AddFront_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->AddFront_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->AddFront_Textbox.pressEnter == true)
        {
            int index = std::stoi(str);
            this->AddFront(window, index);
        }
        this->AddFront_Textbox.pressEnter = false;
    }
}
void DataVisualization_2::AddFront(sf::RenderWindow &window, int value)
{
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/AddFront.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    if (this->size == this->capacity)
    {
        this->printMessage(window, "Vector's capacity is full");
        return;
    }
    Image arrow;
    arrow.setImage(WorkingPath + "media/DataVisualization1/arrowright.png");
    this->Vector.at(0).rect.setFillColor(sf::Color::White);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    for (int i = 0; i < size; i++)
    {
        arrow.setPosition(sf::Vector2f(467 + arrow.ImageHolder.getLocalBounds().width / 2.f + 100 * i, 350 - arrow.ImageHolder.getLocalBounds().height + 4));
        arrow.drawImage(window);
    }
    window.display();
    sf::sleep(sf::milliseconds(2000 / speed));

    this->size++;
    for (int i = this->size - 1; i >= 0; i--)
    {
        this->Vector.at(i+1).value = this->Vector.at(i).value;
        this->Vector.at(i+1).setValue();
    }
    // make the first element white and return it back
    this->Vector.at(0).rect.setFillColor(sf::Color::White);
    this->Vector.at(size - 1).rect.setFillColor(sf::Color(106, 231, 255));
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawVector(window);
    window.display();
    sf::sleep(sf::milliseconds(2000 / speed));

    this->Vector.at(0).value = value;
    this->Vector.at(0).setValue();
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawVector(window);
    window.display();
    this->Vector.at(0).rect.setFillColor(sf::Color(106, 231, 255));
}
void DataVisualization_2::AddBackVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->AddBack_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->AddBack_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->AddBack_Textbox.pressEnter == true)
        {
            int index = std::stoi(str);
            this->AddBack(window, index);
        }
        this->AddBack_Textbox.pressEnter = false;
    }
}
void DataVisualization_2::AddBack(sf::RenderWindow &window, int value)
{
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/AddBack.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    if (this->size == this->capacity)
    {
        this->printMessage(window, "Vector's capacity is full");
        return;
    }
    this->size++;
    this->Vector.at(size - 1).rect.setFillColor(sf::Color::White);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawVector(window);
    window.display();
    sf::sleep(sf::milliseconds(2000 / speed));

    this->Vector.at(size - 1).value = value;
    this->Vector.at(size - 1).setValue();
    this->Vector.at(size - 1).rect.setFillColor(sf::Color(106, 231, 255));
}
void DataVisualization_2::AddMiddleVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->AddMiddle_Textbox.isSelected)
    {
        static int value = -1;
        static int index = -1;

        // Receive input string
        std::string str = "";
        this->AddMiddle_Textbox.TextboxHandleEvent(event, str);

        // Check if input is valid
        if (str != "" && this->AddMiddle_Textbox.pressEnter == true)
        {
            if (index == -1) {
                index = std::stoi(str);
                this->AddMiddle_Textbox.EnterMessage.setString("Value: ");
            }
            else {
                value = std::stoi(str);
                this->AddMiddle(window, index, value);
                this->AddMiddle_Textbox.EnterMessage.setString("Index: ");
                value = -1;
                index = -1;
            }
            this->AddMiddle_Textbox.pressEnter = false;
        }
    }
}
void DataVisualization_2::AddMiddle(sf::RenderWindow &window, int index, int value)
{
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/AddMid.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    if (this->size == this->capacity)
    {
        this->printMessage(window, "Vector's capacity is full");
        return;
    }
    if (index < 0 || index > this->size)
    {
        this->printMessage(window, "Index is out of range");
        return;
    }
    if (index == 0)
    {
        AddFront(window, value);
        return;
    }
    if (index == size)
    {
        AddBack(window, value);
        return;
    }
    Image arrow;
    arrow.setImage(WorkingPath + "media/DataVisualization1/arrowright.png");
    this->Vector.at(index).rect.setFillColor(sf::Color::White);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    for (int i = index; i < size; i++)
    {
        arrow.setPosition(sf::Vector2f(467 + arrow.ImageHolder.getLocalBounds().width / 2.f + 100 * i, 350 - arrow.ImageHolder.getLocalBounds().height + 4));
        arrow.drawImage(window);
    }
    window.display();
    sf::sleep(sf::milliseconds(2000 / speed));

    this->size++;
    for (int i = this->size - 1; i >= index; i--)
    {
        this->Vector.at(i+1).value = this->Vector.at(i).value;
        this->Vector.at(i+1).setValue();
    }
    // make the first element white and return it back
    this->Vector.at(size - 1).rect.setFillColor(sf::Color(106, 231, 255));
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawVector(window);
    window.display();
    sf::sleep(sf::milliseconds(2000 / speed));

    this->Vector.at(index).value = value;
    this->Vector.at(index).setValue();
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawVector(window);
    window.display();
    this->Vector.at(index).rect.setFillColor(sf::Color(106, 231, 255));
}

void DataVisualization_2::AllocateSizeVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->AllocateSize_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->AllocateSize_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->AllocateSize_Textbox.pressEnter == true)
        {
            int index = std::stoi(str);
            this->AllocateSize(window, index);
        }
        this->AllocateSize_Textbox.pressEnter = false;
    }
}

void DataVisualization_2::AllocateSize(sf::RenderWindow &window, int size)
{
    CodeScript.setImage(WorkingPath + "media/DataVisualization2/Allocated.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    if (size < 0)
    {
        this->printMessage(window, "Size must be greater than 0");
        return;
    }
    for (int i = this->size; i < size; i++)
    {
        this->Vector.at(i).value = -1;
        this->Vector.at(i).setValue();
        this->Vector.at(i).rect.setFillColor(MainColor);
    }
    this->size = size;
    this->capacity = size;
}

void DataVisualization_2::DeleteFront(sf::RenderWindow &window)
{
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/DeleteFront.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    if (this->size == 0)
    {
        this->printMessage(window, "Vector is empty");
        return;
    }
    Image arrow;
    arrow.setImage(WorkingPath + "media/DataVisualization1/arrowleft.png");
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    for (int i = 0; i < size - 1; i++)
    {
        arrow.setPosition(sf::Vector2f(467 + arrow.ImageHolder.getLocalBounds().width / 2.f + 100 * i, 350 - arrow.ImageHolder.getLocalBounds().height + 4));
        arrow.drawImage(window);
    }
    window.display();
    sf::sleep(sf::milliseconds(2000 / speed));

    this->size--;
    for (int i = 0; i < this->size; i++)
    {
        this->Vector.at(i).value = this->Vector.at(i + 1).value;
        this->Vector.at(i).setValue();
    }
}
void DataVisualization_2::DeleteBack(sf::RenderWindow &window)
{
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/DeleteBack.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    if (this->size == 0)
    {
        this->printMessage(window, "Vector is empty");
        return;
    }
    this->size--;
}
void DataVisualization_2::DeleteMiddleVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->DeleteMiddle_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->DeleteMiddle_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->DeleteMiddle_Textbox.pressEnter == true)
        {
            int index = std::stoi(str);
            this->DeleteMiddle(window, index);
        }
        this->DeleteMiddle_Textbox.pressEnter = false;
    }
}
void DataVisualization_2::DeleteMiddle(sf::RenderWindow &window, int index)
{
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/DeleteMid.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    if (this->size == 0)
    {
        this->printMessage(window, "Vector is empty");
        return;
    }
    if (index < 0 || index >= this->size)
    {
        this->printMessage(window, "Index out of range");
        return;
    }
    if (index == 0)
    {
        DeleteFront(window);
        return;
    }
    if (index == size-1)
    {
        DeleteBack(window);
        return;
    }
    Image arrow;
    arrow.setImage(WorkingPath + "media/DataVisualization1/arrowleft.png");
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    for (int i = index; i < size - 1; i++)
    {
        arrow.setPosition(sf::Vector2f(467 + arrow.ImageHolder.getLocalBounds().width / 2.f + 100 * i, 350 - arrow.ImageHolder.getLocalBounds().height + 4));
        arrow.drawImage(window);
    }
    window.display();
    sf::sleep(sf::milliseconds(2000 / speed));

    this->size--;
    for (int i = index; i < this->size; i++)
    {
        this->Vector.at(i).value = this->Vector.at(i + 1).value;
        this->Vector.at(i).setValue();
    }
}

void DataVisualization_2::AccessVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->AccessButton_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->AccessButton_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->AccessButton_Textbox.pressEnter == true)
        {
            int index = std::stoi(str);
            this->AccessValue(window, index);
        }
        this->AccessButton_Textbox.pressEnter = false;
    }
}

void DataVisualization_2::AccessValue(sf::RenderWindow &window, int index)
{
    std::chrono::milliseconds delayTime(1000 / speed); 
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);

    CodeScript.setImage(WorkingPath + "media/DataVisualization1/Access.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();

    // handle special case;
    if (this->size == 0)
    {
        printMessage(window, "No element to be accessed!");
        return;
    }
    if (index >= this->size || index < 0)
    {
        printMessage(window, "Index is out of range!");
        return;
    }
    this->Vector.at(index).rect.setFillColor(sf::Color::White);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime);
    std::string mess = "Vector[" + std::to_string(index) + "] = " + std::to_string(this->Vector.at(index).value);
    printMessage(window, mess);

    this->Vector.at(index).rect.setFillColor(sf::Color(106, 231, 255));
    return;
}

void DataVisualization_2::UpdateVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->UpdateButton_Textbox.isSelected)
    {
        static int value = -1;
        static int index = -1;

        // Receive input string
        std::string str = "";
        this->UpdateButton_Textbox.TextboxHandleEvent(event, str);

        // Check if input is valid
        if (str != "" && this->UpdateButton_Textbox.pressEnter == true)
        {
            if (index == -1) {
                index = std::stoi(str);
                this->UpdateButton_Textbox.EnterMessage.setString("Value: ");
            }
            else {
                value = std::stoi(str);
                this->Update(window, index, value);
                this->UpdateButton_Textbox.EnterMessage.setString("Index: ");
                value = -1;
                index = -1;
            }
            this->UpdateButton_Textbox.pressEnter = false;
        }
    }
}

void DataVisualization_2::Update(sf::RenderWindow &window, int index, int value)
{
    std::chrono::milliseconds delayTime(1000 / speed); 
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);
 
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/Update.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();

     if (this->size == 0)
    {
        window.draw(CodeHighLight);
        printMessage(window, "No element to be Update");
        return;
    }
    
    if (index >= this->size)
    {
        std::string str = "Index must be from 0 to " + std::to_string(this->size - 1);
        printMessage(window, str);
        return;
    } 
    
    this->Vector.at(index).rect.setFillColor(sf::Color::White);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawVector(window);
    window.display();
    std::this_thread::sleep_for(delayTime);
    
    this->Vector.at(index).value = value;
    this->Vector.at(index).setValue();
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawVector(window);
    window.display();
    std::this_thread::sleep_for(delayTime);
    this->Vector.at(index).rect.setFillColor(sf::Color(106, 231, 255));
}

void DataVisualization_2::swapNodes(sf::RenderWindow &window, int index1, int index2) {
    sf::Vector2f pos1 = Vector.at(index1).rect.getPosition();
    sf::Vector2f pos2 = Vector.at(index2).rect.getPosition();
    float distance = pos2.x - pos1.x;
    float fps = 60 / speed;
    if (distance < 200){
        fps = 30 / speed;
    }
    float movePerFrame = distance / fps;
    // moving up
    // for (float i = 0; i < 60 / speed; i++) {
    //     Vector.at(index1).rect.move(0, -1 * 150 * speed / 60.f);
    //     Vector.at(index1).data.move(0, -1 * 150 * speed / 60.f);
    //     Vector.at(index2).rect.move(0, -1 * 150 * speed / 60.f);
    //     Vector.at(index2).data.move(0, -1 * 150 * speed / 60.f);

    //     window.clear();
    //     window.draw(DefaultBackground);
    //     this->drawVector(window);
    //     this->display(window);
    //     window.display();
    // }

    for (float i = 0; i < fps; i++) {
        Vector.at(index1).rect.move(movePerFrame, 0);
        Vector.at(index1).data.move(movePerFrame, 0);
        Vector.at(index2).rect.move(-1 * movePerFrame, 0);
        Vector.at(index2).data.move(-1 * movePerFrame, 0);

        window.clear();
        window.draw(DefaultBackground);
        this->drawVector(window);
        this->display(window);
        window.display();
    }
    // moving down
    // for (float i = 0; i < 60 / speed; i++) {
    //     Vector.at(index1).rect.move(0, 150 * speed / 60.f);
    //     Vector.at(index1).data.move(0, 150 * speed / 60.f);
    //     Vector.at(index2).rect.move(0, 150 * speed / 60.f);
    //     Vector.at(index2).data.move(0, 150 * speed / 60.f);

    //     window.clear();
    //     window.draw(DefaultBackground);
    //     this->drawVector(window);
    //     this->display(window);
    //     window.display();
    // }

    std::swap(Vector.at(index1), Vector.at(index2));
    Vector.at(index1).setValue();
    Vector.at(index2).setValue();

    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
}

void DataVisualization_2::SearchVector(sf::RenderWindow &window, sf::Event &event)
{
    if (this->SearchButton_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->SearchButton_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->SearchButton_Textbox.pressEnter == true)
        {
            int value = std::stoi(str);
            this->Search(window, value);
        }
        this->SearchButton_Textbox.pressEnter = false;
    }
}

void DataVisualization_2::Search(sf::RenderWindow &window, int value)
{
    std::chrono::milliseconds delayTime(1000 / speed); 
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);
    
    CodeScript.setImage(WorkingPath + "media/DataVisualization1/Search.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();

    // handle special case;
    if (this->size == 0)
    {
        printMessage(window, "No element to be searched");
        return;
    }
    // code
    int index = 0;
    std::string mess = "Value not found!";
    for (int i = 0; i < size; i++)
    {
        this->Vector.at(i).rect.setFillColor(sf::Color::White);
        if (this->Vector.at(i).value == value)
        {
            mess = "Founded at index " + std::to_string(index);
            break;
        } 
        window.clear();
        window.draw(DefaultBackground);
        this->drawVector(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime);
        index++;
    }
    window.clear();
    window.draw(DefaultBackground);
    this->drawVector(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2);
    printMessage(window, mess);

    for (int i = 0; i <= index; i++)
    {
        this->Vector.at(i).rect.setFillColor(sf::Color(106, 231, 255));
    }
    return;
}

void DataVisualization_2::SortAscendingVector(sf::RenderWindow& window) 
{
    std::chrono::milliseconds delayTime(1000 / speed);
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);

    if (size == 0)
    {
        printMessage(window, "No element to be sorted");
        return;
    }

    if (size <= 1) {
        printMessage(window, "Vector is already sorted");
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (Vector.at(j).value < Vector.at(minIndex).value) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapNodes(window, i, minIndex);
        }
    }
    printMessage(window, "Vector sorted");
}

void DataVisualization_2::SortDescendingVector(sf::RenderWindow& window) 
{
    std::chrono::milliseconds delayTime(1000 / speed);
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);

    if (size == 0)
    {
        printMessage(window, "No element to be sorted");
        return;
    }

    if (size <= 1) {
        printMessage(window, "Vector is already sorted");
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (Vector.at(j).value > Vector.at(maxIndex).value) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swapNodes(window, i, maxIndex);
        }
    }
    printMessage(window, "Vector sorted");
}

bool DataVisualization_2::checksize(sf::RenderWindow &window, int size)
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
    this->drawVector(window);
    NotificationImage.drawImage(window);
    window.draw(message);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return false;
}

bool DataVisualization_2::printMessage(sf::RenderWindow &window, std::string message)
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
    this->drawVector(window);
    NotificationImage.drawImage(window);
    window.draw(WarningMessage);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return true;
}

void DataVisualization_2::updateChanges(sf::Font tempFont)
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
    sf::Text DV1Title("Dynamic Array", this->titlefont, 35);
    CreateTitle(DV1Title, 400, 60.f);
    this->Title = DV1Title;

    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 300.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 100.f);

    //Function Key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 125.f, sf::Color(106, 231, 255, 0), "Create", this->font, sf::Color(106, 231, 255));

    this->CreateFromFileButton.CreateButton(130.f, 50.f, this->ControlMenu_btn1.rect.getPosition().x + this->ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Import", this->font, sf::Color(106, 231, 255));
    this->CreateFromFileButton.rect.setOutlineThickness(2.f);
    this->CreateFromFileButton.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->CreateRadom.CreateButton(130.f, 50.f, this->CreateFromFileButton.rect.getPosition().x + this->CreateFromFileButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random", this->font, sf::Color(106, 231, 255));
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

    // Function Key #2: Add
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 175.f, sf::Color(106, 231, 255, 0), "Add/Allocate", this->font, sf::Color(106, 231, 255));
    this->AddFrontButton.CreateButton(130.f, 50.f, this->ControlMenu_btn2.rect.getPosition().x + this->ControlMenu_btn2.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Add Front", this->font, sf::Color(106, 231, 255));
    this->AddFrontButton.rect.setOutlineThickness(2.f);
    this->AddFrontButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AddFront_Textbox, 20, sf::Color::White, true, this->AddFrontButton.rect.getPosition().x, this->AddFrontButton.rect.getPosition().y + 50, font, true, 3);
    this->AddFront_Textbox.EnterMessage.setString("Value: ");
    this->AddMiddleButton.CreateButton(130.f, 50.f, this->AddFrontButton.rect.getPosition().x + this->AddFrontButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Add Mid", this->font, sf::Color(106, 231, 255));
    this->AddMiddleButton.rect.setOutlineThickness(2.f);
    this->AddMiddleButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AddMiddle_Textbox, 20, sf::Color::White, true, this->AddMiddleButton.rect.getPosition().x, this->AddMiddleButton.rect.getPosition().y + 50, font, true, 3);
    this->AddMiddle_Textbox.EnterMessage.setString("Index: ");
    this->AddBackButton.CreateButton(130.f, 50.f, this->AddMiddleButton.rect.getPosition().x + this->AddMiddleButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Add Back", this->font, sf::Color(106, 231, 255));
    this->AddBackButton.rect.setOutlineThickness(2.f);
    this->AddBackButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AddBack_Textbox, 20, sf::Color::White, true, this->AddBackButton.rect.getPosition().x, this->AddBackButton.rect.getPosition().y + 50, font, true, 3);
    this->AddBack_Textbox.EnterMessage.setString("Value: ");
    this->AllocateSizeButton.CreateButton(130.f, 50.f, this->AddBackButton.rect.getPosition().x + this->AddBackButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn2.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Allocate", this->font, sf::Color(106, 231, 255));
    this->AllocateSizeButton.rect.setOutlineThickness(2.f);
    this->AllocateSizeButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AllocateSize_Textbox, 20, sf::Color::White, true, this->AllocateSizeButton.rect.getPosition().x, this->AllocateSizeButton.rect.getPosition().y + 50, font, true, 3);
    this->AllocateSize_Textbox.EnterMessage.setString("Size: ");

    // Function Key #3: Delete
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Delete", this->font, sf::Color(106, 231, 255));
    this->DeleteFrontButton.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Front", this->font, sf::Color(106, 231, 255));
    this->DeleteFrontButton.rect.setOutlineThickness(2.f);
    this->DeleteFrontButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->DeleteMiddleButton.CreateButton(130.f, 50.f, this->DeleteFrontButton.rect.getPosition().x + this->DeleteFrontButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Middle", this->font, sf::Color(106, 231, 255));
    this->DeleteMiddleButton.rect.setOutlineThickness(2.f);
    this->DeleteMiddleButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->DeleteMiddle_Textbox, 20, sf::Color::White, true, this->DeleteMiddleButton.rect.getPosition().x, this->DeleteMiddleButton.rect.getPosition().y + 50, font, true, 3);
    this->DeleteMiddle_Textbox.EnterMessage.setString("Index: ");
    this->DeleteBackButton.CreateButton(130.f, 50.f, this->DeleteMiddleButton.rect.getPosition().x + this->DeleteMiddleButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->DeleteBackButton.rect.setOutlineThickness(2.f);
    this->DeleteBackButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->ClearVectorButton.CreateButton(130.f, 50.f, this->DeleteBackButton.rect.getPosition().x + this->DeleteBackButton.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn3.rect.getPosition().y, sf::Color(106, 231, 255, 0), "DeAllocate", this->font, sf::Color(106, 231, 255));
    this->ClearVectorButton.rect.setOutlineThickness(2.f);
    this->ClearVectorButton.rect.setOutlineColor(sf::Color(106, 231, 255));

    //Function Key #4: Access
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Access", this->font, sf::Color(106, 231, 255));
    this->UpdateButton.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Update", this->font, sf::Color(106, 231, 255));
    this->UpdateButton.rect.setOutlineThickness(2.f);
    this->UpdateButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->UpdateButton_Textbox, 20, sf::Color::White, true, this->UpdateButton.rect.getPosition().x, this->UpdateButton.rect.getPosition().y + 50, font, true, 3);
    this->UpdateButton_Textbox.EnterMessage.setString("Index: ");
    this->AccessButton.CreateButton(130.f, 50.f, this->UpdateButton.rect.getPosition().x + this->UpdateButton.rect.getSize().x / 2.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Access", this->font, sf::Color(106, 231, 255));
    this->AccessButton.rect.setOutlineThickness(2.f);
    this->AccessButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->AccessButton_Textbox, 20, sf::Color::White, true, this->AccessButton.rect.getPosition().x, this->AccessButton.rect.getPosition().y + 50, font, true, 3);
    this->AccessButton_Textbox.EnterMessage.setString("Index: ");

    //Function Key #5: Search
    this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.CreateButton(130.f, 50.f, this->ControlMenu_btn5.rect.getPosition().x + this->ControlMenu_btn5.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.rect.setOutlineThickness(2.f);
    this->SearchButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->SearchButton_Textbox, 20, sf::Color::White, true, this->SearchButton.rect.getPosition().x, this->SearchButton.rect.getPosition().y + 50, font, true, 3);
    this->SearchButton_Textbox.EnterMessage.setString("Value: ");

    //Function Key #6: Sort
    this->ControlMenu_btn6.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Sort", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.CreateButton(130.f, 50.f, this->ControlMenu_btn6.rect.getPosition().x + this->ControlMenu_btn6.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Ascending", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.rect.setOutlineThickness(2.f);
    this->SortButtonAscending.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->SortButtonDescending.CreateButton(130.f, 50.f, this->SortButtonAscending.rect.getPosition().x + this->SortButtonAscending.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Descending", this->font, sf::Color(106, 231, 255));
    this->SortButtonDescending.rect.setOutlineThickness(2.f);
    this->SortButtonDescending.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    for (int i = 0; i < 10; i++)
    {
        this->Vector.at(i).value = i;
        this->Vector.at(i).rect.setSize(sf::Vector2f(100.f, 100.f));
        this->Vector.at(i).rect.setPosition(sf::Vector2f(450 + 100 * i, 400));
        this->Vector.at(i).rect.setOrigin(sf::Vector2f(50, 50));
        this->Vector.at(i).rect.setFillColor(sf::Color(106, 231, 255));
        this->Vector.at(i).rect.setOutlineColor(sf::Color::Black);
        this->Vector.at(i).rect.setOutlineThickness(2.f);

        this->Vector.at(i).data.setCharacterSize(30);
        this->Vector.at(i).data.setFont(this->font);
        this->Vector.at(i).data.setFillColor(sf::Color::Black);
        this->Vector.at(i).data.setString(std::to_string(this->Vector.at(i).value));
        this->Vector.at(i).setValue();
    }
    this->size = 0;
    this->capacity = 0;
    funcstate = 0;    
}