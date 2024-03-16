class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        //T.C.=O(n)
        //S.C.=O(n)
        unordered_map<int,int>mp;
        int currsum=0;
        mp[0]=-1;
        int result=0;
        for(int i=0;i<n;i++){
            currsum+=(nums[i]==1)?1:-1;
            if(mp.find(currsum)!=mp.end()){
                //agar dekha hai tho
                result=max(result,i-mp[currsum]);
            }
            else{
                mp[currsum]=i;
            }
        }
        return result;
    }
};
