#ifndef NPC_HPP
#define NPC_HPP
#pragma once

#include <SFML/Graphics/Rect.hpp>
#include "common.hpp"
#include "sprite.hpp"
#include "file_manager.hpp"

namespace me
{

class npc: public sprite
{
public:
    npc(const char* id, sf::RenderWindow& parentWindow)
        : me::sprite{
            me::filePath(
                         string{"trchar"}.append(id).append(".png").c_str(),
                fm::pokekit_type::NPC).c_str(),
            parentWindow
        }, _pose{0}
    {
    }
    ~npc() {};
    virtual void draw() noexcept override;
    void pollEvent();
private:
    void move(sf::Vector2f offset);
    char _pose;
};

}

#endif

