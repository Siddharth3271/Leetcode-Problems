#include<bits/stdc++.h>
using namespace std;
//naive solution
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n=nums.size();
    int count=0;
    //T.C.=O(n^2)
    //S.C.=O(n)
    for(int i=0;i<n;i++){
        unordered_map<int,int>mp;
        for(int j=i;j<n;j++){
            mp[nums[j]]++;
            if(mp.size()==k){
                count++;
            }
            else if(mp.size()>k){
                break;
            }
        }
    }
    return count;
}

//two pointer approach(try for subarrays with distinct integers lesser than equal to k)
int solve(vector<int>&nums,int k){
    int n=nums.size();
    int count=0;
    int l=0,r=0;
    unordered_map<int,int>mp;
    while(r<n){
        mp[nums[r]]++;
        if(mp.size()>k){
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
        }
        count=count+(r-l+1);
        r++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    //T.C.=O(2n)
    //S.C.=O(n)
    return solve(nums,k)-solve(nums,k-1);
}

