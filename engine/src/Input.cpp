#include <cdx/Input.h>
#include <SFML/Window/Event.hpp>


namespace cdx {

    Input& Input::getInstance() {
        static Input instance;
        return instance;
    }

    Input::Input() : mListener(NULL) {
        mKeyMap = new KeyMap();
        mKeyStates = new bool[Key::KeyCount];
    }

    Input::~Input() {
        delete mKeyMap;
        delete[] mKeyStates;
    }

    void Input::setListener(InputListener* listener) {
        mListener = listener;
    }

    void Input::onEvent(sf::Event& event) {
        if (event.type == sf::Event::KeyReleased) {
            Key key = mKeyMap->getKey(event.key.code);
            if (mKeyStates[key]) {
                mKeyStates[key] = false;
                mListener->onKeyUp(key);
            }
        } else if (event.type == sf::Event::KeyPressed) {
            Key key = mKeyMap->getKey(event.key.code);
            if (!mKeyStates[key]) {
                mKeyStates[key] = true;
                mListener->onKeyDown(key);
            }
        } else if (event.type == sf::Event::MouseButtonPressed) {
            mListener->onMouseDown(event.mouseButton.x, event.mouseButton.y,
                                   event.mouseButton.button == sf::Mouse::Left);
        } else if (event.type == sf::Event::MouseButtonReleased) {
            mListener->onMouseMove(event.mouseButton.x, event.mouseButton.y);
        } else if (event.type == sf::Event::MouseMoved) {
            mListener->onMouseUp(event.mouseButton.x, event.mouseButton.y,
                                 event.mouseButton.button == sf::Mouse::Left);
        }
    }

}
