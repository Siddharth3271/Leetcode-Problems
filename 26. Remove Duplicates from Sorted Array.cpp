class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(1)
        int i=0; //always point to unique element
        int n=nums.size();
        int j=1; //will bring unique elements to i
        while(j<n){
            if(nums[i]!=nums[j]){  //got a unique elements
                i++;
                nums[i]=nums[j];
            }
            j++;
        }
        return i+1;
    }
};
