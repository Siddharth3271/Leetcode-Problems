#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums,int tar){
    if(tar<0){
        return 0;
    }
    int l=0,r=0;
    int sum=0,count=0;
    int n=nums.size();
    while(r<n){
        sum+=nums[r]%2;
        while(sum>tar){   //run through out not individually
            sum=sum-nums[l]%2;
            l++;
        }
        count=count+(r-l+1);
        r++;
    }
    return count;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    int n=nums.size();
    return solve(nums,k)-solve(nums,k-1);
}