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
    sf::Text DV2Title("Dynamic Array", this->titlefont, 35);
    CreateTitle(DV2Title, 400, 60.f);
    this->Title = DV2Title;

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
    this->UpdateButton_Textbox.EnterMessage.setString("Index: ");
    
    //Function Key #3
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Search", this->font, sf::Color(106, 231, 255));
    this->SearchButton.rect.setOutlineThickness(2.f);
    this->SearchButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->SearchButton_Textbox, 20, sf::Color::White, true, this->SearchButton.rect.getPosition().x, this->SearchButton.rect.getPosition().y + 50, font, true, 3);
    this->SearchButton_Textbox.EnterMessage.setString("Value: ");

    //Function Key #4
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Sort", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Ascending", this->font, sf::Color(106, 231, 255));
    this->SortButtonAscending.rect.setOutlineThickness(2.f);
    this->SortButtonAscending.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->SortButtonDescending.CreateButton(130.f, 50.f, this->SortButtonAscending.rect.getPosition().x + this->SortButtonAscending.rect.getSize().x / 2.f + 10.f + 130/2.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Descending", this->font, sf::Color(106, 231, 255));
    this->SortButtonDescending.rect.setOutlineThickness(2.f);
    this->SortButtonDescending.rect.setOutlineColor(sf::Color(106, 231, 255));
    
    // //Function Key #5
    this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Push Back", this->font, sf::Color(106, 231, 255));
    this->PushBackButton.CreateButton(130.f, 50.f, this->ControlMenu_btn5.rect.getPosition().x + this->ControlMenu_btn5.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "PushBack", this->font, sf::Color(106, 231, 255));
    this->PushBackButton.rect.setOutlineThickness(2.f);
    this->PushBackButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    InitTextbox(this->PushBack_Textbox, 20, sf::Color::White, true, this->PushBackButton.rect.getPosition().x, this->PushBackButton.rect.getPosition().y + 50, font, true, 3);
    this->PushBack_Textbox.EnterMessage.setString("Value: ");

    for (int i = 0; i < 10; i++)
    {
        this->Array[i].value = i;
        this->Array[i].rect.setSize(sf::Vector2f(100.f, 100.f));
        this->Array[i].rect.setPosition(sf::Vector2f(450 + 100 * i, 400));
        this->Array[i].rect.setOrigin(sf::Vector2f(50, 50));
        this->Array[i].rect.setFillColor(sf::Color(106, 231, 255));
        this->Array[i].rect.setOutlineColor(sf::Color::Black);
        this->Array[i].rect.setOutlineThickness(2.f);

        this->Array[i].data.setCharacterSize(30);
        this->Array[i].data.setFont(this->font);
        this->Array[i].data.setFillColor(sf::Color::Black);
        this->Array[i].data.setString(std::to_string(this->Array[i].value));
        this->Array[i].setValue();
    }

    this->size = 0;
    funcstate = 0;    
}

void DataVisualization_2::display(sf::RenderWindow &window)
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
        this->UpdateButton.displayButton(window);
        this->UpdateButton_Textbox.drawTo(window);
        break;
    case 3:
        this->SearchButton.displayButton(window);
        this->SearchButton_Textbox.drawTo(window);
        break;
    case 4:
        this->SortButtonAscending.displayButton(window);
        this->SortButtonDescending.displayButton(window);
        break;
    case 5:
        this->PushBackButton.displayButton(window);
        this->PushBack_Textbox.drawTo(window);
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
            DefaultBackground.setTexture(this->page2texture);
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
        else {
            this->CreateRandomFixedSize_Textbox.isSelected = false;
            this->CreateUserDefinedList_Textbox.isSelected = false;
            this->UpdateButton_Textbox.isSelected = false;
            this->SearchButton_Textbox.isSelected = false;
            this->PushBack_Textbox.isSelected = false;
        }
        switch (this->funcstate)
        {
        case 1:
            if (this->CreateEmpty.rect.getGlobalBounds().contains(mousePos))
            {
                this->size = 0;
            }
            if (this->CreateRadom.rect.getGlobalBounds().contains(mousePos))
            {
                createRandomArray();
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
            if (this->UpdateButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->UpdateButton_Textbox.isSelected = !this->UpdateButton_Textbox.isSelected;
            } else {
                this->UpdateButton_Textbox.isSelected = false;
            }
            break;
        case 3:
            if (this->SearchButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->SearchButton_Textbox.isSelected = !this->SearchButton_Textbox.isSelected;
            } else {
                this->SearchButton_Textbox.isSelected = false;
            }
            break;
        case 4:
            if (this->SortButtonAscending.rect.getGlobalBounds().contains(mousePos))
            {
                SortAscendingArray(window);
            } 
            if (this->SortButtonDescending.rect.getGlobalBounds().contains(mousePos))
            {
                SortDescendingArray(window);
            } 
            break;
        case 5:
            if (this->PushBackButton.rect.getGlobalBounds().contains(mousePos))
            {
                this->PushBack_Textbox.isSelected = !this->PushBack_Textbox.isSelected;
            } else {
                this->PushBack_Textbox.isSelected = false;
            }
            break;
        default:
            break;
        }
    }
    else if (ev.type == sf::Event::TextEntered)
    {
        createRandomFixedSizeArray(window, ev);
        createUserDefinedArray(window, ev);
        UpdateArray(window, ev);
        SearchArray(window, ev);
        PushBackVectorInput(window, ev);
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
        //--------------------//

    }
}

