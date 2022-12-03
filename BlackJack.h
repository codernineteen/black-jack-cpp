//
// Created by 전예찬 on 2022/11/27.
//

#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H

#include "UserInterface.h"

enum class EPlayerDecision {
    HIT,
    STAY
};

//게임의 규칙 및 상태 관리
//game logic을 모두 여기로 옮기고 하나의 함수를 main에 넘겨서 실행하기
class BlackJack {
    int minBet;
    int maxBet;
    bool isGameEnd;
    int freeChargeCount;

public:
    BlackJack();
    void run();

private:
    int Bet(Player& p);
    EPlayerDecision GetPlayerDecision();
    void ChargeCoin(Player& p, UserInterface& UI);
    int PlayerTurn(Player& player, Dealer& dealer, Deck& deck, UserInterface& UI);
    int DealerTurn(Player& player, Dealer& dealer, Deck& deck, UserInterface& UI);
};


#endif //BLACKJACK_BLACKJACK_H
