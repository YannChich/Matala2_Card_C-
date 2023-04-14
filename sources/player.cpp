#include "player.hpp"

namespace ariel {

    //Constructor to create a player , inline Constructor
    Player::Player(string name): name(name), win_rate(0), draw_rate(0) {}

    // Function addCard to add a card to the player stack
    void Player::addCard(Card& card){
        cards.push_back(card);
    }
    
    // Function addWiningCard to add a card to the player wining card
    void Player::addWiningCard(Card& card){
        Wining_Card.push_back(card);
    }
}