#include <Ship.h>


Ship::Ship(float x, float y) : mPosition(x, y) {
    init(1);
}

Ship::Ship(float x, float y, float scale) : mPosition(x, y) {
    init(scale);
}


void Ship::setSteering(const Vec2f& steering) {
    mSteering = steering;
}

const Vec2f& Ship::getPosition() const {
    return mPosition;
}

const Vec2f& Ship::getVelocity() const {
    return mVelocity;
}

const float Ship::getMaxSpeed() const {
    return mMaxSpeed;
}

void Ship::init(float scale) {
    mShape.addPoint(-10 * scale, 10 * scale);
    mShape.addPoint(10 * scale, 10 * scale);
    mShape.addPoint(0 * scale, -20 * scale);
    mMass = 5.0f;
    mVelocity(20.0f, 60.0f);
    mMaxSpeed = 60.0f;
}

void Ship::update(float delta) {
    Vec2f acceleration = mSteering / mMass;

    mVelocity += acceleration * delta;
    mVelocity.truncate(mMaxSpeed);
    mPosition += mVelocity * delta;

    if (mVelocity.length_squared() > 0.00000001) {
        mHeading = mVelocity.normalized();
        //Set mSide to be perpendicular to mHeading
    }

    mShape.setPosition(mPosition.x, mPosition.y);
    mShape.setRotation(mHeading);
    mShape.draw();
}
