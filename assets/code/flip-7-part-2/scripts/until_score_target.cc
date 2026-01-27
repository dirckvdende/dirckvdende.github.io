
#include "../src/experiment.h"
#include "../src/strategies/play_until_score.h"
#include "../src/strategies/play_until_score_target.h"

int main() {
    Experiment experiment;
    PlayUntilScoreStrategy playUntilScore(25);
    PlayUntilScoreWithTargetStrategy playUntilScoreTarget(25, 0);
    experiment.add_player(&playUntilScore);
    experiment.add_player(&playUntilScoreTarget);
    experiment.add_player(&playUntilScoreTarget);
    experiment.add_player(&playUntilScoreTarget);
    experiment.simulate_games(1'000'000);
    experiment.print_results();
    return 0;
}