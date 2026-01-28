
#include "expected_score.h"
#include "../game_state.h"
#include "../player.h"
#include "../card.h"
#include <limits>
#include <string>

bool ExpectedScoreStrategy::should_pass(
    const GameState *game_state,
    const Player *player
) {
    if (player->has_second_chance)
        return false;
    std::vector<Card> cards_left = game_state->deck.cards_left();
    int total = 0;
    int count = 0;
    for (const Card &card : cards_left) {
        if (card.is_action())
            continue;
        Player player_copy = *player;
        player_copy.draw_card(card);
        total += player_copy.hand_score();
        count++;
    }
    return player->hand_score() > (double)total / (double)count;
}

const Player *ExpectedScoreStrategy::flip_three_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *ExpectedScoreStrategy::freeze_target(
    const GameState *game_state,
    const Player *player
) {
    return highest_player_target(game_state, player);
}

const Player *ExpectedScoreStrategy::second_chance_target(
    const GameState *game_state,
    const Player *player
) {
    return lowest_player_target(game_state, player);
}

std::string ExpectedScoreStrategy::name() const {
    return "ExpectedScore";
}

const Player *ExpectedScoreStrategy::highest_player_target(
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

const Player *ExpectedScoreStrategy::lowest_player_target(
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
