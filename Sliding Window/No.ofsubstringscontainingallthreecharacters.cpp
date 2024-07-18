#include<bits/stdc++.h>
using namespace std;
//naive solution
int numberOfSubstrings(string s) {
    //T.C.=O(n^2)
    //S.C.=O(1)
    int n=s.length();
    int count=0;
    for(int i=0;i<n;i++){
        int hash[3]={0};
        for(int j=i;j<n;j++){
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                count++;
            }
        }
    }
    return count;
}

//slightly optimized version
//key idea is that when we get the string which contain all three characters we don't need to traverse any further, we already know that further strings will already valid so we will subtract the last index of valid substring with total indices

int numberOfSubstrings(string s) {
    //T.C.=O(n^2)
    //S.C.=O(1)
    int n=s.length();
    int count=0;
    for(int i=0;i<n;i++){
        int hash[3]={0};
        for(int j=i;j<n;j++){
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                count=count+(n-j);
                break;
            }
        }
    }
    return count;
}

//optimal solution
//two pointer
//we will do the reverse -> with every character there is a substring that ends(minimum window)
int numberOfSubstrings(string s) {
    //T.C.=O(n)
    //S.C.=O(1)
    int n=s.length();
    int count=0;
    int lastseen[3]={-1,-1,-1};
    for(int i=0;i<n;i++){
        lastseen[s[i]-'a']=i;
        if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
            count=count+(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
        }
    }
    return count;
}