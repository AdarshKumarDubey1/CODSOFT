#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n-----------\n";
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void ticTacToe() {
    initializeBoard();
    cout << "\n🎮 Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X | Player 2: O\n";

    while (true) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column 0-2): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (checkWin()) {
                printBoard();
                cout << "🏆 Player " << currentPlayer << " wins!\n";
                break;
            } else if (checkDraw()) {
                printBoard();
                cout << "🤝 It's a draw!\n";
                break;
            }
            switchPlayer();
        } else {
            cout << "⚠️ Invalid move. Try again.\n";
        }
    }
}

int main() {
    char playAgain;
    do {
        ticTacToe();
        cout << "🔁 Play again? (y/n): ";
        cin >> playAgain;
        currentPlayer = 'X';
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "👋 Thanks for playing!\n";
    return 0;
}