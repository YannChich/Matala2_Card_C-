#include <iostream>
#include <algorithm>
#include <vector>
#include "game.hpp"

using namespace std;

namespace ariel{

    Game::Game(Player& pl1,Player& pl2):p1(pl1),p2(pl2),round(0),last_turn(""),log(""),winer(""){
       // Create the deck of cards
        for (unsigned int i = 2; i <= 14; i++) {
            Deck.push_back(Card(i, "Heart"));
            Deck.push_back(Card(i, "Spade"));
            Deck.push_back(Card(i, "Diamond"));
            Deck.push_back(Card(i, "Club"));
        }
        // Randomize the deck
        random_shuffle(Deck.begin(), Deck.end()); // Help with Internet to do this https://cplusplus.com/forum/beginner/234369/
        // Give the cards to the players
        for (unsigned int i = 0; i < 26; i++) {
            p1.addCard(Deck[i]);
            p2.addCard(Deck[i+26]);
        }
    }

    void Game::Classic_Case(vector<Card>& Vec_p1 , vector<Card>& Vec_p2){
        if (Vec_p1.back().compareTo(Vec_p2.back()) == -1) {  // if we enter in this if , c_p1 == 2 and c_p2 == AS --> c_p1 is the winner
            for (unsigned int i = 0; i < Vec_p1.size(); i++) {
                p1.addWiningCard(Vec_p1[i]);
                p1.addWiningCard(Vec_p2[i]);
            }
            p1.addWinRate();
            this->last_turn += " The winner of the turn n°" +to_string(this->round) + " is : " + p1.getName() + ".\n";
        }
        else if (Vec_p1.back().compareTo(Vec_p2.back()) == -2){ // if we enter in this if , c_p1 == AS and c_p2 == 2 --> c_p2 is the winner
            for (unsigned int i = 0; i < Vec_p2.size(); i++) {
                p2.addWiningCard(Vec_p1[i]);
                p2.addWiningCard(Vec_p2[i]);
            }
            p2.addWinRate();
            this->last_turn += " The winner of the turn n°" +to_string(this->round) + " is : " + p2.getName() + ".\n";
        }
        else if (Vec_p1.back().compareTo(Vec_p2.back()) == 2) { // if we enter in this if , c_p1 < c_p2 --> c_p2 is the winner
            for (unsigned int i = 0; i < Vec_p2.size(); i++) {
                p2.addWiningCard(Vec_p1[i]);
                p2.addWiningCard(Vec_p2[i]);
            }
            p2.addWinRate();
            this->last_turn += " The winner of the turn n°" +to_string(this->round) + " is : " + p2.getName() + ".\n";
        }
        else if (Vec_p1.back().compareTo(Vec_p2.back()) == 1) { // if we enter in this if , c_p1 > c_p2 --> c_p1 is the winner
            for (unsigned int i = 0; i < Vec_p1.size(); i++) {
                p1.addWiningCard(Vec_p1[i]);
                p1.addWiningCard(Vec_p2[i]);
            }
            p1.addWinRate();
            this->last_turn += " The winner of the turn n°" +to_string(this->round) + " is : " + p1.getName() + ".\n";
        }
        Vec_p1.clear();
        Vec_p2.clear();
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
        // Create two vector for the cards that the players throw
        vector<Card> CardPlay_p1;
        vector<Card> CardPlay_p2;
        // Every player gonna pop a card from his vector
        Card c_p1 = p1.popCard();
        Card c_p2 = p2.popCard();
        CardPlay_p1.push_back(c_p1);
        CardPlay_p2.push_back(c_p2);

        // update the string last_turn
        this->round++;
        this->last_turn = "Turn n°"+to_string(this->round)+".The first player : "+p1.getName()+" play the card : "+c_p1.toString()+ " , the second player : "+p2.getName()+" play the card : "+c_p2.toString()+".\n";
        // We are going to check different situations

        // 1 : clasic case we got a winner
        if(c_p1.get_NumCard() != c_p2.get_NumCard()){
            this->Classic_Case(CardPlay_p1,CardPlay_p2);
            this->updateWiner();
        }

        // 2 : We have a tie , every player need to throw an other card
        else{ // if we enter in this if , c_p1 == c_p2 --> we need to play an other turn
            while(c_p1.get_NumCard() == c_p2.get_NumCard()){
                // if every player don't got enough cards to throw an other card they going to keep their card and the game is over
                if(p1.stacksize() == 0 && p2.stacksize() == 0){
                    for (unsigned int i = 0; i < CardPlay_p1.size(); i++) {
                        p1.addWiningCard(CardPlay_p1[i]);
                        p2.addWiningCard(CardPlay_p2[i]);
                    }
                    p1.addDrawRate();
                    p2.addDrawRate();
                    this->last_turn += " It's a draw \n";
                    this->updateWiner();
                    break;
                }
                // if every play got only 1 last card in their stack , they gonna keep their cards and the game is over
                if(p1.stacksize() == 1 && p2.stacksize() == 1){
                    // we need to add the last of to their vector and give them their cards back
                    c_p1 = p1.popCard();
                    c_p2 = p2.popCard();
                    CardPlay_p1.push_back(c_p1);
                    CardPlay_p2.push_back(c_p2);
                    for (unsigned int i = 0; i < CardPlay_p1.size(); i++) {
                        p1.addWiningCard(CardPlay_p1[i]);
                        p2.addWiningCard(CardPlay_p2[i]);
                    }
                    p1.addDrawRate();
                    p2.addDrawRate();
                    this->last_turn += " It's a draw \n";
                    this->updateWiner();
                    break;
                }
                p1.addDrawRate();
                p2.addDrawRate();
                // Every player need to put a card face down
                Card down_p1 = p1.popCard();
                Card down_p2 = p2.popCard();
                CardPlay_p1.push_back(down_p1);
                CardPlay_p2.push_back(down_p2);
                // And now put a card to check who is the winner
                c_p1 = p1.popCard();
                c_p2 = p2.popCard();
                CardPlay_p1.push_back(c_p1);
                CardPlay_p2.push_back(c_p2);
                this->last_turn += "The first player : "+p1.getName()+" play the card : "+c_p1.toString()+ " , the second player : "+p2.getName()+" play the card : "+c_p2.toString()+".\n";
                // if it's not a draw we can check every cases
                if(c_p1.get_NumCard() != c_p2.get_NumCard()){
                    this->Classic_Case(CardPlay_p1,CardPlay_p2);
                    break;
                }
            }
        }
        string end = "End of the turn n°"+to_string(this->round)+".\n";
        this->last_turn += "\n";
        log += last_turn;

        
        
    }

