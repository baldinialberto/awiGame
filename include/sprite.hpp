#ifndef SPRITE_HPP
#define SPRITE_HPP

#pragma once
#include <SFML/Graphics.hpp>

namespace me
{

class sprite
{
public:
    sprite(const char* png, int custom_id =0);
    ~sprite();
    sprite& png(const char* png);
    sprite& id(int id);
    const int id();
    const char* png();
private:
    const int _id;
    string _png;
    sfml::sprite _sprite;
    static int _lastid = 0;
};

}

#endif