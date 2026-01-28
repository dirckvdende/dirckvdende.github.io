
#pragma once

#include "../game_state.h"
#include "../player.h"
#include "../strategy.h"
#include <string>

/**
 * Same as the PlayUntilScore strategy, except the target score is
 * increased/decreased based on the score of the highest (or second highest)
 * player
 */
class PlayUntilScorePlusDiffStrategy : public Strategy {

public:

    // Target score after which the player should pass
    int target_score;
    // The amount to add to the target for every point the player is behind the
    // leader
    double slope;

    /**
     * Constructor
     * @param target_score Target score after which to pass
     * @param slope The amount to add to the target for every point the player
     * is behind the leader
     */
    PlayUntilScorePlusDiffStrategy(int target_score, double slope);

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

    /**
     * Score of the leading player, or the second best score if the current
     * player is the leader
     * @param game_state The current state of the game
     * @param player The current player
     * @returns The leader's score
     */
    int highest_opponent_score(
        const GameState *game_state,
        const Player *player) const;

};