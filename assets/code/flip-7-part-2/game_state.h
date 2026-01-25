
#pragma once

#include "deck.h"
#include "player.h"
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

};