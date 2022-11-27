//
// Created by 전예찬 on 2022/11/27.
//

#include "Card.h"
#include <iostream>

Card::Card(ECardType t, int n) : type(t), cardNumber(num) {}

Card::~Card()
{
    std::cout << "Card deleted" << std::endl;
}
