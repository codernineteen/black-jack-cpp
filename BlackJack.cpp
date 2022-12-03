//
// Created by 전예찬 on 2022/11/27.
//

#include "BlackJack.h"
#include <iostream>


BlackJack::BlackJack() {
    isGameEnd = false;
    minBet = 1000;
    maxBet = 10000;
    freeChargeCount = 1;
}

void BlackJack::ChargeCoin(Player& p, UserInterface& UI) {
    UI.ChargeCoin();
    if(freeChargeCount != 0)
    {
        int chargeInput;
        std::cout << "Do you want to charge coin?" << std::endl;
        std::cout << "0. Yes " << "\n" << "1. No, later" << std::endl;
        std::cout << "->";
        std::cin >> chargeInput;
        while(chargeInput !=0 and chargeInput != 1) {
            std::cout << "[Invalid Input] : If you want to charge , type 0 or 1" << std::endl;
            std::cout << "->";
            std::cin >> chargeInput;
        }

        if(chargeInput == 0) {
            p.ChangeToMaxBudget();
            std::cout << "Your current budget : " << p.GetBudget() << std::endl;
            freeChargeCount -= 1;
        }
    }
    else
    {
        std::cout << "You used all of your free charge.." << std::endl;
    }

    std::cout << "Going back to menu..." << std::endl;
}

int BlackJack::Bet(Player& p) {

    int betAmount;
    std::cout << "How much you want to bet this game?" << std::endl;
    std::cout << "Current budget : " << p.GetBudget() << std::endl;
    std::cout << "->";
    std::cin >> betAmount;
    while(betAmount > p.GetBudget() and betAmount < minBet and betAmount > maxBet)
    {
        std::cout << "[Invalid Input] : You can't bet money over your budget or betting range!" << std::endl;
        std::cout << "->";
        std::cin >> betAmount;
    }
    std::cout << "Your betting : " << betAmount << std::endl;
    p.DecreaseBudget(betAmount);

    // created by 민병록
    return betAmount;
}

EPlayerDecision BlackJack::GetPlayerDecision() {
    int playerInput;
    std::cout << "Choose one among two options below" << std::endl;
    std::cout << "0 - hit" << std::endl;
    std::cout << "1 - stay" << std::endl;
    std::cout << "->";
    std::cin >> playerInput;
    while(playerInput != 0 and playerInput != 1) {
        std::cout << "[Invalid Input] : If you want to hit , type 0 or If you want to stay, type 1" << std::endl;
        std::cout << "->";
        std::cin >> playerInput;
    }

    EPlayerDecision playerDecision;
    if (playerInput == 0) playerDecision = EPlayerDecision::HIT;
    else playerDecision = EPlayerDecision::STAY;

    return playerDecision;
}

int BlackJack::PlayerTurn(Player& player, Dealer& dealer, Deck& deck, UserInterface& UI) {
    EPlayerDecision playerDecision = GetPlayerDecision();

    int playerCardSum = 0;
    std::vector<Card> playerCards = player.GetPlayerCards();
    for(auto card : playerCards)
    {
        playerCardSum += card.GetCardNumber();
    }

    while(playerDecision == EPlayerDecision::HIT) {

        std::cout << "you hit!" << std::endl; // hit check log
        player.SetACard(deck);
        UI.PrintCard(player, dealer);

        int currentSum = 0;
        for(auto card : player.GetPlayerCards())
        {
            int cardNumber = card.GetCardNumber();
            if(cardNumber == 1 || cardNumber == 11)
            {
                int userInput;
                std::cout << "Your current ace card value :" << cardNumber << std::endl;
                std::cout << "Do you want to revert it?" << std::endl;
                std::cout << "0 - yes" << std::endl;
                std::cout << "1 - no" << std::endl;
                std::cout << "->";
                std::cin >> userInput;
                while (userInput != 0 and userInput != 1)
                {
                    std::cout << "[Invalid Input] : Enter a correct input" << std::endl;
                    std::cout << "->";
                    std::cin >> userInput;
                }
                if (userInput == 0) {
                    card.TransformAceCard();
                }
            }
            currentSum += card.GetCardNumber();
        }

        playerCardSum = currentSum;
        if(playerCardSum > 21)
        {
            return playerCardSum;
        }
        playerDecision = GetPlayerDecision();
    }


    std::cout << "player turn end" << std::endl;

    return playerCardSum;
}

