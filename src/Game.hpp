
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "tileson.hpp"
#include <map>
#include <memory>

class Game
{
public:
    Game();
    bool initialize(const sf::Vector2i &windowSize, const std::string &title = "SFML Tileson Integration");
    void run();

private:
    void drawMap();
    void drawLayer(tson::Layer& layer);
    void drawTileLayer(tson::Layer& layer);
    sf::Vector2f getTileOffset(int tileId, tson::Map *map, tson::Tileset* tileset);
    fs::path getTilesetImagePath(const tson::Tileset &tileset);

    sf::RenderWindow m_window;
    std::unique_ptr<tson::Map> m_map;
    std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
    std::map<std::string, std::unique_ptr<sf::Sprite>> m_sprites;
};

#endif //GAME_HPP
