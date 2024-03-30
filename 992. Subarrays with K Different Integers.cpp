//important pattern
class Solution {
public:
    //total count of subarrays having <=k distinct elements
    int sliding_window(vector<int> &nums,int k){
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0;
        int count=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                //shrink the window from left
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            count+=(j-i+1);   //ending at j
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //T.C.=O(n)
        //S.C.=O(n)
        return sliding_window(nums,k)-sliding_window(nums,k-1);
    }
};
