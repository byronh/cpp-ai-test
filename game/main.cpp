#include <Game.h>


int main() {

    Game* game = new Game();
    game->title = "AI Testing";
    game->width = 1024;
    game->height = 768;
    game->samples = 8;
    game->run();

    return 0;
}
