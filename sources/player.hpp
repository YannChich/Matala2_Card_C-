#pragma once

#include <iostream>
#include <vector> 
#include <string>
#include "card.hpp"
using namespace std;


namespace ariel{

class Player{

private:
    //Data
    string name;
    vector<Card> cards;
    vector<Card> Wining_Card;
    int win_rate;
    int draw_rate;

public:
    //Constructor to create a player , inline Constructor 
    Player(string  name) : name(name){
        this->win_rate = 0;
        this->draw_rate = 0;
    };
    // function for Player
    int stacksize(){ return cards.size();} //prints the amount of cards left.
    int cardesTaken(){ return Wining_Card.size();} // prints the amount of cards this player has won.
    string getName(){ return this->name; } // getter for the name
    string Stat_Player() const { string stats = "Win rate: " + to_string(this->win_rate) + "; Draw rate: " + to_string(this->draw_rate);
    return stats; }// print the stats of the player (win rate and draw rate ...)



    };
}