#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace me
{
    class camera
    {
    public:
        explicit camera(sf::RenderWindow &win);
        virtual ~camera();
        void pollEvent();

    protected:
        void zoom(float value);
        void set_size(float w, float h);
        void set_size(sf::Vector2f size);
        void move(float dx, float dy);
        void move(sf::Vector2f delta);
        void set_pos(float x, float y);
        void set_pos(sf::Vector2f pos);
        void rotate(float angle);
        void set_angle(float angle);

    private:
        sf::RenderWindow &_win;
        sf::View _view;
    };
}

#endif