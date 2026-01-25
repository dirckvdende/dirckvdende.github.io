
#pragma once

#include "card.h"
#include <vector>

/**
 * Automatically re-shuffled deck of cards. Has a discard() function to put
 * discarded cards. This way cards that are still in player's hands aren't
 * re-shuffled. The deck starts off full as the default Flip 7 deck
 */
class CardDeck {

public:

    /**
     * Constructor
     */
    CardDeck();

    /**
     * Draw a card from the deck
     * @returns The card that was drawn
     * @throws An error if there are no cards in the deck
     */
    Card draw();

    /**
     * Put a card in the discard pile
     * @param card The card to discard
     */
    void discard(const Card &card);

    /**
     * Size of the draw pile. This can be zero if the discard pile needs to be
     * reshuffled!
     * @returns The size of the draw pile
     */
    int size() const;

    /**
     * Size of the discard pile
     * @return The discard pile size
     */
    int discard_size() const;

private:

    // Cards currently in the draw pile. Back of the vector contains the first
    // card to be drawn
    std::vector<Card> draw_pile;
    // Cards in the discard pile. Back of the vector contains the last card
    // discarded
    std::vector<Card> discard_pile;

    /**
     * Reshuffle the discard pile and put it at the front (!) of the draw pile
     */
    void shuffle();

};