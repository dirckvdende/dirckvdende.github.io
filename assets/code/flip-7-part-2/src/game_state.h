
#pragma once

#include "deck.h"
#include "player.h"
#include <string>
#include <vector>

/**
 * State of the game with the players and the deck
 */
struct GameState {

    // Players in the game
    std::vector<Player> players;
    // Deck of cards
    CardDeck deck;

    /**
     * Whether the game has finished
     * @returns A boolean if the game has finished
     */
    bool has_finished() const;

    /**
     * Check if the current round has ended because there are no more active
     * players
     * @returns Whether there are any active players left this round
     */
    bool has_active_players() const;

    /**
     * Get the winning player of a game
     * @return Index of the winning player, or -1 if there is no winner yet. If
     * there are multiple people with the same highest score, the first player
     * in the list of players is returned
     */
    int winner() const;

    /**
     * Reset all players to active and clear their hands. Put player's hands on
     * the discard pile
     */
    void clear_round();

    /**
     * Add the hand scores of the all players to their totals
     */
    void add_scores();

    /**
     * String representation of the game state
     * @return The string
     */
    std::string string() const;

};