
#include <iostream>
#include <vector>
using namespace std;

int n;

void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check same column
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row) {
    // All queens placed successfully
    if (row == n)
        return true;

    // Try placing queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cout << "Enter value of N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid value of N." << endl;
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution:\n";
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
