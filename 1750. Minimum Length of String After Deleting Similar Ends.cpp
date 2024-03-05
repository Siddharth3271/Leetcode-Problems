class Solution {
public:
    int minimumLength(string s) {
        //T.C.=O(n)  since we are visiting character only once
        //S.C.=O(1)
        int n=s.length();
        int i=0,j=n-1;
        if(s[i]!=s[j]){
            return n;
        }
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            while(i<j && s[i]==ch){
                i++;
            }
            while(j>=i && s[j]==ch){   // if "aa" check for it
                j--;
            }
        }
        return j-i+1;
    }
};
