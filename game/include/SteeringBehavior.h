#pragma once

#include <cdx/Math.h>


class Ship;

class SteeringBehavior {

public:
    Vec2f seek(Ship* ship, const Vec2f& target);

};
