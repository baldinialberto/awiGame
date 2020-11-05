#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics/Rect.hpp>
#pragma once

#include "common.hpp"
#include "sprite.hpp"
#include "file_manager.hpp"

namespace me
{

class npc: public sprite
{
public:
    npc(int id, sf::RenderWindow& parentWindow)
        : me::sprite{
            me::filePath(
                string{"trchar" + to_string(id) + ".png"}.c_str(),
                fm::pokekit_type::NPC).c_str(),
            parentWindow
        }
    {
    }
    ~npc()
        : ~sprite()
    {
    }

    void pollEvent();
private:
    void move();
    char _pose;
};

}

#endif

