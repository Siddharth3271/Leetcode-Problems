#include<bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
    int maxlen=0;
    //T.C.=O(n^2) nearly
    //S.C.=O(1)
    for(int i=0;i<n;i++){
        int zeroes=0;
        for(int j=i;j<n;j++){   //not running for exacty n times
            if(nums[j]==0){
                zeroes++;
            }
            if(zeroes<=k){
                int len=j-i+1;
                maxlen=max(maxlen,len);
            }
            else{
                break;
            }
        }
    }
    return maxlen;       
}

//better(sliding window+two pointer)
// int longestOnes(vector<int>& nums, int k) {
//     int n=nums.size();
//     int maxlen=0;
//     int l=0,r=0;
//     //T.C.=O(n)+O(n)=>O(2n)
//     //S.C.=O(1)
//     int zeroes=0;
//     while(r<n){
//         if(nums[r]==0){
//             zeroes++;
//         }
//         while(zeroes>k){
//             if(nums[l]==0){
//                 zeroes--;
//             }
//             l++;
//         }
//         if(zeroes<=k){
//             int len=r-l+1;
//             maxlen=max(maxlen,len);
//         }
//         r++;
//     }
//     return maxlen;       
// }

//optimal(sliding window)
// int longestOnes(vector<int>& nums, int k) {
//     //T.C.=O(n)

//     int n=nums.size();
//     int maxlen=0;
//     int l=0,r=0;
//     int zeroes=0;
//     while(r<n){
//         if(nums[r]==0){
//             zeroes++;
//         }
//         if(zeroes>k){
//             if(nums[l]==0){
//                 zeroes--;
//             }
//             l++;
//         }
//         if(zeroes<=k){
//             int len=r-l+1;
//             maxlen=max(maxlen,len);   //extend the size only if zeroes are under control
//         }
//         r++;
//     }
//     return maxlen;       
// }

int main(){
    vector<int>nums{1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0};
    int a=longestOnes(nums,4);
    std::cout<<a<<endl;
    return 0;
}