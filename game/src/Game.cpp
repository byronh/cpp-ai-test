#include <Game.h>
#include <iostream>


void Game::onInitialize() {
    cdx::Input::getInstance().setListener(this);

    mShips.push_back(new Ship(200, 300));
    mShips.push_back(new Ship(300, 300));
    mShips.push_back(new Ship(400, 300));
    mShips.push_back(new Ship(500, 300));
}

void Game::onPause() {
    mPaused = true;
}

void Game::onResume() {
    mPaused = false;
}

void Game::onUpdate(float delta) {
    if (!mPaused) {
        for (auto it = mShips.begin(); it != mShips.end(); ++it) {
            (*it)->setSteering(mSteeringBehavior.seek(*it, mTarget));
            (*it)->update(delta);
        }
    }
}

void Game::onShutdown() {

}

void Game::onKeyUp(cdx::Key key) {
    if (key == cdx::Key::Escape) {
        cdx::Application::getInstance().exit();
    }
}

void Game::onKeyDown(cdx::Key key) {

}

void Game::onMouseMove(int x, int y) {
    mTarget(x, y);
}
