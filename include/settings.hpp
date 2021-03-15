#ifndef _SETTINGS_HPP
#define _SETTINGS_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include "../include/common.hpp"
#include "../include/file_manager.hpp"

#define GAME_SETTINGS_SAVE_LOCATION "./res/settings"

namespace me
{
    struct _game_settings
    {
        unsigned char _aa;  //1
        unsigned char _fps; //1
        bool _fs;           //1
        int _windim_x;      //4
        int _windim_y;      //4
    };

    class game_settings
    {
    public:
        explicit game_settings(const char *filePath);
        game_settings();
        virtual ~game_settings();
        const unsigned char aa() const;
        const unsigned char fps() const;
        const sf::Vector2i win_dims() const;
        const bool fullscreen() const;
        const sf::ContextSettings &setts() const;
        int aa(unsigned char value);
        int fps(unsigned char value);
        int win_dims(const sf::Vector2i value);
        int fullscreen(bool value);
        bool operator==(const game_settings &g) const;
        //friend ostream &operator<<(ostream &os, const game_settings &sett);
        void print() const;

    private:
        int
        _write(const char *path) const;
        int _read(const char *path);

    private:
        unsigned char _antialeasing;
        unsigned char _frames_persecond;
        sf::Vector2i _window_dims;
        bool _fullscreen;
        sf::ContextSettings _settings;
    };
}

#endif