#include <iostream>
#include "deck.h"
#include "card.h"
#include "player.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    this->removeCardFromHand(c1);
    this->removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(int i = 0; i < myHand.size(); i++ ){
        for(int j = 0; j < myHand.size(); j++ ){
            if(j != i && myHand[i] == myHand[j]){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++ ){
        if(myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    long randNum = (rand() % this->getHandSize());
    return myHand.at(randNum);

}

//bool Player::cardInHand(Card c) const {
//    for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++ ){
//        if(*it == c){
//            return true;
//        }
//    }
//    return false;
//}

bool Player::cardInHand(Card c) const {
    for(int i =0; i< myHand.size(); i++ ){
        if(myHand[i] == c){
            return true;
        }
    }
    return false;
}

int Player::getHandSize() const {
    return myHand.size();
}

Card Player::removeCardFromHand(Card c) {
    for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++ ){
        if(*it == c){
            Card returnCard = c;
            myHand.erase(it);
            return returnCard;
        }
    }
}

int Player::getBookSize() const {
    return myBook.size();
}

string Player::showHand() const {
    string hand;
    string space = " ";
    for(int i =0; i < myHand.size(); i++ ){
        string card = myHand[i].toString();
        hand = hand + space + card;
    }
    return hand;
}

string Player::showBooks() const {
    string book;
    string space = " ";
    for(int i =0; i < myBook.size(); i++ ){
        string card = myBook[i].toString();
        book = book + space + card;
    }
    return book;
}

