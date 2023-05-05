#include "DataVisualization7.hpp"

DataVisualization_7::DataVisualization_7()
{
    this->font = defautFont;
    this->titlefont = defautTitleFont;
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
    //---------------------
    CodeHighLight.setPosition(CodeHighLightPosition); // 1170 - 697.5 ~ 35-36
    //---------------------

    //Title
    sf::Text DV7Title("Queue", this->titlefont, 35);
    CreateTitle(DV7Title, 400, 60.f);
    this->Title = DV7Title;
    this->Title.setOutlineThickness(0.f);
    this->Title.setFillColor(sf::Color(106, 231, 255));

    // Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);

    // building the Queue
    this->Queue1.setSize(sf::Vector2f(850, 10));
    this->Queue1.setOrigin(sf::Vector2f(0, 5));
    this->Queue1.setPosition(sf::Vector2f(550, 400));
    this->Queue1.setFillColor(sf::Color::White);
    this->Queue2.setSize(sf::Vector2f(850, 10));
    this->Queue2.setOrigin(sf::Vector2f(0, 5));
    this->Queue2.setPosition(sf::Vector2f(550, 500));
    this->Queue2.setFillColor(sf::Color::White);

// Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 200.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 200.f);

// Function key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Create", this->font, sf::Color(106, 231, 255));
    this->CreateEmpty.CreateButton(130.f, 50.f, this->ControlMenu_btn1.rect.getPosition().x + this->ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Empty", this->font, sf::Color(106, 231, 255));
    this->CreateEmpty.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateEmpty.rect.setOutlineThickness(2.f);

    this->CreateRadom.CreateButton(130.f, 50.f, this->CreateEmpty.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random", this->font, sf::Color(106, 231, 255));
    this->CreateRadom.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateRadom.rect.setOutlineThickness(2.f);
    
    this->ImportFromFileButton.CreateButton(130.f, 50.f, this->CreateRadom.rect.getPosition().x + this->CreateRadom.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Import", this->font, sf::Color(106, 231, 255));
    this->ImportFromFileButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->ImportFromFileButton.rect.setOutlineThickness(2.f);

    this->CreateRandomFixedSize.CreateButton(180.f, 50.f, this->ImportFromFileButton.rect.getPosition().x + this->ImportFromFileButton.rect.getSize().x / 2.f + 160.f / 2.f + 20.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random Fixed Size", this->font, sf::Color(106, 231, 255));
    this->CreateRandomFixedSize.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateRandomFixedSize.rect.setOutlineThickness(2.f);
    InitTextbox(this->CreateRandomFixedSize_Textbox, 20, sf::Color::White, true, this->CreateRandomFixedSize.rect.getPosition().x , this->CreateRandomFixedSize.rect.getPosition().y + 50, font, true, 3);
    this->CreateRandomFixedSize_Textbox.EnterMessage.setString("Size: ");
    
    this->CreateUserDefinedListButton.CreateButton(130.f, 50.f, this->CreateRandomFixedSize.rect.getPosition().x + this->CreateRandomFixedSize.rect.getSize().x / 2.f + 130.f/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "User Defined", this->font, sf::Color(106, 231, 255));
    this->CreateUserDefinedListButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateUserDefinedListButton.rect.setOutlineThickness(2.f);
    InitTextbox(this->CreateUserDefinedList_Textbox, 20, sf::Color::White, true, this->CreateUserDefinedListButton.rect.getPosition().x, this->CreateUserDefinedListButton.rect.getPosition().y + 50, font, true, 3);
    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size: ");

    //Function Key #2: Pushing
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Push", this->font, sf::Color(106, 231, 255));
    InitTextbox(this->InsertHead_Textbox, 20, sf::Color::White, true, this->CreateEmpty.rect.getPosition().x, this->CreateEmpty.rect.getPosition().y + 50, font, true, 3);
    this->InsertHead_Textbox.EnterMessage.setString("Value: ");
    
    //Function Key #3: Pop
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Pop", this->font, sf::Color(106, 231, 255));
    this->DeleteHead.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Head", this->font, sf::Color(106, 231, 255));

    //Function Key #4: Peek
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Peek", this->font, sf::Color(106, 231, 255));
    this->PeekFront.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn4.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Front", this->font, sf::Color(106, 231, 255));
    this->PeekFront.rect.setOutlineThickness(2.f);
    this->PeekFront.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->PeekBack.CreateButton(130.f, 50.f, this->PeekFront.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn4.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->PeekBack.rect.setOutlineThickness(2.f);
    this->PeekBack.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->size = 0;
    this->NodeArray = nullptr;

    funcstate = 0;
}

void DataVisualization_7::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
    this->ControlMenu_btn1.displayButton(window);
    this->ControlMenu_btn2.displayButton(window);
    this->ControlMenu_btn3.displayButton(window);
    this->ControlMenu_btn4.displayButton(window);
    window.draw(this->Queue1);
    window.draw(this->Queue2);

    window.draw(this->menuTable);
    speedText.setString("Speed: x" + std::to_string(speed));
    window.draw(speedText);
    
    CodeScript.drawImage(window);
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
        this->ImportFromFileButton.displayButton(window);
        this->CreateRandomFixedSize.displayButton(window);
        this->CreateRandomFixedSize_Textbox.drawTo(window);
        this->CreateUserDefinedListButton.displayButton(window);
        this->CreateUserDefinedList_Textbox.drawTo(window);
        break;
    case 2:
        this->InsertHead_Textbox.drawTo(window);
        break;
    case 4:
        this->PeekFront.displayButton(window);
        this->PeekBack.displayButton(window);
        break;
    default: // NONE - 0
        break;
    }
}

void DataVisualization_7::handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
            DefaultBackground.setTexture(BackGround1);
            this->NodeArray->DeleteQueue(this->NodeArray);
            this->NodeArray = nullptr;
            this->size = 0;
            this->funcstate = 0;
            this->speed = 2;
        }
        else if (this->ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 1;
        }
        else if (this->ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
        { // pop
            this->funcstate = 3;
            window.clear();
            window.draw(DefaultBackground);
            this->drawNodes(window);
            this->display(window);
            window.display();
            DeleteNodeFront(window);
        }
        else if (this->ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
        { // peek
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
            this->CreateRandomFixedSize_Textbox.isSelected = false;
            this->CreateUserDefinedList_Textbox.isSelected = false;
            this->InsertHead_Textbox.isSelected = false;
        }
        //-----------
        if (this->ControlMenu_btn2.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 2;
            this->InsertHead_Textbox.isSelected = !this->InsertHead_Textbox.isSelected;
        } else {
            this->InsertHead_Textbox.isSelected = false;
        }
        //-----------
        switch (this->funcstate)
        {
        case 1:
            if (this->CreateEmpty.rect.getGlobalBounds().contains(mousePos))
            {
                this->NodeArray->DeleteQueue(this->NodeArray);
                this->NodeArray = nullptr;
                this->size = 0;
            }
            if (this->CreateRadom.rect.getGlobalBounds().contains(mousePos))
            {
                this->NodeArray->CreateRandomNodes(this->NodeArray, this->size, this->font);
            }
            if (this->ImportFromFileButton.rect.getGlobalBounds().contains(mousePos))
            {
                ImportFromFile(window);
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
        case 4:
            if (this->PeekFront.rect.getGlobalBounds().contains(mousePos))
            {
                this->PeekFrontQueue(window);
            }
            else if (this->PeekBack.rect.getGlobalBounds().contains(mousePos))
            {
                this->PeekBackQueue(window);
            }
            break;
        default:
            break;
        }
    }
    else if (ev.type == sf::Event::TextEntered)
    {
        CreateRandomFixedSizeQueue(window, ev); 
        CreateUserDefinedListQueue(window, ev);
        InsertNodeBackQueue(window, ev);
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
    // free
}

void DataVisualization_7::ImportFromFile(sf::RenderWindow &window)
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
            this->NodeArray->DeleteQueue(this->NodeArray);
            int num;
            int i = 0;
            while (inputFile >> num)
            {
                Queue_Node* temp = this->NodeArray->createNode(600 + i * 150, 450, 30, this->font, num);
                this->NodeArray->addBack(this->NodeArray, temp);
                i++;
                if (i > 5)
                {
                    break;
                }
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

void DataVisualization_7::CreateRandomFixedSizeQueue(sf::RenderWindow &window, sf::Event &event)
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
            if (size <= 6)
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

void DataVisualization_7::CreateUserDefinedListQueue(sf::RenderWindow &window, sf::Event &event)
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

void DataVisualization_7::CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values)
{
    this->NodeArray->DeleteQueue(this->NodeArray);
    int n = values.size();
    if (n < 0 || n > 6)
    {
        this->printMessage(window, "Size be must from 1 to 6");
        return;
    }
    for (int i = 0; i < n; i++)
    { //250 + i * 150, 250, 30
        Queue_Node* temp = this->NodeArray->createNode(600 + i * 150, 450, 30, this->font, values[i]);
        this->NodeArray->addBack(this->NodeArray, temp);
    }
    this->size = n;
}

void DataVisualization_7::InsertNodeBackQueue(sf::RenderWindow &window, sf::Event &event)
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
            this->InsertNodeBack(window, value);
        }
        this->InsertHead_Textbox.pressEnter = false;
    }
}

void DataVisualization_7::InsertNodeBack(sf::RenderWindow &window, int data)
{
    std::chrono::milliseconds delayTime(1000 / speed); 
    std::chrono::milliseconds delayTime1(25);

    CodeScript.setImage(WorkingPath + "media/DataVisualization7/push.png");
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();

    // std::this_thread::sleep_for(delayTime); 
    if (this->NodeArray == nullptr)
    {
        this->NodeArray = this->NodeArray->createNode(600, 450, 30, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return;
    Queue_Node* LastNode = this->NodeArray;
    while (LastNode->next != nullptr) LastNode = LastNode->next;
    Queue_Node* newNode = this->NodeArray->createNode(window.getSize().x / 2.f, 300, 30, this->font, data);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();
    std::this_thread::sleep_for(delayTime);

// getting the lastNode;
    Queue_Node* temp = this->NodeArray;
    while (temp != nullptr)
    {
        window.clear();
        window.draw(DefaultBackground);
        temp->circle.setFillColor(sf::Color(106, 231, 255));
        temp->text.setFillColor(sf::Color::Black);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
        std::this_thread::sleep_for(delayTime);
        temp = temp->next;
    }
 // moving right
    for (int i = 0; i < 50; i++)
    {
        newNode->circle.move(10, 0);
        newNode->text.move(10, 0);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
    }
//moving down
    for (int i = 0; i < 25; i++)
    {
        window.clear();
        window.draw(DefaultBackground);
        newNode->circle.move(0, 6);
        newNode->text.move(0, 6);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
    }

    LastNode->next = newNode;
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();

    float moving_distance = (newNode->circle.getPosition().x - 150 - LastNode->circle.getPosition().x) / 50.f;
    // moving
    for (int i = 0; i < 50; i++)
    {
        window.clear();
        window.draw(DefaultBackground);
        newNode->circle.move(moving_distance * -1, 0);
        newNode->text.move(moving_distance * -1, 0);
        this->drawNodes(window);
        this->display(window);
        window.display();
    }
    std::this_thread::sleep_for(delayTime);

    // Recolor the node
    Queue_Node* cur = this->NodeArray;
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
}

void DataVisualization_7::drawNodes(sf::RenderWindow &window)
{
    Queue_Node* temp = this->NodeArray;
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

DataVisualization_7::~DataVisualization_7()
{
    this->NodeArray->DeleteQueue(this->NodeArray);
}

bool DataVisualization_7::checkSize(sf::RenderWindow &window, int size)
{
    if (size < 6) return true;
    std::chrono::milliseconds delayTime(750);
    sf::Text message;
    message.setString("Size must be from 0 to 6");
    message.setCharacterSize(50);
    message.setFillColor(sf::Color::White);
    message.setOutlineColor(sf::Color::Red);
    message.setOutlineThickness(5);
    message.setFont(this->font);
    message.setOrigin(message.getLocalBounds().width/2.f, message.getLocalBounds().height/2.f);
    message.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f + 100.f);
    window.draw(message);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return false;
}

int DataVisualization_7::getQueueSize()
{
    Queue_Node* temp = this->NodeArray;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void DataVisualization_7::DeleteNodeFront(sf::RenderWindow &window)
{   
    std::chrono::milliseconds delayTime(1500 / speed); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05

    CodeScript.setImage(WorkingPath + "media/DataVisualization7/pop.png");
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();

    if (this->NodeArray == nullptr)
    {
        printMessage(window, "There is no Node to be deleted!");
        return;
    }

    if (this->NodeArray->next == nullptr)
    {
        this->NodeArray->circle.setFillColor(sf::Color(106, 231, 255));
        this->NodeArray->text.setFillColor(sf::Color::Black);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime); 
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
            window.display();
            std::this_thread::sleep_for(delayTime1); 
        }
        Queue_Node* temp = this->NodeArray;
        this->NodeArray = nullptr;
        delete temp;
        this->size = 0;
        return;
    }

    Queue_Node* cur = this->NodeArray;
    this->NodeArray = this->NodeArray->next;

    window.clear();
    window.draw(DefaultBackground);
    cur->circle.setFillColor(sf::Color(106, 231, 255));
    cur->text.setFillColor(sf::Color::Black );
    this->NodeArray->drawArrow(window, cur->circle.getPosition(), this->NodeArray->circle.getPosition());
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
        window.clear();
        window.draw(DefaultBackground);
        this->NodeArray->drawArrow(window, cur->circle.getPosition(), this->NodeArray->circle.getPosition());
        window.draw(cur->circle);
        window.draw(cur->text);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime1); 
    }
    delete cur;
    cur = nullptr;
    window.clear();
    window.draw(DefaultBackground);   
    this->drawNodes(window);
    this->display(window);
    window.display();
    // move the rest nodes after delete
    for (int i = 0; i < 25; i++)
    {
        Queue_Node* temp = this->NodeArray;
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
        window.display();
    }
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    this->size--;
}   

