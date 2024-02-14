class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //T.C=O(n)
        //S.C=O(n)
        int n=nums.size();
        int pos=0;
        int neg=1;
        vector<int> res(n);
        for(int &val:nums){
            if(val>0){
                res[pos]=val;
                pos=pos+2;
            }
            if(val<0){
                res[neg]=val;
                neg=neg+2;
            }
        }
        return res;
    }
};
