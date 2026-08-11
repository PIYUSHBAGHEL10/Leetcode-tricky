class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int strt=0;
        while(strt<= end){
             int mid = strt + (end-strt)/2;
            if(nums[mid]==target){
                return mid;
             }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                strt=mid+1;
            }
        }
        return -1;
    }
};