#include "Textbox.hpp"

#include <iostream> // for debugging

Textbox::Textbox(unsigned int maxChars) :
    m_size(maxChars),
    m_rect(sf::Vector2f(15 * m_size, 20)), // 15 pixels per char, 20 pixels height, you can tweak
    m_hasfocus(false)
{
    if (!m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) { // I'm working on Windows, you can put your own font instead
        std::cerr << "Failed to load font file\n";
    }

    m_rect.setOutlineThickness(2);
    m_rect.setFillColor(sf::Color::White);
    m_rect.setOutlineColor(sf::Color(127, 127, 127));
}

const std::string Textbox::getText() const {
    return m_text;
}

void Textbox::setPosition(float x, float y) {
    sf::Transformable::setPosition(x, y);
    m_rect.setPosition(x, y);
}

bool Textbox::contains(sf::Vector2f point) const {
    return m_rect.getGlobalBounds().contains(point);
}

void Textbox::setFocus(bool focus) {
    m_hasfocus = focus;
    if (focus) {
        m_rect.setOutlineColor(sf::Color::Blue);
    }
    else {
        m_rect.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
    }
}

void Textbox::handleInput(sf::Event e) {
    if (!m_hasfocus || e.type != sf::Event::TextEntered)
        return;

    if (e.text.unicode == 8) {   // Delete key
        m_text = m_text.substr(0, m_text.size() - 1);
    }
    else if (m_text.size() < m_size) {
        m_text += e.text.unicode;
    }
}

void Textbox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_rect, states);

    sf::Text text(m_text, m_font, 16); // adjust font size as necessary
    text.setFillColor(sf::Color::Black);
    text.setPosition(m_rect.getPosition() + sf::Vector2f(5, 0)); // offset to avoid border
    target.draw(text, states);
}
