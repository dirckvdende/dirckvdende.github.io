
#pragma once

#include "game_state.h"
#include "player.h"
#include <string>

/**
 * Flip 7 strategy
 */
class Strategy {

public:

    /**
     * Destructor
     */
    virtual ~Strategy();

    /**
     * Determine whether a player should pass
     * @param game_state The current game state
     * @param player The player to determine the action for. It is this player's
     * turn
     * @return Whether the player should pass
     */
    virtual bool should_pass(
        const GameState *game_state,
        const Player *player) = 0;

    /**
     * Pick an active player to give the flip three card
     * @param game_state The current game state
     * @param player The player whose turn it currently is (i.e. that is giving
     * the card)
     * @return The player to give the card to, which must be active
     */
    virtual const Player *flip_three_target(
        const GameState *game_state,
        const Player *player) = 0;

    /**
     * Pick an active player to give the freeze card
     * @param game_state The current game state
     * @param player The player whose turn it currently is (i.e. that is giving
     * the card)
     * @return The player to give the card to, which must be active
     */
    virtual const Player *freeze_target(
        const GameState *game_state,
        const Player *player) = 0;

    /**
     * Pick an active player to give the second chance card. Normally a player
     * would want to give it to themselves. However, if the player already has
     * a second chance card the card must be given to someone else who doesn't
     * have a second chance card. If there is no player to give it to the card
     * is discarded
     * @param game_state The current game state
     * @param player The player whose turn it currently is (i.e. that is giving
     * the card)
     * @return The player to give the card to, which must be active and not
     * already have a second chance card
     */
    virtual const Player *second_chance_target(
        const GameState *game_state,
        const Player *player) = 0;

    /**
     * The name of the strategy
     * @return The strategy name as a string
     */
    virtual std::string name() const = 0;

};