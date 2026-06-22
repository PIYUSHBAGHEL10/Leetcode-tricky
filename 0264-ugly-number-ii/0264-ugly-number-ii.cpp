class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> set;
        long no = 1;
        set.insert(no);
        for(int i=0; i<n; i++){
            no = *set.begin();
            set.erase(no);
            set.insert(no*2);
            set.insert(no*3);
            set.insert(no*5);
        }
        return no;
    }
};