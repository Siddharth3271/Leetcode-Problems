class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        int sum=0;
        for(auto &it:mp){
            if(it.second==1){
                sum+=it.first;
            }
        }
        return sum;
        //T.C=>O(n)
        //S.C=>O(n)
    }
};
