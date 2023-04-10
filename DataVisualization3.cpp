#include "DataVisualization3.hpp"

void CreateTitle3(sf::Text &Title, float PosX, float PosY)
{
    Title.setOutlineColor(sf::Color::Red);
    Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color::White);
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

DataVisualization_3::DataVisualization_3()
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

    if (!page2texture.loadFromFile("media/img/menubackground.jpg")) // Replace "background.jpg" with the path to your image file
    {
        std::cerr << "Failed to load BackGround" << "\n";
        return;
    }

    if (!InsertHeadImg.loadFromFile("media/DataVisualization3/InsertHead.png"))
    {
        std::cerr << "Failed to load InsertHeadImg" << "\n";
        return;
    }

    //Title
    sf::Text DV3Title("Singly Linked List", this->titlefont, 40);
    CreateTitle(DV3Title, 350, 60.f);
    this->Title = DV3Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    // Menu table
    this->menuTable.setSize(sf::Vector2f(200.f, 250.f));
    this->menuTable.setFillColor(sf::Color(106, 231, 255, 0));
    this->menuTable.setOutlineColor(sf::Color(106, 231, 255));
    this->menuTable.setOutlineThickness(5.f);
    this->menuTable.setPosition(150.f, 1080 / 2.f + 100.f);

    //Function Key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 125.f, sf::Color(106, 231, 255, 0), "Create", this->font, sf::Color(106, 231, 255));
    // this->ControlMenu_btn1.rect.setOutlineThickness(0);

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
    // int desiredHeight = static_cast<int>(450 * static_cast<float>(InsertHeadImg.getSize().y) / InsertHeadImg.getSize().x);
    InsertHeadSprite.setScale(static_cast<float>(static_cast<int>(450 * static_cast<float>(InsertHeadImg.getSize().y) / InsertHeadImg.getSize().x)) / InsertHeadImg.getSize().x, static_cast<float>(450) / InsertHeadImg.getSize().y);
    InsertHeadSprite.setPosition(sf::Vector2f(1000, 665));
    
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

    this->size = 0;
    this->NodeArray = nullptr;
    funcstate = 0;
}

