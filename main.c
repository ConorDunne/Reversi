#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "disksAndPlayers.h"


int main(void)
{
    // Variables declaration

    player player1= {"player1", NONE,0};
    player player2= {"player2", NONE,0};
    disk board[SIZE][SIZE];

    initializePlayers(player1, player2);

    initializeBoard(board);

    printBoard(board);

    //method to get user input
    bool finished = false;  //  Boolean Value to repeat game until over
    int playerGo = 0;       //  Who's Go is it (playerGomod2)

    //  Repeats game untill finished
    while(!finished)
        movePlayer(playerGo++, player1, player2, board);
}
