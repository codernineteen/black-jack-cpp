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
    std::cout << "1. Start" << std::endl;
    std::cout << "2. Rule Description" << std::endl;
    std::cout << "3. Current Budget" << std::endl;
    std::cout << "4. ExitGame" << std::endl;
}



//플레이어가 가진 카드 정보를 토대로 출력
void UserInterface::PrintCard(Player& player)
{
    std::vector<Card> playerCards = player.GetCards();
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

void UserInterface::InputMessamge()
{
    std::cout << "Enter one option above four: ";
}


int UserInterface::GetPlayerInput()
{
    int mode;
    std::cin >> mode;

    return mode;
}

