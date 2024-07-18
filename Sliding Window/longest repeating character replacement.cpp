#include<bits/stdc++.h>
using namespace std;
//we have to minimise the no. of conversions and get longest substring
//this can be done by formula Totallen-maxfreq

//brute force
int characterReplacement(string s, int k) {
    //T.C.=O(n^2)
    //S.C.=O(1)
    int n=s.length();
    int maxlen=0;
    for(int i=0;i<n;i++){
        int hash[26]={0};
        int maxfreq=0;
        for(int j=i;j<n;j++){
            hash[s[j]-'A']++;
            maxfreq=max(maxfreq,hash[s[j]-'A']);
            int changes=(j-i+1)-maxfreq;
            if(changes<=k){
                maxlen=max(maxlen,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxlen;
}

//optimization(two ppointer+sliding window)
int characterReplacement(string s, int k) {
    //T.C.=O(n+n)*O(26)
    //S.C.=O(1)
    int n=s.length();
    int maxlen=0;
    int maxfreq=0;
    int l=0,r=0;
    int hash[26]={0};
    while(r<n){
        hash[s[r]-'A']++;
        maxfreq=max(maxfreq,hash[s[r]-'A']);
        int changes=(r-l+1)-maxfreq;
        while(changes>k){
            hash[s[l] - 'A']--;
            l++;
            maxfreq = 0;
            for (int i = 0; i < 26; i++) {
                maxfreq = max(maxfreq, hash[i]);
            }
            changes = (r - l + 1) - maxfreq;
        }
        if(changes<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

//optimized
int characterReplacement(string s, int k) {
    //T.C.=O(n)
    //S.C.=O(1)
    int n=s.length();
    int maxlen=0;
    int maxfreq=0;
    int l=0,r=0;
    int hash[26]={0};
    while(r<n){
        hash[s[r]-'A']++;
        maxfreq=max(maxfreq,hash[s[r]-'A']);
        int changes=(r-l+1)-maxfreq;
        if(changes>k){
            hash[s[l] - 'A']--;
            l++;
            maxfreq = 0;
            changes = (r - l + 1) - maxfreq;
        }
        if(changes<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}