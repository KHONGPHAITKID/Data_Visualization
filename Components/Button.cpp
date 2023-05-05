#include "Button.hpp"

Button::Button()
{
    // this->display = true;
}
void Button::CreateButton(float recwidth, float recheight, float PosX, float PosY, sf::Color buttonbgcolor, sf::String text, sf::Font &font, sf::Color text_color)
{
    // Set up the rectangle
    this->rect.setSize(sf::Vector2f(recwidth, recheight));
    this->rect.setPosition(sf::Vector2f(PosX, PosY));
    this->rect.setFillColor(buttonbgcolor);
    this->rect.setOrigin(this->rect.getSize().x / 2.f, this->rect.getSize().y / 2.f);

    // Set up the text
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(this->rect.getSize().y / 3.f);
    this->text.setFillColor(text_color);

    // Center the text
    sf::FloatRect textRect = this->text.getLocalBounds();
    this->text.setOrigin(textRect.width/2.f, textRect.height/2.f);
    this->text.setPosition(this->rect.getPosition().x , this->rect.getPosition().y - this->text.getLocalBounds().height / 3.f);
}
void Button::displayButton(sf::RenderWindow &window)
{
        window.draw(this->rect);
        window.draw(this->text);
}

void Button::setSize(float size)
{
    this->text.setCharacterSize(size);
    this->text.setOrigin(this->text.getLocalBounds().width / 2.f, this->text.getLocalBounds().height / 2.f);
    this->text.setPosition(this->rect.getPosition().x , this->rect.getPosition().y - this->text.getLocalBounds().height / 2.f);
}