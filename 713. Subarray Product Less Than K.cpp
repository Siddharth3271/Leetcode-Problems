class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //T.C.=O(n)
        //S.C.=O(1)
        //Sliding window classic template
        if(k<=1){   //if k=1 or k=0
            return 0;
        }
        int n=nums.size();
        int i=0,j=0;
        int product=1;
        int count=0;
        while(j<n){
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
            count+=(j-i+1);  //no. of subarrays ending at j
            j++;
        }
        return count;
    }
};
