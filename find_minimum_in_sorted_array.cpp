class Solution {
public:
    int findMin(vector<int>& nums) {
        //T.C=O(log n)
        //S.C=O(1)
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){   //gadbad
                l=mid+1;
            } 
            else{
                r=mid;
            }
        }
        return nums[r];
    }
};
