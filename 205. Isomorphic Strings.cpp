class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //total 256 ascii characters
        //T.C.=O(n)
        //S.C.=O(1)
        unordered_map<char,char>mp1;  //for checking s->t
        unordered_map<char,char>mp2;  //for checking t->s
        int m=s.length();
        for(int i=0;i<m;i++){
            char ch1=s[i];
            char ch2=t[i];
            if(mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2  || mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1){
                return false;
            }
            mp1[ch1]=ch2;
            mp2[ch2]=ch1;
        }
        return true;
    }
};
