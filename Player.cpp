//
// Created by 전예찬 on 2022/11/27.
//

#include "Player.h"

Player::Player() {}

std::vector<Card> Player::GetCards()
{
    return ownCards;
}

int Player::GetBudget()
{
    return budget;
}

void Player::SetACard(Deck& d)
{
    Card tempCard = d.GetARandomCard();
    ownCards.push_back(tempCard);
}