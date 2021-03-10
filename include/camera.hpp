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

    private:
        sf::RenderWindow &_win;
    };
}

#endif