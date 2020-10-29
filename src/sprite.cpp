#include "../include/sprite.hpp"
#include <SFML/Graphics/Texture.hpp>

me::sprite::sprite(const char* png, int custom_id)
: _id{custom_id}, _sprite{sf::Texture()}
{
    sf::Texture temp_texture;
    if (!temp_texture.loadFromFile(png))
    {
        cout << "unable to read from " << png << endl;
    }
    _sprite.setTexture(temp_texture);
}

me::sprite::~sprite()
{
}

const me::sprite& me::sprite::png(const char* png)
{
    sf::Texture _tex;
    if (_tex.loadFromFile(string(png)))
        _sprite.setTexture(_tex);
    return *this;
}

const me::sprite& me::sprite::id(int id)
{
    // check if id is valid
    _id = id;
    return *this;
}

const sf::Sprite me::sprite::data()
{
    return _sprite;
}

const int me::sprite::id() noexcept
{
    return _id;
}

const char* me::sprite::png() noexcept
{
    return _png.c_str();
}

void me::sprite::draw() noexcept
{
    // draw sprite
}

