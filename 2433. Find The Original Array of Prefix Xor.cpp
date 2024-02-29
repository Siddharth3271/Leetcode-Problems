class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        for(int i=n-1;i>0;i--){
            pref[i]=(pref[i-1]^pref[i]);
        }
        return pref;
        //T.C.=O(n)
        //S.C.=O(1)
    }
};
