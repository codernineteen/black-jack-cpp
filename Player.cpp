//
// Created by 전예찬 on 2022/11/27.
//

#include "Player.h"

Player::Player() {
    budget = 50000;
}

std::vector<Card> Player::GetPlayerCards()
{
    return ownCards;
}

int Player::GetBudget()
{
    return budget;
}

void Player::ChangeToMaxBudget()
{
    budget = 50000;
}

void Player::DecreaseBudget(int amount) {
    budget -= amount;
}

void Player::IncreaseBudget(int amount) {
    budget += amount;
}

void Player::SetACard(Deck& d)
{
    Card tempCard = d.GetARandomCard();
    ownCards.push_back(tempCard);
}

void Player::InitializePlayerCardsToEmpty()
{
    ownCards.clear();
}