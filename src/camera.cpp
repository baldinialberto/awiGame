#include <camera.hpp>
#include <iostream>
using namespace std;

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
	/*     const float deltaPos = 5.0f;
    const float deltaScale = .1f;
    const float deltaRot = 1.0f; */

	if (_focus != nullptr)
	{
		set_pos(_focus->pos());
		_win.setView(_view);
	}

	/*     if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) // move down
    {
        move(0, deltaPos);
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
        move(0, -deltaPos);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) // rotate left
    {
        rotate(-deltaRot);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) // rotate right
    {
        rotate(deltaRot);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // reset view
    {
        _view = _win.getDefaultView();
    }
    else
    {
        return;
    }
    _win.setView(_view); */
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

void me::camera::focus(me::sprite *sprite)
{
	_focus = sprite;
}

void me::camera::target_map(me::map *target)
{
	_map = target;
}