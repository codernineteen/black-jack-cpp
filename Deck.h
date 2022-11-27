//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "Card.h"
#include <vector>

class Deck {
    std::vector<Card> currentDeck;

public:
    Deck();
    void Shuffle();

private:
    Card* GetACard();
    void SetDeck();
};


#endif //BLACKJACK_DECK_H