void DataVisualization_2::drawArray(sf::RenderWindow &window)
{
    if (this->size != 0)
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
        index.setPosition(this->Array[i].rect.getPosition().x, this->Array[i].rect.getPosition().y + 100);
        index.setOrigin(index.getLocalBounds().width / 2.f, index.getLocalBounds().height / 2.f);
        window.draw(this->Array[i].rect);
        window.draw(this->Array[i].data);
        window.draw(index);
    }
}

void DataVisualization_2::createRandomArray()
{
    this->size = 2 + rand() % 8;
    for (int i = 0; i < this->size; i++)
    {
        this->Array[i].value = 1 + rand() % 99;
        this->Array[i].setValue();
    }
}

void DataVisualization_2::createRandomSort()
{
    this->size = 2 + rand() % 8;
    for (int i = 0; i < this->size; i++)
    {
        this->Array[i].value = 1 + rand() % 99;
        this->Array[i].setValue();
    }
    this->sortAscending();
}

void DataVisualization_2::createRandomFixedSize(int size)
{
    this->size = size;
    for (int i = 0; i < this->size; i++)
    {
        this->Array[i].value = 1 + rand() % 99;
        this->Array[i].setValue();
    }
}

void DataVisualization_2::createRandomFixedSizeArray(sf::RenderWindow &window, sf::Event &event)
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
                this->createRandomFixedSize(size);
                // this->N(this->NodeArray, this->size, this->font);
            } else {
                this->checksize(window, size);
            }
        }
        this->CreateRandomFixedSize_Textbox.pressEnter = false;
    }
}

void DataVisualization_2::createUserDefinedArray(sf::RenderWindow &window, sf::Event &event)
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
    for (int i = 0; i < this->size; i++)
    {
        this->Array[i].value = values[i];
        this->Array[i].setValue();
    }
}

void DataVisualization_2::UpdateArray(sf::RenderWindow &window, sf::Event &event)
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
 
     if (this->size == 0)
    {
        window.draw(CodeHighLight);
        printMessage(window, "There is no Node to be Update");
        return;
    }
    
    if (index >= this->size)
    {
        std::string str = "Index must be from 0 to " + std::to_string(this->size - 1);
        printMessage(window, str);
        return;
    } 
    
    this->Array[index].rect.setFillColor(sf::Color::White);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawArray(window);
    // window.draw(CodeHighLight);
    // NotificationImage.drawImage(window);
    window.display();
    std::this_thread::sleep_for(delayTime);
    
    this->Array[index].value = value;
    this->Array[index].setValue();
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawArray(window);
    // window.draw(CodeHighLight);
    // NotificationImage.drawImage(window);
    window.display();
    std::this_thread::sleep_for(delayTime);
    this->Array[index].rect.setFillColor(sf::Color(106, 231, 255));
}

void DataVisualization_2::swapNodes(sf::RenderWindow &window, int index1, int index2) {
    sf::Vector2f pos1 = Array[index1].rect.getPosition();
    sf::Vector2f pos2 = Array[index2].rect.getPosition();
    float distance = pos2.x - pos1.x;
    float fps = 60 / speed;
    if (distance < 200){
        fps = 30 / speed;
    }
    float movePerFrame = distance / fps;
    // moving up
    for (float i = 0; i < 60 / speed; i++) {
        Array[index1].rect.move(0, -1 * 150 * speed / 60.f);
        Array[index1].data.move(0, -1 * 150 * speed / 60.f);
        Array[index2].rect.move(0, -1 * 150 * speed / 60.f);
        Array[index2].data.move(0, -1 * 150 * speed / 60.f);

        window.clear();
        window.draw(DefaultBackground);
        this->drawArray(window);
        this->display(window);
        window.display();
    }

    for (float i = 0; i < fps; i++) {
        Array[index1].rect.move(movePerFrame, 0);
        Array[index1].data.move(movePerFrame, 0);
        Array[index2].rect.move(-1 * movePerFrame, 0);
        Array[index2].data.move(-1 * movePerFrame, 0);

        window.clear();
        window.draw(DefaultBackground);
        this->drawArray(window);
        this->display(window);
        window.display();
    }
    // moving down
    for (float i = 0; i < 60 / speed; i++) {
        Array[index1].rect.move(0, 150 * speed / 60.f);
        Array[index1].data.move(0, 150 * speed / 60.f);
        Array[index2].rect.move(0, 150 * speed / 60.f);
        Array[index2].data.move(0, 150 * speed / 60.f);

        window.clear();
        window.draw(DefaultBackground);
        this->drawArray(window);
        this->display(window);
        window.display();
    }

    std::swap(Array[index1], Array[index2]);
    Array[index1].setValue();
    Array[index2].setValue();

    window.clear();
    window.draw(DefaultBackground);
    this->drawArray(window);
    this->display(window);
    window.display();
}

