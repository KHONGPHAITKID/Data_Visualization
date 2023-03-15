#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>

class Textbox : public sf::Transformable, public sf::Drawable {
public:
    Textbox(unsigned int maxChars);

    const std::string getText() const;

    void setPosition(float x, float y) override;

    bool contains(sf::Vector2f point) const;

    void setFocus(bool focus);

    void handleInput(sf::Event e);

private:
    unsigned int m_size;
    sf::Font m_font;
    std::string m_text;
    sf::RectangleShape m_rect;
    bool m_hasfocus;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // TEXTBOX_HPP
