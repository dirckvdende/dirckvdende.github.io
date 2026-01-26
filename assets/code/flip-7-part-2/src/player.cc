
#include "card.h"
#include "constants.h"
#include "player.h"
#include <stdexcept>
#include <string>

Player::Player() :
    score(0),
    active(true),
    has_second_chance(false) { }

void Player::add_score() {
    score += hand_score();
}

std::vector<Card> Player::clear_round() {
    std::vector<Card> discards = hand;
    hand.clear();
    active = true;
    has_second_chance = false;
    return discards;
}

void Player::clear() {
    score = 0;
    hand.clear();
    active = true;
    has_second_chance = false;
}

std::vector<Card> Player::draw_card(const Card &card) {
    if (card.is_action())
        throw std::runtime_error("Cannot add action card to hand");
    if (!active)
        throw std::runtime_error("Cannot draw card for player which has "
        "passed or busted");
    if (card_is_bust(card)) {
        std::vector<Card> discards = hand;
        hand.clear();
        active = false;
        return discards;
    }
    hand.push_back(card);
    return {};
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
    return number_score * (has_times_two ? 2 : 1) + bonus_score +
        (has_won_round() ? win_round_bonus : 0);
}

bool Player::has_won_round() const {
    int number_cards = 0;
    for (const Card &card : hand)
        if (card.type == NUMBER)
            number_cards++;
    return number_cards >= cards_to_win_round;
}

std::string Player::string() const {
    std::string out = "Player:   Score = " + std::to_string(score) +
        "   Active = " + (active ? "true" : "false") +
        "   Second Chance = " + (has_second_chance ? "true" : "false") +
        "\n    Hand: ";
    bool first = true;
    for (const Card &card : hand) {
        if (!first)
            out += "  ";
        out += card.string();
        first = false;
    }
    return out;
}

bool Player::card_is_bust(const Card &card) const {
    for (const Card &hand_card : hand)
        if (hand_card.type == NUMBER && hand_card.value == card.value)
            return true;
    return false;
}