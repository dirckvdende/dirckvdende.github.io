
from simplified_game import SimplifiedFlip7
import matplotlib.pyplot as plt
import random

def worth_it(game: SimplifiedFlip7) -> bool:
    expected_score = (1.0 - game.bust_chance) * (game.score + game.no_bust_average)
    return game.score < expected_score

SAMPLES = 10000
REMOVE_CARDS = range(73)
SEED = 42

random.seed(SEED)
average_scores = []

for remove_cards in REMOVE_CARDS:
    busts = 0
    score_sum = 0
    for _ in range(SAMPLES):
        game = SimplifiedFlip7()
        game.remove_random_cards(remove_cards)
        while len(game.hand) < 7 and not game.busted and worth_it(game):
            game.take_card()
        if game.busted:
            busts += 1
        score_sum += game.score

    print("Cards removed:", remove_cards)
    print("Busts:", busts / SAMPLES * 100, "%")
    print("Average score:", score_sum / SAMPLES)
    print()
    average_scores.append(score_sum / SAMPLES)

fig, ax = plt.subplots(layout="constrained")

ax.set_xlabel("Removed cards (total cards = 79)")
ax.set_ylabel("Average score")
ax.bar(range(len(REMOVE_CARDS)), average_scores, color="#a12e7e")
ax.set_xticks(range(len(REMOVE_CARDS)), REMOVE_CARDS)
fig.set_size_inches(12, 5)
fig.set_dpi(120)
plt.savefig("is_next_move_worth_it.png")