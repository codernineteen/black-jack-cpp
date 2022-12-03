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
void UserInterface::PrintCard(Player& player)
{
    std::vector<Card> playerCards = player.GetPlayerCards();
    std::vector<int> CardIndices;
    for(auto card : playerCards)
    {
        CardIndices.push_back(card.GetCardStartIndex());
    }

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

