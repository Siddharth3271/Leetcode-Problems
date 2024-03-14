class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //approach 1
        //T.C.=O(n)
        //S.C.=O(n)
        int n=nums.size();
        unordered_map<int,int>mp;
        int res=0;
        int currsum=0;
        mp[0]=1;   //since i have already seen currsum=0 once
        for(int &num:nums){
            currsum+=num;
            int rem_sum=currsum-goal; //have i seen it in past
            if(mp.find(rem_sum)!=mp.end()){
                res+=mp[rem_sum];    
            }
            mp[currsum]++;  //jisko dekha usko bhi add kardo
        }
        return res;
    }
};


//approach 2
//sliding window
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //approach 2
        //T.C.=O(2*n)==O(n)  //since each element is visited twice i and j respectively
        //S.C.=O(1)
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        int window_sum=0;
        int count_zero=0;   //finding no. of prefix zeroes
        while(j<n){
            window_sum+=nums[j];
            while((nums[i]==0 || window_sum>goal) && i<j){   //i.....j
                if(nums[i]==0){
                    count_zero++;
                }
                else{
                    count_zero=0;  //reset to 0
                }
                window_sum-=nums[i];
                i++;
            }
            if(window_sum==goal){
                count+=1+count_zero;
            }
            j++;
        }
        return count;
    }
};
