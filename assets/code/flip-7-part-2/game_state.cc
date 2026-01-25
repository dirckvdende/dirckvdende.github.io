
#include "constants.h"
#include "game_state.h"
#include "player.h"

bool GameState::has_finished() const {
    for (const Player &player : players)
        if (player.score >= win_score)
            return true;
    return false;
}