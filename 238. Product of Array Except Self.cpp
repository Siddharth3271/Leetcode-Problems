class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(n)
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>res;
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            left[i]=nums[i-1]*left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            res.push_back(left[i]*right[i]);
        }
        return res;
    }
};

//approach 2

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=nums.size();
        vector<int>res(n);
        res[0]=1;
        for(int i=1;i<n;i++){
            res[i]=nums[i-1]*res[i-1];
        }
        int right_prod=1;
        for(int i=n-1;i>=0;i--){
            res[i]=res[i]*right_prod;
            right_prod*=nums[i];
        }
        return res;
    }
};
