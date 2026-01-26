
#include "experiment.h"
#include "game.h"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <random>

Experiment::Experiment() {}

void Experiment::add_player(Strategy *strategy) {
    strategies.push_back(strategy);
    wins.push_back(0);
}

void Experiment::simulate_games(int count) {
    if (strategies.size() == 0)
        throw std::runtime_error("Cannot simulate games with zero players");
    // TODO: Shuffle player order each game
    for (int i = 0; i < count; i++) {
        auto [shuffledStrategies, shuffledIndices] = shufflePlayers();
        Game game;
        for (Strategy *strategy : shuffledStrategies)
            game.add_player(strategy);
        game.play_game();
        int winner = game.game_state().winner();
        if (winner == -1)
            throw std::runtime_error("Error: finished game early");
        wins[shuffledIndices[winner]]++;
    }
}

void Experiment::print_results() const {
    int games_played = 0;
    for (const int &win_count : wins)
        games_played += win_count;
    if (games_played == 0) {
        std::cout << "No games simulated" << std::endl;
        return;
    }
    std::cout << "Games won by players (" << games_played << " total):"
        << std::endl;
    for (int i = 0; i < (int)wins.size(); i++) {
        std::string name = strategies[i]->name();
        if (name.size() < 24u)
            name.insert(name.size(), 24u - name.size(), ' ');
        std::cout << "    " << name << " " << wins[i] << std::endl;
    }
}

std::pair<std::vector<Strategy *>, std::vector<int>>
Experiment::shufflePlayers() const {
    std::vector<Strategy *> shuffled = strategies;
    std::vector<int> indices;
    for (int i = 0; i < (int)shuffled.size(); i++)
        indices.push_back(i);
    std::random_device rd;
    std::mt19937 g(rd());
    // Fisher-Yates shuffle
    for (int i = shuffled.size() - 1; i > 0; i--) {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, i);
        int j = dist(g);
        std::swap(shuffled[i], shuffled[j]);
        std::swap(indices[i], indices[j]);
    }
    return { shuffled, indices };
}