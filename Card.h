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
    int cardStartIndex;

public:
    Card(ECardType cardType, int number);
    ~Card();

    int GetCardNumber();
    int GetCardStartIndex();
    void TransformAceCard();
};


#endif //BLACKJACK_CARD_H
