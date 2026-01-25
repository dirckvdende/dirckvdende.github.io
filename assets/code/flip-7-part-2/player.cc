
#include "player.h"
#include "card.h"
#include <stdexcept>

Player::Player() :
    score(0),
    stopped(false),
    has_second_chance(false) { }

void Player::add_score() {
    score += hand_score();
}

void Player::clear_round() {
    hand.clear();
    stopped = false;
    has_second_chance = false;
}

void Player::clear() {
    score = 0;
    hand.clear();
    stopped = false;
    has_second_chance = false;
}

bool Player::draw_card(const Card &card) {
    if (card.is_action())
        throw std::runtime_error("Cannot add action card to hand");
    if (stopped)
        throw std::runtime_error("Cannot draw card for player which has "
        "passed or busted");
    if (card.type == NUMBER) {
        for (const Card &hand_card : hand) {
            if (hand_card.type == NUMBER && hand_card.value == card.value) {
                hand.clear();
                stopped = true;
                return true;
            }
        }
    }
    hand.push_back(card);
}

int Player::hand_score() const {
    int number_score = 0;
    bool has_times_two = false;
    int bonus_score = 0;
    for (const Card &card : hand) {
        if (card.type == NUMBER)
            number_score += card.value;
        else if (card.type == BONUS)
            bonus_score += card.value;
        else
            has_times_two = true;
    }
    return number_score * (has_times_two ? 2 : 1) + bonus_score;
}