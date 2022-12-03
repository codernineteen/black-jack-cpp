//
// Created by 전예찬 on 2022/11/27.
//

#include "Dealer.h"

Dealer::Dealer() {}

void Dealer::SetACard(Deck &d) {
    Card tempCard = d.GetARandomCard();
    ownCards.push_back(tempCard);
}

std::vector<Card> Dealer::GetDealerCards() {
    return ownCards;
}