#include "Stack.hpp"

void Stack_Node::DeleteStack(Stack_Node* &pHead)
{
    Stack_Node* temp = pHead;
    while (pHead != nullptr)
    {
        pHead = pHead->next;
        delete temp;
        temp = pHead;
    }
    pHead = nullptr;
}

void Stack_Node::SortStack(Stack_Node* &pHead)
{
    Stack_Node* i = pHead;
    while (i->next != nullptr)
    {
        Stack_Node* min_ptr = i;
        Stack_Node* j = i->next;
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

void Stack_Node::addBack(Stack_Node* &pHead, Stack_Node* &temp)
{
    if (pHead == nullptr)
    {
        pHead = temp;
        return;
    }
    temp->next = pHead;
    pHead = temp;
}

void Stack_Node::CreateRandomSortStack(Stack_Node* &head, int &n, sf::Font &font)
{
    DeleteStack(head);
    n = 1 + rand() % 5;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        Stack_Node* tmp = createNode(960, 627.5f - 75 * i, 75, 300, font, value);
        addBack(head, tmp);
    }
    Stack_Node* i = head;
    while (i->next != nullptr)
    {
        Stack_Node* min_ptr = i;
        Stack_Node* j = i->next;
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
        i->text.setOrigin(i->text.getLocalBounds().width / 2.f, i->text.getLocalBounds().height / 2.f);
        if (i->data < 10)
        {
            i->text.setPosition(i->rec.getPosition().x, i->rec.getPosition().y - 10);
        } else {
            i->text.setPosition(i->rec.getPosition().x - 1, i->rec.getPosition().y - 10);
        }
        i = i->next;
    }
}

Stack_Node* Stack_Node::createNode(float x, float y, float height, float width, sf::Font &font, int value) 
{
    Stack_Node* nc = new Stack_Node;
    nc->data = value;
    std::string str = std::to_string(value);
    nc->next = nullptr;

    nc->rec.setSize(sf::Vector2f(width, height));
    nc->rec.setFillColor(sf::Color(106, 231, 255));
    nc->rec.setOrigin(sf::Vector2f(150, 75 / 2.f));
    nc->rec.setOutlineThickness(2);
    nc->rec.setOutlineColor(sf::Color::Black);
    nc->rec.setPosition(sf::Vector2f(x, y));

    nc->text.setFont(font);
    nc->text.setString(str);
    nc->text.setCharacterSize(40.f);
    nc->text.setFillColor(sf::Color::Black);
    nc->text.setOrigin(sf::Vector2f(nc->text.getLocalBounds().width/2.f, nc->text.getLocalBounds().height/2.f));
    nc->text.setPosition(nc->rec.getPosition().x, nc->rec.getPosition().y - nc->text.getLocalBounds().height / 2.f);

    return nc;
}

void Stack_Node::CreateFixedNodes(Stack_Node* &v, int &n, sf::Font &font)
{
    DeleteStack(v);
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        Stack_Node* temp = createNode(960, 627.5f - 75 * i, 75, 300, font, value);
        addBack(v, temp);
    }
}

void Stack_Node::CreateRandomNodes(Stack_Node* &v, int &n, sf::Font &font)
{
    DeleteStack(v);
    n = 1 + rand() % 6;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        Stack_Node* temp = createNode(960, 627.5f - 75 * i, 75, 300, font, value);
        addBack(v, temp);
    }
}