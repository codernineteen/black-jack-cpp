//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_USERINTERFACE_H
#define BLACKJACK_USERINTERFACE_H

#include "Player.h"
#include <vector>
#include <string>

class UserInterface {
    std::vector<std::string> cardLines;

public:
    UserInterface();

    void Greeting();
    int ShowMenu();
    void PrintCard(Player& player);
    void PrintBudget(Player& player);

};


#endif //BLACKJACK_USERINTERFACE_H
