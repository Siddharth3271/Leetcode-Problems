class Solution {
public:
//T.C=>O(n)
//S.C=>O(n)
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {};
        if(n == 1) {
            return {nums[0]};
        }
        int count1 = 0;
        int maj1   = NULL;
        
        int count2 = 0;
        int maj2   = NULL;
        
        
        for(int i = 0; i<n; i++) {
            if(maj1 != NULL && nums[i] == maj1)
                count1++;
            else if(maj2 != NULL && nums[i] == maj2)
                count2++;
            else if(count1 == 0) {
                count1 = 1;
                maj1 = nums[i];
            } else if (count2 == 0) {
                count2 = 1;
                maj2 = nums[i];
            } else {
                count1--;
                count2--;
            }
        }
        
        vector<int> result; 
        count1 = 0;
        count2 = 0;
        for(int num:nums) {
            if(num == maj1)
                count1++;
            else if(num == maj2)  //else if ? why ?  Because we don't want duplicate. Example ({0, 0, 0}
                count2++;
        }
        if(count1 > floor(n/3))
            result.push_back(maj1);
        if(count2 > floor(n/3))
            result.push_back(maj2);
        return result;
    }
};
