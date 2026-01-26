
#pragma once

#include "strategy.h"
#include <vector>
#include <utility>

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

    /**
     * Shuffle the list of players
     * @returns A vector with strategies that is a shuffled version of the
     * strategies property, and a vector of indices that point back to the
     * indices in the strategies property
     */
    std::pair<std::vector<Strategy *>, std::vector<int>> shufflePlayers() const;

};