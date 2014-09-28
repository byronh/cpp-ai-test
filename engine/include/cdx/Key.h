#pragma once

#include <map>


namespace cdx {

    enum Key {
        Unknown,

        Escape,
        Left,
        Right,
        Up,
        Down,

        KeyCount
    };

    class KeyMap {

    public:
        KeyMap();
        virtual ~KeyMap() {};

        Key getKey(int code);
        void setKey(int code, Key key);

    private:
        std::map<int, Key> mMap;

    };

}
