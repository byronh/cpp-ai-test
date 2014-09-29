#include <SteeringBehavior.h>
#include <Ship.h>


Vec2f SteeringBehavior::seek(Ship* ship, Vec2f const& target) {
    Vec2f desiredVelocity = target - ship->getPosition();
    desiredVelocity.normalize();
    desiredVelocity *= ship->getMaxSpeed();
    return desiredVelocity - ship->getVelocity();
}
