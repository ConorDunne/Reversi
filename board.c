#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"


void initializePlayers(player *player1, player *player2){
    int nameSize;
    char tempName[20];
    // Insert player 1
    printf("Player 1 please insert your name:   \n");
    fgets(player1->name, 20, stdin);
    nameSize = strlen(player1->name);
    player1->name[nameSize -1] = '\0';


    // Assign colours and points to player 1
    player1->type = BLACK;
    player1->points = 2;

    // Insert player 2
    printf("Player 2 please insert your name:   \n");
    fgets(player2->name, 20, stdin);
    nameSize = strlen(player2->name);
    player2->name[nameSize -1] = '\0';


    // Assign colours and points to player 2
    player2->type = WHITE;
    player2->points = 2;

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


void printBoard(player *player1, player *player2, disk board[SIZE][SIZE]){
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
                case VALID:
                  printf("A | ");
                default:
                    break;
            }
        }
    }

    printf("\n\t %s: %d", player1->name, player1->points);
    printf("\n\t %s: %d", player2->name, player2->points);
}

void saveBoard(disk board[SIZE][SIZE], player player1, player player2)
{
    FILE *fp;

    if((fp = fopen("result.txt", "a")) == NULL)
        puts(" ERROR: Cannot Open File");
    else
    {
        int i,j;
        j = 0;

        fprintf(fp, "\n    ");
        for(i=0; i< SIZE; i++){
            fprintf(fp, "%d   ",i+1);
        }
        for(i=0; i< SIZE; i++){
            fprintf(fp, "\n%d | ", i+1);
            for(j=0;j<SIZE; j++){
                switch(board[i][j].type){
                    case BLACK:
                        fprintf(fp, "1 | ");
                        break;
                    case WHITE:
                        fprintf(fp, "0 | ");
                        break;
                    case NONE:
                        fprintf(fp, "x | ");
                        break;
                    case VALID:
                      fprintf(fp, "A | ");
                    default:
                        break;
                }
            }
    }
}
}
