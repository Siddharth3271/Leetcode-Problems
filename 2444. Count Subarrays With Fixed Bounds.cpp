class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        //T.C.=O(n)
        //S.C.=O(1)
        long long ans=0;
        int minpos=-1;
        int maxpos=-1;
        int culprit=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mink || nums[i]>maxk){
                culprit=i;
            }
            if(nums[i]==maxk){
                maxpos=i;
            }
            if(nums[i]==mink){
                minpos=i;
            }
            long long smaller=min(minpos,maxpos);
            long long temp=smaller-culprit;
            ans+=(temp<=0)? 0:temp;
        }
        return ans;
    }
};
