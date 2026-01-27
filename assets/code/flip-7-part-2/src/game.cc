
#include "game.h"
#include "game_state.h"
#include "player.h"
#include "strategy.h"
#include <stdexcept>
#include <iostream>
#include <random>
#include <string>
#include <vector>

Game::Game() :
    current_player(0),
    round_ended(false) {}

void Game::add_player(Strategy *strategy, std::string name) {
    Player player;
    player.name = name;
    state.players.push_back(player);
    strategies.push_back(strategy);
}

void Game::play_game() {
    // Generate random starting player
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,
        player_count() - 1);
    int start_player = dist(g);
    while (!state.has_finished()) {
        play_round(start_player);
        // To make it more fair, rotate starting player every round
        start_player = (start_player + 1) % player_count();
    }
}

void Game::play_round(int start_player) {
    current_player = start_player;
    bool everyone_inactive = false;
    while (!everyone_inactive && !round_ended) {
        play_turn();
        everyone_inactive = move_to_next_player();
    }
    state.add_scores();
    state.clear_round();
    round_ended = false;
    stats.rounds_done++;
}

void Game::play_turn() {
    if (round_ended)
        throw std::runtime_error("Cannot play when round has ended");
    if (player_count() == 0)
        throw std::runtime_error("Cannot play turn when there are no players");
    Player &player = state.players[current_player];
    Strategy *strategy = strategies[current_player];
    if (!player.active)
        throw std::runtime_error("Cannot play turn for inactive player");
    // Determine if the player wants to pass
    if (strategy->should_pass(&state, &player)) {
        player.active = false;
        return;
    }
    flip(&player);
}

const GameState &Game::game_state() const {
    return state;
}

const GameStats &Game::game_stats() const {
    return stats;
}

int Game::player_count() const {
    return state.players.size();
}

bool Game::move_to_next_player() {
    int start = current_player;
    current_player = (current_player + 1) % player_count();
    while (current_player != start && !state.players[current_player].active)
        current_player = (current_player + 1) % player_count();
    return current_player == start && !state.players[current_player].active;
}

void Game::discard_all(const std::vector<Card> &cards) {
    for (const Card &card : cards)
        state.deck.discard(card);
}

bool Game::second_chance_target_available() const {
    for (const Player &player : state.players)
        if (player.active && !player.has_second_chance)
            return true;
    return false;
}

void Game::flip(Player *player) {
    Strategy *strategy = strategies[player - state.players.begin().base()];
    Card card = state.deck.draw();
    switch (card.type) {
        case NUMBER:
        case TIMES_TWO:
        case BONUS:
            discard_all(player->draw_card(card));
            break;
        case SECOND_CHANCE:
            if (second_chance_target_available()) {
                Player *target = (Player *)strategy->second_chance_target(
                    &state, player);
                if (!target->active || target->has_second_chance)
                    throw std::runtime_error("Cannot give second chance card "
                    "to player that is either inactive or already has a second "
                    "chance card");
                target->has_second_chance = true;
            }
            break;
        case FREEZE: {
            Player *target = (Player *)strategy->freeze_target(&state, player);
            if (!target->active)
                throw std::runtime_error("Cannot give freeze card to inactive "
                "player");
            target->active = false;
            break;
        }
        case FLIP_THREE: {
            Player *target = (Player *)strategy->flip_three_target(&state,
                player);
            if (!target->active)
                throw std::runtime_error("Cannot give flip 3 card to inactive "
                "player");
            flip_three(target);
        }
    }
    if (player->has_won_round()) {
        stats.round_wins++;
        round_ended = true;
    }
}

void Game::flip_three(Player *target) {
    for (int i = 0; i < 3 && target->active && !round_ended; i++)
        flip(target);
}