void DataVisualization_3::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
    window.draw(this->menuTable);
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
            DefaultBackground.setTexture(this->page2texture);
            this->NodeArray->DeleteSLL(this->NodeArray);
            this->NodeArray = nullptr;
            this->size = 0;
            this->funcstate = 0;
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
        // if (str != "" && (std::stoi(str) < 0 || std::stoi(str) > 10))
        // {
        //     this->printMessage(window, "Size must be from 1 to 10");
        //     str = "";
        //     this->CreateUserDefinedList_Textbox.isSelected = false;
        //     values.clear(); // clear Vector
        //     return;
        // }
        if (str != "" && this->CreateUserDefinedList_Textbox.pressEnter == true)
        {
            if (num_values == 0) 
            {
                num_values = std::stoi(str);
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
        this->NodeArray = this->NodeArray->createNode(250, 250, 30, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return;
    SLL_Node* newNode = this->NodeArray->createNode(this->NodeArray->circle.getPosition().x, this->NodeArray->circle.getPosition().y + 150, 30, this->font, data);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();
    sleep(1.25);
    for (int i = 0; i < 25; i++)
    {
        SLL_Node* temp = this->NodeArray;
        while (temp != nullptr)
        {
            temp->circle.move(6, 0);
            temp->text.move(6, 0);
            temp = temp->next;
        }
        window.clear();
        window.draw(DefaultBackground);
        newNode->circle.move(0, -6);
        newNode->text.move(0, -6);
        this->NodeArray->drawArrow(window, newNode->circle.getPosition(), this->NodeArray->circle.getPosition());
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
        this->NodeArray = this->NodeArray->createNode(250, 250, 30, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return;
    SLL_Node* LastNode = this->NodeArray;
    while (LastNode->next != nullptr) LastNode = LastNode->next;
    SLL_Node* newNode = this->NodeArray->createNode(LastNode->circle.getPosition().x + 150, LastNode->circle.getPosition().y + 150, 30, this->font, data);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();
    std::this_thread::sleep_for(delayTime);

    SLL_Node* temp = this->NodeArray;
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
    LastNode->next = newNode;
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();

    // moving
    for (int i = 0; i < 25; i++)
    {
        window.clear();
        window.draw(DefaultBackground);
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

void DataVisualization_3::InsertNodeMid(sf::RenderWindow &window, int data, int index)
{
    std::chrono::milliseconds delayTime(500); // 0.5 seconds
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
    SLL_Node* newNode = this->NodeArray->createNode(pre->circle.getPosition().x + 150, pre->circle.getPosition().y + 150, 30, this->font, data);
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();
    std::this_thread::sleep_for(delayTime); 

    SLL_Node* temp = this->NodeArray;
    do {
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
    while (temp != iteratorNode);

    pre->next = newNode;
    newNode->next = iteratorNode;
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();

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
        this->drawNodes(window);
        this->display(window);
        window.display();
    }
    std::this_thread::sleep_for(delayTime); 

    // Recolor the node
    SLL_Node* cur = this->NodeArray;
    while (cur != newNode)
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

    if (this->NodeArray->next == nullptr)
    {
        this->NodeArray->circle.setFillColor(sf::Color::Red);
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
        SLL_Node* temp = this->NodeArray;
        this->NodeArray = nullptr;
        delete temp;
        this->size = 0;
        return;
    }

    SLL_Node* cur = this->NodeArray;
    this->NodeArray = this->NodeArray->next;

    window.clear();
        window.draw(DefaultBackground);
    cur->circle.setFillColor(sf::Color::Red);
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
        window.display();
    }
    window.clear();
        window.draw(DefaultBackground);
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
        window.clear();
        window.draw(DefaultBackground);
        cur->circle.setFillColor(sf::Color(106, 231, 255));
        cur->text.setFillColor(sf::Color::Black);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime2); 
        pre = cur;
        cur = cur->next;
    }
    cur->circle.setFillColor(sf::Color::Black);
    cur->text.setFillColor(sf::Color(106, 231, 255));
    window.clear();
    window.draw(DefaultBackground);
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
        window.clear();
        window.draw(DefaultBackground);
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
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2); 
    cur = this->NodeArray;
    while (cur != nullptr)
    {
        cur->circle.setFillColor(sf::Color(106, 231, 255, 0));
        cur->text.setFillColor(sf::Color(106, 231, 255));
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
        cur->circle.setFillColor(sf::Color(106, 231, 255));
        cur->text.setFillColor(sf::Color::Black);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.display();
        pre = cur;
        cur = cur->next;
        std::this_thread::sleep_for(delayTime2); 
    }
    // color Red
    cur->circle.setFillColor(sf::Color::Red);
    window.clear();
        window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2); 
    // delete it 
    for (int i = 0; i < 25; i++)
    {
        cur->circle.move(0, 6);
        cur->text.move(0, 6);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.display();
    }

    std::this_thread::sleep_for(delayTime2); 
    pre->next = cur->next;
    window.clear();
    window.draw(DefaultBackground);
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
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.draw(cur->circle);
        window.draw(cur->text);
        window.display();
    }
    std::this_thread::sleep_for(delayTime2); 
    
    delete cur;
    cur = nullptr;
    window.clear();
    window.draw(DefaultBackground);
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime2); 

    // recolor yellow
    cur = this->NodeArray;
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
        window.clear();
        temp->circle.setFillColor(sf::Color(106, 231, 255));
        temp->text.setFillColor(sf::Color::Black);
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime2); 
        temp = temp->next;
    }

    temp->circle.setFillColor(sf::Color::Red);
    window.clear();
    window.draw(DefaultBackground);
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
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
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
        this->drawNodes(window);
        this->display(window);
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
        temp->circle.setFillColor(sf::Color(106, 231, 255));
        temp->text.setFillColor(sf::Color::Black);
        window.clear();
        window.draw(DefaultBackground);
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime2);

        if (temp->data == value) {
            std::string mess = "Founded at index " + std::to_string(index);
            temp->circle.setFillColor(sf::Color::Red);
            window.clear();
        window.draw(DefaultBackground);
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
        temp->circle.setFillColor(sf::Color(106, 231, 255, 0));
        temp->text.setFillColor(sf::Color(106, 231, 255));
        temp = temp->next;
    }
    window.clear();
    window.draw(DefaultBackground);
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
