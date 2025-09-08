
from simplified_game import SimplifiedFlip7
import matplotlib.pyplot as plt
import random

# Samples per target score
SAMPLES = 10000
TARGET_SCORES = range(1, 60)
SEED = 42

def do_experiment(*, all_cards: bool = True, plot_color: str = "#a12e7e",
filename: str = "output.png", remove_cards: int = 0) -> None:
    random.seed(SEED)
    average_scores = []
    for target_score in TARGET_SCORES:
        busts = 0
        score_sum = 0
        for _ in range(SAMPLES):
            game = SimplifiedFlip7()
            if not all_cards:
                game.remove_random_cards(remove_cards)
            while (len(game.hand) < 7 and not game.busted and game.score <
            target_score):
                game.take_card()
            if game.busted:
                busts += 1
            score_sum += game.score
        print("Target:", target_score)
        print("Busts:", busts / SAMPLES * 100, "%")
        print("Average score:", score_sum / SAMPLES)
        print()
        average_scores.append(score_sum / SAMPLES)
    fig, ax = plt.subplots(layout="constrained")

    ax.set_xlabel("Target score")
    ax.set_ylabel("Average score")
    ax.bar(range(len(TARGET_SCORES)), average_scores, color=plot_color)
    ax.set_xticks(range(len(TARGET_SCORES)), TARGET_SCORES)
    fig.set_size_inches(12, 5)
    fig.set_dpi(120)
    plt.savefig(filename)

do_experiment(all_cards=True, filename="target_n.png", remove_cards=0)
do_experiment(all_cards=False, filename="target_n_70_removed.png", remove_cards=60)
do_experiment(all_cards=False, filename="target_n_60_removed.png", remove_cards=70)
