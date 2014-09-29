#pragma once

#include <cdx/Math.h>
#include <SFML/Graphics/ConvexShape.hpp>


namespace sf {
    class RenderWindow;
}

namespace cdx {

    class Shape {

    public:
        Shape();
        virtual ~Shape() {};

        void addPoint(float x, float y);
        void setOrigin(float x, float y);
        void setPosition(float x, float y);
        void setRotation(float angle);
        void setRotation(const Vec2f& heading);
        void setColor(unsigned char r, unsigned char g, unsigned char b);
        void draw();

    private:
        sf::RenderWindow* mWindow;
        sf::ConvexShape mConvexShape;
        unsigned int mIndex = 0;

    };

}
