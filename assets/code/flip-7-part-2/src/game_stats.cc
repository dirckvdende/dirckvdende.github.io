
#include "game_stats.h"
#include <string>

std::string GameStats::string() const {
    return "Rounds done: " + std::to_string(rounds_done) + "\n"
        + "Round wins: " + std::to_string(round_wins);
}