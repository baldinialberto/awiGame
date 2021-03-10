#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include "../include/common.hpp"
#include "../include/map.hpp"

namespace me
{
    class rendercamera
    {
    public:
        explicit rendercamera();
        virtual ~rendercamera();
        void move(sf::Vector2f movement);
        void changeMap(map &map);
        sf::Vector2f pos() const;
        ostream &operator<<(ostream &os)
        {
            os << _map.png();
            return os;
        }
        void anchor(me::sprite &to);
        void free();

    private:
        sf::Vector2f _pos;
        char _zoom;
        map &_map;
    };

}

#endif