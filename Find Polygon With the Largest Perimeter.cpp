class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        //Greedy approach
        //T.C=O(n log n)
        //S.C=O(1)
        int n=nums.size();
        sort(nums.begin(),nums.end());  //can help, after that we can get every largest edge to comapre with sum of previous edges
        long long perimeter=0;
        long long rem_sides_sum=0; //cumulative sum
        for(int i=0;i<n;i++){
            if(nums[i]<rem_sides_sum){
                perimeter=rem_sides_sum+nums[i];
            }
            rem_sides_sum+=nums[i];
        }
        return perimeter==0?-1:perimeter;
    }
};
