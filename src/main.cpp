#include <iostream>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, const char** args)
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
            || event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    
    return EXIT_SUCCESS;
}
