#ifndef NPC_HPP
#define NPC_HPP
#pragma once

#include <chrono>
#include <SFML/Graphics.hpp>
#include "common.hpp"
#include "sprite.hpp"
#include "file_manager.hpp"

namespace me
{

    class npc : public sprite
    {
    public:
        explicit npc(const char *id, sf::RenderWindow &parentWindow);
        virtual ~npc(){};
        virtual void pollEvent() override;

    protected:
        virtual void update() override;
        void move(sf::Vector2f offset);

    protected:
        char _holdPose = 10;
        char _oldPose;
        char _pose;
        sf::Vector2f _speed;
        chrono::steady_clock::time_point _lastUpdate;
    };

}

#endif
