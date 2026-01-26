
#include "draw_till_bust.h"
#include "../game_state.h"
#include "../player.h"
#include <limits>

bool DrawTillBustStrategy::should_pass(
    const GameState *game_state,
    const Player *player
) {
    (void)game_state;
    (void)player;
    return false;
}

const Player *DrawTillBustStrategy::flip_three_target(
    const GameState *game_state,
    const Player *player
) {
    (void)game_state;
    return player;
}

const Player *DrawTillBustStrategy::freeze_target(
    const GameState *game_state,
    const Player *player
) {
    (void)game_state;
    return player;
}

const Player *DrawTillBustStrategy::second_chance_target(
    const GameState *game_state,
    const Player *player
) {
    if (!player->has_second_chance)
        return player;
    int lowest_score = std::numeric_limits<int>::max();
    const Player *lowest_player = nullptr;
    for (const Player &player : game_state->players) {
        if (player.score < lowest_score) {
            lowest_score = player.score;
            lowest_player = &player;
        }
    }
    return lowest_player;
}