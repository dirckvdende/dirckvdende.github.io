
#include "play_until_score.h"
#include "../game_state.h"
#include "../player.h"
#include <limits>
#include <string>

PlayUntilScoreStrategy::PlayUntilScoreStrategy(int target_score) :
    target_score(target_score) {}

bool PlayUntilScoreStrategy::should_pass(
    const GameState *game_state,
    const Player *player
) {
    (void)game_state;
    return player->hand_score() >= target_score && !player->has_second_chance;
}

const Player *PlayUntilScoreStrategy::flip_three_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *PlayUntilScoreStrategy::freeze_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *PlayUntilScoreStrategy::second_chance_target(
    const GameState *game_state,
    const Player *player
) {
    return lowest_player_target(game_state, player);
}

std::string PlayUntilScoreStrategy::name() const {
    return "PlayUntilScore(" + std::to_string(target_score) + ")";
}

const Player *PlayUntilScoreStrategy::highest_player_target(
    const GameState *game_state,
    const Player *player
) const {
    int highest_score = -1;
    const Player *highest_player = nullptr;
    for (const Player &player : game_state->players) {
        if (player.score > highest_score && player.active) {
            highest_score = player.score;
            highest_player = &player;
        }
    }
    if (highest_player == nullptr)
        return player;
    return highest_player;
}

const Player *PlayUntilScoreStrategy::lowest_player_target(
    const GameState *game_state,
    const Player *player
) const {
    if (!player->has_second_chance)
        return player;
    int lowest_score = std::numeric_limits<int>::max();
    const Player *lowest_player = nullptr;
    for (const Player &player : game_state->players) {
        if (player.score < lowest_score && player.active &&
        !player.has_second_chance) {
            lowest_score = player.score;
            lowest_player = &player;
        }
    }
    return lowest_player;
}

