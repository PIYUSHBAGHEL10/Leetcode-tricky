class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int champ, maxCountOnes = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int countOnes = 0;
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    countOnes++;
            if (maxCountOnes < countOnes) {
                champ = i;
                maxCountOnes = countOnes;
            }
        }
        return champ;
    }
};