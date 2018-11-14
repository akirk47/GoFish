#include <iostream>
#include "card.h"
#include <string>


using namespace std;

Card::Card(){

    myRank =1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){

    myRank = rank;
    mySuit = s;
};

string Card::toString() const {

    string rank = this->rankString(myRank);
    string suit = this->suitString(mySuit);
    return rank + suit;
}

bool Card::sameSuitAs(const Card &c) const {
    if(this->mySuit == c.mySuit){
        return true;
    }
    else{
        return false;
    }
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    string suit;

    if(s == spades){
        suit = "s";
    }
    else if(s == hearts){
        suit = "h";
    }
    else if(s == diamonds){
        suit = "d";
    }
    else{
        suit = "c";
    }

    return suit;
}

string Card::rankString(int r) const {
    string rank;

    if(r== 1){
        rank = "A";
    }
    else if(r ==11){
        rank = "J";
    }
    else if(r ==12){
        rank = "Q";
    }
    else if(r ==13){
        rank = "K";
    }
    else if(r == 2){
        rank = "2";
    }
    else if(r == 3){
        rank = "3";
    }
    else if(r == 4){
        rank = "4";
    }
    else if(r == 5){
        rank = "5";
    }
    else if(r == 6){
        rank = "6";
    }
    else if(r == 7){
        rank = "7";
    }
    else if(r == 8){
        rank = "8";
    }
    else if(r == 9){
        rank = "9";
    }
    else{
        rank = "10";
    }
    return rank;
}

//checks if the ranks of cards match
bool Card::operator==(const Card &rhs) const {
    if(myRank == rhs.myRank){
        return true;
    }
    else{
        return false;
    }
}

bool Card::operator!=(const Card &rhs) const {
    if(myRank != rhs.myRank || mySuit != rhs.mySuit){
        return true;
    }
    else{
        return false;
    }
}