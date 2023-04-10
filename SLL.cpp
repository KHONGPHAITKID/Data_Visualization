#include "SLL.hpp"

// int randNum() 
// {
//     return rand() % 99 + 1;
// }

void SLL_Node::DeleteSLL(SLL_Node* &pHead)
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

void SLL_Node::SortSLL(SLL_Node* &pHead)
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

void SLL_Node::addBack(SLL_Node* &pHead, SLL_Node* &temp)
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

void SLL_Node::CreateRandomSortSLL(SLL_Node* &head, int &n, sf::Font &font)
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

// int SLL_Node::randNumNode() 
// {
//     srand(time(NULL));
//     return rand() % 99 + 1;
// }

SLL_Node* SLL_Node::createNode(float x, float y, float radius, sf::Font &font, int value) 
{
    SLL_Node* nc = new SLL_Node;
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

void SLL_Node::CreateFixedNodes(SLL_Node* &v, int &n, sf::Font &font)
{
    DeleteSLL(v);
    for (int i = 0; i < n; i++)
    {
        int value = 1 + rand() % 99;
        SLL_Node* temp = createNode(250 + i * 150, 250, 30, font, value);
        addBack(v, temp);
    }
}

void SLL_Node::CreateRandomNodes(SLL_Node* &v, int &n, sf::Font &font)
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

void SLL_Node::drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second)
{
    SLLArrow arrow(first, second, sf::Color::White);
    window.draw(arrow);
}

//=============================

SLLArrow::SLLArrow()
{
    this->length = 0;
    this->angle = 0;
    this->color = sf::Color::White;
    this->position = sf::Vector2f(0, 0);
    this->update();
}

SLLArrow::SLLArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color)
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

SLLArrow::~SLLArrow()
{
}

void SLLArrow::setLength(float length)
{
    this->length = length;
    this->update();
}

void SLLArrow::setAngle(float angle)
{
    this->angle = angle;
    this->update();
}

void SLLArrow::setColor(sf::Color color)
{
    this->color = color;
    this->update();
}

void SLLArrow::setPosition(sf::Vector2f position)
{
    this->position = position;
    this->update();
}

void SLLArrow::setHeadPosition(sf::Vector2f HeadPosition)
{
    this->HeadPosition = HeadPosition;
    this->update();
}

float SLLArrow::getLength() const
{
    return this->length;
}

float SLLArrow::getAngle() const
{
    return this->angle;
}

sf::Color SLLArrow::getColor() const
{
    return this->color;
}

sf::Vector2f SLLArrow::getPosition() const
{
    return this->position;
}

sf::Vector2f SLLArrow::getHeadPosition() const
{
    return this->HeadPosition;
}

void SLLArrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->body);
    target.draw(this->head);
}

void SLLArrow::update()
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