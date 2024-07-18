#include<bits/stdc++.h>
using namespace std;
//T.C.=O(2*2n)
//S.C.=O(1)
int solvegoal(vector<int>&nums,int tar){
    if(tar<0){
        return 0;
    }
    int l=0,r=0;
    int sum=0,count=0;
    int n=nums.size();
    while(r<n){
        sum+=nums[r];
        while(sum>tar){   //run through out not individually
            sum=sum-nums[l];
            l++;
        }
        count=count+(r-l+1);
        r++;
    }
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    
    //applying simple mathematics
    //func(nums,goal)-func(nums,goal-1);
    //we get sum==goal subarrays
    return solvegoal(nums,goal)-solvegoal(nums,goal-1);
}