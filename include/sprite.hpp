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
    explicit sprite(const char* png, sf::RenderWindow& parentWindow);
    ~sprite();
    const sprite& load_texture(const char* filepath);
    const sprite& set_textRect(int x, int y, int w, int h);
    const sprite& id(int id);
    const sf::Sprite& data();
    const int id() noexcept;
    const char* png() noexcept;
    virtual void draw() noexcept;
    void priority(unsigned char value);
    unsigned char priority();
    bool collidable(); // if _collidable is set on constr. nn
    void collidable(bool value);
private:
    int _id;
    string _png;
    sf::IntRect _text_rect;
    sf::Texture _texture;
protected:
    unsigned char _priority;
    bool _collidable;
    sf::Vector2f _pos;
    sf::Sprite _sprite;
    sf::RenderWindow& _win;
};

}
#endif
