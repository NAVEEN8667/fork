#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], int player);

int main() {
    char board[SIZE][SIZE];
    int currentPlayer = 1;
    int gameStatus = 0;

    initializeBoard(board);

    while (1) {
        displayBoard(board);
        playerMove(board, currentPlayer);

        gameStatus = checkWin(board);
        if (gameStatus == 1) {
            displayBoard(board);
            printf("Player %d wins!\n", currentPlayer);
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            printf("The game is a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;
    // Check rows and columns
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove(char board[SIZE][SIZE], int player) {
    int row, col;
    char mark = (player == 1) ? 'X' : 'O';

    while (1) {
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = mark;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

