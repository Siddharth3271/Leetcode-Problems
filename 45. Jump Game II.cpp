class Solution {
public:
    int jump(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=nums.size();
        int jumps=0;
        int current=0;
        int farthest=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,nums[i]+i);
            if(i==current){
                current=farthest;
                jumps++;
            }
        }
        return jumps;
    }
};
