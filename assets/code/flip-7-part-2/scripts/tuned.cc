
#include "../src/experiment.h"
#include "../src/strategies/expected_score.h"
#include "../src/strategies/tuned.h"
#include "../src/strategies/play_until_score.h"
#include "../src/strategies/play_until_score_plus_diff.h"

int main() {
    Experiment experiment;
    TunedStrategy tuned(true, true);
    ExpectedScoreStrategy expectedScore;
    PlayUntilScorePlusDiffStrategy playUntilScorePlusDiff(25, 0.1);
    PlayUntilScoreStrategy playUntilScore(25);
    experiment.add_player(&tuned);
    experiment.add_player(&playUntilScore);
    experiment.add_player(&playUntilScorePlusDiff);
    experiment.add_player(&expectedScore);
    experiment.simulate_games(1'0'000);
    experiment.print_results();
    return 0;
}