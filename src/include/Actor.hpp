#pragma once
#include <SFML/Graphics.hpp>

class Actor : public sf::Drawable
{
private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};