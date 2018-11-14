//
// Created by user on 11/8/2018.
//

#ifndef GOFISH_DECK_H
#define GOFISH_DECK_H

#include "card.h"
using namespace std;


class Deck
{
    static const int SIZE = 52;

public:


    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the cards in the current deck
    Card dealCard();   // get a card, after 52 are dealt, fail

    int  size() const; // # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif //GOFISH_DECK_H
