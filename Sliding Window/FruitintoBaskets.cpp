#include<bits/stdc++.h>
using namespace std;
//brute force
// int totalFruit(vector<int>& fruits) {
//     //T.C.=O(n^2)
//     //S.C.=O(1)  only 3 elements
//     int n=fruits.size();
//     int maxlen=0;
//     for(int i=0;i<n;i++){
//         set<int>s;
//         for(int j=i;j<n;j++){
//             s.insert(fruits[j]);   //at max 3 elements therefore log 3 ==1
//             if(s.size()<=2){
//                 maxlen=max(maxlen,j-i+1);
//             }
//             if(s.size()>2){
//                 break;
//             }
//         }
//     }
//     return maxlen;
// }

//better approach(sliding window+map)
// int totalFruit(vector<int>& fruits) {
//     //T.C.=O(n)+O(n)=>O(2n)
//     //S.C.=O(1)  3 elements only
//     int n=fruits.size();
//     int maxlen=0;
//     int l=0,r=0;
//     unordered_map<int,int>mp;
//     while(r<n){
//         mp[fruits[r]]++;
//         if(mp.size()>2){
//             //first make it possible
//             while(mp.size()>2){    //not everytime it moves(but worst possible cas ecan be n)=> 3 3 3 3 1 2 l moves entirely
//                 mp[fruits[l]]--;
//                 if(mp[fruits[l]]==0){
//                     mp.erase(fruits[l]);
//                 }
//                 l++;
//             }
//         }
//         if(mp.size()<=2){
//             maxlen=max(maxlen,r-l+1);
//         }
//         r++;
//     }
//     return maxlen;
// }

//optimal approach

int totalFruit(vector<int>& fruits) {
    //T.C.=O(n)
    //S.C.=O(1)  3 elements only
    int n=fruits.size();
    int maxlen=0;
    int l=0,r=0;
    unordered_map<int,int>mp;
    while(r<n){
        mp[fruits[r]]++;
        if(mp.size()>2){
            mp[fruits[l]]--;   //move l++ till it becomes acceptable
            if(mp[fruits[l]]==0){
                mp.erase(fruits[l]);
            }
            l++;
        }
        if(mp.size()<=2){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

