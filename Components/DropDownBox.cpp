#include "DropDownBox.hpp"
#include <iostream>

DropdownBox::DropdownBox(sf::Vector2f position, sf::Vector2f size, std::string titleText, std::vector<std::string> optionTexts) :
    isExpanded(false),
    selectedOptionIndex(-1)
{
    font = defautFont;

    // Background
    background.setPosition(position);
    background.setSize(size);
    background.setFillColor(sf::Color::White);
    background.setOutlineThickness(2);
    background.setOutlineColor(sf::Color::Black);

    Titlebackground.setPosition(position);
    Titlebackground.setSize(size + sf::Vector2f(0, -20.f));
    Titlebackground.setFillColor(sf::Color::White);
    Titlebackground.setOutlineThickness(2);
    Titlebackground.setOutlineColor(sf::Color::Black);

    // Title
    title.setFont(font);
    title.setString(titleText);
    title.setCharacterSize(16);
    title.setFillColor(sf::Color::Black);
    title.setPosition(position + sf::Vector2f(10, 5));

    // Options
    for (std::string optionText : optionTexts)
    {
        sf::Text option;
        option.setFont(font);
        option.setString(optionText);
        option.setCharacterSize(16);
        option.setFillColor(sf::Color::Black);
        option.setPosition(position + sf::Vector2f(10, size.y + options.size() * 20 - 10));
        options.push_back(option);
    }
}

void DropdownBox::draw(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(title);
    if (isExpanded)
    {
        for (sf::Text option : options)
        {
            window.draw(option);
        }
    }
}

void DropdownBox::expand()
{
    isExpanded = true;
    background.setSize(sf::Vector2f(background.getSize().x, options.size() * 20 + 40));
}

void DropdownBox::collapse()
{
    isExpanded = false;
    background.setSize(sf::Vector2f(background.getSize().x, 50));
}

bool DropdownBox::handleEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (Titlebackground.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            if (isExpanded)
            {
                collapse();
            }
            else
            {
                expand();
            }
            return true;
        }
        else if (isExpanded)
        {
            for (int i = 0; i < options.size(); i++)
            {
                if (options[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    selectedOptionIndex = i;
                    title.setString(options[i].getString());
                    storage = title.getString();
                    collapse();
                    return true;
                }
            }
        }
    }
    return false;
}