
#include "card.h"
#include <string>

Card::Card(CardType type, int value) :
    type(type),
    value(value) {}

std::string Card::string() const {
    switch (type) {
        case NUMBER:
            return std::to_string(value);
        case TIMES_TWO:
            return "x2";
        case BONUS:
            return "+" + std::to_string(value);
        case SECOND_CHANCE:
            return "SC";
        case FLIP_THREE:
            return "F3";
        case FREEZE:
            return "FR";
    }
}

bool Card::is_action() const {
    return type == SECOND_CHANCE
        || type == FLIP_THREE
        || type == FREEZE;
}