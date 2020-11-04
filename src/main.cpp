#include <iostream>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "../include/common.hpp"
#include "../include/sprite.hpp"

using namespace std;

int main(int argc, const char** args)
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    
    me::sprite test { me::filePath("trchar056.png", fm::pokekit_type::NPC).c_str() };
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
        window.draw(test.data());
        window.display();
    }
    
    return EXIT_SUCCESS;
}
