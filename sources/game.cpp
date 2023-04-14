#include <iostream>
#include <algorithm>
#include "game.hpp"

using namespace std;

namespace ariel{

    Game::Game(Player& pl1,Player& pl2):p1(pl1),p2(pl2),round(0){
       // Create the deck of cards
        for (int i = 2; i <= 14; i++) {
            Deck.push_back(Card(i, "Heart"));
            Deck.push_back(Card(i, "Spade"));
            Deck.push_back(Card(i, "Diamond"));
            Deck.push_back(Card(i, "Club"));
        }
        // Randomize the deck
        random_shuffle(Deck.begin(), Deck.end()); // Help with Internet to do this https://cplusplus.com/forum/beginner/234369/
        // Give the cards to the players
        for (int i = 0; i < 26; i++) {
            p1.addCard(Deck[i]);
            p2.addCard(Deck[i+26]);
        }
    }

    void Game::playTurn(){
        // The 1 test to send a exception for the StudentTest1.cpp
        if (p1.stacksize() == 0 || p2.stacksize() == 0) {
            throw invalid_argument("The game is already over");
        }
        // The 2 test to send a exception for the StudentTest1.cpp
        if (&p1 == &p2) {
            throw invalid_argument("The players are the same");
        }
        // Every player gonna pop a card from his vector and compare them
        
    }


}

