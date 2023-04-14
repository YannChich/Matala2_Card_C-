#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"
using namespace std;


namespace ariel{

class Game{

private:
    //Data
    vector<Card> Deck; // the deck of 52 cards for the game
    Player& p1; // reference for the first Player
    Player& p2; // reference for the second Player
    int round; // the current round

public:
    //Constructor outline
    Game(Player& pl1,Player& pl2);
    void playTurn(); // play one turn 
    void printLastTurn(); // print the last turn stats
    void playAll(); // play the game until the end
    void printWiner(); // Print the winner of the game
    void printLog();
    void printStats();
    int get_sizeDeck(){ return this->Deck.size();}


    };


}