#include "header.hpp"

/*
sf::Font font;
sf::Color(22, 73, 154)
sf::Color sf::Color(22, 73, 154) = sf::Color(22, 73, 154);
const sf::Color Pink1(253, 0, 112);
const sf::Color Purple1(104, 0, 120);
*/
Button::Button()
{
    this->display = true;
}
void Button::CreateButton(float recwidth, float recheight, float PosX, float PosY, sf::Color buttonbgcolor, sf::Color buttonOutlineColor, sf::String text, sf::Font &font, sf::Color text_color)
{
    // Set up the rectangle
    this->rect.setSize(sf::Vector2f(recwidth, recheight));
    this->rect.setPosition(sf::Vector2f(PosX, PosY));
    this->rect.setFillColor(buttonbgcolor);
    this->rect.setOutlineThickness(5);
    this->rect.setOutlineColor(buttonOutlineColor);
    this->rect.setOrigin(this->rect.getSize().x / 2.f, this->rect.getSize().y / 2.f);

    // Set up the text
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(this->rect.getSize().y / 3.f);
    this->text.setFillColor(text_color);

    // Center the text
    sf::FloatRect textRect = this->text.getLocalBounds();
    this->text.setOrigin(textRect.width/2.f, textRect.height/2.f);
    // this->text.setPosition(this->rect.getPosition().x + this->rect.getSize().x/ 2.f, this->rect.getPosition().y + this->rect.getSize().y/ 2.f);
    this->text.setPosition(this->rect.getPosition().x , this->rect.getPosition().y - this->text.getLocalBounds().height / 3.f);
}
void Button::displayButton(sf::RenderWindow &window)
{
    if (this->display)
    {
        window.draw(this->rect);
        window.draw(this->text);
    }
}
//---

void CreateTitle(sf::Text &Title, float PosX, float PosY)
{
    Title.setOutlineColor(sf::Color::Red);
    Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color::White);
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

int randNum() {
    return rand() % 99 + 1;
}

Node createNode(float x, float y, float radius, sf::Font &font) {
    Node nc;
    nc.circle.setRadius(radius);
    nc.circle.setPosition(x, y);
    nc.circle.setFillColor(sf::Color::Yellow);
    nc.text.setFont(font);
    nc.text.setString(std::to_string(randNum()));
    nc.text.setCharacterSize(20);
    // nc.text.setOrigin(nc.text.getLocalBounds().height / 2.f, nc.text.getLocalBounds().width / 2.f);
    nc.text.setPosition(x + radius/2, y + radius/2);
    nc.text.setFillColor(sf::Color::Black);
    return nc;
}

void CreateRandomNodes(Node v[], int &n, sf::Font &font)
{
    n = 3 + rand() % 7;
    for (int i = 0; i < n; i++)
    {
        v[i] = createNode(250 + i * 150, 250, 30, font);
    }
    // sortArray(v, n);
}

void drawArrow(sf::RenderWindow window, sf::Vector2f first, sf::Vector2f second)
{
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = first;
    line[1].position = second;
    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;
    line[0].color.a = 200;
    line[1].color.a = 200;
    line[0].texCoords = sf::Vector2f(0, 0);
    line[1].texCoords = sf::Vector2f(5.f, 5.f);
    window.draw(line);
}

void swapNode(sf::Text &a, sf::Text &b)
{
    sf::Text temp = a;
    a = b;
    b = temp;
}

void sortArray(Node v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (std::stoi(v[min].text.getString().toAnsiString()) > std::stoi(v[j].text.getString().toAnsiString()))
            {
                // std::cout << v[min].text.getString().toAnsiString() << " > " << v[j].text.getString().toAnsiString() << std::endl;
                min = j;
            }
        }
        std::string temp = v[min].text.getString().toAnsiString();
        v[min].text.setString(v[i].text.getString().toAnsiString());
        v[i].text.setString(temp);
    }
}

void CreateRandomSortNodes(Node v[], int &n, sf::Font &font)
{
    n = 3 + rand() % 7;
    for (int i = 0; i < n; i++)
    {
        v[i] = createNode(250 + i * 150, 250, 30, font);
    }
    sortArray(v, n);
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
    this->startButton.CreateButton(600, 150, 1920 / 2.f, 530, sf::Color(104, 0, 120), sf::Color(253, 0, 112), "Start", font, sf::Color(253, 0, 112));
    this->settingsButton.CreateButton(600, 150, 1920 / 2.f - settingsButton.rect.getSize().x / 2.f, startButton.rect.getPosition().y + startButton.rect.getSize().y / 2.f + 30 + 150 / 2.f, sf::Color(104, 0, 120), sf::Color(253, 0, 112), "Setting", font, sf::Color(253, 0, 112));
}
void MenuPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    // this->backButton.displayButton(window);
    this->settingsButton.displayButton(window);
    this->startButton.displayButton(window);
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);

}
void SettingPage::display(sf::RenderWindow &window)
{
    window.draw(this->Title);
    this->backButton.displayButton(window);
}

