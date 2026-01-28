
#include "../src/experiment.h"
#include "../src/strategies/play_until_score.h"
#include "../src/strategies/play_until_score_plus_diff.h"
#include <iostream>
#include <random>

constexpr int runs_per_target = 100'000;

int main() {
    std::vector<int> as_vector;
    for (double d = -0.05; d <= 0.3; d += 0.005) {
        Experiment experiment;
        PlayUntilScorePlusDiffStrategy base(25, d);
        PlayUntilScoreStrategy opp1(25), opp2(25), opp3(25);
        for (Strategy *strategy : std::vector<Strategy *>{
            &base, &opp1, &opp2, &opp3})
            experiment.add_player(strategy);
        experiment.simulate_games(runs_per_target);
        std::cout << "Games won with slope " << d << ": " <<
            experiment.get_wins()[0] << std::endl;
        as_vector.push_back(experiment.get_wins()[0]);
    }
    std::cout << "[";
    for (const int &v : as_vector)
        std::cout << v << ", ";
    std::cout << "]" << std::endl;
    return 0;
}