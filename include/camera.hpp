#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#pragma once
#include "../include/common.hpp"
#include "../include/map.hpp"

namespace me
{
    class rendercamera
    {
    public:
        explicit rendercamera();
        virtual ~rendercamera();
        void move(pair<int, int> movement);
        void changeMap(map &map);
        pair<int, int> pos() const;
        ostream &operator<<(ostream &os)
        {
            os << _map.png();
            return os;
        }

    private:
        pair<int, int> _pos;
        char _zoom;
        map &_map;
    };

}

#endif