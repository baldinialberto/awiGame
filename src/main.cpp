#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "../include/common.hpp"
#include "../include/sprite.hpp"
#include "../include/npc.hpp"

using namespace std;

int main(int argc, const char** args)
{
    sf::RenderWindow window(sf::VideoMode(480, 320), "SFML works!");
    
    me::npc test {"056", window};
    //cout << std::__fs::filesystem::current_path() << endl;

    while (window.isOpen())
    {
        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
            || event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        test.pollEvent();
        window.clear();
        test.draw();
        window.display();
        
        chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
        this_thread::sleep_for(chrono::milliseconds(1000 / 10 - static_cast<int>(chrono::duration<float>(t2 - t1).count() * 1000)));
    }
    
    return EXIT_SUCCESS;
}
