#include<bits/stdc++.h>
using namespace std;
//T.C.=O(n^2)
//S.C.=O(256)
string minWindow(string s, string t) {
    int n=s.length();
    int m=t.length();
    if (m > n) return ""; 
    int minlen=INT_MAX;
    int startidx=-1;
    int originalHash[256] = {0};
        
    // Fill the original hash table with counts of characters in t
    for (int j = 0; j < m; j++) {
        originalHash[t[j]]++;
    }
    for(int i=0;i<n;i++){
        int hash[256];
        memcpy(hash, originalHash, sizeof(originalHash));
        int count=0;
        for(int j=0;j<m;j++){
            hash[t[j]]++;
        }
        for(int k=0;k<n;k++){
            if(hash[s[k]]>0){
                count++;
            }
            hash[s[k]]--;
            if(count==m){
                if(k-i+1<minlen){
                    minlen=k-i+1;
                    startidx=i;
                    break;
                }
            }

        }
    }
    if (startidx == -1) return "";
    return s.substr(startidx,minlen);
}

//better approach(sliding window)
//T.C.=O(2n)+O(m)
//S.C.=O(1)
string minWindow(string s, string t) {
    int n=s.length();
    int m=t.length();
    if (m > n) return ""; 
    int hash[256]={0};
    int l=0,r=0;
    int minlen=INT_MAX;
    int startidx=-1;
    int count=0;
    for(int i=0;i<m;i++){
        hash[t[i]]++;
    }
    while(r<n){
        if(hash[s[r]]>0){
            count++;
        }
        hash[s[r]]--;
        while(count==m){
            if(r-l+1<minlen){
                minlen=r-l+1;
                startidx=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0){
                count--;
            }
            l++;
        }
        r++;
    }
    if (startidx == -1) return "";
    return s.substr(startidx,minlen);
}