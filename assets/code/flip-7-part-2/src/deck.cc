
#include "card.h"
#include "deck.h"
#include "util.h"
#include <algorithm>
#include <random>
#include <stdexcept>
#include <vector>

CardDeck::CardDeck() {
    // Add the cards to the discard pile so shuffle() can put them on the draw
    // pile in a random order
    discard_pile.push_back(Card(NUMBER, 0));
    for (int i = 1; i <= 12; i++)
        for (int j = 0; j < i; j++)
            discard_pile.push_back(Card(NUMBER, i));
    for (int i = 2; i <= 10; i += 2)
        discard_pile.push_back(Card(BONUS, i));
    discard_pile.push_back(Card(TIMES_TWO));
    for (int i = 0; i < 3; i++) {
        discard_pile.push_back(Card(FLIP_THREE));
        discard_pile.push_back(Card(SECOND_CHANCE));
        discard_pile.push_back(Card(FREEZE));
    }
    shuffle();
}

Card CardDeck::draw() {
    if (draw_pile.empty())
        throw std::runtime_error("Cannot draw from empty pile");
    Card card = draw_pile.back();
    draw_pile.pop_back();
    if (draw_pile.empty())
        shuffle();
    return card;
}

void CardDeck::discard(const Card &card) {
    discard_pile.push_back(card);
}

void CardDeck::shuffle() {
    shuffle_vector(discard_pile);
    draw_pile.insert(draw_pile.begin(), discard_pile.begin(),
        discard_pile.end());
}

int CardDeck::size() const {
    return draw_pile.size();
}

int CardDeck::discard_size() const {
    return discard_pile.size();
}

std::vector<Card> CardDeck::cards_left() const {
    std::vector<Card> cards = draw_pile;
    shuffle_vector(cards);
    return cards;
}