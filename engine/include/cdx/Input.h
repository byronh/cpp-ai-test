#pragma once

#include <cdx/Key.h>


namespace sf {
    class Event;
    class Key;
}

namespace cdx {

    class InputListener;
    class KeyMap;

    class Input {

    public:
        static Input& getInstance();
        ~Input();

        void setListener(InputListener* listener);

        void onEvent(sf::Event& event);

    private:
        Input();
        Input(const Input& other);
        void operator=(const Input& other);

        InputListener* mListener;
        KeyMap* mKeyMap;
        bool* mKeyStates;

    };


    class InputListener {

    public:
        virtual ~InputListener() {};

        virtual void onKeyUp(Key key) {}
        virtual void onKeyDown(Key key) {}
        virtual void onMouseUp(int x, int y, bool left) {}
        virtual void onMouseMove(int x, int y) {}
        virtual void onMouseDown(int x, int y, bool left) {}

    };

}
