#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"





int validMove(disk played, disk board[SIZE][SIZE]) //checks if the move is valid. 1st checks your disk is next to opposite colour,
{                                                  //then calls endsWithYourColour. Returns 0 if valid 1 if not.
   int x = played.pos.row;
   int y = played.pos.col;
   int Oppositecolour;

   if(played.type == WHITE)
      Oppositecolour = BLACK;
   else if (played.type == BLACK)
      Oppositecolour = WHITE;

   for(int i = 0; i < 9; i++) //to check all directions surrounding played piece
      {
         if( ((x >= 0) && (y >= 0)) && ((x<= 7) && (y <= 7)) ) //if the piece is within the board
            {
               switch(i) //checking what piece is next to the played piece
               {
               case 0:
                 if((board[x][y-1].type == Oppositecolour) && ((x>=0)&&(y >0)&&(x<=7)&&(y<=7))) //checking north of played piece
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;

                  break;
               case 1:
                  if((board[x+1][y-1].type == Oppositecolour) &&((x>=0)&&(y>0)&&(x<7)&&(y<=7)))  //checking north east
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 2:
                  if((board[x+1][y].type == Oppositecolour) && ((x>=0)&&(y>=0)&&(x<7)&&(y<=7))) //east
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 3:
                  if((board[x+1][y+1].type == Oppositecolour) && ((x>=0)&&(y>=0)&&(x<7)&&(y<7))) //south east
                   if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 4:
                  if((board[x][y+1].type == Oppositecolour) && ((x>=0)&&(y>=0)&&(x<=7)&&(y<7))) //south
                    if(endsWithYourColour(played,i,board) == 0)
                       return 0;
                  break;
               case 5:
                  if((board[x-1][y+1].type == Oppositecolour) &&((x>0)&&(y>=0)&&(x<=7)&&(y<7))) // south west
                  if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 6:
                  if((board[x-1][y].type == Oppositecolour) &&((x>0)&&(y>=0)&&(x<=7)&&(y<=7)))// west
                  if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               case 7:
                  if((board[x-1][y-1].type == Oppositecolour) && ((x>0)&&(y>0)&&(x<=7)&&(y<=7))) // north west
                  if(endsWithYourColour(played,i,board) == 0)
                     return 0;
                  break;
               default :
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
      while(currentSpace != played.type && ((x>= 0) && (y > 0) && (x<=7) && (y <= 7))) //as long as piece is an oppoiste colour and itsn't the edge of the board
         {
            currentSpace = board[x][y-1].type; //checking straight ahead
            if(currentSpace == played.type) //if straight line is ended with same colour token
               return 0;
            y--; //moving in the straight line
         }

      break;
   case 1:
       while(currentSpace != played.type && ((x>=0) && (y > 0) && (x<7) && (y <= 7))) //keeping going until hits opposite colour and it isn't the edge of th board
         {
            currentSpace = board[x+1][y-1].type; //checking north east
            if(currentSpace == played.type) //if straight line is ended with the same colour token
               return 0;
            y--; //moving in straight line
            x++; // moving in straight line
         }

      break;
   case 2:
       while(currentSpace != played.type && ((x>= 0) && (y >= 0) && (x<7) && (y <= 7)))
         {
            currentSpace = board[x+1][y].type; //checking east
            if(currentSpace == played.type)
            return 0;
            x++;
         }

      break;
   case 3:
       while(currentSpace != played.type && ((x>= 0) && (y >= 0) && (x<7) && (y <7)))
         {
            currentSpace = board[x+1][y+1].type; //south east
            if(currentSpace == played.type)
               return 0;
            y++;
            x++;
         }

      break;
   case 4:
       while(currentSpace != played.type && ((x>= 0) && (y >= 0) && (x<=7) && (y < 7)))
         {
            currentSpace = board[x][y+1].type; //south
            if(currentSpace == played.type)
               return 0;
            y++;
         }

      break;
   case 5:
       while(currentSpace != played.type && ((x> 0) && (y >= 0) && (x<=7) && (y < 7)))
         {
            currentSpace = board[x-1][y+1].type; //south west
            if(currentSpace == played.type)
               return 0;
            y++;
            x--;
         }

      break;
   case 6:
       while(currentSpace != played.type && ((x> 0) && (y >= 0) && (x<=7) && (y <= 7)))
         {
            currentSpace = board[x-1][y].type; //west
            if(currentSpace == played.type)
               return 0;
            x--;
         }

      break;
   case 7:
       while(currentSpace != played.type &&((x> 0) && (y > 0) && (x<=7) && (y <= 7)))
         {
            currentSpace = board[x-1][y-1].type; //north west
            if(currentSpace == played.type)
               return 0;
            y--;
            x--;
         }

      break;
   default :
      return 1;

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
        disk moveMade;
        moveMade.type = player1.type;
        disk boardsquare;

        int check = 1;
        while(check == 1)
        {
            printf(" Insert move (x y): ");
                scanf("%d%*c%d", &moveMade.pos.row, &moveMade.pos.col); //the %*c is a way to stop scanf reading in characters. e.g if someone typed 3,4 the , would be discouted
                moveMade.pos.row -= 1;
                moveMade.pos.col -= 1;

               check = validMove(moveMade, board);
            if(check == 1) {
              printf("\n\n ERROR: Invalid move");
            }
        }

        flipCounter(moveMade, &player1, &player2, board);

        //  Remove Valid Move Disks
        for(int r=0; r<8; r++)
        {
            for(int c=0; c<8; c++)
            {
                if(board[r][c].type == VALID)
                    board[r][c].type = NONE;
            }
        }

    }
    else
    {
        printf("\n %s's go.", player2.name);

        int valid = findValidMove(player2, board);

        if(valid == 0)
          return false; //  Returns false if no valid move, ends game

      printBoard(board);

        //  Make move
        disk moveMade;
        moveMade.type = player2.type;

        int check = 1;
        while(check == 1)
        {
            printf(" Insert move (x y): ");
            scanf("%d%*c%d", &moveMade.pos.row, &moveMade.pos.col);

            moveMade.pos.row -= 1;
            moveMade.pos.col -= 1;

               check = validMove(moveMade, board);
            if(check == 1)
                printf("\n\n ERROR: Invalid move");
        }


        flipCounter(moveMade, &player2, &player1, board);
        //  Remove Valid Move Disks
        for(int r=0; r<8; r++)
        {
            for(int c=0; c<8; c++)
            {
                if(board[r][c].type == VALID)
                    board[r][c].type = NONE;
            }
        }

    }
}

int findValidMove(player player1, disk board[SIZE][SIZE])
{
  int val=0;  //  Changes to 1 if valid move found
  disk boardsquare;
  disk currentsquare;

  currentsquare.type = player1.type;
  for(int row=0; row<SIZE; row++)   //  Scans through rows
  {
    for(int col=0; col<SIZE; col++)   //  Scans through columns
    {
      currentsquare.pos.row = row;
      currentsquare.pos.col = col;
      boardsquare.type = board[row][col].type;
      if(validMove(currentsquare, board) == 0)   // Valid Move Found
      {
        board[row][col].type = VALID;
        val = 1;
      }
    }
  }

  return val;
}

void flipCounter(disk moveMade, player *player1, player *player2, disk board[SIZE][SIZE])
{
    scanCounters(moveMade, &player1, &player2, board, 1, 0); //south
    scanCounters(moveMade, &player1, &player2, board, 1, 1); //south east
    scanCounters(moveMade, &player1, &player2, board, 0, 1); //east
    scanCounters(moveMade, &player1, &player2, board, -1, 1); //north east
    scanCounters(moveMade, &player1, &player2, board, -1, 0); //north
    scanCounters(moveMade, &player1, &player2, board, -1, -1); //north west
    scanCounters(moveMade, &player1, &player2, board, 0, -1); //west
    scanCounters(moveMade, &player1, &player2, board, 1, -1); //south west
}

void scanCounters(disk moveMade, player *player1, player *player2, disk board[SIZE][SIZE], int xChange, int yChange)
{
    int y = moveMade.pos.col + yChange;
    int x = moveMade.pos.row + xChange;


    int end = 0;
    int points = 0;
    while((y>=0 && x>=0) && (y<=7 && x<=7) && end == 0)
    {

        if(moveMade.type == WHITE)
        {
            if(board[x][y].type == WHITE)
            {
                points = returnAndFlip(moveMade, board, xChange, (x - xChange), yChange, (y - yChange));
                player2->points += points;
                end = 1;
            }
            else if(board[x][y].type == NONE)
                end = 0;
        }
        else if(moveMade.type == BLACK)
        {

            if(board[x][y].type == BLACK)
            {
                points = returnAndFlip(moveMade, board, xChange, (x - xChange), yChange, (y - yChange));
                player1->points += points;
                end = 1;
            }
            else if(board[x][y].type == NONE)
                end = 0;
        }

        x += xChange;
        y += yChange;
    }
}

int returnAndFlip(disk moveMade, disk board[SIZE][SIZE], int xChange, int x, int yChange, int y)
{
    int point = 0;
    int end = 0;

    int colSelected = moveMade.pos.col;
    int rowSelected = moveMade.pos.row;
    while(end == 0)
    {
        if(board[x][y].type == WHITE && moveMade.type == BLACK)
        {
            board[rowSelected][colSelected].type = BLACK;
            board[x][y].type = BLACK;
            point++;
        }
        else if(board[x][y].type == BLACK && moveMade.type == WHITE)
        {
            board[rowSelected][colSelected].type = WHITE;
            board[x][y].type = WHITE;
            point++;
        }
        else
            end = 1;

        x -= xChange;
        y -= yChange;
    }
    return point;
}
