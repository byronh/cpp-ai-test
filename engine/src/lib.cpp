#include <SFML/Graphics.hpp>
#include <lib.h>
#include <iostream>


struct Foo {
    int val = 123;
};


int helloFunc() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Foo f;
    std::cout << f.val << std::endl;

    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 42;
}
