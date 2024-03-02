class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int max=INT_MIN;
        //T.C.=(n log n)
        //S.C.=O(1)
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int a=nums[i]+nums[j];
            if(a>max){
                max=a;
            }
            i++;
            j--;
        }
        return max;
    }
};
