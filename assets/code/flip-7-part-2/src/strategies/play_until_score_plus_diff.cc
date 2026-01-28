
#include "play_until_score_plus_diff.h"
#include "../game_state.h"
#include "../player.h"
#include <limits>
#include <string>

PlayUntilScorePlusDiffStrategy::PlayUntilScorePlusDiffStrategy(
    int target_score,
    double slope
) : target_score(target_score),
    slope(slope) {}

bool PlayUntilScorePlusDiffStrategy::should_pass(
    const GameState *game_state,
    const Player *player
) {
    return !player->has_second_chance && player->hand_score() >= target_score + slope * (highest_opponent_score(game_state, player) - player->score);
}

const Player *PlayUntilScorePlusDiffStrategy::flip_three_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *PlayUntilScorePlusDiffStrategy::freeze_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *PlayUntilScorePlusDiffStrategy::second_chance_target(
    const GameState *game_state,
    const Player *player
) {
    return lowest_player_target(game_state, player);
}

std::string PlayUntilScorePlusDiffStrategy::name() const {
    return "PlayUntilScore(" + std::to_string(target_score) + ", delta=" +
        std::to_string(slope) + ")";
}

const Player *PlayUntilScorePlusDiffStrategy::highest_player_target(
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

const Player *PlayUntilScorePlusDiffStrategy::lowest_player_target(
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

int PlayUntilScorePlusDiffStrategy::highest_opponent_score(
    const GameState *game_state,
    const Player *player
) const {
    int highest_score = 0;
    for (const Player &other_player : game_state->players)
        if (&other_player != player && other_player.score > highest_score)
            highest_score = other_player.score;
    return highest_score;
}