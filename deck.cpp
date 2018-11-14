#include <iostream>
#include "deck.h"
#include "card.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


Deck::Deck() {
    int index = 0;
    for(int i=0; i<4; i++){
        for(int j=1; j<=13; j++){

                myCards[index] = Card(j, (Card::Suit)i);
                index++;

        }
    }
    myIndex = 0;
}

void Deck::shuffle() {
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    for(int i=0; i<this->size(); i++){
        long randNum = (rand() % this->size());
        Card temp = myCards[i];
        myCards[i] = myCards[randNum];
        myCards[randNum] = temp;
    }
}

int Deck::size() const {
    int sizeOfDeck = sizeof(this->myCards)/sizeof(this->myCards[0]);
    return sizeOfDeck-myIndex;
}

Card Deck::dealCard() {
    if(myIndex != 52){
        Card dealtCard = myCards[myIndex];
        myIndex ++;
        return dealtCard;
    }
    else{
        cout << "no cards left" << endl;
        exit (EXIT_FAILURE);
    }
}