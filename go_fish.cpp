#include <iostream>
#include <fstream>   // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 7;

    ofstream myfile;
    myfile.open ("gofish_results.txt");
    Player p1("Alex");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    while(d.size() > 0 ){
        while(1){
            Card c1 = p1.chooseCardFromHand();
            myfile<< p1.getName() << " asks " << p2.getName() << " for " << c1.rankString(c1.getRank()) << "\n";

            if(p2.rankInHand(c1)){
                for(int i=0; i<3; i++){
                    if(p2.rankInHand(c1)){
                        p1.addCard(p2.removeCardFromHand(c1));
                        myfile<< p2.getName() << " gives a " << c1.toString() << " to " << p1.getName() << "\n";
                        Card bookCard1;
                        Card bookCard2;
                        if(p1.checkHandForBook(bookCard1, bookCard2)){
                            p1.bookCards(bookCard1, bookCard2);
                        }
                    }
                }
            }
            else{
                p1.addCard(d.dealCard());
                myfile<< p1.getName() << " draws a " << c1.toString() << "\n \n";
                break;
            }
        }





        while(1){
            Card c2 = p2.chooseCardFromHand();
            myfile<< p2.getName() << " asks " << p1.getName() << " for " << c2.rankString(c2.getRank()) << "\n";
            if(p1.rankInHand(c2)){
                for(int i=0; i<3; i++){
                    if(p1.rankInHand(c2)){
                        p2.addCard(p1.removeCardFromHand(c2));

                        myfile<< p1.getName() << " gives a " << c2.toString() << " to " << p2.getName() << "\n";
                        Card bookCard1;
                        Card bookCard2;
                        if(p2.checkHandForBook(bookCard1, bookCard2)){
                            p2.bookCards(bookCard1, bookCard2);
                        }
                    }
                }
            }
            else{
                p2.addCard(d.dealCard());
                myfile<< p2.getName() << " draws a " << c2.toString() << "\n \n";
                break;
            }
        }

    }

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(p1.getHandSize() != 0 && p2.getHandSize() != 0){
        while(1){
            Card c1 = p1.chooseCardFromHand();
            myfile<< p1.getName() << " asks " << p2.getName() << " for " << c1.rankString(c1.getRank()) << "\n";
            if(p2.rankInHand(c1)){
                for(int i=0; i<3; i++){
                    if(p2.rankInHand(c1)){
                        p1.addCard(p2.removeCardFromHand(c1));
                        myfile<< p2.getName() << " gives a " << c1.toString() << " to " << p1.getName() << "\n";
                        Card bookCard1;
                        Card bookCard2;
                        if(p1.checkHandForBook(bookCard1, bookCard2)){
                            p1.bookCards(bookCard1, bookCard2);
                        }
                    }
                }
            }
            else{
                Card bookCard1;
                Card bookCard2;

                if(p1.checkHandForBook(bookCard1, bookCard2)){
                    p1.bookCards(bookCard1, bookCard2);
                }
                break;
            }
        }





        while(1){
            Card c2 = p2.chooseCardFromHand();
            myfile<< p2.getName() << " asks " << p1.getName() << " for " << c2.rankString(c2.getRank()) << "\n";
            if(p1.rankInHand(c2)){
                for(int i=0; i<3; i++){
                    if(p1.rankInHand(c2)){
                        p2.addCard(p1.removeCardFromHand(c2));
                        myfile<< p1.getName() << " gives a " << c2.toString() << " to " << p2.getName() << "\n";
                        Card bookCard1;
                        Card bookCard2;
                        if(p2.checkHandForBook(bookCard1, bookCard2)){
                            p2.bookCards(bookCard1, bookCard2);
                        }
                    }
                }
            }
            else{
                Card bookCard1;
                Card bookCard2;
                if(p2.checkHandForBook(bookCard1, bookCard2)){
                    p2.bookCards(bookCard1, bookCard2);
                }
                break;
            }
        }
    }



    cout << p1.getName() <<" has : " << p1.showBooks() << endl;
    cout << p2.getName() <<" has : " << p2.showBooks() << endl;

    cout << d.size() << endl;

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    if(p1.getBookSize() > p2.getBookSize()){
        myfile << p1.getName() << " is the winner!! \n";
    }
    else if(p2.getBookSize() > p1.getBookSize()){
        myfile << p2.getName() << " is the winner!!\n";
    }
    else{
        myfile<< "it is a tie \n";
    }

    myfile.close();

    return EXIT_SUCCESS;


}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}