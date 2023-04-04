#include "CLL.hpp"

void CLL_Node::DeleteCLL(CLL_Node* &pHead)
{
    CLL_Node* temp = pHead;
    while (pHead != nullptr)
    {
        pHead = pHead->next;
        delete temp;
        temp = pHead;
    }
    pHead = nullptr;
}

void CLL_Node::SortCLL(CLL_Node* &pHead)
{
    CLL_Node* i = pHead;
    while (i->next != nullptr)
    {
        CLL_Node* min_ptr = i;
        CLL_Node* j = i->next;
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

void CLL_Node::addBack(CLL_Node* &pHead, CLL_Node* &temp)
{
    if (pHead == nullptr)
    {
        pHead = temp;
        return;
    }
    CLL_Node* cur = pHead;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

void CLL_Node::CreateRandomSortCLL(CLL_Node* &head, int &n, sf::Font &font)
{
    DeleteCLL(head);
    n = 5 + rand() % 5;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        CLL_Node* tmp = createNode(250 + i * 150, 350, 30, font, value);
        addBack(head, tmp);
    }
    CLL_Node* i = head;
    while (i->next != nullptr)
    {
        CLL_Node* min_ptr = i;
        CLL_Node* j = i->next;
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

CLL_Node* CLL_Node::createNode(float x, float y, float radius, sf::Font &font, int value) 
{
    CLL_Node* nc = new CLL_Node;
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

void CLL_Node::CreateFixedNodes(CLL_Node* &v, int &n, sf::Font &font)
{
    DeleteCLL(v);
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        CLL_Node* temp = createNode(250 + i * 150, 350, 30, font, value);
        addBack(v, temp);
    }
}

void CLL_Node::CreateRandomNodes(CLL_Node* &v, int &n, sf::Font &font)
{
    DeleteCLL(v);
    n = 5 + rand() % 5;
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        CLL_Node* temp = createNode(250 + i * 150, 350, 30, font, value);
        addBack(v, temp);
    }
}

void CLL_Node::drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second)
{
    CLLArrow arrow(first, second, sf::Color::White);
    window.draw(arrow);
}

//=============================

CLLArrow::CLLArrow()
{
    this->length = 0;
    this->angle = 0;
    this->color = sf::Color::White;
    this->position = sf::Vector2f(0, 0);
    this->update();
}

CLLArrow::CLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color)
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

        this->length = sqrt(pow(truePos2.x - truePos1.x, 2) + pow(truePos2.y - truePos1.y, 2)) - 20;
        this->position.x = truePos1.x;
        this->position.y = truePos1.y;
        this->HeadPosition.x = truePos1.x + length*cos(this->angle);
        this->HeadPosition.y = truePos1.y + length*sin(this->angle);
    } else { 
        position1.x += 30;
        position2.x -= 30;
        this->angle = 0;
        this->length = position2.x - position1.x - 20;
        this->HeadPosition.x = position1.x + length;
        this->HeadPosition.y = position1.y;
        this->position.x = position1.x;
        this->position.y = position1.y;
    }
    this->update();
}

CLLArrow::~CLLArrow()
{
}

void CLLArrow::setLength(float length)
{
    this->length = length;
    this->update();
}

void CLLArrow::setAngle(float angle)
{
    this->angle = angle;
    this->update();
}

void CLLArrow::setColor(sf::Color color)
{
    this->color = color;
    this->update();
}

void CLLArrow::setPosition(sf::Vector2f position)
{
    this->position = position;
    this->update();
}

void CLLArrow::setHeadPosition(sf::Vector2f HeadPosition)
{
    this->HeadPosition = HeadPosition;
    this->update();
}

float CLLArrow::getLength() const
{
    return this->length;
}

float CLLArrow::getAngle() const
{
    return this->angle;
}

sf::Color CLLArrow::getColor() const
{
    return this->color;
}

sf::Vector2f CLLArrow::getPosition() const
{
    return this->position;
}

sf::Vector2f CLLArrow::getHeadPosition() const
{
    return this->HeadPosition;
}

void CLLArrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->body);
    target.draw(this->head);
}

void CLLArrow::update()
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
}