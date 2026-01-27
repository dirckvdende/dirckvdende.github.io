
#include "tuned.h"
#include "../constants.h"
#include "../game_state.h"
#include "../player.h"
#include <limits>
#include <string>

constexpr int target_score = 25;
constexpr double slope = .1;

TunedStrategy::TunedStrategy(
    bool useDrawsWhen200,
    bool useFlip3OnSelf
) : useDrawsWhen200(useDrawsWhen200),
    useFlip3OnSelf(useFlip3OnSelf) {}

bool TunedStrategy::should_pass(
    const GameState *game_state,
    const Player *player
) {
    if (player->has_second_chance)
        return false;
    if (useDrawsWhen200) {
        // If another player has >200 and we're behind, we need to draw
        int highest = 0;
        for (const Player &other_player : game_state->players)
            highest = std::max(highest, other_player.score +
                other_player.hand_score());
        if (highest > win_score && highest > player->score +
            player->hand_score())
            return false;
    }
    int cur_target_score = target_score + slope * (
        highest_opponent_score(game_state, player) - player->score);
    return player->hand_score() >= cur_target_score;
}

const Player *TunedStrategy::flip_three_target(
    const GameState *game_state,
    const Player *player
) {
    if (useFlip3OnSelf) {
        // If player has no cards, give it to themselves
        if (player->hand.size() == 0)
            return player;
    }
    return highest_player_target(game_state, player);
}

const Player *TunedStrategy::freeze_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *TunedStrategy::second_chance_target(
    const GameState *game_state,
    const Player *player
) {
    return lowest_player_target(game_state, player);
}

std::string TunedStrategy::name() const {
    return "Tuned";
}

const Player *TunedStrategy::highest_player_target(
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

const Player *TunedStrategy::lowest_player_target(
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

int TunedStrategy::highest_opponent_score(
    const GameState *game_state,
    const Player *player
) const {
    int highest_score = 0;
    for (const Player &other_player : game_state->players)
        if (&other_player != player && other_player.score > highest_score)
            highest_score = other_player.score;
    return highest_score;
}