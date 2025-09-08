
import random

class SimplifiedFlip7:

    def __init__(self):
        self.counts = list(range(13))
        self.counts[0] = 1
        self.hand = []
        self.total = sum(self.counts)
        self.busted = False

    def take_card(self) -> int:
        if self.busted or len(self.hand) >= 7:
            return -1
        index = random.randrange(self.total)
        card = card_count = 0
        while card_count + self.counts[card] <= index:
            card_count += self.counts[card]
            card += 1
        self.total -= 1
        self.counts[card] -= 1
        if card in self.hand:
            self.busted = True
        else:
            self.hand.append(card)

    @property
    def bust_chance(self) -> float:
        if self.busted:
            return 1.0
        return sum(self.counts[num] for num in self.hand) / self.total

    @property
    def score(self) -> int:
        if self.busted:
            return 0
        return sum(self.hand) + (15 if len(self.hand) >= 7 else 0)
    
    @property
    def no_bust_average(self) -> float:
        """ Average card value of cards that wouldn't bust """
        cards = 0
        total = 0.0
        for value, count in enumerate(self.counts):
            if value not in self.hand:
                cards += count
                total += value * count
        if cards == 0:
            return 0.0
        return total / cards