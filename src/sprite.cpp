#include "../include/sprite.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

me::sprite::sprite(const char* filepath, sf::RenderWindow& parentWindow)
: _id{0}, _png{filepath}, _win{parentWindow}
{
    load_texture(filepath);
}

me::sprite::~sprite()
{
}

const me::sprite& me::sprite::load_texture(const char* filepath)
{
    if (_texture.loadFromFile(string(filepath)))
    {
        _sprite.setTexture(_texture);
        _png = string(filepath);
    } else
    {
        cout << "Unable to open file " << filepath << endl;
    }
    return *this;
}

const me::sprite& me::sprite::set_textRect(int x, int y, int w, int h)
{
    _sprite.setTextureRect(sf::IntRect(x, y, w, h));
    return *this;
}

const me::sprite& me::sprite::id(int id)
{
    // check if id is valid
    _id = id;
    return *this;
}

const sf::Sprite& me::sprite::data()
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
    cout << "draw " << _png << endl;
    _win.draw(_sprite);
}

