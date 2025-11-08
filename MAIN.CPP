#include "Game.h"

int main() {
    Game game;
    game.Init();
        
    while (!game.ShouldClose()) {
        game.Update();
        game.Draw();
    }

            return 0;

}           