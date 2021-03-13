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
        explicit sprite(const char *png, sf::RenderWindow &parentWindow);
        virtual ~sprite();
        const sprite &load_texture(const char *filepath);
        const sprite &set_textRect(int x, int y, int w, int h);
        const sprite &id(int id);
        virtual const sf::Sprite &data() const;
        virtual void pollEvent() = 0;
        virtual const int id() const noexcept;
        virtual const char *png() const noexcept;
        virtual void draw() noexcept;
        virtual unsigned char priority() const noexcept;
        virtual sf::Vector2f pos() const noexcept;
        virtual bool collidable() const noexcept;
        virtual bool operator<(const sprite &cto) const noexcept;
        virtual bool operator>(const sprite &cto) const noexcept;
        virtual bool operator==(const sprite &cto) const noexcept;
        virtual ostream &operator<<(ostream &os) const noexcept;

    protected:
        virtual void priority(unsigned char value) { _priority = value; };
        void collidable(bool value) { _collidable = value; };

    protected:
        int _id;
        string _png;
        sf::IntRect _text_rect;
        sf::Texture _texture;
        unsigned char _priority;
        bool _collidable;
        sf::Vector2f _pos;
        sf::Sprite _sprite;
        sf::RenderWindow &_win;
    };

}
#endif
