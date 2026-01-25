
#pragma once

#include "card.h"
#include <vector>

/**
 * Player in a Flip 7 game
 */
struct Player {

    // Score of the player from previous rounds. Even if the player has passed
    // this score does not include the current round
    int score;
    // Current player hand. This is empty if the player has busted and contains
    // the player's cards if they have passed. This does not include action
    // cards
    std::vector<Card> hand;
    // Whether the player has stopped this round (either passed or busted)
    bool stopped;
    // Whether the player has a second chance card (NOTE: According to the
    // rules, the player can only have one)
    bool has_second_chance;

    /**
     * Constructor
     */
    Player();

    /**
     * Add the score from the player's hand to the total score
     */
    void add_score();

    /**
     * Clear the player's hand, stopped boolean and second chance
     * @returns List of cards that should be put on the discard pile
     */
    std::vector<Card> clear_round();

    /**
     * Reset the entire player
     */
    void clear();

    /**
     * Add a card to the player's hand, or let the player bust. If the player
     * busts their hand is cleared and the stopped variable is set
     * @param card The card to draw. Must not be an action card
     * @returns List of cards that should be put on the discard pile
     * @throws An error if the card is an action card or the player has already
     * busted/passed
     */
    std::vector<Card> draw_card(const Card &card);

    /**
     * The player's current hand score
     * @returns The value of the player's hand
     */
    int hand_score() const;

};