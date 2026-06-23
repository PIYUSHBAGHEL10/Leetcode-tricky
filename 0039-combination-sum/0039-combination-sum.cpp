class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int idx, int target, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            dfs(i, target - candidates[i], candidates); // reuse allowed
            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, target, candidates);
        return ans;
    }
};
