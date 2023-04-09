#include "card.hpp"
#include <stdexcept>
using namespace std;
using namespace ariel;

Card::Card(unsigned int num_card, string type) {
    if (num_card < 1 || num_card > 15) { // J = 11 , Q = 12 , K = 13 , AS = 14
        throw invalid_argument("Invalid card number");
    }

    if (type != "Heart" && type != "Spade" && type != "Diamond" && type != "Club") {
        throw invalid_argument("Invalid card type");
    }

    this->num_card = num_card;
    this->type = type;
    }

