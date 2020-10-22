#include "../include/window.hpp"
#include <SFML/Window/VideoMode.hpp>

me::window::window(int width, int height, const char* title)
: _win{sf::VideoMode(width, height), "AwiGame"}
{
}

me::window::~window()
{
}

bool me::window::isOpen()
{
    return _win.isOpen();
}

const me::window& me::window::win()
{
    return *this;
}

const me::window& me::window::display()
{
    _win.display();
    return *this;
}
