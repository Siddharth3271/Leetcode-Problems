class Solution {
public:
    typedef long long ll;

    ll findcost(vector<int> &nums,vector<int> &cost,int target){
        ll result=0;
        for(int i=0;i<nums.size();i++){
            result+=(ll)abs(nums[i]-target)*cost[i];
        }
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //using binary search
        ll answer=INT_MAX;
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            ll cost1=findcost(nums,cost,mid);
            ll cost2=findcost(nums,cost,mid+1);
            answer=min(cost1,cost2);
            if(cost2>cost1){
                right=mid-1;   //move to left side
            }
            else{
                left=mid+1;    // move to right side
            }
        }
        return answer==INT_MAX ? 0:answer;
    }
};

/*    Time Complexity:
        Finding the minimum and maximum elements in the nums vector takes O(n)O(n) time, where nn is the size of the nums vector.
        The binary search loop runs until left becomes greater than right, which typically takes O(log⁡(max−min))O(log(max−min)) iterations, where maxmax and minmin are the maximum and minimum elements in the nums vector, respectively.
        Inside each iteration of the binary search loop, findcost function is called twice, each taking O(n)O(n) time, where nn is the size of the nums vector.
        Therefore, the overall time complexity is O(nlog⁡(max−min))O(nlog(max−min)).

    Space Complexity:
        The space complexity is O(1)O(1) because the extra space used by your code does not scale with the size of the input.*/
