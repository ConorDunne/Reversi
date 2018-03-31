
#include <stdio.h>
#include <stdlib.h>
#include "disksAndPlayers.h"


int main()
{
    // Variables declaration

    player player1= {"player1", NONE,0};
    player player2= {"player2", NONE,0};
    disk board[SIZE][SIZE];

    initializePlayers(player1, player2);

    initializeBoard(board);

    printBoard(board);

    //method to get user input

    //invoke a method that implements the game logic
    validMove(/*variable type disk of player's move*/,board); //validMove will check if move player entered was valid. If valid it returns 0. If not it returns 1.
    //invoke a method that prints the final result

}
