
#pragma once

#include <vector>
#include "game_state.h"
#include "strategy.h"

/**
 * A Flip 7 game with players with varying strategies
 */
class Game {

public:

    /**
     * Constructor
     */
    Game();

    /**
     * Add a player to the game with the given strategy
     * @param strategy The player's strategy
     */
    void add_player(Strategy *strategy);

    /**
     * Play the game until a player wins
     */
    void play_game();

    /**
     * Play a round of the game, until no more players are active
     * @param start_player Index of the player to start. By default this is the
     * first player in the list of players
     */
    void play_round(int start_player = 0);

    /**
     * Play a single player's turn. Assumes the current_player index points to
     * a player that is still active. The current_player index is not updated.
     * This function will update round_ended when applicable
     * @throws An error if the current player is not active, or if there are no
     * players
     */
    void play_turn();

    /**
     * Get the current game state
     * @return The state of the game
     */
    const GameState &game_state() const;

    /**
     * Number of players in the game
     * @returns The number of players
     */
    int player_count() const;

private:

    // Current state of the game
    GameState state;
    // Strategies of the different players. This will have the same length as
    // state.players
    std::vector<Strategy *> strategies;
    // Currently active player index
    int current_player;
    // Whether the current round has ended
    bool round_ended;

    /**
     * Move the current_player index to the next active player. If there are no
     * more active players the index is kept the same
     * @returns A boolean indicating if there are no more active players left
     */
    bool move_to_next_player();

    /**
     * Discard all cards from a vector
     * @param cards The cards to discard
     */
    void discard_all(const std::vector<Card> &cards);

    /**
     * Whether there is any player that can receive a second chance card
     * @returns Whether the second chance card can be given to anyone
     */
    bool second_chance_target_available() const;

    /**
     * Let a player flip a card
     * @param player The player to flip a card
     */
    void flip(Player *player);

    /**
     * let a player flip 3 cards
     * @param target The target player to flip the cards
     */
    void flip_three(Player *target);

};