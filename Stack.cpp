#include "Stack.hpp"
//circle

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
    // Stack_Node* cur = pHead;
    // while (cur->next != nullptr)
    // {
    //     cur = cur->next;
    // }
    // cur->next = temp;
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
    nc->rec.setFillColor(sf::Color::Yellow);
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

void Stack_Node::drawArrow(sf::RenderWindow &window, sf::Vector2f first, sf::Vector2f second)
{
    StackArrow arrow(first, second, sf::Color::White);
    window.draw(arrow);
}

//=============================

StackArrow::StackArrow()
{
    this->length = 0;
    this->angle = 0;
    this->color = sf::Color::White;
    this->position = sf::Vector2f(0, 0);
    this->update();
}

StackArrow::StackArrow(sf::Vector2f position1, sf::Vector2f position2, sf::Color color)
{
    this->color = color;
    // not in the same line
    if (position1.y != position2.y) 
    {
        //find the 2 true points
        sf::Vector2f truePos1, truePos2;
        this->angle = atan2(position2.y - position1.y, position2.x - position1.x);
        truePos1.x = position1.x + 20*cos(this->angle); // 20 is the node's circle radius
        truePos1.y = position1.y + 20*sin(this->angle);
        truePos2.x = position2.x - 20*cos(this->angle);
        truePos2.y = position2.y - 20*sin(this->angle);

        this->length = sqrt(pow(truePos2.x - truePos1.x, 2) + pow(truePos2.y - truePos1.y, 2)) - 10;
        this->position.x = truePos1.x;
        this->position.y = truePos1.y;
        this->HeadPosition.x = truePos1.x + length*cos(this->angle);
        this->HeadPosition.y = truePos1.y + length*sin(this->angle);
    } else { 
        position1.x += 20;
        position2.x -= 20;
        this->angle = 0;
        this->length = position2.x - position1.x - 10;
        this->HeadPosition.x = position1.x + length;
        this->HeadPosition.y = position1.y;
        this->position.x = position1.x;
        this->position.y = position1.y;
    }
    this->update();
}

StackArrow::~StackArrow()
{
}

void StackArrow::setLength(float length)
{
    this->length = length;
    this->update();
}

void StackArrow::setAngle(float angle)
{
    this->angle = angle;
    this->update();
}

void StackArrow::setColor(sf::Color color)
{
    this->color = color;
    this->update();
}

void StackArrow::setPosition(sf::Vector2f position)
{
    this->position = position;
    this->update();
}

void StackArrow::setHeadPosition(sf::Vector2f HeadPosition)
{
    this->HeadPosition = HeadPosition;
    this->update();
}

float StackArrow::getLength() const
{
    return this->length;
}

float StackArrow::getAngle() const
{
    return this->angle;
}

sf::Color StackArrow::getColor() const
{
    return this->color;
}

sf::Vector2f StackArrow::getPosition() const
{
    return this->position;
}

sf::Vector2f StackArrow::getHeadPosition() const
{
    return this->HeadPosition;
}

void StackArrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->body);
    target.draw(this->head);
}

void StackArrow::update()
{
    this->body.setSize(sf::Vector2f(this->length, 5));
    this->body.setOrigin(sf::Vector2f(0, 2.5));
    this->body.setPosition(this->position);
    this->body.setRotation(this->angle * 180 / 3.1415 );
    this->body.setFillColor(this->color);

    this->head.setPointCount(3);
    this->head.setPoint(0, sf::Vector2f(0, 0));
    this->head.setPoint(1, sf::Vector2f(10, 5));
    this->head.setPoint(2, sf::Vector2f(0, 10));
    this->head.setOrigin(sf::Vector2f(0, 5));
    this->head.setPosition(this->HeadPosition);
    this->head.setRotation(this->angle * 180 / 3.1415);
    this->head.setFillColor(this->color);
}