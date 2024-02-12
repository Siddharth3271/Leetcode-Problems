class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //boyer moore Voting algorithm

        //T.C=>O(n)
        //S.C=>O(1)
        int n=nums.size();
        int count=0;
        int maj=NULL;
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                maj=nums[i];
            }
            else if(nums[i]==maj){
                count++;
            }
            else{
                count--;
            }
        }
        return maj;
    }
};
