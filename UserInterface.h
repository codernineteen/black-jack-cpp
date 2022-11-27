//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_USERINTERFACE_H
#define BLACKJACK_USERINTERFACE_H

#include "Deck.h"
#include <vector>
#include <string>

class UserInterface {
    std::vector<std::string> cardLines;

public:
    UserInterface();

    void PrintCard(Deck& cardDeck);

};


#endif //BLACKJACK_USERINTERFACE_H
