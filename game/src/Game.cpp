#include <Game.h>
#include <iostream>


void Game::onInitialize() {
    cdx::Input::getInstance().setListener(this);
}

void Game::onPause() {
    paused = true;
}

void Game::onResume() {
    paused = false;
}

void Game::onUpdate(float delta) {

}

void Game::onRender() {

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
