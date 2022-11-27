//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

enum class ECardType
{
    SPADE,
    HEART,
    CLOVER,
    DIAMOND
};

class Card {
    ECardType type;
    int cardNumber;

public:
    Card(ECardType t, int n);
    ~Card();
};


#endif //BLACKJACK_CARD_H
