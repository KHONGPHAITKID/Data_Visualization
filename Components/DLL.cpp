#include "DLL.hpp"

void DLL_Node::DeleteDLL(DLL_Node* &pHead)
{
    DLL_Node* temp = pHead;
    while (pHead != nullptr)
    {
        pHead = pHead->next;
        delete temp;
        temp = pHead;
    }
    pHead = nullptr;
}

void DLL_Node::SortDLL(DLL_Node* &pHead)
{
    DLL_Node* i = pHead;
    while (i->next != nullptr)
    {
        DLL_Node* min_ptr = i;
        DLL_Node* j = i->next;
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

void DLL_Node::addBack(DLL_Node* &pHead, DLL_Node* &temp)
{
    if (pHead == nullptr)
    {
        pHead = temp;
        return;
    }
    DLL_Node* cur = pHead;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

void DLL_Node::CreateRandomSortDLL(DLL_Node* &head, int &n, sf::Font &font)
{
    DeleteDLL(head);
    n = 5 + rand() % 5;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        DLL_Node* tmp = createNode(250 + i * 150, 250, 30, font, value);
        addBack(head, tmp);
    }
    DLL_Node* i = head;
    while (i->next != nullptr)
    {
        DLL_Node* min_ptr = i;
        DLL_Node* j = i->next;
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
            i->text.setPosition(i->circle.getPosition().x, i->circle.getPosition().y - 7);
        } else {
            i->text.setPosition(i->circle.getPosition().x - 1, i->circle.getPosition().y - 7);
        }
        i = i->next;
    }
}

DLL_Node* DLL_Node::createNode(float x, float y, float radius, sf::Font &font, int value) 
{
    DLL_Node* nc = new DLL_Node;
    nc->data = value;
    std::string str = std::to_string(value);
    nc->next = nullptr;
    nc->circle.setRadius(radius);
    nc->circle.setPosition(x, y);
    nc->circle.setFillColor(sf::Color(106, 231, 255, 0));
    nc->circle.setOrigin(nc->circle.getRadius(), nc->circle.getRadius());
    nc->circle.setOutlineThickness(2);
    nc->circle.setOutlineColor(sf::Color(106, 231, 255));

    nc->text.setFont(font);
    nc->text.setString(str);
    nc->text.setCharacterSize(radius / 3.f * 2.f);
    nc->text.setFillColor(sf::Color(106, 231, 255));
    nc->text.setOrigin(nc->text.getLocalBounds().width / 2.f, nc->text.getLocalBounds().height / 2.f);
    if (nc->data < 10)
    {
        nc->text.setPosition(nc->circle.getPosition().x, nc->circle.getPosition().y - 7);
    } else {
        nc->text.setPosition(nc->circle.getPosition().x - 1, nc->circle.getPosition().y - 7);
    }
    return nc;
}

void DLL_Node::CreateFixedNodes(DLL_Node* &v, int &n, sf::Font &font)
{
    DeleteDLL(v);
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        DLL_Node* temp = createNode(250 + i * 150, 250, 30, font, value);
        addBack(v, temp);
    }
}

void DLL_Node::CreateRandomNodes(DLL_Node* &v, int &n, sf::Font &font)
{
    DeleteDLL(v);
    n = 5 + rand() % 5;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        DLL_Node* temp = createNode(250 + i * 150, 250, 30, font, value);
        addBack(v, temp);
    }
}

void DLL_Node::drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second)
{
    DLLArrow arrow(first, second, sf::Color::White);
    window.draw(arrow);
}

//=============================

DLLArrow::DLLArrow()
{
    this->length = 0;
    this->angle = 0;
    this->color = sf::Color::White;
    this->position = sf::Vector2f(0, 0);
    this->update();
}

DLLArrow::DLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color)
{
    this->color = color;
    // not in the same line
    if (position1.y != position2.y) 
    {
        //find the 2 true points
        sf::Vector2f truePos1, truePos2;
        this->angle = atan2(position2.y - position1.y, position2.x - position1.x);
        truePos1.x = position1.x + 30*cos(this->angle);
        truePos1.y = position1.y + 30*sin(this->angle);
        truePos2.x = position2.x - 30*cos(this->angle);
        truePos2.y = position2.y - 30*sin(this->angle);

        this->length = sqrt(pow(truePos2.x - truePos1.x, 2) + pow(truePos2.y - truePos1.y, 2)) - 40;
        this->position.x = truePos1.x + 20*cos(this->angle);
        this->position.y = truePos1.y + 20*sin(this->angle);
        this->TailPosition.x = truePos1.x + 20*cos(this->angle);
        this->TailPosition.y = truePos1.y + 20*sin(this->angle);
        this->HeadPosition.x = truePos1.x + (length + 20)*cos(this->angle);
        this->HeadPosition.y = truePos1.y + (length + 20)*sin(this->angle);
    } else { 
        position1.x += 30;
        position2.x -= 30;
        this->angle = 0;
        this->length = position2.x - position1.x - 40;
        this->position.x = position1.x + 20;
        this->position.y = position1.y;
        this->HeadPosition.x = position1.x + length + 20;
        this->HeadPosition.y = position1.y;
        this->TailPosition.x = position1.x + 20;
        this->TailPosition.y = position1.y;
    }
    this->update();
}

void DLLArrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->body);
    target.draw(this->head);
    target.draw(this->tail);
}

void DLLArrow::update()
{
    this->body.setSize(sf::Vector2f(this->length, 5));
    this->body.setOrigin(sf::Vector2f(0, 2.5));
    this->body.setPosition(this->position);
    this->body.setRotation(this->angle * 180 / 3.1415 );
    this->body.setFillColor(this->color);

    this->head.setPointCount(3);
    this->head.setPoint(0, sf::Vector2f(0, 0));
    this->head.setPoint(1, sf::Vector2f(20, 10));
    this->head.setPoint(2, sf::Vector2f(0, 20));
    this->head.setOrigin(sf::Vector2f(0, 10));
    this->head.setPosition(this->HeadPosition);
    this->head.setRotation(this->angle * 180 / 3.1415);
    this->head.setFillColor(this->color);

    this->tail.setPointCount(3);
    this->tail.setPoint(0, sf::Vector2f(0, 10));
    this->tail.setPoint(1, sf::Vector2f(20, 0));
    this->tail.setPoint(2, sf::Vector2f(20, 20));
    this->tail.setOrigin(sf::Vector2f(20, 10));
    this->tail.setPosition(this->TailPosition);
    this->tail.setRotation(this->angle * 180 / 3.1415);
    this->tail.setFillColor(this->color);
}