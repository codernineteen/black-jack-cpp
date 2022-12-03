//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_USERINTERFACE_H
#define BLACKJACK_USERINTERFACE_H

#include "Player.h"
#include "Dealer.h"
#include <vector>
#include <string>

class UserInterface {
    std::vector<std::string> cardLines;

public:
    UserInterface();

    void Greeting();
    void ShowMenu();
    void ChargeCoin();
    void PrintCard(Player &player, Dealer &dealer);
    void PrintDescription(); //Minbyeongrok
    void PrintBudget(Player& player);

};


#endif //BLACKJACK_USERINTERFACE_H
