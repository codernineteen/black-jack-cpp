//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "Deck.h"
#include <vector>

class Player {
    int budget;
    std::vector<Card> ownCards;

public:
    Player();

    std::vector<Card> GetCards();
    int GetBudget();
    void SetACard(Deck& d); //이것도 테스트용 - 나중에 hit으로만 카드 받아야한다.
};


#endif //BLACKJACK_PLAYER_H
