
#pragma once

#include <string>

/** Type of a Flip 7 card */
enum CardType {
    // Normal number card
    NUMBER,
    // Times two score multiplier
    TIMES_TWO,
    // Additive bonus card
    BONUS,
    // Extra life
    SECOND_CHANCE,
    // Flip 3 cards
    FLIP_THREE,
    // Freeze a player card
    FREEZE,
};

/**
 * Card in a Flip 7 game
 */
struct Card {

    // The type of the card
    CardType type;
    // Value of the card in case of number or bonus cards
    int value = 0;

    /**
     * Constructor
     * @param type The type of the card
     * @param value The card value in the case of a number or bonus card
     */
    Card(CardType type, int value = 0);

    /**
     * Represent the card as a string
     * @returns The string representation
     */
    std::string string() const;

    /**
     * Whether the card is an action card
     * @returns A boolean indicating if this is an action card
     */
    bool is_action() const;

};