StartPage::StartPage()
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);

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
    this->rect1.CreateButton(rectWidth, rectHeight, startX1, startY1, sf::Color(0, 154, 172), sf::Color(22, 73, 154), "Static Array", font, sf::Color::White);
    // #2. Dynamic array rectangle
    rect2.CreateButton(rectWidth, rectHeight, startX1, startY1 + rectHeight + padding, sf::Color(218, 83, 44), sf::Color(22, 73, 154), "Dynamic array", font, sf::Color::White);
    // #3. Singly linked list rectangle
    rect3.CreateButton(rectWidth, rectHeight, startX1, startY1 + (rectHeight + padding) * 2.f, sf::Color(160, 0, 167), sf::Color(22, 73, 154), "Singly linked list", font, sf::Color::White);
    // #4. Doubly linked list rectangle
    rect4.CreateButton(rectWidth, rectHeight, startX2, startY2, sf::Color(186, 29, 71), sf::Color(22, 73, 154), "Doubly Linked List", font, sf::Color::White);
    // #5. Circular linked list rectangle
    rect5.CreateButton(rectWidth, rectHeight, startX2, startY2 + rectHeight + padding, sf::Color(124, 192, 204), sf::Color(22, 73, 154), "Circular Linked List", font, sf::Color::White);
    // #6. Stack rectangle
    rect6.CreateButton(rectWidth, rectHeight, startX2, startY2 + (rectHeight + padding) * 2.f, sf::Color(0, 160, 0), sf::Color(22, 73, 154), "Stack", font, sf::Color::White);
    // #7. Queue rectangle
    rect7.CreateButton(rectWidth + padding*2, rectHeight, 1920 / 2.f,  startY2 + (rectHeight + padding) * 3.f, sf::Color(38, 116, 236), sf::Color(22, 73, 154), "Queue", font, sf::Color::White);
}

void StartPage::display(sf::RenderWindow &window)
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_1::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_2::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}

DataVisualization_3::DataVisualization_3()
{
    //Font
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
    
    //Function Key #1
    this->ControlMenu_btn1.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 125.f, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Create", font, sf::Color::White);
    this->ControlMenu_btn1.rect.setOutlineThickness(0);
    this->CreateEmpty.CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Empty", font, sf::Color::White);
    this->CreateEmpty.display = false;
    this->CreateRadom.CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 130.f, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Random", font, sf::Color::White);
    this->CreateRadom.display = false;
    this->CreateRandomSort.CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 130.f * 2, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Random Sort", font, sf::Color::White);
    this->CreateRandomSort.display = false;
    this->CreateRandomFixedSize.CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 130.f * 3, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Random Fixed Size", font, sf::Color::White);
    this->CreateRandomFixedSize.display = false;
    this->CreateUserDefinedList.CreateButton(130.f, 50.f, ControlMenu_btn1.rect.getPosition().x + ControlMenu_btn1.rect.getSize().x / 2.f + 20.f + 130/2.f + 130.f * 4, ControlMenu_btn1.rect.getPosition().y, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "User Defined", font, sf::Color::White);
    this->CreateUserDefinedList.display = false;
    //Function Key #2
    this->ControlMenu_btn2.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 175.f, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Add", font, sf::Color::White);
    this->ControlMenu_btn2.rect.setOutlineThickness(0);
    //Function Key #3
    this->ControlMenu_btn3.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 225.f, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Delete", font, sf::Color::White);
    this->ControlMenu_btn3.rect.setOutlineThickness(0);
    //Function Key #4
    this->ControlMenu_btn4.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 275.f, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Update", font, sf::Color::White);
    this->ControlMenu_btn4.rect.setOutlineThickness(0);
    //Function Key #5
    this->ControlMenu_btn5.CreateButton(200.f, 50.f, 250.f, 1080 / 2.f + 325.f, sf::Color(255, 138, 39), sf::Color(22, 73, 154), "Search", font, sf::Color::White);
    this->ControlMenu_btn5.rect.setOutlineThickness(0);
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
    if (this->CreateEmpty.display)
    {
        this->CreateEmpty.displayButton(window);
        this->CreateRadom.displayButton(window);;
        this->CreateRandomSort.displayButton(window);
        this->CreateRandomFixedSize.displayButton(window);
        this->CreateUserDefinedList.displayButton(window);
    }
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_4::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_5::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_6::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
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
    this->backButton.CreateButton(100.f, 50.f, 70.f, 45.f, sf::Color(128, 128, 128), sf::Color(128, 128, 128), "Back", font, sf::Color::White);
}

void DataVisualization_7::display(sf::RenderWindow &window)
{
    this->backButton.displayButton(window);
    window.draw(this->Title);
}