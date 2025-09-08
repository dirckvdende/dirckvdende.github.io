
from simplified_game import SimplifiedFlip7
import matplotlib.pyplot as plt

# Samples per target score
SAMPLES = 10000
TARGET_SCORES = range(1, 60)

average_scores = []

for target_score in TARGET_SCORES:
    busts = 0
    score_sum = 0
    for _ in range(SAMPLES):
        game = SimplifiedFlip7()
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

ax.set_ylabel("Average score")
rects = ax.bar(range(len(average_scores)), average_scores)
ax.set_xticks(range(len(average_scores)), TARGET_SCORES)
fig.set_size_inches(12, 5)
fig.set_dpi(120)
plt.savefig("target_n.png")