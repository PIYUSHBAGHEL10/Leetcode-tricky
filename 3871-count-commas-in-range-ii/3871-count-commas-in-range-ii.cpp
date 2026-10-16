class Solution {
public:
    int64_t pow[6] = {1000, 1000000, 1000000000, 1000000000000, 1000000000000000, 1000000000000000000};
    
    int64_t countCommas(auto& n) {
        int64_t t = 0;        
        for (auto& p : pow) t += n>=p;
        
        return t*(n+1) - (pow[t]-1000)/999;
    }
};