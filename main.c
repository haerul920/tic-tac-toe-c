#include <stdio.h>

char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

char checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' '; // belum ada pemenang
}

int isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';
    initBoard();
    printf("=== Game Tic Tac Toe ===\n");
    printf("Pemain 1 = X, Pemain 2 = O\n");
    while (1) {
        printBoard();
        printf("Giliran %c. Masukkan baris dan kolom (1-3 1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);
        row--; col--; // agar index mulai dari 0
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Posisi tidak valid! Coba lagi.\n");
            continue;
        }
        board[row][col] = currentPlayer;
        winner = checkWinner();
        if (winner != ' ') {
            printBoard();
            printf("Pemenang adalah %c!\n", winner);
            break;
        }
        if (isFull()) {
            printBoard();
            printf("Seri!\n");
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
