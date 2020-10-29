#ifndef SPRITE_HPP
#define SPRITE_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include "../include/common.hpp"

namespace me
{

class sprite
{
public:
    sprite(const char* png, int custom_id =0);
    ~sprite();
    const sprite& png(const char* png);
    const sprite& id(int id);
    const sf::Sprite data();
    const int id() noexcept;
    const char* png() noexcept;
    void draw() noexcept;
private:
    int _id;
    string _png;
    sf::Sprite _sprite;
};

}
#endif
