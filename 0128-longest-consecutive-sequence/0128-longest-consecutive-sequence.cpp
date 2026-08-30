class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> start,end;
        map<int,int> seen;

        int len=1;
        int n = nums.size();

        if(n == 0) return 0;

        for(int i=0;i<n;i++){
            int x = nums[i];
            //since we only store boundaries we need a seperate map check now
            if(seen[x]) continue;
            seen[x] = 1;

            int lc = x-1;
            int rc = x+1;

            int cur = 1;

            //find interval ending at x-1 and interval starting at x+1
            int ll = end[lc];
            int rl = start[rc];

            cur += (ll+rl);

            //new boundaries after merging
            int lb = x-ll;
            int rb = x+rl;

            //old boundaries disappear
            start.erase(rc);
            end.erase(lc);

            //store new merged interval
            start[lb] = cur;
            end[rb] = cur;

            len = max(len,cur);
        }
        return len;
    }
};