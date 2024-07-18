#include<bits/stdc++.h>
using namespace std;
// int lengthOfLongestSubstring(string s) {
//     //T.C.=O(n^2)
//     //S.C.=O(256)
//     //naive solution
//     int maxlen=0;
//     for(int i=0;i<s.size();i++){
//         unordered_map<int,int>mp;
//         for(int j=i;j<s.size();j++){
//             if(mp.find(s[j])!=mp.end()){
//                 break;
//             }
//             int len=j-i+1;
//             maxlen=max(len,maxlen);
//             mp[s[j]]=1;
//         }
//     }
//     return maxlen;
// }
int lengthOfLongestSubstring(string s) {
    //start thinking of sliding window and two pointer approach
    vector<int>freq(256,-1);  //to store index
    int l=0,r=0;
    int maxlen=0;
    int n=s.size();
    while(r<n){
        if(freq[s[r]]!=-1){
            if(freq[s[r]]>l){
                l=freq[s[r]]+1;
            }
        }
        int len=r-l+1;
        maxlen=max(len,maxlen);
        freq[s[r]]=r;
        r++;
    }
    return maxlen;
}