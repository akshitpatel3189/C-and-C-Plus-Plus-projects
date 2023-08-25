#include <stdio.h>
#include <stdbool.h>

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    
    int currentPlayer = 1; // Player 1 starts
    int moves = 0; // Count of total moves
    
    while (moves < 9) {
        printf("Current board:\n");
        displayBoard(board);
        
        int choice;
        printf("Player %d, enter your move: ", currentPlayer);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 9) {
            printf("Invalid move. Choose a number between 1 and 9.\n");
            continue;
        }
        
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move. Cell already taken.\n");
            continue;
        }
        
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
        
        if (checkWin(board, board[row][col])) {
            printf("Player %d wins!\n", currentPlayer);
            displayBoard(board);
            break;
        }
        
        moves++;
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    
    if (moves == 9) {
        printf("It's a draw!\n");
    }
    
    return 0;
}