#include <cdx/Shape.h>
#include <cdx/Application.h>


namespace cdx {

    Shape::Shape() {
        mWindow = Application::getInstance().getWindow();
    }

    void Shape::addPoint(float x, float y) {
        mConvexShape.setPointCount(mIndex + 1);
        mConvexShape.setPoint(mIndex++, sf::Vector2<float>(x, y));
    }

    void Shape::setOrigin(float x, float y) {
        mConvexShape.setOrigin(x, y);
    }

    void Shape::setPosition(float x, float y) {
        mConvexShape.setPosition(x, y);
    }

    void Shape::setRotation(float angle) {
        mConvexShape.setRotation(angle);
    }

    void Shape::setRotation(const Vec2f& heading) {
        mConvexShape.setRotation(atan2f(heading.x, -heading.y) / 0.0174532925f);
    }

    void Shape::setColor(unsigned char r, unsigned char g, unsigned char b) {
        mConvexShape.setFillColor(sf::Color(r, g, b));
    }

    void Shape::draw() {
        mWindow->draw(mConvexShape);
    }

}
