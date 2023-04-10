#include "DataVisualization6.hpp"
//Stack
void CreateTitle6(sf::Text &Title, float PosX, float PosY)
{
    Title.setOutlineColor(sf::Color::Red);
    Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color::White);
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

DataVisualization_6::DataVisualization_6()
{
    //Fonts
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV6Title("Stack", this->font, 90);
    CreateTitle6(DV6Title, 1920 / 2.f, 50.f);
    this->Title = DV6Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
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
    // this->Stackbody2.setPosition(sf::Vector2f(960, 660));
    this->Stackbody2.setPosition(sf::Vector2f(960, 675));

    this->Stackbody3.setSize(sf::Vector2f(470.f, 20.f));
    this->Stackbody3.setFillColor(sf::Color::White);
    this->Stackbody3.setRotation(270);
    this->Stackbody3.setOrigin(sf::Vector2f(0, 10));
    this->Stackbody3.setPosition(sf::Vector2f(1122, 675));


    //Function Key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(255, 138, 39), "Create", this->font, sf::Color::White);
    this->CreateEmpty.CreateButton(130.f, 50.f, this->ControlMenu_btn1.rect.getPosition().x + this->ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Empty", this->font, sf::Color::White);
    this->CreateRadom.CreateButton(130.f, 50.f, this->CreateEmpty.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Random", this->font, sf::Color::White);
    this->CreateRandomSort.CreateButton(130.f, 50.f, this->CreateRadom.rect.getPosition().x + this->CreateRadom.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Random Sort", this->font, sf::Color::White);
    this->CreateRandomFixedSize.CreateButton(180.f, 50.f, this->CreateRandomSort.rect.getPosition().x + this->CreateRandomSort.rect.getSize().x / 2.f + 160.f / 2.f + 20.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "Random Fixed Size", this->font, sf::Color::White);
    InitTextbox(this->CreateRandomFixedSize_Textbox, 20, sf::Color::White, true, this->CreateRandomFixedSize.rect.getPosition().x , this->CreateRandomFixedSize.rect.getPosition().y + 50, font, true, 3);
    this->CreateRandomFixedSize_Textbox.EnterMessage.setString("Size: ");
    this->CreateUserDefinedListButton.CreateButton(130.f, 50.f, this->CreateRandomFixedSize.rect.getPosition().x + this->CreateRandomFixedSize.rect.getSize().x / 2.f + 130.f/2.f + 10.f, this->ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), "User Defined", this->font, sf::Color::White);
    InitTextbox(this->CreateUserDefinedList_Textbox, 20, sf::Color::White, true, this->CreateUserDefinedListButton.rect.getPosition().x, this->CreateUserDefinedListButton.rect.getPosition().y + 50, font, true, 3);
    this->CreateUserDefinedList_Textbox.EnterMessage.setString("Size: ");

    //Function Key #2: Pushing
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(255, 138, 39), "Add", this->font, sf::Color::White);
    InitTextbox(this->InsertHead_Textbox, 20, sf::Color::White, true, this->CreateEmpty.rect.getPosition().x, this->CreateEmpty.rect.getPosition().y + 50, font, true, 3);
    this->InsertHead_Textbox.EnterMessage.setString("Value: ");
    
    //Function Key #3: Pop
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(255, 138, 39), "Delete", this->font, sf::Color::White);
    this->DeleteHead.CreateButton(130.f, 50.f, this->ControlMenu_btn3.rect.getPosition().x + this->ControlMenu_btn3.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, 1080 / 2.f + 225.f, sf::Color(255, 138, 39), "Head", this->font, sf::Color::White);

    //Function Key #4: Peek
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 375.f, sf::Color(255, 138, 39), "Peek", this->font, sf::Color::White);

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

    switch (this->funcstate)
    {
    case 1:
        this->CreateEmpty.displayButton(window);
        this->CreateRadom.displayButton(window);;
        this->CreateRandomSort.displayButton(window);
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
            this->NodeArray->DeleteStack(this->NodeArray);
            this->NodeArray = nullptr;
            this->size = 0;
            this->funcstate = 0;
        }
        else if (this->ControlMenu_btn1.rect.getGlobalBounds().contains(mousePos))
        {
            this->funcstate = 1;
        }
        else if (this->ControlMenu_btn3.rect.getGlobalBounds().contains(mousePos))
        { // pop
            this->funcstate = 3;
            window.clear(sf::Color(22, 73, 154));
            this->drawNodes(window);
            this->display(window);
            window.display();
            DeleteNodeFront(window);
        }
        else if (this->ControlMenu_btn4.rect.getGlobalBounds().contains(mousePos))
        { // peek
            this->funcstate = 4;
            window.clear(sf::Color(22, 73, 154));
            this->drawNodes(window);
            this->display(window);
            window.display();
            PeekNode(window);
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
            if (this->CreateRandomSort.rect.getGlobalBounds().contains(mousePos))
            {
                this->NodeArray->CreateRandomSortStack(this->NodeArray, this->size, this->font);
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
    }
    // free
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
    std::chrono::milliseconds delayTime(750);
    if (this->NodeArray == nullptr)
    {
        this->NodeArray = this->NodeArray->createNode(960, 627.5, 75, 300, font, data);
        this->size = 1;
        return;
    }
    if (checkSize(window, this->size) == false) return; // 960 200
    Stack_Node* newNode = this->NodeArray->createNode(480, 172.5, 75, 300, this->font, data);
    window.draw(newNode->rec);
    window.draw(newNode->text);
    window.display();
    // sleep(1);
    std::this_thread::sleep_for(delayTime);
    for (int i = 0; i < 25; i++)
    {
        newNode->rec.move(19.2, 0);
        newNode->text.move(19.2, 0);
        window.clear(sf::Color(22, 73, 154));
        // this->NodeArray->drawArrow(window, newNode->rec.getPosition(), this->NodeArray->rec.getPosition());
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->rec);
        window.draw(newNode->text);
        window.display();
    }
    // first node is currently at the bottom so it cause the fking bug!!!
    float distance = (this->NodeArray->rec.getPosition().y - 75 - newNode->rec.getPosition().y) / 25.0;
    for (int i = 0; i < 25; i++)
    {
        newNode->rec.move(0, distance);
        newNode->text.move(0, distance);
        window.clear(sf::Color(22, 73, 154));
        // this->NodeArray->drawArrow(window, newNode->rec.getPosition(), this->NodeArray->rec.getPosition());
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->rec);
        window.draw(newNode->text);
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
    if (this->NodeArray == nullptr)
    {
        printMessage(window, "There is no Node to be deleted!");
        return;
    }
    std::chrono::milliseconds delayTime(1000); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05

    // if (this->NodeArray->next == nullptr) // one element case
    // {
        this->NodeArray->rec.setFillColor(sf::Color::Red);
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
        std::this_thread::sleep_for(delayTime); 
        
        float movePerFrame = (this->NodeArray->rec.getPosition().y - 172.5) / 25.f;
        for (int i = 0; i < 25; i++)
        {
            this->NodeArray->rec.move(0, -1 * movePerFrame);
            this->NodeArray->text.move(0, -1 * movePerFrame);
            window.clear(sf::Color(22, 73, 154));
            this->drawNodes(window);
            this->display(window);
            window.display();
            // std::this_thread::sleep_for(delayTime); 
        }
        for (int i = 0; i < 25; i++)
        {
            this->NodeArray->rec.move(19.2f, 0);
            this->NodeArray->text.move(19.2f, 0);
            window.clear(sf::Color(22, 73, 154));
            this->drawNodes(window);
            this->display(window);
            window.display();
            // std::this_thread::sleep_for(delayTime); 
        }
        Stack_Node* temp = this->NodeArray;
        this->NodeArray = this->NodeArray->next;
        delete temp;
        window.clear(sf::Color(22, 73, 154));
        this->drawNodes(window);
        this->display(window);
        window.display();
        this->size--;
        return;
    // }

    // Stack_Node* cur = this->NodeArray;
    // this->NodeArray = this->NodeArray->next;

    // window.clear(sf::Color(22, 73, 154));
    // cur->rec.setFillColor(sf::Color::Red);
    // // this->NodeArray->drawArrow(window, cur->rec.getPosition(), this->NodeArray->rec.getPosition());
    // window.draw(cur->rec);
    // window.draw(cur->text);
    // this->drawNodes(window);
    // this->display(window);
    // window.display();

    // std::this_thread::sleep_for(delayTime); 
    // while (cur->rec.getRadius() > 16)
    // {
    //     float radius = cur->rec.getRadius();
    //     radius = radius * 0.75;
    //     cur->rec.setRadius(radius);
    //     cur->rec.setOrigin(radius, radius);
    //     cur->text.setCharacterSize(radius / 3.f * 2.f);
    //     cur->text.setOrigin(cur->text.getLocalBounds().width / 2.f, cur->text.getLocalBounds().height / 2.f);
    //     window.clear(sf::Color(22, 73, 154));
    //     // this->NodeArray->drawArrow(window, cur->rec.getPosition(), this->NodeArray->rec.getPosition());
    //     window.draw(cur->rec);
    //     window.draw(cur->text);
    //     this->drawNodes(window);
    //     this->display(window);
    //     window.display();
    //     std::this_thread::sleep_for(delayTime1); 
    // }
    // delete cur;
    // cur = nullptr;
    // window.clear(sf::Color(22, 73, 154));   
    // this->drawNodes(window);
    // this->display(window);
    // window.display();
    // // move up after delete
    // for (int i = 0; i < 25; i++)
    // {
    //     Stack_Node* temp = this->NodeArray;
    //     while (temp != nullptr)
    //     {
    //         window.clear(sf::Color(22, 73, 154));
    //         temp->rec.move(0, -3);
    //         temp->text.move(0, -3);
    //         temp = temp->next;
    //     }
    //     this->drawNodes(window);
    //     this->display(window);
    //     window.display();
    // }
    // window.clear(sf::Color(22, 73, 154));
    // this->drawNodes(window);
    // this->display(window);
    // window.display();
    // this->size--;
}   

void DataVisualization_6::PeekNode(sf::RenderWindow &window)
{
    // coding
    if (this->NodeArray == nullptr)
    {
        printMessage(window, "Stack is empty!");
        return;
    }
    std::chrono::milliseconds delayTime(1000); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05
    this->NodeArray->rec.setFillColor(sf::Color::Red);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    std::string mess = "stack.top() = " + std::to_string(this->NodeArray->data);
    printMessage(window, mess);
    this->NodeArray->rec.setFillColor(sf::Color::Yellow);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
}

bool DataVisualization_6::printMessage(sf::RenderWindow &window, std::string message/*, int min_range, int max_range, int value*/)
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
    WarningMessage.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f + 100.f);
    window.draw(WarningMessage);
    window.display();
    std::this_thread::sleep_for(delayTime);
    return true;
}
