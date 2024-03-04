class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        //we need a set for every row
        int n=0; //for finding the maximum rows needed
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
            n=max(n,mp[it]);
        }
        vector<vector<int>>ans(n);
        vector<set<int>>s(n);
        for(auto x: nums){
            for(int i=0;i<n;i++){     //iterating through each row
                if(s[i].find(x)==s[i].end()){
                    ans[i].push_back(x);
                    s[i].insert(x);
                    break;
                }
            }
        }
        return ans;
    }
};
/*
    Constructing the frequency map (mp): This step iterates over all elements of nums once, resulting in a time complexity of O(m).
    Finding the maximum rows needed: This step involves finding the maximum frequency in the frequency map, which takes O(m) time.
    Constructing the result matrix (ans): For each element in nums, the function iterates through the rows (up to n) of the result matrix to find a suitable position. In the worst case, this can take O(m⋅n) time.

Therefore, the overall time complexity is O(m⋅n).

As for space complexity:

    The space complexity of the frequency map (mp) is O(m).
    The space complexity of the result matrix (ans) is also O(m), considering that it might contain all elements of nums.
    Each row in the result matrix has a corresponding set (s) to track unique elements, resulting in an additional space complexity of O(m).

Hence, the overall space complexity is O(m).
*/
