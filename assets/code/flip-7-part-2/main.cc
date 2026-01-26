
#include <iostream>
#include "experiment.h"
#include "strategies/draw_till_bust.h"
#include "strategies/play_until_score.h"

int main() {
    Experiment experiment;
    DrawTillBustStrategy drawTillBust;
    PlayUntilScoreStrategy playUntilScore(25);
    experiment.add_player(&drawTillBust);
    experiment.add_player(&drawTillBust);
    experiment.add_player(&playUntilScore);
    experiment.add_player(&playUntilScore);
    experiment.simulate_games(1000);
    experiment.print_results();
    return 0;
}