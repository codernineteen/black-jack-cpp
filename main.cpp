#include "Deck.h"
#include "UserInterface.h"
#include "Player.h"

int main()
{
    //카드 덱 생성
    Deck tempDeck = Deck();
    UserInterface UI = UserInterface();
    Player player1 = Player();

    //카드 두 개 생성
    player1.SetACard(tempDeck);
    player1.SetACard(tempDeck);

    UI.Greeting();
    UI.ShowMenu();
    // UI.PrintCard(player1); 잘 출력되는 것 확인함.

    return 0;
}
