class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //T.C=O(n)
        //S.C=O(n)
        //approach 1
        int n=s.length();
        int i=0;
        string ans=string(n,'0');
        for(char &ch: s){
            if(ch=='1'){
                if(ans[n-1]=='1'){   //least significant bit need to be 1 for odd
                    ans[i]='1';
                }
                else{
                    ans[n-1]='1';
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //T.C=O(n)
        //S.C=O(n)
        //approach 2
        int n=s.length();
        int i=0;
        string ans=string(n,'0');
        int cnt=count(s.begin(),s.end(),'1');
        int j=0;
        while(cnt>1){  //remaining 1 to be assigned to lsb
            ans[j]='1';
            j++;
            cnt--;
        }
        ans[n-1]='1';
        return ans;
    }
};
