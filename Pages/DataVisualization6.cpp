#include "DataVisualization6.hpp"

DataVisualization_6::DataVisualization_6()
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
    DeleteCodeScriptButton.setImage(WorkingPath + "media/img/deleteCodeHightLight.png");
    DeleteCodeScriptButton.setPosition(sf::Vector2f(1870, 725));
    isPause = true;

    // Code Script
    CodeScriptPosition = sf::Vector2f(1520,740);
    CodeHighLightPosition = sf::Vector2f(1170, 795);
    CodeScript.setPosition(CodeScriptPosition);
    CodeHighLight.setSize(sf::Vector2f(700, 30));
    CodeHighLight.setFillColor(sf::Color(106, 231, 255, 100));
    CodeHighLight.setOutlineColor(sf::Color(106, 231, 255));
    CodeHighLight.setPosition(CodeHighLightPosition); // 1170 - 697.5 ~ 35

    //Title
    sf::Text DV6Title("Stack", this->titlefont, 35);
    CreateTitle(DV6Title, 400, 60.f);
    this->Title = DV6Title;
    this->Title.setOutlineThickness(0.f);
    this->Title.setFillColor(sf::Color(106, 231, 255));
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 200.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 200.f);

    //build the stack image
    this->Stackbody1.setSize(sf::Vector2f(470.f, 20.f));
    this->Stackbody1.setFillColor(sf::Color::White);
    this->Stackbody1.setRotation(270);
    this->Stackbody1.setOrigin(sf::Vector2f(0, 10));
    this->Stackbody1.setPosition(sf::Vector2f(798, 675));

    this->Stackbody2.setSize(sf::Vector2f(344.f, 20.f));
    this->Stackbody2.setFillColor(sf::Color::White);
    this->Stackbody2.setRotation(0);
    this->Stackbody2.setOrigin(sf::Vector2f(172.f, 10));
    this->Stackbody2.setPosition(sf::Vector2f(960, 675));

    this->Stackbody3.setSize(sf::Vector2f(470.f, 20.f));
    this->Stackbody3.setFillColor(sf::Color::White);
    this->Stackbody3.setRotation(270);
    this->Stackbody3.setOrigin(sf::Vector2f(0, 10));
    this->Stackbody3.setPosition(sf::Vector2f(1122, 675));

    //Function Key #1
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

    this->size = 0;
    this->NodeArray = nullptr;

    funcstate = 0;
}

void DataVisualization_6::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
    this->ControlMenu_btn1.displayButton(window);
    this->ControlMenu_btn2.displayButton(window);
    this->ControlMenu_btn3.displayButton(window);
    this->ControlMenu_btn4.displayButton(window);
    window.draw(Stackbody1);
    window.draw(Stackbody3);
    window.draw(Stackbody2);

    window.draw(this->menuTable);
    speedText.setString("Speed: x" + std::to_string(speed));
    window.draw(speedText);
    
    if (CodeScriptVisible)
    {
        CodeScript.drawImage(window);
        DeleteCodeScriptButton.drawImage(window);
    }
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
    default: // NONE - 0
        break;
    }
}

