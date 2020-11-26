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
    map(const char* id, bool collidable,
            sf::RenderWindow& parentWindow)
        : me::sprite{
            me::filePath(
                         string{"trchar"}.append(id).append(".png").c_str(),
                fm::pokekit_type::PROP).c_str(),
            parentWindow
        }, _collidable{collidable}
    {
    }
    ~map();
    const pair<int, int> dims();
private:
    pair<int, int> _dims;
};

}

#endif
