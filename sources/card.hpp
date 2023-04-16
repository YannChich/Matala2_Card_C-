#pragma once

#include <iostream>
#include <string>
using namespace std;


namespace ariel{

class Card{

private:
    //Data
    unsigned int num_card; // Card :  2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < J < Q < K < AS
    string type; // there are 4 types : Heart , Spade , Diamond , Club 

public:
    //Constructor to create card , inline
    Card(unsigned int num_card, string type);
    unsigned int get_NumCard() const { return this->num_card;} // Getter for the value of the card
    string get_Type(){ return this->type;} // Getter for the type of the card
    void set_type(const string& type){ this->type = type; }
    void set_numCard(unsigned int value){ this->num_card = value; }
    string toString(); // Print the card 
    int compareTo(Card card); // Compare between two cards

    };
}