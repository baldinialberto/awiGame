#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "common.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

namespace me
{

class window
{
public:
    explicit window(int width, int height, const char* title);
    ~window();
    bool isOpen();
    const window& win();
    const window& display();
private:
    sf::RenderWindow _win;
};

}

#endif
