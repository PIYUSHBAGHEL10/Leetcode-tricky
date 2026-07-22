class Solution {
public:
    int findArea(vector<vector<int>>& grid, int currRow, int currCol, int m, int n) {
        if (currRow < 0 || currCol < 0 || currRow >= m || currCol >= n || grid[currRow][currCol] == 0)
            return 0;
        grid[currRow][currCol] = 0;

        int count = 1;
        count += findArea(grid, currRow - 1, currCol, m, n);
        count += findArea(grid, currRow + 1, currCol, m, n);
        count += findArea(grid, currRow, currCol - 1, m, n);
        count += findArea(grid, currRow, currCol + 1, m, n);

        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int currRow = 0; currRow < m; currRow++)
            for (int currCol = 0; currCol < n; currCol++) {
                if (grid[currRow][currCol] == 1) {
                    ans = max(ans, findArea(grid, currRow, currCol, m, n));
                }
            }
        return ans;
    }
};