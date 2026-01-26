
#include "card.h"
#include "constants.h"
#include "game_state.h"
#include "player.h"
#include <vector>

bool GameState::has_finished() const {
    for (const Player &player : players)
        if (player.score >= win_score)
            return true;
    return false;
}

bool GameState::has_active_players() const {
    for (const Player &player : players)
        if (player.active)
            return true;
    return false;
}

int GameState::winner() const {
    int max_score = 199;
    int max_player = -1;
    for (int i = 0; i < players.size(); i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            max_player = i;
        }
    }
    return max_player;
}

void GameState::clear_round() {
    for (Player &player : players) {
        std::vector<Card> discards = player.clear_round();
        for (const Card &card : discards)
            deck.discard(card);
    }
}

void GameState::add_scores() {
    for (Player &player : players)
        player.add_score();
}

std::string GameState::string() const {
    std::string out;
    bool first = true;
    for (const Player &player : players) {
        out += (first ? "" : "\n") + player.string();
        first = false;
    }
    return out;
}