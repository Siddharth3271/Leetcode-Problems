#include<bits/stdc++.h>
using namespace std;
//brute force
// int kDistinctChars(int k, string &str)
// {
//     //T.C.=O(n^2)*log(256)  considering map is taking some time complexity
//     //S.C.=O(256)
//     int maxlen=0;
//     unordered_map<char,int>mp;
//     int n=str.length();
//     for(int i=0;i<n;i++){
//         mp.clear();
//         for(int j=i;j<n;j++){
//             mp[str[j]]++;
//             if(mp.size()<=k){
//                 maxlen=max(maxlen,j-i+1);
//             }
//             else  break;
//         }
//     }
//     return maxlen;
// }

//sliding window+two pointer
int kDistinctChars(int k, string &str)
{
    //T.C.=O(n)+O(n)+O(log(256))  considering map is taking some time complexity
    //S.C.=O(256)
    int maxlen=0;
    unordered_map<char,int>mp;
    int n=str.length();
    int l=0,r=0;
    while(r<n){
        mp[str[r]]++;
        while(mp.size()>k){
            mp[str[l]]--;
            if(mp[str[l]]==0){
                mp.erase(str[l]);
            }
            l++;
        }
        if(mp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

//more optimisation(we will not update maxlen unneccessarily)
int kDistinctChars(int k, string &str)
{
    //T.C.=O(n)+O(log(256))  considering map is taking some time complexity
    //S.C.=O(256)
    int maxlen=0;
    unordered_map<char,int>mp;
    int n=str.length();
    int l=0,r=0;
    while(r<n){
        mp[str[r]]++;
        if(mp.size()>k){
            mp[str[l]]--;
            if(mp[str[l]]==0){
                mp.erase(str[l]);
            }
            l++;
        }
        if(mp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}