#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <common.hpp>
#include <sprite.hpp>
#include <npc.hpp>
#include <map.hpp>
#include <camera.hpp>

using namespace std;

bool compareSprite(shared_ptr<me::sprite> a, shared_ptr<me::sprite> b) { return *(a.get()) < *(b.get()); };

int main(int argc, const char **args)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window{sf::VideoMode(480, 320), "Awigame",
                            sf::Style::Default, settings};

    me::camera camera{window};

    vector<shared_ptr<me::sprite>> spriteV{
        static_cast<shared_ptr<me::sprite>>(new me::npc("056", window))};
    std::sort(spriteV.begin(), spriteV.end(), compareSprite);

    me::map testMap{"MAP_02", {2000, 2000}, window};

    camera.focus(spriteV.at(0).get());
    camera.target_map(&testMap);

    /*     for (auto x : spriteV)
        cout << x->png() << endl; */

    while (window.isOpen())
    {
        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        for (auto x : spriteV)
            x.get()->pollEvent();

        camera.pollEvent();

        window.clear();

        testMap.draw();
        for (auto x : spriteV)
            x.get()->draw();

        window.display();

        chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
        this_thread::sleep_for(
            chrono::milliseconds(
                1000 / 10 - static_cast<int>(chrono::duration<float>(t2 - t1).count() * 1000)));
    }

    return EXIT_SUCCESS;
}
