class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minLength =INT_MAX, currentSum =0, length = 0;
        
        for(int right = 0; right < nums.size(); right++){
            currentSum += nums[right];
            while(currentSum >= target){
                length = right- left + 1;
                minLength = min(length, minLength);
                currentSum -= nums[left];
                left++;
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};