
#pragma once

#include "strategy.h"
#include <vector>

/**
 * Used to run a batch of games with the same player strategies
 */
class Experiment {

public:

    /**
     * Constructor
     */
    Experiment();

    /**
     * Add a player with a given strategy to the experiment
     * @param strategy The strategy of the player
     */
    void add_player(Strategy *strategy);

    /**
     * Simulate a given number of games
     * @param count The number of games to simulate
     */
    void simulate_games(int count);

    /**
     * Print the results of the experiment to stdout
     */
    void print_results() const;

private:

    // Strategies of the players
    std::vector<Strategy *> strategies;
    // Win counts of the players
    std::vector<int> wins;

};