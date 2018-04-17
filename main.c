#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"


int main(void)
{
    // Variables declaration
player player1= {"player1", BLACK,0};
player player2= {"player2", WHITE,0};

    disk board[SIZE][SIZE];

    initializePlayers(&player1, &player2);

    initializeBoard(board);

    printBoard(board);

    //method to get user input
    bool finished = false;  //  Boolean Value to repeat game until over
    int playerGo = 0;       //  Who's Go is it (playerGomod2)

    //  Repeats game untill finished
    while( (playerGo < 64) || !finished)
        finished = movePlayer(playerGo++, player1, player2, board);
}