void DataVisualization_7::PeekFrontQueue(sf::RenderWindow &window)
{
    // coding
    std::chrono::milliseconds delayTime(1500 / speed); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05

    CodeScript.setImage(WorkingPath + "media/DataVisualization7/peekfront.png");
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();

    if (this->NodeArray == nullptr)
    {
        printMessage(window, "Queue is empty!");
        return;
    }
    this->NodeArray->circle.setFillColor(sf::Color(106, 231, 255));
    this->NodeArray->text.setFillColor(sf::Color::Black);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    std::string mess = "Queue.top() = " + std::to_string(this->NodeArray->data);
    printMessage(window, mess);
    this->NodeArray->circle.setFillColor(sf::Color(106, 231, 255, 0));
    this->NodeArray->text.setFillColor(sf::Color(106, 231, 255));
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
}

void DataVisualization_7::PeekBackQueue(sf::RenderWindow &window)
{
    std::chrono::milliseconds delayTime(1500 / speed); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05

    CodeScript.setImage(WorkingPath + "media/DataVisualization7/peekback.png");
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();

    if (this->NodeArray == nullptr)
    {
        printMessage(window, "Queue is empty!");
        return;
    }
    Queue_Node* temp = this->NodeArray;
    while (temp->next != nullptr) temp = temp->next;
    temp->circle.setFillColor(sf::Color(106, 231, 255));
    temp->text.setFillColor(sf::Color::Black);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    std::string mess = "Queue.back() = " + std::to_string(temp->data);
    printMessage(window, mess);
    // temp->circle.setFillColor(sf::Color::Yellow);
    temp->circle.setFillColor(sf::Color(106, 231, 255, 0));
    temp->text.setFillColor(sf::Color(106, 231, 255));
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
}

