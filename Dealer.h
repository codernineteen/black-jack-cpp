//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H

#include <vector>
#include "Deck.h"

class Dealer {
    std::vector<Card> ownCards;

public:
    Dealer();

    std::vector<Card> GetDealerCards();
    void SetACard(Deck& d);
};


#endif //BLACKJACK_DEALER_H
