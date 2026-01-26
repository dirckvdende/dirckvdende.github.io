
#include "../src/experiment.h"
#include "../src/strategies/play_until_score.h"
#include <iostream>
#include <random>

constexpr int max_target = 50;
constexpr int runs_per_target = 10000;

int main() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,
        max_target);
    for (int i = 1; i <= 50; i++) {
        Experiment experiment;
        PlayUntilScoreStrategy base(i);
        PlayUntilScoreStrategy opp1(1), opp2(1), opp3(1);
        for (Strategy *strategy : {&base, &opp1, &opp2, &opp3})
            experiment.add_player(strategy);
        for (int j = 0; j < runs_per_target; j++) {
            for (PlayUntilScoreStrategy *strategy : {&opp1, &opp2, &opp3})
                strategy->target_score = dist(g);
            experiment.simulate_games(1);
        }
        std::cout << "Games won with target score " << i << ": " <<
            (i < 10 ? " " : "") << experiment.get_wins()[0] << std::endl;
    }
    return 0;
}