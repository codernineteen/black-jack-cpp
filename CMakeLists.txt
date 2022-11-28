cmake_minimum_required(VERSION 3.23)
project (blackjack)

set(CMAKE_CXX_STANDARD 14)

add_executable(blackjack main.cpp Deck.cpp Deck.h Card.cpp Card.h Player.cpp Player.h Dealer.cpp Dealer.h UserInterface.cpp UserInterface.h BlackJack.cpp BlackJack.h)