void DataVisualization_6::handleEvent(sf::RenderWindow &window, sf::Vector2f &mousePos, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed)
    {
        if (this->backButton.rect.getGlobalBounds().contains(mousePos))
        {
            currentState = Start;
            DefaultBackground.setTexture(BackGround1);
            this->NodeArray->DeleteStack(this->NodeArray);
            this->NodeArray = nullptr;
            this->size = 0;
            this->funcstate = 0;
            this->speed = 2;
            this->CodeScriptVisible = false;
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
            window.clear();
            window.draw(DefaultBackground);
            this->drawNodes(window);
            this->display(window);
            window.display();
            PeekNode(window);
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
                this->NodeArray->DeleteStack(this->NodeArray);
                this->NodeArray = nullptr;
                this->size = 0;
            }
            if (this->CreateRadom.rect.getGlobalBounds().contains(mousePos))
            {
                this->NodeArray->CreateRandomNodes(this->NodeArray, this->size, this->font);
            }
            if (this->ImportFromFileButton.rect.getGlobalBounds().contains(mousePos))
            {
                // this->NodeArray->ImportFromFileButtonStack(this->NodeArray, this->size, this->font);
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
        default:
            break;
        }
    }
    else if (ev.type == sf::Event::TextEntered)
    {
        CreateRandomFixedSizeStack(window, ev); 
        CreateUserDefinedListStack(window, ev);
        InsertNodeFrontStack(window, ev);
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

void DataVisualization_6::ImportFromFile(sf::RenderWindow &window)
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
            // delete the Node
            this->NodeArray->DeleteStack(this->NodeArray);
            int num;
            int i = 0;
            while (inputFile >> num)
            {
                Stack_Node* temp = this->NodeArray->createNode(960, 627.5 - 75 * i, 75, 300, this->font, num);
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

void DataVisualization_6::CreateRandomFixedSizeStack(sf::RenderWindow &window, sf::Event &event)
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

void DataVisualization_6::CreateUserDefinedListStack(sf::RenderWindow &window, sf::Event &event)
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
                if (num_values > 6)
                {
                    this->printMessage(window, "Size must be from 1 to 6");
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

void DataVisualization_6::CreateUserDefinedList(sf::RenderWindow &window, std::vector<int> &values)
{
    this->NodeArray->DeleteStack(this->NodeArray);
    int n = values.size();
    if (n < 0 || n > 6)
    {
        this->printMessage(window, "Size be must from 1 to 6");
        return;
    }
    for (int i = 0; i < n; i++)
    { //createNode(960, 200 + 75 * i, 20, font, value);
        Stack_Node* temp = this->NodeArray->createNode(960, 627.5 - 75 * i, 75, 300, this->font, values[i]);
        this->NodeArray->addBack(this->NodeArray, temp);
    }
    this->size = n;
}

void DataVisualization_6::InsertNodeFrontStack(sf::RenderWindow &window, sf::Event &event)
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

void DataVisualization_6::InsertNodeFront(sf::RenderWindow &window, int data)
{
    std::chrono::milliseconds delayTime(1500 / speed);
    CodeScript.setImage(WorkingPath + "media/DataVisualization6/push.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();

    if (this->NodeArray == nullptr)
    {
        this->NodeArray = this->NodeArray->createNode(960, 627.5, 75, 300, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return; // 960 200
    Stack_Node* newNode = this->NodeArray->createNode(480, 172.5, 75, 300, this->font, data);
    window.clear();
    window.draw(DefaultBackground);
    this->display(window);
    this->drawNodes(window);
    window.draw(newNode->rec);
    window.draw(newNode->text);
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y));
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime);
    for (int i = 0; i < 25; i++)
    {
        newNode->rec.move(19.2, 0);
        newNode->text.move(19.2, 0);
        window.clear();
        window.draw(DefaultBackground);
        // this->NodeArray->drawArrow(window, newNode->rec.getPosition(), this->NodeArray->rec.getPosition());
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->rec);
        window.draw(newNode->text);
        CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 35));
        window.draw(CodeHighLight);
        window.display();
    }
    float distance = (this->NodeArray->rec.getPosition().y - 75 - newNode->rec.getPosition().y) / 25.0;
    for (int i = 0; i < 25; i++)
    {
        newNode->rec.move(0, distance);
        newNode->text.move(0, distance);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->rec);
        window.draw(newNode->text);
        window.draw(CodeHighLight);
        window.display();
    }
    newNode->next = this->NodeArray;
    this->NodeArray = newNode;
    this->size++;
}

void DataVisualization_6::drawNodes(sf::RenderWindow &window)
{
    Stack_Node* temp = this->NodeArray;
    while (temp != nullptr)
    {
        if (temp->next != nullptr)
        {
            sf::Vector2f first(temp->rec.getPosition());
            sf::Vector2f second(temp->next->rec.getPosition());
            // this->NodeArray->drawArrow(window, first, second);
        }
        window.draw(temp->rec);
        window.draw(temp->text);
        temp = temp->next;
    }
}

DataVisualization_6::~DataVisualization_6()
{
    this->NodeArray->DeleteStack(this->NodeArray);
}

