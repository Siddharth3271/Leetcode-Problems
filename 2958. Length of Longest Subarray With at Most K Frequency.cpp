class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        //T.C.=O(n)  at most each element will be visited twice  2*O(n)
        //S.C.=O(n)
        unordered_map<int,int>mp;
        int i=0,j=0;
        int res=0;
        while(j<n){
            mp[nums[j]]++;
            while(i<j && mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};
