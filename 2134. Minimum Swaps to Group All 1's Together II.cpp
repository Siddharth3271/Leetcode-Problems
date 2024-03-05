class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=nums.size();
        int one=0;
        int zero=0;
        for(int i=0;i<n;i++){
            one+=(nums[i]==1);
            zero+=(nums[i]==0);
        }
        //converting circular array to straight array
        nums.insert(nums.end(),nums.begin(),nums.end());
        int ans=n;
        int i=0,j=0,ones=0;
        while(j<2*n){
            ones+=(nums[j]==1);
            if(j-i+1==one){
                ans=min(ans,one-ones);
                ones-=(nums[i]==1);
                i++;
            }
            j++;
        }
        return ans;
    }
};
