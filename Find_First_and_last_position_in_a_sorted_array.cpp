//method 1

const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                res.push_back(i);
                break;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]==target){
                res.push_back(j);
                break;
            }
        }
        if(res.empty()){
            return {-1,-1};
        }
        return res;
    }
};
//Time complexity:
// Best case: O(1). This occurs when the target is either the first or last element in the array, and it is found in the first iteration of the respective loop. In this case, only one comparison is needed.
// Average case: O(n). On average, the target might be found somewhere in the middle of the array. Both loops iterate through the entire array in the worst case, leading to a total of 2n comparisons.
// Worst case: O(n). This occurs when the target is not present in the array, and both loops complete their full iterations without finding it. This results in 2n comparisons.

// Space complexity:
// O(1). The algorithm uses a constant amount of additional space regardless of the input size. It only uses fixed-size variables like n, i, j, and the res vector (whose size is limited to 2 in the worst case).

// method 2
const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int findrightmost(vector<int>&nums,int target,int n){
        int l=0,r=n-1;
        int right_most=-1;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==target){
            right_most=mid;   //possibly the answer
            l=mid+1;          //look more on left
        }
        else if(nums[mid]<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
        return right_most;
}
    int findleftmost(vector<int> &nums,int target,int n){
        int l=0,r=n-1;
        int left_most=-1;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==target){
            left_most=mid;   //possibly the answer
            r=mid-1;          //look more on left
        }
        else if(nums[mid]<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
        return left_most;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left_most=findleftmost(nums,target,n);
        int right_most=findrightmost(nums,target,n);
        return {left_most,right_most};
    }
};

// Time complexity:
// Overall: O(log n). This is because both findleftmost and findrightmost functions use binary search, which has a time complexity of O(log n). The searchRange function simply calls these two functions, so its overall time complexity remains O(log n).
// Best case: O(1). If the target is either the first or last element in the array, it will be found in the first iteration of the respective binary search, resulting in just one comparison.
// Average case: O(log n). On average, the target will be found within a logarithmic number of iterations of the binary search loops.
// Worst case: O(log n). Even in the worst case (target not found or present multiple times), the binary search loops will still execute a logarithmic number of iterations.

// Space complexity:
// O(1). The algorithm still uses a constant amount of additional space, regardless of the input size. It employs fixed-size variables and vectors for its computations.
