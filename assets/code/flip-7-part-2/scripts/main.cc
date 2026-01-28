
#include "../src/experiment.h"
#include "../src/strategies/draw_till_bust.h"
#include "../src/strategies/play_until_score.h"
#include <iostream>
#include <limits>

// Pre-defined strategies to be added to an experiment by the user
const std::vector<Strategy *> strategy_presets = {
    new DrawTillBustStrategy(),
    new PlayUntilScoreStrategy(25),
};

// Currently selected strategies
std::vector<Strategy *> strategies;

/**
 * Ask the user for integer input, without a given bound. If the user enters an
 * integer out of bounds the prompt is given again
 * @param min Minimum value the integer should have
 * @param max Maximum value the integer should have
 * @param prompt The prompt text to put before the input field
 * @return The entered integer
 */
int number_input(int min, int max, const std::string &prompt = "Enter option") {
    int option;
    std::cout << "(" << prompt << ") " << std::flush;
    std::cin >> option;
    while (option < min || option > max) {
        std::cout << "Invalid option" << std::endl;
        std::cout << "(Enter option) " << std::flush;
        std::cin >> option;
    }
    std::cout << std::endl;
    return option;
}

/**
 * Display the menu for adding a player to the experiment
 */
void add_player_menu() {
    std::cout << "Select player strategy:\n";
    for (int i = 0; i < (int)strategy_presets.size(); i++) {
        const Strategy *preset = strategy_presets[i];
        std::cout << "    (" << (i + 1) << ") " << preset->name() << "\n";
    }
    std::cout << std::endl;
    int option = number_input(0, (int)strategy_presets.size());
    strategies.push_back(strategy_presets[option - 1]);
}

/**
 * Display the menu for running an experiment
 */
void run_experiment_menu() {
    Experiment experiment;
    for (Strategy *strategy : strategies)
        experiment.add_player(strategy);
    int game_count = number_input(0, std::numeric_limits<int>::max(),
        "Number of games");
    experiment.simulate_games(game_count);
    experiment.print_results();
    std::cout << std::endl;
}

/**
 * Display the main menu
 */
void main_menu() {
    while (true) {
        std::cout << "Current players: ";
        for (const Strategy *strategy : strategies)
            std::cout << strategy->name() << " ";
        std::cout << "\n";
        std::cout << "Select an option:\n"
            << "    (1) Run experiment\n"
            << "    (2) Add player\n" << std::endl;
        int option = number_input(1, 2);
        if (option == 1) {
            run_experiment_menu();
            break;
        }
        if (option == 2)
            add_player_menu();
    }
}

int main() {
    std::cout << "\n    Flip 7 game simulator\n"
        << "    Compares different strategies for Flip 7 players\n"
        << std::endl;
    main_menu();
    for (Strategy *preset : strategy_presets)
        delete preset;
    return 0;
}