bool DataVisualization_7::printMessage(sf::RenderWindow &window, std::string message/*, int min_range, int max_range, int value*/)
{
    // std::chrono::milliseconds delayTime(750);
    // sf::Text WarningMessage;
    // WarningMessage.setString(message);
    // WarningMessage.setCharacterSize(50);
    // WarningMessage.setFillColor(sf::Color::White);
    // WarningMessage.setOutlineColor(sf::Color::Red);
    // WarningMessage.setOutlineThickness(5);
    // WarningMessage.setFont(this->font);
    // WarningMessage.setOrigin(WarningMessage.getLocalBounds().width/2.f, WarningMessage.getLocalBounds().height/2.f);
    // WarningMessage.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f + 100.f);
    // window.draw(WarningMessage);
    // window.display();
    // std::this_thread::sleep_for(delayTime);
    // return true;
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
    NotificationImage.drawImage(window);
    window.draw(WarningMessage);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return true;
}

void DataVisualization_7::updateChanges(sf::Font tempFont)
{
    this->font = tempFont;
    this->titlefont = tempFont;
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
    CodeHighLight.setPosition(CodeHighLightPosition); // 1170 - 697.5 ~ 35-36

    //Title
    sf::Text DV7Title("Queue", this->titlefont, 35);
    CreateTitle(DV7Title, 400, 60.f);
    this->Title = DV7Title;
    this->Title.setOutlineThickness(0.f);
    this->Title.setFillColor(sf::Color(106, 231, 255));

    // Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);

    // building the Queue
    this->Queue1.setSize(sf::Vector2f(850, 10));
    this->Queue1.setOrigin(sf::Vector2f(0, 5));
    this->Queue1.setPosition(sf::Vector2f(550, 400));
    this->Queue1.setFillColor(sf::Color::White);
    this->Queue2.setSize(sf::Vector2f(850, 10));
    this->Queue2.setOrigin(sf::Vector2f(0, 5));
    this->Queue2.setPosition(sf::Vector2f(550, 500));
    this->Queue2.setFillColor(sf::Color::White);

// Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 200.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 200.f);

// Function key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Create", this->font, sf::Color(106, 231, 255));
    this->CreateEmpty.CreateButton(130.f, 50.f, this->ControlMenu_btn1.rect.getPosition().x + this->ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Empty", this->font, sf::Color(106, 231, 255));
    this->CreateEmpty.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateEmpty.rect.setOutlineThickness(2.f);

    this->CreateRadom.CreateButton(130.f, 50.f, this->CreateEmpty.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random", this->font, sf::Color(106, 231, 255));
    this->CreateRadom.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateRadom.rect.setOutlineThickness(2.f);
    
    this->ImportFromFileButton.CreateButton(130.f, 50.f, this->CreateRadom.rect.getPosition().x + this->CreateRadom.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Import", this->font, sf::Color(106, 231, 255));
    this->ImportFromFileButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->ImportFromFileButton.rect.setOutlineThickness(2.f);

    this->CreateRandomFixedSize.CreateButton(180.f, 50.f, this->ImportFromFileButton.rect.getPosition().x + this->ImportFromFileButton.rect.getSize().x / 2.f + 160.f / 2.f + 20.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Random Fixed Size", this->font, sf::Color(106, 231, 255));
    this->CreateRandomFixedSize.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateRandomFixedSize.rect.setOutlineThickness(2.f);
    InitTextbox(this->CreateRandomFixedSize_Textbox, 20, sf::Color::White, true, this->CreateRandomFixedSize.rect.getPosition().x , this->CreateRandomFixedSize.rect.getPosition().y + 50, font, true, 3);
    this->CreateRandomFixedSize_Textbox.EnterMessage.setString("Size: ");
    
    this->CreateUserDefinedListButton.CreateButton(130.f, 50.f, this->CreateRandomFixedSize.rect.getPosition().x + this->CreateRandomFixedSize.rect.getSize().x / 2.f + 130.f/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(106, 231, 255, 0), "User Defined", this->font, sf::Color(106, 231, 255));
    this->CreateUserDefinedListButton.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->CreateUserDefinedListButton.rect.setOutlineThickness(2.f);
    InitTextbox(this->CreateUserDefinedList_Textbox, 20, sf::Color::White, true, this->CreateUserDefinedListButton.rect.getPosition().x, this->CreateUserDefinedListButton.rect.getPosition().y + 50, font, true, 3);
    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size: ");

    //Function Key #2: Pushing
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(106, 231, 255, 0), "Push", this->font, sf::Color(106, 231, 255));
    InitTextbox(this->InsertHead_Textbox, 20, sf::Color::White, true, this->CreateEmpty.rect.getPosition().x, this->CreateEmpty.rect.getPosition().y + 50, font, true, 3);
    this->InsertHead_Textbox.EnterMessage.setString("Value: ");
    
    //Function Key #3: Pop
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(106, 231, 255, 0), "Pop", this->font, sf::Color(106, 231, 255));
    this->DeleteHead.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(106, 231, 255, 0), "Head", this->font, sf::Color(106, 231, 255));

    //Function Key #4: Peek
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 375.f, sf::Color(106, 231, 255, 0), "Peek", this->font, sf::Color(106, 231, 255));
    this->PeekFront.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn4.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Front", this->font, sf::Color(106, 231, 255));
    this->PeekFront.rect.setOutlineThickness(2.f);
    this->PeekFront.rect.setOutlineColor(sf::Color(106, 231, 255));
    this->PeekBack.CreateButton(130.f, 50.f, this->PeekFront.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn4.rect.getPosition().y, sf::Color(106, 231, 255, 0), "Back", this->font, sf::Color(106, 231, 255));
    this->PeekBack.rect.setOutlineThickness(2.f);
    this->PeekBack.rect.setOutlineColor(sf::Color(106, 231, 255));

    this->size = 0;
    this->NodeArray = nullptr;

    funcstate = 0;
}
