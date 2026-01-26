
#include <iostream>
#include "experiment.h"
#include "strategies/draw_till_bust.h"

int main() {
    Experiment experiment;
    DrawTillBustStrategy strategy;
    experiment.add_player(&strategy);
    experiment.add_player(&strategy);
    experiment.add_player(&strategy);
    experiment.simulate_games(1000);
    experiment.print_results();
    return 0;
}