
#pragma once

#include <string>

/**
 * Game statistics and info
 */
struct GameStats {

    // Number of rounds that have finished
    int rounds_done = 0;
    // Number of times a player has won a round by getting 7 cards
    int round_wins = 0;

    /**
     * String representation of the stats
     * @returns The string
     */
    std::string string() const;

};