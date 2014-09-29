#include <cdx/Math.h>
#include <cdx/Shape.h>


#pragma once

class Ship {

public:
    Ship(float x, float y);
    Ship(float x, float y, float scale);
    virtual ~Ship() {}

    void update(float delta);
    void setSteering(const Vec2f& steering);

    const Vec2f& getPosition() const;
    const Vec2f& getVelocity() const;
    const float getMaxSpeed() const;

protected:
    Vec2f mPosition;
    Vec2f mVelocity;
    Vec2f mHeading;
    Vec2f mSide;

    Vec2f mSteering;

    float mMass;
    float mMaxSpeed;
    float mMaxForce;
    float mMaxTurnRate;

    cdx::Shape mShape;

    void init(float scale);

};