bool DataVisualization_6::checkSize(sf::RenderWindow &window, int size)
{
    if (size < 6) return true;
    std::chrono::milliseconds delayTime(1500 / speed);
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

int DataVisualization_6::getStackSize()
{
    Stack_Node* temp = this->NodeArray;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void DataVisualization_6::DeleteNodeFront(sf::RenderWindow &window)
{   
    
    std::chrono::milliseconds delayTime(1500 / speed); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05
    CodeScript.setImage(WorkingPath + "media/DataVisualization6/pop.png");
    CodeScriptVisible = true;
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

    this->NodeArray->rec.setFillColor(sf::Color::Red);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 36));
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    
    float movePerFrame = (this->NodeArray->rec.getPosition().y - 172.5) / 25.f;
    for (int i = 0; i < 25; i++)
    {
        this->NodeArray->rec.move(0, -1 * movePerFrame);
        this->NodeArray->text.move(0, -1 * movePerFrame);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 72));
        window.draw(CodeHighLight);
        window.display();
    }
    for (int i = 0; i < 25; i++)
    {
        this->NodeArray->rec.move(19.2f, 0);
        this->NodeArray->text.move(19.2f, 0);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 72));
        window.draw(CodeHighLight);
        window.display();
    }
    Stack_Node* temp = this->NodeArray;
    this->NodeArray = this->NodeArray->next;
    delete temp;
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 107));
    window.draw(CodeHighLight);
    window.display();
    this->size--;
    std::this_thread::sleep_for(delayTime); 
    return;
}   

void DataVisualization_6::PeekNode(sf::RenderWindow &window)
{
    std::chrono::milliseconds delayTime(1500 / speed); 
    std::chrono::milliseconds delayTime1(50); 
    CodeScript.setImage(WorkingPath + "media/DataVisualization6/peek.png");
    CodeScriptVisible = true;
    CodeHighLight.setPosition(CodeHighLightPosition);
    CodeScript.setPosition(CodeScriptPosition);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();

    if (this->NodeArray == nullptr)
    {
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y));
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime); 
        printMessage(window, "Stack is empty!");
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y));
        window.draw(CodeHighLight);
        window.display();
        std::this_thread::sleep_for(delayTime); 
        return;
    }
    this->NodeArray->rec.setFillColor(sf::Color::Red);
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    std::string mess = "stack.top() = " + std::to_string(this->NodeArray->data);
    printMessage(window, mess);
    this->NodeArray->rec.setFillColor(sf::Color(106, 231, 255));
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    CodeHighLight.setPosition(sf::Vector2f(CodeHighLightPosition.x, CodeHighLightPosition.y + 36));
    window.draw(CodeHighLight);
    window.display();
    std::this_thread::sleep_for(delayTime); 
}

bool DataVisualization_6::printMessage(sf::RenderWindow &window, std::string message/*, int min_range, int max_range, int value*/)
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
    NotificationImage.drawImage(window);
    window.draw(WarningMessage);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return true;
}

void DataVisualization_6::updateChanges(sf::Font tempFont)
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
    CodeScriptPosition = sf::Vector2f(1520,740);
    CodeHighLightPosition = sf::Vector2f(1170, 697.5f);
    CodeScript.setPosition(CodeScriptPosition);
    CodeHighLight.setSize(sf::Vector2f(700, 30));
    CodeHighLight.setFillColor(sf::Color(106, 231, 255, 100));
    CodeHighLight.setOutlineColor(sf::Color(106, 231, 255));
    //---------------------
    CodeHighLight.setPosition(CodeHighLightPosition); // 1170 - 697.5 ~ 35
    //---------------------

    //Title
    sf::Text DV6Title("Stack", this->titlefont, 35);
    CreateTitle(DV6Title, 400, 60.f);
    this->Title = DV6Title;
    this->Title.setOutlineThickness(0.f);
    this->Title.setFillColor(sf::Color(106, 231, 255));
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 72.5f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 200.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 200.f);

    //build the stack image
    this->Stackbody1.setSize(sf::Vector2f(470.f, 20.f));
    this->Stackbody1.setFillColor(sf::Color::White);
    this->Stackbody1.setRotation(270);
    this->Stackbody1.setOrigin(sf::Vector2f(0, 10));
    this->Stackbody1.setPosition(sf::Vector2f(798, 675));

    this->Stackbody2.setSize(sf::Vector2f(344.f, 20.f));
    this->Stackbody2.setFillColor(sf::Color::White);
    this->Stackbody2.setRotation(0);
    this->Stackbody2.setOrigin(sf::Vector2f(172.f, 10));
    this->Stackbody2.setPosition(sf::Vector2f(960, 675));

    this->Stackbody3.setSize(sf::Vector2f(470.f, 20.f));
    this->Stackbody3.setFillColor(sf::Color::White);
    this->Stackbody3.setRotation(270);
    this->Stackbody3.setOrigin(sf::Vector2f(0, 10));
    this->Stackbody3.setPosition(sf::Vector2f(1122, 675));

    //Function Key #1
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

    this->size = 0;
    this->NodeArray = nullptr;

    funcstate = 0;
}
