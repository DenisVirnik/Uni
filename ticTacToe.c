#include <stdio.h>

int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
    int move;

    printf("Welcome to Tic Tac Toe!\n");

    for (int i = 0; i < 9; i++) {
        //printing the board based on the array dived by 3
        printf("\n");
        printf(" %c | %c | %c \n", board[0], board[1], board[2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[3], board[4], board[5]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[6], board[7], board[8]);

        printf("\nPlayer %c, enter your move (1-9): ", player); //chosing the array num to assaing the x/o
        scanf("%d", &move); //scans the input and the checks if its <1 Or >9 which is not in array & check if the spot is already taken

        if (move < 1 || move > 9) {
            printf("Invalid move, please enter a number between 1 and 9.\n");
            i--;
            continue;
        }

        if (board[move-1] == 'X' || board[move-1] == 'O') {
            printf("That spot is already taken, please choose another spot.\n");
            i--;
            continue;
        }

        board[move-1] = player;

        if (board[0] == player && board[1] == player && board[2] == player ||
            board[3] == player && board[4] == player && board[5] == player ||
            board[6] == player && board[7] == player && board[8] == player ||
            board[0] == player && board[3] == player && board[6] == player ||
            board[1] == player && board[4] == player && board[7] == player ||
            board[2] == player && board[5] == player && board[8] == player ||
            board[0] == player && board[4] == player && board[8] == player ||
            board[2] == player && board[4] == player && board[6] == player) {
            printf("\nCongratulations, player %c wins!\n", player);
            break;
        }

        if (i == 8) {
            printf("\nThe game is a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
