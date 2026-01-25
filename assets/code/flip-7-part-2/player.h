
#pragma once

class Game;

/**
 * Player in the game, which can have an associated strategy
 */
class Player {

public:

    /**
     * Constructor
     */
    Player();

    /**
     * Whether the player wants to currently pass
     * @param game The game state
     * @returns A boolean indicating if the player wants to pass
     */
    virtual bool shouldPass(const Game &game) = 0;

};