int BlackJack::DealerTurn(Player& player, Dealer& dealer, Deck& deck, UserInterface& UI) { // Minbyeongr
    int dealerCardSum = 0;
    for(auto card : dealer.GetDealerCards()) {
        if(card.GetCardNumber() == 1)
        {
            card.TransformAceCard();
        }
        dealerCardSum += card.GetCardNumber();
    }
    while(dealerCardSum <= 16) {
        std::cout << "Dealer get a new card" << std::endl;
        dealer.SetACard(deck);
        UI.PrintCard(player, dealer);
        Card currentCard = dealer.GetDealerCards().back();
        if(currentCard.GetCardNumber() + dealerCardSum > 21)
        {
            for(auto card : dealer.GetDealerCards())
            {
                if(card.GetCardNumber() == 11)
                {
                    card.TransformAceCard();
                    dealerCardSum -= 10;
                }
            }
        }
        dealerCardSum += currentCard.GetCardNumber();
    }

    std::cout << "dealer stop" << std::endl;

    return dealerCardSum;
}

//main에서 실행시킬 유일한 함수
void BlackJack::run() {
    //------------ 변수 생성 ------------
    //카드 덱 생성
    int inputMenu;
    UserInterface UI = UserInterface();
    Player p = Player();

    //------------ 함수 호출 및 로직------------

    UI.Greeting();
    UI.ShowMenu();
    std::cout << "->";
    std::cin >> inputMenu;

    while(!isGameEnd) {
        switch(inputMenu) {
            case 1: {
                Deck tempDeck = Deck();
                Dealer d = Dealer();
                //딜러 카드 두 개 생성
                d.SetACard(tempDeck);
                d.SetACard(tempDeck);
                //플레이어 카드 두 개 생성
                p.SetACard(tempDeck);
                p.SetACard(tempDeck);
                UI.PrintCard(p, d);
                //플레이어 턴 시작
                int playerCardSum = 0;
                int dealerCardSum = 0;
                int playerBetting = Bet(p);
                playerCardSum = PlayerTurn(p, d, tempDeck, UI);
                if(playerCardSum > 21)
                {
                    std::cout << "[Burst] : you lose" << std::endl;
                    p.InitializePlayerCardsToEmpty();
                    break;
                }
                else
                {
                    dealerCardSum = DealerTurn(p, d, tempDeck, UI);
                }

                if(dealerCardSum > 21)
                {
                    if(playerCardSum == 21)
                    {
                        p.IncreaseBudget(playerBetting*2.5);
                    }
                    else
                    {
                        p.IncreaseBudget(playerBetting*2);
                    }
                    std::cout << "Dealer lose" << std::endl;
                }
                else
                {
                    if(dealerCardSum == playerCardSum)
                    {
                        p.IncreaseBudget(playerBetting);
                        std::cout << "Push" << std::endl;
                    }
                    else if(dealerCardSum > playerCardSum)
                    {
                        std::cout << "Dealer win" << std::endl;
                    }
                    else if(dealerCardSum < playerCardSum)
                    {
                        if(playerCardSum == 21)
                        {
                            p.IncreaseBudget(playerBetting*2.5);
                        }
                        else
                        {
                            p.IncreaseBudget(playerBetting*2);
                        }
                        std::cout << "Player win" << std::endl;
                    }
                }
                p.InitializePlayerCardsToEmpty();
                break;
            }
            case 2:
                UI.PrintDescription();
                break;
            case 3:
                UI.PrintBudget(p);
                break;
            case 4:
                ChargeCoin(p, UI);
                break;
            case 5:
                isGameEnd = true;
                std::cout << "Exit BlackJack Game..." << std::endl;
                break;
            default:
                std::cout << "[Invalid input] : Enter correct input (1~5)" << std::endl;
                break;
        }
        if(isGameEnd != true)
        {
            UI.ShowMenu();
            std::cout << "->";
            std::cin >> inputMenu;
        }
    }

}
