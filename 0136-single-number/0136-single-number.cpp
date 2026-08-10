class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int c =0;
        for(int i : nums){
            c =i^c;
        }
        return c;
    }
};