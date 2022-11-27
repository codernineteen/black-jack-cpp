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

//플레이어가 가진 카드 정보를 토대로 출력
void UserInterface::PrintCard(Deck& cardDeck)
{
    //이 아래 코드 나중에 플레이어가 가진 카드로 출력하는 코드로 바꿔야함
    Card Card1 = cardDeck.GetARandomCard(); // 테스트 용으로 카드 하나 뽑아오기
    Card Card2 = cardDeck.GetARandomCard();
    int Card1Idx = Card1.GetCardStartIndex();
    int Card2Idx = Card2.GetCardStartIndex();
    for(int i=0; i < 9; i++)
    {
        if(i==0 or i==8)
        {
            std::cout << cardLines[Card1Idx+i] << "  ";
            std::cout << cardLines[Card2Idx+i];
        }
        else
        {
            std::cout << cardLines[Card1Idx+i] << " ";
            std::cout << cardLines[Card2Idx+i];
        }

        std::cout << "\n";
    }
}

