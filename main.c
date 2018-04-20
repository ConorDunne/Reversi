#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"


int main(void)
{
    // Variables declaration
player player1= {"player1", NONE,0};
player player2= {"player2", NONE,0};

    disk board[SIZE][SIZE];

    initializePlayers(&player1, &player2);

    initializeBoard(board);

    printBoard(&player1, &player2, board);

    //method to get user input
    bool finished = false;  //  Boolean Value to repeat game until over
    int playerGo = 0;       //  Who's Go is it (playerGomod2)

    //  Repeats game untill finished
    while( (playerGo < 64) && !finished)
        finished = movePlayer(playerGo++, &player1, &player2, board);

if(player1.points > player2.points)
   {
      printf("Congratulations %s. You are the winner,with %d points! \n",player1.name,player1.points);

   }

else if(player1.points < player2.points)
{
   printf("Congratualtions %s. you are the winner, with %d points\n",player2.name,player2.points);
}

else
   printf("DRAW!");

}



