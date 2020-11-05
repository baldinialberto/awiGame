#include "../include/npc.hpp"

void me::npc::draw() noexcept
{
    const int width_offs = 32, height_offs = 48;
    set_textRect(
        _pose % 4 * width_offs, _pose / 4 * height_offs,
        width_offs, height_offs
    );
    _win.draw(_sprite);
}

void me::npc::pollEvent()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // move down
    {
        if (_pose / 4 == 0) // still moving down
        {    _pose = (_pose + 1) % 4;
        } else {            // start moving down
            _pose = 0;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // move left
    {
        if (_pose / 4 == 1) // still moving left
        {    _pose = (_pose + 1) % 4 + 4;
        } else {            // start moving left
            _pose = 4;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // move right
    {
        if (_pose / 4 == 2) // still moving right
        {    _pose = (_pose + 1) % 4 + 8;
        } else {            // start moving right
            _pose = 8;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // move up
    {
        if (_pose / 4 == 3) // still moving up
        {    _pose = (_pose + 1) % 4 + 12;
        } else {            // start moving up
            _pose = 12;
        }
    } else {
        _pose /= 4;
        _pose *= 4;
    }
}

void me::npc::move()
{
}
