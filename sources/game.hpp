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
    string last_turn;
    string log;
    string winer;
    void Classic_Case(vector<Card>& pl1 , vector<Card>& pl2); // check every classic cases in the game

public:
    //Constructor outline
    Game(Player& pl1,Player& pl2);
    void playTurn(); // play one turn 
    void printLastTurn() const; // print the last turn stats
    void playAll(); // play the game until the end
    void printWiner() const; // Print the winner of the game
    void updateWiner(); // Gonna update the string winer
    void printLog() const; // Print every turns of the game
    void printStats() const; // Print the stats of each player of the game
    size_t get_sizeDeck() const{ return this->Deck.size();} // return the size of the deck


    };


}