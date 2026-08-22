class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
         int strt=0;
    int end=A.size()-1;
    while(strt<=end)
    {
        int loner=strt+1;
        if(A[strt]==A[end]){
            return A[strt];
        }
        if( A[strt]==A[loner]){
            strt=strt+2;
        }
        else if (A[strt]!=A[loner])
        {
            return A[strt];
        }
    }
    return -1;
    }
};