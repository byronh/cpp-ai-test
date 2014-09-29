#pragma once

#include <cdx/Application.h>
#include <cdx/Input.h>

#include <Ship.h>
#include <SteeringBehavior.h>
#include <vector>


class Game : public cdx::ApplicationListener, public cdx::InputListener {

public:
    Game() {};
    virtual ~Game() {};

    virtual void onInitialize() override;
    virtual void onPause() override;
    virtual void onResume() override;
    virtual void onUpdate(float delta) override;
    virtual void onShutdown() override;

    virtual void onKeyUp(cdx::Key key) override;
    virtual void onKeyDown(cdx::Key key) override;
    virtual void onMouseMove(int x, int y) override;

private:
    bool mPaused = false;
    std::vector<Ship*> mShips;
    SteeringBehavior mSteeringBehavior;
    Vec2f mTarget;

};
