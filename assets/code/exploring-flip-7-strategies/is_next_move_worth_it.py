
from simplified_game import SimplifiedFlip7
import matplotlib.pyplot as plt

def worth_it(game: SimplifiedFlip7) -> bool:
    expected_score = (1.0 - game.bust_chance) * (game.score + game.no_bust_average)
    return game.score < expected_score

SAMPLES = 10000

average_scores = []

busts = 0
score_sum = 0
for _ in range(SAMPLES):
    game = SimplifiedFlip7()
    while len(game.hand) < 7 and not game.busted and worth_it(game):
        game.take_card()
    if game.busted:
        busts += 1
    score_sum += game.score

print("Busts:", busts / SAMPLES * 100, "%")
print("Average score:", score_sum / SAMPLES)
print()