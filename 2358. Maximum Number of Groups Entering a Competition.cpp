class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        //T.C.=O(1)
        //S.C.=O(1)
        //sum of no of groups is less than the size of array
        //(1+2+3+......+n)<grades.size()
        //n(n+1)/2<s
        //n^2+n-2s--> use Shri Dharacharya Formula
        int s=grades.size();
        return (-1+sqrt(1+8*s))/2;   //since we have to return maximum no. of groups which need to be positive
    }
};
