class Solution {
public:
//T.C=O(1)
//S.C=O(1)
    bool isPowerOfTwo(int n) {
        if(n>0){
            return !(n&(n-1));
        }
        return false;
    }
};
