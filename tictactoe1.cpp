#include <iostream>
#include <stdlib.h>
using namespace std;

/* tictactoe */

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};
char currentplayer='X';

void printBoard() {
	system("cls");
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void makeMove() {
    int row, col;

    do {
        cout << currentplayer << "'s turn. Enter row (1-3): ";
		cin >> row;
		cout << "and enter column (1-3): ";
        cin >> col;

        row--;  // Adjust for 0-based indexing
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
        }
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

    board[row][col] = currentplayer;
    
}

bool checkWin() {
    // Check rows
    for (int i=0; i<3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }
    // Check columns
    for (int i=0; i<3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}

bool checkTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // empty space found, not a tie
            }
        }
    }
    return true;  // spaces filled, game tied
}
		  
int main() {
	string player1, player2;
	cout << "Enter Player 1's(X) name: ";
	getline(cin, player1);
	cout << "Enter Player 2's(O) name: ";
	getline (cin, player2);
	
    while (!checkWin() && !checkTie()) {
        printBoard();
        makeMove();
        if (currentplayer == 'X') {
    		currentplayer = 'O';
		} else {
    		currentplayer = 'X';
		} //switch players
    }

    printBoard();

    if (checkWin()) {
    	if (currentplayer=='O') {
        	cout << player1 << " wins!" << endl;
    	} else {
    		cout << player2 << "wins!" << endl;
		}
    } else {
        cout << "Tie game!" << endl;
    }

    return 0;
}	  