#ifndef SPRITE_HPP
#define SPRITE_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include "../include/common.hpp"
#include "../include/camera.hpp"

namespace me
{

    class sprite
    {
    public:
        explicit sprite(const char *png, sf::RenderWindow &parentWindow, me::rendercamera &camera);
        virtual ~sprite();
        const sprite &load_texture(const char *filepath);
        const sprite &set_textRect(int x, int y, int w, int h);
        const sprite &id(int id);
        const sf::Sprite &data() const;
        virtual void pollEvent(){};
        const int id() const noexcept;
        const char *png() const noexcept;
        virtual void draw() noexcept;
        virtual unsigned char priority() const noexcept { return _priority; };
        bool collidable() const noexcept { return _collidable; };
        virtual bool operator<(const sprite &cto) const noexcept { return _priority < cto.priority(); }
        virtual bool operator>(const sprite &cto) const noexcept { return _priority < cto.priority(); }
        virtual bool operator==(const sprite &cto) const noexcept { return _priority == cto.priority(); }
        virtual ostream &operator<<(ostream &os) const noexcept
        {
            cout << "Called" << endl;
            os << _png.c_str();
            return os;
        }

    protected:
        virtual void priority(unsigned char value) { _priority = value; };
        void collidable(bool value) { _collidable = value; };

    private:
        int _id;
        string _png;
        sf::IntRect _text_rect;
        sf::Texture _texture;

    protected:
        unsigned char _priority;
        bool _collidable;
        sf::Vector2f _pos;
        sf::Vector2f _camera_pos;
        sf::Sprite _sprite;
        sf::RenderWindow &_win;
        me::rendercamera &_camera;
    };

}
#endif
