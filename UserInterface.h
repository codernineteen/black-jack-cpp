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
    void ShowMenu();
    void PrintCard(Player& player);

    int GetPlayerInput();

};


#endif //BLACKJACK_USERINTERFACE_H
