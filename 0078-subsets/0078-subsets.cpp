class Solution {
private:
      void solve(vector<int> nums , vector<int> outputs ,int index , vector<vector<int>>&ans) {
        if(index >= nums.size()){
            ans.push_back(outputs); 
            return ;
        }
        int element=nums[index];
        outputs.push_back(element);
        solve(nums , outputs , index+1 , ans);

        outputs.pop_back();
        solve(nums , outputs , index+1 , ans);
        }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>outputs;
        solve(nums , outputs , 0 , ans);
        return ans;
    }
};