void DataVisualization_2::SearchArray(sf::RenderWindow &window, sf::Event &event)
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
    // CodeScript.setPosition(CodeScriptPosition);
    // CodeScript.setImage("media/DataVisualization3/Search.png");
    std::chrono::milliseconds delayTime(1000 / speed); 
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);
    // CodeHighLight.setPosition(CodeHighLightPosition);

    // handle special case;
    if (this->size == 0)
    {
        // CodeScript.drawImage(window);
        // window.draw(CodeHighLight);
        printMessage(window, "There is no Node to be searched");
        return;
    }
    // code
    int index = 0;
    std::string mess = "";
    for (int i = 0; i < size; i++)
    {
        this->Array[i].rect.setFillColor(sf::Color::White);
        if (this->Array[i].value == value)
        {
            mess = "Founded at index " + std::to_string(index);
            break;
        } 
        window.clear();
        window.draw(DefaultBackground);
        this->drawArray(window);
        this->display(window);
        // window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime);
        index++;
    }
    if (this->Array[index].value != value)
    {
        mess = "Value not found!";
    }
    window.clear();
    window.draw(DefaultBackground);
    this->drawArray(window);
    this->display(window);
    // window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime2);
    printMessage(window, mess);

    for (int i = 0; i <= index; i++)
    {
        this->Array[i].rect.setFillColor(sf::Color(106, 231, 255));
    }
    return;
}

void DataVisualization_2::SortAscendingArray(sf::RenderWindow& window) 
{
    std::chrono::milliseconds delayTime(1000 / speed);
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);

    if (size <= 1) {
        printMessage(window, "Array is already sorted");
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (Array[j].value < Array[minIndex].value) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapNodes(window, i, minIndex);
        }
    }
    printMessage(window, "Array sorted");
}

void DataVisualization_2::SortDescendingArray(sf::RenderWindow& window) 
{
    std::chrono::milliseconds delayTime(1000 / speed);
    std::chrono::milliseconds delayTime1(50);
    std::chrono::milliseconds delayTime2(500 / speed);

    if (size <= 1) {
        printMessage(window, "Array is already sorted");
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (Array[j].value > Array[maxIndex].value) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swapNodes(window, i, maxIndex);
        }
    }
    printMessage(window, "Array sorted");
}

// void DataVisualization_2::SortAscendingArray();
// void DataVisualization_2::SortDescendingArray();

void DataVisualization_2::PushBackVectorInput(sf::RenderWindow &window, sf::Event &event)
{
    if (this->PushBack_Textbox.isSelected)
    {
        std::string str = "";
        // recieve Input String
        this->PushBack_Textbox.TextboxHandleEvent(event, str);
        // check if input is valid
        if (str != "" && this->PushBack_Textbox.pressEnter == true)
        {
            int value = std::stoi(str);
            this->PushBackVector(window, value);
        }
        this->PushBack_Textbox.pressEnter = false;
    }
}

void DataVisualization_2::PushBackVector(sf::RenderWindow &window, int value)
{
    std::chrono::milliseconds delayTime(1000 / speed);
    if (this->size >= 10)
    {
        printMessage(window, "Vector is full");
        return;
    }
    this->Array[size].value = value;
    this->Array[size].setValue();
    this->size++;
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawArray(window);
    // window.draw(CodeHighLight);
    window.display();

    std::this_thread::sleep_for(delayTime);
    printMessage(window, "Pushed back");
    return;
}

void DataVisualization_2::sortAscending()
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (this->Array[min].value > this->Array[j].value)
            {
                min = j;
            }
        }
        int temp = this->Array[min].value;
        this->Array[min].value = this->Array[i].value;
        this->Array[i].value = temp;
    }
    for (int i = 0; i < size; i++)
    {
        this->Array[i].setValue();
    }
}

void DataVisualization_2::sortDescending()
{
    for (int i = 0; i < size; i++)
    {
        int max = i;
        for (int j = i + 1; j < size; j++)
        {
            if (this->Array[max].value < this->Array[j].value)
            {
                max = j;
            }
        }
        int temp = this->Array[max].value;
        this->Array[max].value = this->Array[i].value;
        this->Array[i].value = temp;
    }
    for (int i = 0; i < size; i++)
    {
        this->Array[i].setValue();
    }
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
    this->drawArray(window);
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
    this->drawArray(window);
    // window.draw(CodeHighLight);
    NotificationImage.drawImage(window);
    window.draw(WarningMessage);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return true;
}