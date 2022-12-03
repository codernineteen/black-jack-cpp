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

    std::vector<Card> GetPlayerCards();
    int GetBudget();
    void DecreaseBudget(int amount);
    void IncreaseBudget(int amount);
    void SetACard(Deck& d);
    void InitializePlayerCardsToEmpty();
    void ChangeToMaxBudget();
};


#endif //BLACKJACK_PLAYER_H
