#include "SLL.hpp"
#include "SLLArrow.hpp"

int randNum() 
{
    return rand() % 99 + 1;
}

void DeleteSLL(SLL_Node* &pHead)
{
    SLL_Node* temp = pHead;
    while (pHead != nullptr)
    {
        pHead = pHead->next;
        delete temp;
        temp = pHead;
    }
    pHead = nullptr;
}

void SortSLL(SLL_Node* &pHead)
{
    SLL_Node* i = pHead;
    while (i->next != nullptr)
    {
        SLL_Node* min_ptr = i;
        SLL_Node* j = i->next;
        while (j != nullptr)
        {
            if (j->data < min_ptr->data)
            {
                min_ptr = j;
            }
            j = j->next;
        }
        int temp = i->data;
        i->data = min_ptr->data;
        min_ptr->data = temp;
        i = i->next;
    }
}

void addBack(SLL_Node* &pHead, SLL_Node* &temp)
{
    if (pHead == nullptr)
    {
        pHead = temp;
        return;
    }
    SLL_Node* cur = pHead;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

// void CreateRandomSLL(SLL_Node* &pHead)
// {
//     DeleteSLL(pHead);
//     int n = 4 + srand() % 6;
//     while (n--)
//     {
//         int randomValue = 1 + srand() % 99;
//         addBack(pHead, randomValue);
//     }
// }

void CreateRandomSortSLL(SLL_Node* &head, int &n, sf::Font &font)
{
    DeleteSLL(head);
    n = 5 + rand() % 5;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        SLL_Node* tmp = createNode(250 + i * 150, 250, 30, font, value);
        addBack(head, tmp);
    }
    SLL_Node* i = head;
    while (i->next != nullptr)
    {
        SLL_Node* min_ptr = i;
        SLL_Node* j = i->next;
        while (j != nullptr)
        {
            if (j->data < min_ptr->data)
            {
                min_ptr = j;
            }
            j = j->next;
        }
        int temp = i->data;
        i->data = min_ptr->data;
        min_ptr->data = temp;
        i = i->next;
    }

    // update text 
    i = head;
    while (i != nullptr)
    {
        i->text.setString(std::to_string(i->data));
        i = i->next;
    }
}

int randNumNode() {
    srand(time(NULL));
    return rand() % 99 + 1;
}

//--------------
SLL_Node* createNode(float x, float y, float radius, sf::Font &font, int value) 
{
    SLL_Node* nc = new SLL_Node;
    nc->data = value;
    std::string str = std::to_string(value);
    nc->next = nullptr;
    nc->circle.setRadius(radius);
    nc->circle.setPosition(x, y);
    nc->circle.setFillColor(sf::Color::Yellow);
    nc->circle.setOrigin(nc->circle.getRadius(), nc->circle.getRadius());

    nc->text.setFont(font);
    nc->text.setString(str);
    nc->text.setCharacterSize(radius / 3.f * 2.f);
    nc->text.setFillColor(sf::Color::Black);
    nc->text.setOrigin(nc->text.getLocalBounds().width / 2.f, nc->text.getLocalBounds().height / 2.f);
    nc->text.setPosition(nc->circle.getPosition().x - 0, nc->circle.getPosition().y - 7);
    return nc;
}

void CreateFixedNodes(SLL_Node* &v, int &n, sf::Font &font)
{
    DeleteSLL(v);
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        SLL_Node* temp = createNode(250 + i * 150, 250, 30, font, value);
        addBack(v, temp);
    }
}

void CreateRandomNodes(SLL_Node* &v, int &n, sf::Font &font)
{
    DeleteSLL(v);
    n = 5 + rand() % 5;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        SLL_Node* temp = createNode(250 + i * 150, 250, 30, font, value);
        addBack(v, temp);
    }
}

void drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second)
{
    // sf::VertexArray line(sf::Lines, 2);
    // line[0].position = first;
    // line[1].position = second;
    // line[0].color = sf::Color::White;
    // line[1].color = sf::Color::White;
    // line[0].color.a = 200;
    // line[1].color.a = 200;
    // line[0].texCoords = sf::Vector2f(0, 0);
    // line[1].texCoords = sf::Vector2f(5.f, 5.f);
    SLLArrow arrow(first, second, sf::Color::White);


    window.draw(arrow);
    // window.draw(line);
}