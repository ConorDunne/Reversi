    #include <stdbool.h>
    #define SIZE 8

    enum colour{
        WHITE,
        BLACK,
        NONE,
        VALID
    };

    typedef struct position{
        int row;
        int col;
    } position;

    typedef struct disk{
        enum colour type;
        position pos;
    } disk;

    typedef struct player{
        char name[20];
        enum colour type;
        int points;
    } player;

    void initializePlayers(player player1, player player2);

    void initializeBoard(disk board[SIZE][SIZE]);

    void printBoard(disk board [SIZE][SIZE]);

    int validMove(disk played, disk board[SIZE][SIZE]);

    int endsWithYourColour(disk played, int i, disk board[SIZE][SIZE]);

    bool movePlayer(int playerGo, player player1, player player2, disk board[SIZE][SIZE]);

    int findValidMove(player player1, disk board[SIZE][SIZE]);
