class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(1)
        //slow and fast pointer technique
        //1,3,4,2,2
        //s
        //      f    pehle hi do step aage move kar deta hoon
        int slow=nums[0];
        int fast=nums[0];
        slow=nums[slow];
        fast=nums[nums[fast]];
        //detect cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        //slow ko wapis bhej do
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;   //where they meet again is the duplicate number and starting of cycle
    }
};
