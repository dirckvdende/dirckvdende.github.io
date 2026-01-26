
#pragma once

#include "../game_state.h"
#include "../player.h"
#include "../strategy.h"
#include <string>

/**
 * Strategy where the player keeps drawing until they reach a given target score
 * in their hand.
 * 
 * Flip 3 cards are played on the other player with the highest score, or the
 * current player if there are no other active players
 * 
 * Freezes are also played on the other player with the highest score
 * 
 * Second chance is played on the current player, unless this is not possible.
 * Then it is played on the other player with the lowest score
 * 
 * Score is determined as a combination of the player's score from previous
 * round plus the current round score
 */
class PlayUntilScoreStrategy : public Strategy {

public:

    /**
     * Constructor
     * @param target_score Target score after which to pass
     */
    PlayUntilScoreStrategy(int target_score);

    virtual bool should_pass(
        const GameState *game_state,
        const Player *player) final;

    virtual const Player *flip_three_target(
        const GameState *game_state,
        const Player *player) final;

    virtual const Player *freeze_target(
        const GameState *game_state,
        const Player *player) final;

    virtual const Player *second_chance_target(
        const GameState *game_state,
        const Player *player) final;

    virtual std::string name() const final;

private:
    
    // Target score after which the player should pass
    int target_score;

    /**
     * Find the best player to play a flip 3 or freeze card on, which is the
     * player with the highest score other than the current player (if there
     * are other active players)
     * @param game_state The current state of the game
     * @param player The current player
     * @returns The player to target
     */
    const Player *highest_player_target(
        const GameState *game_state,
        const Player *player) const;

    /**
     * Find the best player to give a second chance card, which is the current
     * player if possible. If not, it is the other player with the lowest score
     * @param game_state The current state of the game
     * @param player The current player
     * @return The player to target
     */
    const Player *lowest_player_target(
        const GameState *game_state,
        const Player *player) const;

};