//
// Created by user on 11/8/2018.
//

#ifndef GOFISH_CARD_H
#define GOFISH_CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:


    enum Suit {spades, hearts, diamonds, clubs};

    Card();          // default, ace of spades

    Card(int rank, Suit s);

    string toString()              const;  // return string version e.g. Ac 4h Js
    bool sameSuitAs(const Card& c) const;  // true if suit same as c
    int  getRank()                 const;  // return rank, 1..13
    string suitString(Suit s)      const;  // return "s", "h",...

    string rankString(int r)       const;  // return "A", "2", ..."Q"


    bool operator == (const Card& rhs) const; /// for a card to be equal only rank needs to be the same
    bool operator != (const Card& rhs) const;



private:

    int myRank;
    Suit mySuit;


};

ostream& operator << (ostream& out, const Card& c);

#endif //GOFISH_CARD_H