    void Game::updateWiner(){
        if(this->p1.stacksize() > 0 || this->p2.stacksize() > 0){
            this->winer = "The game is not over yet \n";
        }
        if(this->p1.cardesTaken() > this->p2.cardesTaken()){
            this->winer = "The winer is : "+this->p1.getName()+"\n";
        }
        else if(this->p1.cardesTaken() < this->p2.cardesTaken()){
            this->winer = "The winer is : "+this->p2.getName()+"\n";
        }
        else {
            this->winer = "There is no Winer , Draw \n";
        }
    }

    void Game::printLastTurn() const{
        cout << this->last_turn << endl;
    }

    void Game::printLog() const{
        cout << this->log << endl;
    }

    void Game::printWiner() const{
        cout << this->winer << endl;
    }

    void Game::playAll(){
        while (p1.stacksize() != 0 && p2.stacksize() != 0) {
            this->playTurn();
        }
    }

    void Game::printStats() const{
        cout << "The first player : " << p1.getName() << " got " << p1.cardesTaken() <<" cards that he win. Stats :"<< p1.Get_WinRate() << " Win rate and " << p1.Get_DrawRate() << " draws rate " << "on a total of "+to_string(this->round)+ " rounds." << endl;
        cout << "The second player : " << p2.getName() << " got " << p2.cardesTaken() <<" cards that he win. Stats :"<< p2.Get_WinRate() << " Win rate and " << p2.Get_DrawRate() << " draws rate " << "on a total of "+to_string(this->round)+ " rounds" << endl;
        
    }


}

