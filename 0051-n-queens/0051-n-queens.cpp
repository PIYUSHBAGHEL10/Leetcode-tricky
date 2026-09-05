class Solution {
public:
    bool valid_row(int curr_row, vector<vector<char>>& grid, int n) {
        for (int i = 0; i < n; i++) {
            if (grid[curr_row][i] == 'Q') {
                return false;
            }
        }
        return true;
    }

    bool valid_col(int curr_col, vector<vector<char>>& grid, int n) {
        for (int i = 0; i < n; i++) {
            if (grid[i][curr_col] == 'Q') {
                return false;
            }
        }
        return true;
    }
    bool valid_diagonal(const vector<vector<char>>& grid, int curr_row, int curr_col, int n) {
    // Top-Left Diagonal
    for (int i = curr_row - 1, j = curr_col - 1; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j] == 'Q') return false;
    }
    // Top-Right Diagonal
    for (int i = curr_row - 1, j = curr_col + 1; i >= 0 && j < n; i--, j++) {
        if (grid[i][j] == 'Q') return false;
    }
    return true;
}

   bool isValid(vector<vector<char>>& grid, int curr_row, int curr_col, int n) {
    return valid_col(curr_col, grid, n) && valid_diagonal(grid, curr_row, curr_col, n);
}

    vector<string> populate(vector<vector<char>>& grid, int n) {
        vector<string> result;
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += grid[i][j];
            }
            result.push_back(temp);
        }
        return result;
    }

    void solve(vector<vector<char>>& grid, int curr_row, int n,
               vector<vector<string>>& ans) {
        if (curr_row == n) {
            vector<string> temp = populate(grid, n);
            ans.push_back(temp);
            return;
        }
        for (int curr_col = 0; curr_col < n; curr_col++) {
            if (isValid(grid, curr_row, curr_col, n)) {
                grid[curr_row][curr_col] = 'Q';
                solve(grid, curr_row + 1, n, ans);
                grid[curr_row][curr_col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    solve(grid, 0, n, ans);
    return ans;
}
};