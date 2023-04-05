#include "DataVisualization7.hpp"

void CreateTitle7(sf::Text &Title, float PosX, float PosY)
{
    Title.setOutlineColor(sf::Color::Red);
    Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color::White);
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

DataVisualization_7::DataVisualization_7()
{
    //Fonts
    if (!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load Fonts" << "\n";
        return;
    }
    //Title
    sf::Text DV7Title("Queue", this->font, 90);
    CreateTitle7(DV7Title, 1920 / 2.f, 50.f);
    this->Title = DV7Title;
    //Back button
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), "Back", this->font, sf::Color::White);
    
    this->Queue1.setSize(sf::Vector2f(850, 10));
    this->Queue1.setOrigin(sf::Vector2f(0, 5));
    this->Queue1.setPosition(sf::Vector2f(550, 400));
    this->Queue1.setFillColor(sf::Color::White);

    this->Queue2.setSize(sf::Vector2f(850, 10));
    this->Queue2.setOrigin(sf::Vector2f(0, 5));
    this->Queue2.setPosition(sf::Vector2f(550, 500));
    this->Queue2.setFillColor(sf::Color::White);

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
    this->PeekFront.CreateButton(130.f, 50.f, this->ControlMenu_btn4.rect.getPosition().x + this->ControlMenu_btn4.rect.getSize().x / 2.f + 20.f + 130/2.f + 10.f, this->ControlMenu_btn4.rect.getPosition().y, sf::Color(255, 138, 39), "Front", this->font, sf::Color::White);
    this->PeekBack.CreateButton(130.f, 50.f, this->PeekFront.rect.getPosition().x + this->CreateEmpty.rect.getSize().x / 2.f + 130/2.f + 10.f, this->ControlMenu_btn4.rect.getPosition().y, sf::Color(255, 138, 39), "Back", this->font, sf::Color::White);

    // this->PeekBack


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
            this->NodeArray->DeleteQueue(this->NodeArray);
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
            // PeekNode(window);
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
            if (this->CreateRandomSort.rect.getGlobalBounds().contains(mousePos))
            {
                this->NodeArray->CreateRandomSortQueue(this->NodeArray, this->size, this->font);
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
        InsertNodeFrontQueue(window, ev);
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

void DataVisualization_7::InsertNodeFrontQueue(sf::RenderWindow &window, sf::Event &event)
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

void DataVisualization_7::InsertNodeFront(sf::RenderWindow &window, int data)
{
    std::chrono::milliseconds delayTime(500); // 0.5 seconds
    std::chrono::milliseconds delayTime1(25); // 0.5 seconds

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
 // moving right
    for (int i = 0; i < 50; i++)
    {
        window.clear(sf::Color(22, 73, 154));
        newNode->circle.move(10, 0);
        newNode->text.move(10, 0);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
        // std::this_thread::sleep_for(delayTime1);
    }
//moving down
    for (int i = 0; i < 50; i++)
    {
        window.clear(sf::Color(22, 73, 154));
        newNode->circle.move(0, 3);
        newNode->text.move(0, 3);
        this->drawNodes(window);
        this->display(window);
        window.draw(newNode->circle);
        window.draw(newNode->text);
        window.display();
        // std::this_thread::sleep_for(delayTime1);
    }

    LastNode->next = newNode;
    window.draw(newNode->circle);
    window.draw(newNode->text);
    window.display();

    float moving_distance = (newNode->circle.getPosition().x - 150 - LastNode->circle.getPosition().x) / 50.f;
    // moving
    for (int i = 0; i < 50; i++)
    {
        window.clear(sf::Color(22, 73, 154));
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
        cur->circle.setFillColor(sf::Color::Yellow);
        cur = cur->next;
    }
    window.clear(sf::Color(22, 73, 154));
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
        window.clear(sf::Color(22, 73, 154));
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
            window.clear(sf::Color(22, 73, 154));
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

    window.clear(sf::Color(22, 73, 154));
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
        window.clear(sf::Color(22, 73, 154));
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
    window.clear(sf::Color(22, 73, 154));   
    this->drawNodes(window);
    this->display(window);
    window.display();
    // move up after delete
    for (int i = 0; i < 25; i++)
    {
        Queue_Node* temp = this->NodeArray;
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

void DataVisualization_7::PeekFrontQueue(sf::RenderWindow &window)
{
    // coding
    if (this->NodeArray == nullptr)
    {
        printMessage(window, "Queue is empty!");
        return;
    }
    std::chrono::milliseconds delayTime(1000); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05
    this->NodeArray->circle.setFillColor(sf::Color::Red);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    std::string mess = "Queue.top() = " + std::to_string(this->NodeArray->data);
    printMessage(window, mess);
    this->NodeArray->circle.setFillColor(sf::Color::Yellow);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
}

void DataVisualization_7::PeekBackQueue(sf::RenderWindow &window)
{
    if (this->NodeArray == nullptr)
    {
        printMessage(window, "Queue is empty!");
        return;
    }
    std::chrono::milliseconds delayTime(1000); // 0.5 seconds
    std::chrono::milliseconds delayTime1(50); // 0.05
    Queue_Node* temp = this->NodeArray;
    while (temp->next != nullptr) temp = temp->next;
    temp->circle.setFillColor(sf::Color::Red);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
    std::this_thread::sleep_for(delayTime); 
    std::string mess = "Queue.back() = " + std::to_string(temp->data);
    printMessage(window, mess);
    temp->circle.setFillColor(sf::Color::Yellow);
    window.clear(sf::Color(22, 73, 154));
    this->drawNodes(window);
    this->display(window);
    window.display();
}

bool DataVisualization_7::printMessage(sf::RenderWindow &window, std::string message/*, int min_range, int max_range, int value*/)
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
