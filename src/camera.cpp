#include <camera.hpp>

me::camera::camera(sf::RenderWindow &win)
    : _win{win}
{
    _view = _win.getDefaultView();
    _win.setView(_view);
}

me::camera::~camera()
{
    _win.setView(_win.getDefaultView());
}

void me::camera::pollEvent()
{
    const float deltaPos = 2.0;
    const float deltaScale = .5;
    const float deltaRot = .5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) // move down
    {
        move(0, -deltaPos);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) // move left
    {
        move(-deltaPos, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) // move right
    {
        move(deltaPos, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) // move up
    {
        move(0, deltaPos);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) // rotate left
    {
        rotate(-deltaRot);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) // rotate right
    {
        rotate(deltaRot);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) // zoom in
    {
        zoom(deltaScale);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) // zoom out
    {
        zoom(-deltaScale);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // reset view
    {
        _view = _win.getDefaultView();
    }
    else
    {
        return;
    }
    _win.setView(_view);
}

void me::camera::zoom(float value)
{
    _view.zoom(value);
}

void me::camera::set_size(float w, float h)
{
    _view.setSize(w, h);
}

void me::camera::set_size(sf::Vector2f size)
{
    set_size(size.x, size.y);
}

void me::camera::move(float dx, float dy)
{
    _view.move(dx, dy);
}

void me::camera::move(sf::Vector2f delta)
{
    move(delta.x, delta.y);
}

void me::camera::set_pos(float x, float y)
{
    _view.setCenter(x, y);
}

void me::camera::set_pos(sf::Vector2f pos)
{
    set_pos(pos.x, pos.y);
}

void me::camera::rotate(float angle)
{
    _view.rotate(angle);
}

void me::camera::set_angle(float angle)
{
    _view.setRotation(angle);
}
