//
// Created by 전예찬 on 2022/11/27.
//

#include "UserInterface.h"
#include <fstream>
#include <iostream>

UserInterface::UserInterface() {
    std::string line;
    std::ifstream inFile;
    inFile.open("cards.txt");
    if(inFile.is_open())
    {
        while(getline(inFile,line)) {
            cardLines.push_back(line);
        }
    }
    else
    {
        std::cout << "Can't open file" << std::endl;
    }
    inFile.close();
};

void UserInterface::Greeting()
{
    std::cout << R"(
------------------------------------------------------------------------------------------------------------

▀█████████▄   ▄█          ▄████████  ▄████████    ▄█   ▄█▄           ▄█    ▄████████  ▄████████    ▄█   ▄█▄
  ███    ███ ███         ███    ███ ███    ███   ███ ▄███▀          ███   ███    ███ ███    ███   ███ ▄███▀
  ███    ███ ███         ███    ███ ███    █▀    ███▐██▀            ███   ███    ███ ███    █▀    ███▐██▀
 ▄███▄▄▄██▀  ███         ███    ███ ███         ▄█████▀             ███   ███    ███ ███         ▄█████▀
▀▀███▀▀▀██▄  ███       ▀███████████ ███        ▀▀█████▄             ███ ▀███████████ ███        ▀▀█████▄
  ███    ██▄ ███         ███    ███ ███    █▄    ███▐██▄            ███   ███    ███ ███    █▄    ███▐██▄
  ███    ███ ███▌    ▄   ███    ███ ███    ███   ███ ▀███▄          ███   ███    ███ ███    ███   ███ ▀███▄
▄█████████▀  █████▄▄██   ███    █▀  ████████▀    ███   ▀█▀      █▄ ▄███   ███    █▀  ████████▀    ███   ▀█▀
             ▀                                   ▀              ▀▀▀▀▀▀                            ▀

------------------------------------------------------------------------------------------------------------
)" << "\n";
}

void UserInterface::ShowMenu()
{
    std::cout << R"(
------------------------------------------------------------------------------------------------------------

                 .-~~-.                 /\                  /\
                {      }              .'  `.              .'  `.               .-~~~-__-~~~-.
             .-~-.    .-~-.          '      `.           '      `.            {              }
            {              }       <          >       .'          `.           `.          .'
             `.__.'||`.__.'         `.      .'       {              }            `.      .'
                   ||                 `.  .'          ~-...-||-...-~               `.  .'
                  '--`                  \/                  ||                       \/


                                            [GAME MENU]


                                            1. Start Game
                                            2. Rule Description
                                            3. Current Budget
                                            4. Charge Budget
                                            5. ExitGame

------------------------------------------------------------------------------------------------------------
)" << "\n";
}



//플레이어가 가진 카드 정보를 토대로 출력
void UserInterface::PrintCard(Player& player, Dealer& dealer)
{
    std::vector<Card> playerCards = player.GetPlayerCards();
    std::vector<int> CardIndices;
    std::vector<Card> dealerCards = dealer.GetDealerCards(); //딜러 카드 받아오기
    std::vector<int> dCardIndices;

    for(auto card : playerCards)
    {
        CardIndices.push_back(card.GetCardStartIndex());
    }

    for(auto card: dealerCards) {
        dCardIndices.push_back(card.GetCardStartIndex());
    }


    //딜러
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------Dealer Cards--------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    if(dCardIndices.size() == 2)
    {
        for(int i=0; i < 9; i++)
        {
            if(i==0 or i==8)
            {
                std::cout << cardLines[dCardIndices[0]+i] << "  ";
                std::cout << cardLines[468+i] << "  ";
            }
            else
            {
                std::cout << cardLines[dCardIndices[0]+i] << " ";
                std::cout << cardLines[468+i] << " ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        for(int i=0; i < 9; i++)
        {
            if(i==0 or i==8)
            {
                for(int CardIdx : dCardIndices)
                {
                    std::cout << cardLines[CardIdx+i] << "  ";
                }
            }
            else
            {
                for(int CardIdx : dCardIndices)
                {
                    std::cout << cardLines[CardIdx+i] << " ";
                }
            }

            std::cout << "\n";
        }
    }


    std::cout<<"\n";

    //유저
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------Player Cards--------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;

    for(int i=0; i < 9; i++)
    {
        if(i==0 or i==8)
        {
            for(int CardIdx : CardIndices)
            {
                std::cout << cardLines[CardIdx+i] << "  ";
            }
        }
        else
        {
            for(int CardIdx : CardIndices)
            {
                std::cout << cardLines[CardIdx+i] << " ";
            }
        }

        std::cout << "\n";
    }
}

void UserInterface::PrintBudget(Player &player)
{
    int currentBudget = player.GetBudget();

    std::cout << "Your current budget is : " <<  currentBudget << std::endl;
}

void UserInterface::PrintDescription() { //Minbyeongrok
    std::cout << "+============Rule Description============+" << std::endl;
    std::cout << R"(
------------------------------------------------------------------------------------------------------------
<< How to Play Blackjack Game? >>

? How to win: Sum of the card numbers that you have is more than deler's, you win!

First, You (Player) and dealer enter the game.
Second, When you enter 1.(start), blackjack game is started.
Third, You should bet the game money within the range(1,000~10,000).
Next,
You and dealer get each two cards. One of the dealer' card is not opened.
You can have two options, hit or stay. If you think that you need one more new card to win,
choose hit, or you choose stay.
============================================================================================================
<< BlackJack Terms >>

* HIT : Getting one more card from the first two states
* STAY : Ending a turn without drawing any more cards.
* INSURANCE : If the dealer's open card is an Ace, you can bet the insurance money.
If the dealer is blackjack, the player is rewarded with double the insurance money.
If the dealer does not blackjack, the player loses the insurance money.
* PUSH : If the sum of the cards of the player and the dealer is the same,
it is a tie and the bet amount is refunded.
* SURRENDER : The player gives up the game and gets half of the bet amount back.
However, if the dealer has a blackjack, the game cannot be abandoned.
------------------------------------------------------------------------------------------------------------
)" << "\n";
}

void UserInterface::ChargeCoin() {
    std::cout << R"(
------------------------------------------------------------------------------------------------------------

                                                  ██████████
                                                ██          ██
                                              ██    ░░██░░░░░░██
                                            ██    ░░██████░░░░░░██
                                            ██  ░░░░██░░░░░░░░░░██
                                            ██  ░░░░░░██░░░░░░░░██
                                            ██  ░░░░░░░░██░░░░░░██
                                            ██  ░░░░██████░░░░░░██
                                              ██  ░░░░██░░░░░░██
                                                ██░░░░░░░░░░██
                                                  ██████████

                                              [CHARGING STATION]
------------------------------------------------------------------------------------------------------------
)"<< std::endl;
}

