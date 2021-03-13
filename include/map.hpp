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
        explicit map(const char *filename, sf::Vector2i mDims, sf::RenderWindow &parentWindow)
            : me::sprite{
                  me::filePath(string(filename).append(".png").c_str(), fm::pokekit_type::PROP).c_str(),
                  parentWindow}
        {
            priority(0);
        }
        virtual ~map(){};
        virtual void pollEvent() override{};
    };

}

#endif
