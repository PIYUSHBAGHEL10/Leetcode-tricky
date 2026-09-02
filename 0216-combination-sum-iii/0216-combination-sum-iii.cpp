class Solution {
public:
    vector<int> res;
    void solve(vector<int>& arr, int k, int n, vector<vector<int>>& ans,
               int& sum, vector<int>& res, int index) {
        if (res.size()== k) {
            if(sum==n){
                 ans.push_back(res);
            return;
            }
           
        }

        for (int i = index; i < arr.size(); i++) {
            if (sum < n) {
                if (res.size() < k) {
                    res.push_back(arr[i]);
                    sum += arr[i];
                    solve(arr, k, n, ans, sum, res, i + 1);
                    res.pop_back();
                    sum=sum-arr[i];
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        int sum = 0;
        solve(arr, k, n, ans, sum, res, 0);
        return ans;
    }
};