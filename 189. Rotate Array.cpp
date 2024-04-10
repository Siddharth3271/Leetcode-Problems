class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.begin()+k);
        
    }
};
