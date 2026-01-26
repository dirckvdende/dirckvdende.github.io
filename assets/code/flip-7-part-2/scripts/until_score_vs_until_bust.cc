
#include "../src/experiment.h"
#include "../src/strategies/draw_till_bust.h"
#include "../src/strategies/play_until_score.h"

int main() {
    Experiment experiment;
    DrawTillBustStrategy drawTillBust;
    PlayUntilScoreStrategy playUntilScore(25);
    experiment.add_player(&drawTillBust);
    experiment.add_player(&playUntilScore);
    experiment.add_player(&playUntilScore);
    experiment.simulate_games(10000);
    experiment.print_results();
    return 0;
}