
#include "experiment.h"
#include "game.h"
#include <stdexcept>
#include <iostream>

Experiment::Experiment() {}

void Experiment::add_player(Strategy *strategy) {
    strategies.push_back(strategy);
    wins.push_back(0);
}

void Experiment::simulate_games(int count) {
    if (strategies.size() == 0)
        throw std::runtime_error("Cannot simulate games with zero players");
    for (int i = 0; i < count; i++) {
        Game game;
        for (Strategy *strategy : strategies)
            game.add_player(strategy);
        game.play_game();
        int winner = game.game_state().winner();
        if (winner == -1)
            throw std::runtime_error("Error: finished game early");
        wins[winner]++;
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