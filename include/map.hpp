#ifndef MAP_HPP
#define MAP_HPP
#pragma once

#include <SFML/Graphics/Rect.hpp>
#include "common.hpp"
#include "sprite.hpp"
#include "file_manager.hpp"
#include <tuple>

namespace me
{
    class map : public sprite
    {
    public:
        explicit map(const char *filename, sf::Vector2i mDims, sf::RenderWindow &parentWindow);
        virtual ~map();
        virtual void pollEvent() override{};

    protected:
        virtual void update() override{};
    };
}

#endif
