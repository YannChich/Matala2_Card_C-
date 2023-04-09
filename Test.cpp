#include "doctest.h"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;


TEST_CASE("Creation of Player"){
    Player p1("Yann"); // After the creation of a player , he got 2 stack(one for his cards and 
    // the second for the wining card) , also a win_rate and draw_rate
    Player p2("David");
    CHECK(p1.getName() == "Yann");
    CHECK(p2.getName() == "David");
    CHECK_FALSE(p1.getName() == "yann");
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    string stats = p1.Stat_Player();
    CHECK_FALSE(stats.empty()); // check if the string is empty
}

TEST_CASE("Creation of the card"){
    Card card_Ten(10, "Heart");
    CHECK(card_Ten.get_NumCard() == 10);
    CHECK(card_Ten.get_Type() == "Heart");
    card_Ten.set_type("Diamond");
    CHECK(card_Ten.get_Type() == "Diamond");
    card_Ten.set_numCard(8);
    CHECK(card_Ten.get_NumCard() == 8);

    CHECK_THROWS([](){Card card(18, "House");}()); // Lambda expression to test the constructor of Card
}

TEST_CASE("Creation of a Game"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK(game.get_sizeDeck() == 52);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

}

TEST_CASE("During the game"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for (int i=0;i<5;i++) {
    game.playTurn();
    }
    // Every player play 5 card or more if there are draws
    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
    // There is a winner 
    game.playAll();
    // size of deck + size of deck of each player may be equal to 52 == number of card in 1 game
    CHECK((game.get_sizeDeck()+p1.stacksize()+p1.cardesTaken()+p2.stacksize()+p2.cardesTaken()) == 52);
    CHECK(game.get_sizeDeck() == 0);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);

}