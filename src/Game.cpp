
#include "Game.hpp"

Game::Game() = default;

bool Game::initialize(const sf::Vector2i &windowSize, const std::string &title)
{
    m_window.create(sf::VideoMode(windowSize.x, windowSize.y), title);
    
    tson::Tileson t;
    std::vector<uint8_t> fileContent;
    std::ifstream file("m.tmj", std::ios::binary);
    fileContent.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    m_map = t.parse(fileContent.data(), fileContent.size(), nullptr);

    if(m_map == nullptr || m_map->getStatus() != tson::ParseStatus::OK)
        return false;

    return true;
}

void Game::run()
{
    while(m_window.isOpen())
    {
        sf::Event event;
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear();
        drawMap();
        m_window.display();
    }
}

void Game::drawMap()
{
    for(auto& layer : m_map->getLayers())
    {
        drawLayer(layer);
    }
}

void Game::drawLayer(tson::Layer& layer)
{
    // Implementation based on the SfmlDemoManager example...
}

void Game::drawTileLayer(tson::Layer& layer)
{
    // Implementation based on the SfmlDemoManager example...
}

sf::Vector2f Game::getTileOffset(int tileId, tson::Map *map, tson::Tileset* tileset)
{
    // Implementation based on the SfmlDemoManager example...
    return {0.f, 0.f}; // Placeholder
}

fs::path Game::getTilesetImagePath(const tson::Tileset &tileset)
{
    // Implementation based on the SfmlDemoManager example...
    return ""; // Placeholder
}
