#include <SFML/Graphics.hpp>
#include <iostream>

struct TextWriter
{
    sf::Text WriteText(const char *text, int x, int y)
    {
        sf::Text _text;
        sf::Font font;
        if (!font.loadFromFile("./Hylian64.ttf"))
        {
            std::cout << "Unable to load font file" << std::endl;
        }

        // select the font
        _text.setFont(font); // font is a sf::Font

        // set the string to display
        _text.setString(L"Hello world");

        // set the character size
        _text.setCharacterSize(24); // in pixels, not points!

        // set the color
        _text.setFillColor(sf::Color::Red);

        // set the text style
        _text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        return _text;
    }
};
