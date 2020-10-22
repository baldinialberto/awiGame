#include "../include/sprite.hpp"
#include <SFML/Graphics/Texture.hpp>

me::sprite::sprite(const char* png, int custom_id)
: _id{custom_id}, _sprite{sf::Texture()}
{
}

me::sprite::~sprite()
{
}

me::sprite& me::sprite::png(const char* png)
{
    sf::Texture _tex;
    if (_tex.loadFromFile(string(png)))
        _sprite.setTexture(_tex);
    return *this;
}

