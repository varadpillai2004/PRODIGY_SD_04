#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// Function to print the Sudoku grid
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

// Function to check if placing a number in the given position is valid
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Check if 'num' is not in the current row
    for (int x = 0; x < SIZE; ++x) {
        if (board[row][x] == num) return false;
    }

    // Check if 'num' is not in the current column
    for (int x = 0; x < SIZE; ++x) {
        if (board[x][col] == num) return false;
    }

    // Check if 'num' is not in the current 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Recursive function to solve the Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            // Find an empty cell
            if (board[row][col] == 0) {
                for (int num = 1; num <= SIZE; ++num) {
                    // Check if placing 'num' in the empty cell is valid
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num; // Place 'num'
                        if (solveSudoku(board)) return true; // Recursive call
                        board[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found, trigger backtracking
            }
        }
    }
    return true; // All cells are filled correctly
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

    cout << "Enter the Sudoku grid (9x9), use 0 for empty cells:" << endl;

    // Reading the Sudoku grid from user input
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

