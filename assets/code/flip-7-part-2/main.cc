
#include <iostream>
#include "game.h"
#include "strategies/draw_till_bust.h"

int main() {
    Game game;
    DrawTillBustStrategy strategy;
    game.add_player(&strategy);
    game.add_player(&strategy);
    game.add_player(&strategy);
    game.play_game();
    std::cout << game.game_state().string() << std::endl;
    std::cout << game.game_stats().string() << std::endl;
    return 0;
}