//
// Created by 전예찬 on 2022/11/27.
//

#include "Card.h"
#include <iostream>

Card::Card(ECardType cardType, int number) {
    type = cardType;
    cardNumber = number > 10 ? 10 : number;
    //카드 타입마다 생성자에서 start index를 구한다.
    //start index를 구하는 이유는 UserInterface 클래스에서 cards.txt안의 모든 줄을
    //벡터로 변환하게 되는데, 카드 한 장은 총 9줄로 구성돼있으므로 카드 숫자와 관련하여 벡터안에서 시작 위치만 기억하면된다.
    //시작 위치(cardStartIndex) 이후에 연달은 8개 데이터는 시작 위치에 종속되어있다.
    switch(type)
    {
        case ECardType::CLOVER:
            if(number == 1) cardStartIndex = 0;
            else cardStartIndex = 0 + (14 - number) * 9;
            break;
        case ECardType::HEART:
            if(number == 1) cardStartIndex = 117;
            else cardStartIndex = 117 + (14 - number) * 9;
            break;
        case ECardType::DIAMOND:
            if(number == 1) cardStartIndex = 234;
            else cardStartIndex = 234 + (14 - number) * 9;
            break;
        case ECardType::SPADE:
            if(number == 1) cardStartIndex = 351;
            else cardStartIndex = 351 + (14 - number) * 9;
            break;
    }
}

Card::~Card() {}


int Card::GetCardNumber() {
    return cardNumber;
}

int Card::GetCardStartIndex()
{
    return cardStartIndex;
}

void Card::TransformAceCard()
{
    if(cardNumber == 1)
    {
        cardNumber = 11;
    }
    else
    {
        cardNumber = 1;
    }
}
