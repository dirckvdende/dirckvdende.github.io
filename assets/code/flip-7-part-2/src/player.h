
#pragma once

#include "card.h"
#include <string>
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
    // Whether the player is still active this round (hasn't passed or busted)
    bool active;
    // Whether the player has a second chance card (NOTE: According to the
    // rules, the player can only have one)
    bool has_second_chance;
    // Name of the player
    std::string name;

    /**
     * Constructor
     */
    Player();

    /**
     * Add the score from the player's hand to the total score
     */
    void add_score();

    /**
     * Clear the player's hand, active boolean and second chance
     * @returns List of cards that should be put on the discard pile
     */
    std::vector<Card> clear_round();

    /**
     * Reset the entire player
     */
    void clear();

    /**
     * Add a card to the player's hand, or let the player bust. If the player
     * busts their hand is cleared and the active variable is unset
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

    /**
     * Check if the player has enough different number cards to win the round
     * @returns Whether the player has won the round
     */
    bool has_won_round() const;

    /**
     * String representation of the player
     * @returns The string
     */
    std::string string() const;

private:

    /**
     * Check if a given card will make the player bust
     * @param card The card to check for
     * @returns Whether the card will make the player bust
     */
    bool card_is_bust(const Card &card) const;

};