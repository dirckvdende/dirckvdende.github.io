
#pragma once

#include "../game_state.h"
#include "../player.h"
#include "../strategy.h"

/**
 * Strategy where the player keeps drawing until they bust or get 7 cards
 */
class DrawTillBustStrategy : public Strategy {

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

};