//
// Created by 전예찬 on 2022/11/27.
//

#include "Deck.h"
#include <random>

Deck::Deck()
{
    //총 52개의 카드를 하나의 카드 타입마다 13개씩 생성하는 코드
    for(int i = 0; i < 52; i++)
    {
        if(i >= 0 and i <=12)
        {
            Card temp(ECardType::CLOVER, i+1);
            currentDeck.push_back(temp);
        }
        else if(i >= 13 and i <= 25)
        {
            Card temp(ECardType::HEART, i+1 - 13);
            currentDeck.push_back(temp);
        }
        else if(i >= 26 and i <= 38)
        {
            Card temp(ECardType::DIAMOND, i+1 - 26);
            currentDeck.push_back(temp);
        }
        else
        {
            Card temp(ECardType::SPADE, i+1 - 39);
            currentDeck.push_back(temp);
        }
    }
}

//테스트 용
Card Deck::GetACard(int index) {
    return currentDeck[index];
}

//카드 덱에서 랜덤한 카드 하나를 뽑는 함수 - 뽑고 나서 currentDeck으로부터 제거하여 중복 발생을 방지해야됌 (코드 추가 필요)
Card Deck::GetARandomCard()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, currentDeck.size()); // define the range
    int randomIndex = distr(gen); // generate numbers

    return currentDeck[randomIndex];
}

