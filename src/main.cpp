#include <iostream>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "../include/common.hpp"
#include "../include/sprite.hpp"
#include "../include/npc.hpp"

using namespace std;

int main(int argc, const char** args)
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    
    me::npc test {56, window};
    cout << std::filesystem::current_path() << endl;

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
        test.draw();
        window.display();
    }
    
    return EXIT_SUCCESS;
}
