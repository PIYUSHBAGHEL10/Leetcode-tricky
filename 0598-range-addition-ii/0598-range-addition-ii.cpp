class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int max=m*n;
        if(ops.empty()){return max;}
        std::vector<int>inter;
        inter.push_back(ops[0][0]);
        inter.push_back(ops[0][1]);
        for(int i=1;i<ops.size();++i){
            inter[0]=std::min(inter[0],ops[i][0]);
            inter[1]=std::min(inter[1],ops[i][1]);
        }
        return (inter[0]*inter[1]);
    }
};