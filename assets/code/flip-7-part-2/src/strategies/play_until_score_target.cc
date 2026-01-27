
#include "play_until_score_target.h"
#include "../game_state.h"
#include "../player.h"
#include "../strategy.h"
#include <limits>
#include <string>

PlayUntilScoreWithTargetStrategy::PlayUntilScoreWithTargetStrategy(
    int target_score,
    Strategy *target_player
) : target_score(target_score),
    target_player(target_player) {}

bool PlayUntilScoreWithTargetStrategy::should_pass(
    const GameState *game_state,
    const Player *player
) {
    (void)game_state;
    return player->hand_score() >= target_score && !player->has_second_chance;
}

const Player *PlayUntilScoreWithTargetStrategy::flip_three_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *PlayUntilScoreWithTargetStrategy::freeze_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *PlayUntilScoreWithTargetStrategy::second_chance_target(
    const GameState *game_state,
    const Player *player
) {
    return lowest_player_target(game_state, player);
}

std::string PlayUntilScoreWithTargetStrategy::name() const {
    return "PlayUntilScore(" + std::to_string(target_score) + ", target = "
        + std::to_string(target_player) + ")";
}

const Player *PlayUntilScoreWithTargetStrategy::highest_player_target(
    const GameState *game_state,
    const Player *player
) const {
    // If possible, give it to the target player
    for (const Player &player : game_state->players)
        if (player)
    if (game_state->players[target_player].active)
        return &game_state->players[target_player];
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

const Player *PlayUntilScoreWithTargetStrategy::lowest_player_target(
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
    // Have to give it to the target player
    if (lowest_player == nullptr)
        return &game_state->players[target_player];
    return lowest_player;
}

