#include <settings.hpp>

me::game_settings::game_settings(const char *filePath)
{
    if (_read(GAME_SETTINGS_SAVE_LOCATION))
    {
        game_settings();
    }
};
me::game_settings::game_settings()
{
    _antialeasing = 2;
    _frames_persecond = 30;
    _window_dims = sf::Vector2i(960, 640);
}
me::game_settings::~game_settings()
{
    if (_write(GAME_SETTINGS_SAVE_LOCATION))
    {
        std::cout << "Unable to write settings file" << endl;
    }
};

const unsigned char me::game_settings::aa() const
{
    return _antialeasing;
};
const unsigned char me::game_settings::fps() const
{
    return _frames_persecond;
};
const sf::Vector2i me::game_settings::win_dims() const
{
    return _window_dims;
};
const bool me::game_settings::fullscreen() const
{
    return _fullscreen;
};
int me::game_settings::aa(unsigned char value)
{
    if (value >= 0 && value < 9)
    {
        _antialeasing = value;
    }
};
int me::game_settings::fps(unsigned char value)
{
    if (value > 0 && value < 201)
    {
        _frames_persecond = value;
    }
};
int me::game_settings::win_dims(const sf::Vector2i value)
{
    if (value.x > 100 && value.x < 5000 &&
        value.y > 100 && value.y < 5000 &&
        value.x >= value.y)
    {
        _window_dims = value;
    }
};
int me::game_settings::fullscreen(bool value)
{
    _fullscreen = value;
};