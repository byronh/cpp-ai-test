#include <cdx/Key.h>
#include <SFML/Window/Keyboard.hpp>


namespace cdx {

    KeyMap::KeyMap() {
        setKey(sf::Keyboard::Escape, Key::Escape);
        setKey(sf::Keyboard::Left, Key::Left);
        setKey(sf::Keyboard::Right, Key::Right);
        setKey(sf::Keyboard::Up, Key::Up);
        setKey(sf::Keyboard::Down, Key::Down);
    }

    Key KeyMap::getKey(int code) {
        auto pos = mMap.find(code);
        if (pos == mMap.end()) {
            return Key::Unknown;
        } else {
            return pos->second;
        }
    }

    void KeyMap::setKey(int code, Key key) {
        mMap.emplace(code, key);
    }
}
