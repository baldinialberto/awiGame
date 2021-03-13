#include "../include/npc.hpp"

me::npc::npc(const char *id, sf::RenderWindow &parentWindow)
    : me::sprite{
          me::filePath(
              string{"trchar"}.append(id).append(".png").c_str(),
              fm::pokekit_type::NPC)
              .c_str(),
          parentWindow},
      _pose{0}, _oldPose{1}
{
    priority(2);
    update();
    _lastUpdate = chrono::steady_clock::now();
}

void me::npc::update()
{
    if (_pose != _oldPose)
    {
        const int width_offs = 32, height_offs = 48;
        set_textRect(
            _pose % 4 * width_offs, _pose / 4 * height_offs,
            width_offs, height_offs);
        _oldPose = _pose;
    }
    float dTime = static_cast<float>(
        chrono::duration<float>(
            chrono::steady_clock::now() - _lastUpdate)
            .count() *
        30);

    move({_speed.x * dTime, _speed.y * dTime});

    _lastUpdate = chrono::steady_clock::now(); // update last time
}

void me::npc::pollEvent()
{
    const float delta{10.0f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // move down
    {
        if (_pose / 4 == 0) // still moving down
        {
            if (_holdPose)
            {
                _holdPose--;
            }
            else
            {
                _pose = (_pose + 1) % 4;
                _holdPose = 10;
            }
        }
        else
        { // start moving down
            _pose = 0;
            _holdPose = 10;
        }
        _speed.x = 0.0f;
        _speed.y = delta;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // move left
    {
        if (_pose / 4 == 1) // still moving left
        {
            if (_holdPose)
            {
                _holdPose--;
            }
            else
            {
                _pose = (_pose + 1) % 4 + 4;
                _holdPose = 10;
            }
        }
        else
        { // start moving left
            _pose = 4;
            _holdPose = 10;
        }
        _speed.x = -delta;
        _speed.y = 0.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // move right
    {
        if (_pose / 4 == 2) // still moving right
        {
            if (_holdPose)
            {
                _holdPose--;
            }
            else
            {
                _pose = (_pose + 1) % 4 + 8;
                _holdPose = 10;
            }
        }
        else
        { // start moving right
            _pose = 8;
            _holdPose = 10;
        }
        _speed.x = delta;
        _speed.y = 0.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // move up
    {
        if (_pose / 4 == 3) // still moving up
        {
            if (_holdPose)
            {
                _holdPose--;
            }
            else
            {
                _pose = (_pose + 1) % 4 + 12;
                _holdPose = 10;
            }
        }
        else
        { // start moving up
            _pose = 12;
            _holdPose = 10;
        }
        _speed.x = 0.0f;
        _speed.y = -delta;
    }
    else
    {
        _speed.x = _speed.y = 0.0f;
        _pose -= _pose % 4;
    }
    update();
}

void me::npc::move(sf::Vector2f offset)
{
    _pos += offset;
    _sprite.move(offset);
}
