#include <iostream>
#include "Deck.h"
#include "UserInterface.h"

int main()
{
    //카드 덱 생성
    Deck tempDeck = Deck();
    UserInterface UI = UserInterface();

    UI.PrintCard(tempDeck);

    return 0;
}
