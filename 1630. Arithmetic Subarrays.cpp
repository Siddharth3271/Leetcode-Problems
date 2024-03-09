class Solution {
public:
    //T.C.=O(m *n)
    //S.C.=O(n)
    bool isAP(vector<int>& nums){
        int n=nums.size();
        int minE=INT_MAX;
        int maxE=INT_MIN;
        unordered_set<int>s;
        for(int &num:nums){
            minE=min(minE,num);
            maxE=max(maxE,num);
            s.insert(num);
        }
        if((maxE-minE)%(n-1)!=0){
            return false;
        }
        int d=((maxE-minE)/(n-1));
        int curr=minE;
        while(curr<maxE){
            if(s.find(curr)==s.end()){   //if not found
                return false;
            }
            curr+=d;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool>check;
        for(int i=0;i<m;i++){
            int start=l[i];
            int end=r[i];
            vector<int>arr;
            for(int j=start;j<=end;j++){
                arr.push_back(nums[j]);
            }
            bool ans=isAP(arr);
            check.push_back(ans);
        }
        return check;
    }
};
