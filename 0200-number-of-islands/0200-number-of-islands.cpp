class Solution {
public:
    void countIsland(vector<vector<char>>& grid, int currRow, int currCol, int row, int col) {
        if (currRow < 0 || currRow >= row || currCol < 0 || currCol >= col || grid[currRow][currCol] == '0')
            return;

    grid[currRow][currCol] = '0';

    countIsland(grid, currRow - 1, currCol, row, col);
    countIsland(grid, currRow + 1, currCol, row, col);
    countIsland(grid, currRow, currCol - 1, row, col);
    countIsland(grid, currRow, currCol + 1, row, col);
}
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col= grid[0].size();
        for (int currRow = 0; currRow < row; currRow++)
            for (int currCol = 0; currCol < col; currCol++)
                if (grid[currRow][currCol] == '1') {
                    ans++;
                    countIsland(grid, currRow, currCol, row, col);
                }
        return ans;
    }
};