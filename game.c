#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

int gitDebug; // making a change to file to see if it's being uploaded to respository



int validMove(disk played, disk board[SIZE][SIZE]) //checks if the move is valid. 1st checks your disk is next to opposite colour,
{                                                  //then calls endsWithYourColour. Returns 0 if valid 1 if not.
   int x = played.pos.row;
   int y = played.pos.col;
   int Oppositecolour;

   if(played.type == WHITE)
      Oppositecolour = BLACK;
   else
      Oppositecolour = WHITE;

   for(int i = 0; i < 9; i++) //to check all directions surrounding played piece
      {
         if( ((x >= 0) && (y >= 0)) && ((x<= 7) && (y <= 7)) ) //if the piece is within the board
            {
               switch(i) //checking what piece is next to the played piece
               {
               case 0:
                 if(board[y-1][x].type == Oppositecolour) //checking north of played piece
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;

                  break;
               case 1:
                  if(board[y-1][x+1].type == Oppositecolour)  //checking north east
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 2:
                  if(board[y][x+1].type == Oppositecolour) //east
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 3:
                  if(board[y+1][x+1].type == Oppositecolour) //south east
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 4:
                  if(board[y+1][x].type == Oppositecolour) //south
                    if(endsWithYourColour(played,i,board) == 0)
                       return 0;
                  break;
               case 5:
                  if(board[y+1][x-1].type == Oppositecolour) // south west
                  if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 6:
                  if(board[y][x-1].type == Oppositecolour)// west
                  if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 7:
                  if(board[y-1][x-1].type == Oppositecolour) // north west
                  if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               default :
                  printf("\n\aInvaild move\n");
                  return 1;
               }

            }
      }

}


int endsWithYourColour(disk played, int i, disk board[SIZE][SIZE]) //checks that a line of opposite coloured disks ends with your disk colour
{                                                                  // returns 0 if true and 1 if false
 int currentSpace = NONE;

 int x = played.pos.row;
 int y = played.pos.col;

 switch(i) //checking what piece is next to the played piece
{
   case 0:
      while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7)) //as long as piece is an oppoiste colour and itsn't the edge of the board
         {
            currentSpace = board[y-1][x].type; //checking straight ahead
            if(currentSpace == played.type) //if straight line is ended with same colour token
               return 0;
            y--; //moving in the straight line
         }

      break;
   case 1:
       while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7)) //keeping going until hits opposite colour and it isn't the edge of th board
         {
            currentSpace = board[y-1][x+1].type; //checking north east
            if(currentSpace == played.type) //if straight line is ended with the same colour token
               return 0;
            y--; //moving in straight line
            x++; // moving in straight line
         }

      break;
   case 2:
       while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7))
         {
            currentSpace = board[y][x+1].type; //checking east
            if(currentSpace == played.type)
            return 0;
            x++;
         }

      break;
   case 3:
       while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7))
         {
            currentSpace = board[y+1][x+1].type; //south east
            if(currentSpace == played.type)
               return 0;
            y++;
            x++;
         }

      break;
   case 4:
       while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7))
         {
            currentSpace = board[y+1][x].type; //south
            if(currentSpace == played.type)
               return 0;
            y++;
         }

      break;
   case 5:
       while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7))
         {
            currentSpace = board[y+1][x-1].type; //south west
            if(currentSpace == played.type)
               return 0;
            y++;
            x--;
         }

      break;
   case 6:
       while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7))
         {
            currentSpace = board[y][x-1].type; //west
            if(currentSpace == played.type)
               return 0;
            x--;
         }

      break;
   case 7:
       while(currentSpace != played.type && (x&&y >= 0 && x&&y <= 7))
         {
            currentSpace = board[y-1][x-1].type; //north west
            if(currentSpace == played.type)
               return 0;
            y--;
            x--;
         }

      break;
   default :
      printf("\n\aInvaild move\n");
      return 1;
      break;
}

}

bool movePlayer(int playerGo, player player1, player player2, disk board[SIZE][SIZE]) // Searches board for valid move
{
  //  Game Theory, APS (Like Nim)
    if(playerGo%2 == 0)
    {
        printf("\n %s's go.", player1.name);

        int valid = findValidMove(player1, board);

        if(valid == 0)
          return false; //  Returns false if no valid move, ends game

        printBoard(board);

        //  Make move
    }
    else
    {
        printf("\n %s's go.", player2.name);

        int valid = findValidMove(player2, board);

        if(valid == 0)
          return false; //  Returns false if no valid move, ends game

        printBoard(board);

        //  Make move
    }
}

void initializePlayers(player player1, player player2){
    int nameSize;
    // Insert player 1
    printf("Player 1 please insert your name:   \n");
    fgets(player1.name, 20, stdin);
    nameSize = strlen(player1.name);
    player1.name[nameSize -1] = '/0';

    // Assign colours and points to player 1
    player1.type = BLACK;
    player1.points = 2;

    // Insert player 2
    printf("Player 2 please insert your name:   \n");
    fgets(player2.name, 20, stdin);
    nameSize = strlen(player2.name);
    player2.name[nameSize -1] = '/0';

    // Assign colours and points to player 2
    player2.type = WHITE;
    player2.points = 2;

}

void initializeBoard(disk board [SIZE][SIZE]){
 int i, j;
 //board initialization
    for(i=0; i< SIZE; i++){
        for(j=0;j<SIZE; j++){
            if(i==3){
                if(j==3)
                    board[i][j].type = WHITE;
                else{
                    if(j==4)
                        board[i][j].type = BLACK;
                    else
                        board[i][j].type = NONE;
                    }
                }
            else {
                if(i==4){
                    if(j == 3)
                        board[i][j].type = BLACK;
                    else {
                        if(j == 4)
                        board[i][j].type = WHITE;
                        else
                            board[i][j].type = NONE;
                        }
                    }
                else
                    board[i][j].type = NONE;
            }
            board[i][j].pos.row = i;
            board[i][j].pos.col = j;

            }
        }
    }


void printBoard(disk board[SIZE][SIZE]){
    int i,j;
    j = 0;

    printf("\n    ");
    for(i=0; i< SIZE; i++){
        printf("%d   ",i+1);
    }
    for(i=0; i< SIZE; i++){
        printf("\n%d | ", i+1);
        for(j=0;j<SIZE; j++){
            switch(board[i][j].type){
                case BLACK:
                    printf("1 | ");
                    break;
                case WHITE:
                    printf("0 | ");
                    break;
                case NONE:
                    printf("x | ");
                    break;
                default:
                    break;
            }
        }
    }

}

int findValidMove(player player1, disk board[SIZE][SIZE])
{
  int val=0;  //  Changes to 1 if valid move found

  for(int row=0; row<SIZE; row++)   //  Scans through rows
  {
    for(int col=0; col<SIZE; col++)   //  Scans through columns
    {
      if(validMove(player1, board) == 1)   // Valid Move Found
      {
        board[row][col].type = VALID;
        val = 1;
      }
    }
  }

  return val;
}
