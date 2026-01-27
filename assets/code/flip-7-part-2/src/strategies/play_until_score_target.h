
#pragma once

#include "../game_state.h"
#include "../player.h"
#include "../strategy.h"
#include <string>

/**
 * Same as the PlayUntilScore strategy, except one player is the "target" of
 * action cards, meaning they get all freeze and flip 3 cards, and don't get any
 * double second chance cards
 */
class PlayUntilScoreWithTargetStrategy : public Strategy {

public:

    // Target score after which the player should pass
    int target_score;
    // Strategy that the target player uses
    Strategy *target_player;

    /**
     * Constructor
     * @param target_score Target score after which to pass
     * @param target_player Strategy that the target player uses
     */
    PlayUntilScoreWithTargetStrategy(
        int target_score,
        Strategy *target_player);

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
     * target player or the player with the highest score other than the current
     * player (if there are other active players)
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
     * except the target player
     * @param game_state The current state of the game
     * @param player The current player
     * @return The player to target
     */
    const Player *lowest_player_target(
        const GameState *game_state,
        const Player *player) const;

};