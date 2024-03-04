class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(1)
        if(nums.size()<3) return 0;
        int start=0,end=1,diff,n,sum=0;
        for(int i=1;i<nums.size();i++){
            diff=nums[end]-nums[start];
            while(i+1<nums.size() && nums[i+1]-nums[i]==diff){
                end++;
                i++;
            }
            n=(end-start)+1;  //counting the numbers in single arithmetic triplet
            if(n>=3){  //the block should have at least three elements
                sum+=(n-2)*(n+1-2)/2;
            }
            start=end;   //for next arithmetic triplets
            end++;
        }
        return sum;
    }
};
