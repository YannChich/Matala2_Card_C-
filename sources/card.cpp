#include "card.hpp"
#include <stdexcept>
using namespace std;

namespace ariel {

Card::Card(unsigned int num_card, string type) {
    if (num_card < 2 || num_card > 15) { // J = 11 , Q = 12 , K = 13 , AS = 14
        throw invalid_argument("Invalid card number");
    }

    if (type != "Heart" && type != "Spade" && type != "Diamond" && type != "Club") {
        throw invalid_argument("Invalid card type");
    }

    this->num_card = num_card;
    this->type = type;
    }

string Card::toString() { 
    string card = "";
    switch (this->num_card) {
        case 11:
            card += "J";
            break;
        case 12:
            card += "Q";
            break;
        case 13:
            card += "K";
            break;
        case 14:
            card += "AS";
            break;
        default:
            card += to_string(this->num_card);
            break;
    }
    card += " ";
    card += this->type;
    return card;
 }

int Card::compareTo(Card card) {
    // 2 win the AS = 14
    // if this card is 2 and the other is AS return -1
    if (this->num_card == 2 && card.get_NumCard() == 14) {
        return -1;
    }
    // if this card is AS and the other is 2 return 1
    else if (this->num_card == 14 && card.get_NumCard() == 2) {
        return -2;
    }
    // if this card is smaller than the other then the function return 0
    else if (this->num_card < card.get_NumCard()) {
        return 2;
    }
    // if this card is bigger than the other then the function return 1
    else if (this->num_card > card.get_NumCard()) {
        return 1;
    }

    return 0;
 }


}
