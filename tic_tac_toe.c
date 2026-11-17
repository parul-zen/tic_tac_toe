#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// 1. Draws the 3x3 board in the terminal
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("  %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf(" ---|---|---\n");
        }
    }
    printf("\n");
}

// 2. Checks if 'X' or 'O' has 3 in a row
int checkWin(char mark) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) return 1;
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) return 1;
    }
    // Check both diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) return 1;
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) return 1;

    return 0;
}

// 3. Checks if all 9 spots are taken
int isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Found an empty spot
            }
        }
    }
    return 1; // Board is full
}

// 4. Smart Bot Logic ('O')
void botMove() {
    // Priority 1: Try every empty spot to see if Bot ('O') can win immediately
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = 'O';
                if (checkWin('O')) return; // Winning move found! Keep it.
                board[i][j] = backup;      // Undo test move
            }
        }
    }

    // Priority 2: Check if user('X') is about to win and block them
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = 'X';
                if (checkWin('X')) {
                    board[i][j] = 'O';     // Block the user!
                    return;
                }
                board[i][j] = backup;      // Undo test move
            }
        }
    }

    // Priority 3: Take the center if open
    if (board[1][1] == '5') {
        board[1][1] = 'O';
        return;
    }

    // Priority 4: Take any open corner
    int corners[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int k = 0; k < 4; k++) {
        int r = corners[k][0];
        int c = corners[k][1];
        if (board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = 'O';
            return;
        }
    }

    // Priority 5: Take the first remaining open spot
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int main() {
    int choice;
    printf("=== TIC-TAC-TOE: YOU (X) vs BOT (O) ===\n");

    while (1) {
        printBoard();

        // user Turn
        printf("Enter a spot (1-9): ");
        scanf("%d", &choice);

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid spot! Try again.\n");
            continue;
        }

        board[row][col] = 'X';

        if (checkWin('X')) {
            printBoard();
            printf("You win! (You found a loophole!)\n");
            break;
        }
        if (isFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // Bot Turn
        botMove();

        if (checkWin('O')) {
            printBoard();
            printf("Bot wins!\n");
            break;
        }
        if (isFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}