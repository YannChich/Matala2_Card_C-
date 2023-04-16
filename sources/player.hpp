#pragma once
#include "card.hpp"
#include <vector>
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
    Player(string  name);

    // function for Player

    size_t stacksize() const { return cards.size();} //prints the amount of cards left.

    size_t cardesTaken() const { return Wining_Card.size();} // prints the amount of cards this player has won.

    string getName() const { return this->name; } // getter for the name

    // Function to print the win rate and draw rate of the player
    string Stat_Player() const { 
        string stats = "Win rate: " + to_string(this->win_rate) + "; Draw rate: " + to_string(this->draw_rate);
        return stats; 
    }

    void addCard(Card& card); // add a card to the player stack

    void addWiningCard(Card& card); // add a card to the player wining card

    void addWinRate(){ this->win_rate++; } // add 1 to the win rate

    void addDrawRate(){ this->draw_rate++; } // add 1 to the draw rate

    int Get_WinRate() const { return this->win_rate; } // get the win rate

    int Get_DrawRate() const { return this->draw_rate; } // get the draw rate

    Card popCard(); // pop a card from the player stack

    };
}