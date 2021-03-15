#include <settings.hpp>

me::game_settings::game_settings(const char *filePath)
{
    if (_read(GAME_SETTINGS_SAVE_LOCATION))
    {
        std::cout << "Unable to read settings file" << endl;
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

const sf::ContextSettings &me::game_settings::setts() const
{
    return _settings;
}

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
    else
    {
        return 1;
    }
    return 0;
};
int me::game_settings::fps(unsigned char value)
{
    if (value > 0 && value < 201)
    {
        _frames_persecond = value;
    }
    else
    {
        return 1;
    }
    return 0;
};
int me::game_settings::win_dims(const sf::Vector2i value)
{
    if (value.x > 100 && value.x < 5000 &&
        value.y > 100 && value.y < 5000 &&
        value.x >= value.y)
    {
        _window_dims = value;
    }
    else
    {
        return 1;
    }
    return 0;
};
int me::game_settings::fullscreen(bool value)
{
    _fullscreen = value;
    return 0;
};

int me::game_settings::_write(const char *path) const
{
    me::fIt file{path, "w"};
    _game_settings s{
        _antialeasing,
        _frames_persecond,
        _fullscreen,
        _window_dims.x,
        _window_dims.y};
    return file.write((char *)(&s), sizeof(s));
}

int me::game_settings::_read(const char *path)
{
    me::fIt file{path, "r"};
    _game_settings s;
    int res = file.read((char *)(&s), sizeof(s));
    if (!res)
    {
        _antialeasing = s._aa;
        _frames_persecond = s._fps;
        _fullscreen = s._fs;
        _window_dims = sf::Vector2i(s._windim_x, s._windim_y);
    }
    return res;
}

bool me::game_settings::operator==(const game_settings &g) const
{
    return _antialeasing == g.aa() &&
           _frames_persecond == g.fps() &&
           _window_dims == g.win_dims() &&
           _fullscreen == g.fullscreen();
}

/* std::ostream &me::game_settings::operator<<(ostream &os)
{
    os << "aa : " << _antialeasing << endl
       << "fps : " << _frames_persecond << endl
       << "dims : (" << _window_dims.x << ", " << _window_dims.y << ")\n";
    return os;
} */

void me::game_settings::print() const
{
    cout << "aa : " << (int)_antialeasing << endl
         << "fps : " << (int)_frames_persecond << endl
         << "dims : (" << _window_dims.x << ", " << _window_dims.y << ")\n";
}