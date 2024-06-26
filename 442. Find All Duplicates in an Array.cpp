class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            int idx=num-1;
            if(nums[idx]<0){
                res.push_back(num);
            }
            else{
                nums[idx]=-1*nums[idx];
            }
        }
        return res;
    }
};
