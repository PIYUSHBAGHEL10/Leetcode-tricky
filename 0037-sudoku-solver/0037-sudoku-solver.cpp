class Solution {
public:
    bool valid_row(vector<vector<char>>& board, int currRow, int currVal) {
        for (int i = 0; i < 9; i++) {
            if (board[currRow][i] == currVal + '0') {
                return false;
            }
        }
        return true;
    }

    bool valid_col(vector<vector<char>>& board, int currCol, int currVal) {
        for (int i = 0; i < 9; i++) {
            if (board[i][currCol] == currVal + '0') {
                return false;
            }
        }
        return true;
    }

    bool valid_grid(vector<vector<char>>& board, int currRow, int currCol,
                    int currVal) {
        int x = 3 * (currRow / 3);
        int y = 3 * (currCol / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i+x][j+y] == currVal + '0') {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidCell(vector<vector<char>>& board, int currRow, int currCol,
                     int currVal) {
        return valid_row(board, currRow, currVal) &&
               valid_col(board, currCol, currVal) &&
               valid_grid(board, currRow, currCol, currVal);
    }

    bool sudokuSolver(vector<vector<char>>& board, int currRow, int currCol) {
        if (currRow == 9) {
            return true;
        }

        int nextRow = 0;
        int nextCol = 0;

        if (currCol == 8) {
            nextRow = currRow + 1;
            nextCol = 0;
        } else {
            nextCol = currCol + 1;
            nextRow = currRow;
        }

        // if not filled then call
        if (board[currRow][currCol] != '.') {
            return sudokuSolver(board, nextRow, nextCol);
        }
        // try all possibilities from 1 to 9 numbers
        for (int currVal = 1; currVal < 10; currVal++) {
            // if valid then make the change
            if (isValidCell(board, currRow, currCol, currVal)) {
                board[currRow][currCol] = '0' + currVal;
                // if already solved then return true directly
                if (sudokuSolver(board, nextRow, nextCol) == true)
                    return true;
                // backtracking
                board[currRow][currCol] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board){
        sudokuSolver(board , 0 , 0);
    }
};