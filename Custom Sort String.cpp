class Solution {
public:
    string customSortString(string order, string s) {
        //approach 1
        //T.C.=O(n)
        //S.C.=O(n)
        int count[26]={0};
        for(char &ch:s){
            count[ch-'a']++;
        }
        string res="";
        for(char &ch:order){     //first maintaining order
            while(count[ch-'a']>0){
                res.push_back(ch);
                count[ch-'a']--;
            }
        }
        
        for(char &ch:s){     //remaining characters were pushed back
            if(count[ch-'a']>0){
                res.push_back(ch);
            }
        }
        return res;
    }
};


class Solution {
public:
    
    string customSortString(string order, string s) {
        //approach 2
        //T.C.=O(m+ n log n)=> m is length of order string and n is length of s string
        //S.C.=O(1)
        vector<int>mp(26,-1);
        for(int i=0;i<order.length();i++){
            char ch=order[i];
            mp[ch-'a']=i;
        }
        auto mycomp=[&mp](char &ch1,char &ch2){
            return mp[ch1-'a']<mp[ch2-'a'];
        };
        sort(s.begin(),s.end(),mycomp);
        return s;
    }
};
