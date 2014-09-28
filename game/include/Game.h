#pragma once

#include <cdx/Application.h>
#include <cdx/Input.h>


class Game : public cdx::ApplicationListener, public cdx::InputListener {

public:
    Game() {};
    virtual ~Game() {};

    virtual void onInitialize() override;
    virtual void onPause() override;
    virtual void onResume() override;
    virtual void onUpdate(float delta) override;
    virtual void onRender() override;
    virtual void onShutdown() override;

    virtual void onKeyUp(cdx::Key key) override;
    virtual void onKeyDown(cdx::Key key) override;

private:
    bool paused = false;

};
