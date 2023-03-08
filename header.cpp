#include "header.hpp"

void swapNode(Node &a, Node &b)
{
    Node temp = a;
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
                min = j;
            }
        }
        swapNode(v[min], v[i]);
    }
}

void CreateTitle(sf::Text &Title, float PosX, float PosY)
{
    Title.setOutlineColor(sf::Color::Red);
    Title.setOutlineThickness(5.f);
    Title.setFillColor(sf::Color::White);
    Title.setOrigin(Title.getLocalBounds().width / 2.f, Title.getLocalBounds().height / 2.f);
    Title.setPosition(PosX, PosY);
}

// position: config in main.
Button CreateButton(float recwidth, float recheight, float PosX, float PosY, sf::Color buttonbgcolor, sf::Color buttonOutlineColor, sf::String text, sf::Font &font, sf::Color text_color) {
    
    Button b;
    // Set up the rectangle
    b.rect.setSize(sf::Vector2f(recwidth, recheight));
    b.rect.setPosition(sf::Vector2f(PosX, PosY));
    b.rect.setFillColor(buttonbgcolor);
    b.rect.setOutlineThickness(5);
    b.rect.setOutlineColor(buttonOutlineColor);
    b.rect.setOrigin(b.rect.getSize().x / 2.f, b.rect.getSize().y / 2.f);

    // Set up the text
    b.text.setFont(font);
    b.text.setString(text);
    b.text.setCharacterSize(b.rect.getSize().y / 3.f);
    b.text.setFillColor(text_color);

    // Center the text
    sf::FloatRect textRect = b.text.getLocalBounds();
    b.text.setOrigin(textRect.width/2.f, textRect.height/2.f);
    // b.text.setPosition(b.rect.getPosition().x + b.rect.getSize().x/ 2.f, b.rect.getPosition().y + b.rect.getSize().y/ 2.f);
    b.text.setPosition(b.rect.getPosition().x , b.rect.getPosition().y - b.text.getLocalBounds().height / 3.f);
    return b;
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
    sortArray(v, n);
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